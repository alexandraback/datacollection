import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class JamC 
{
	
	static class Posibilidad
	{
		int[] vals;
		HashMap <Integer, Double> probabilidades = new HashMap <Integer, Double> ();
		
		Posibilidad(int[] vals)
		{
			this.vals = vals.clone();
			HashMap <Integer, Integer> veces = new HashMap <Integer, Integer> ();
			for(int i = 0; i < 8; i++)
			{
				int producto = 1;
				int indice = 0;
				int mascara = i;
				while(mascara != 0)
				{
					if((mascara & 1) == 1)
						producto *= vals[indice];
					mascara >>= 1;
					indice++;
				}
				if(!veces.containsKey(producto))
					veces.put(producto, 0);
				veces.put(producto, veces.get(producto) + 1);
			}
			for(Map.Entry<Integer, Integer> e : veces.entrySet())
				probabilidades.put(e.getKey(), e.getValue() / 8.0);
		}
		
		double darProbabilidad(int p)
		{
			if(!probabilidades.containsKey(p))
				return 0;
			return probabilidades.get(p);
		}
	}
	
	static ArrayList <Posibilidad> posibilidades = new ArrayList <Posibilidad> ();
	
	
	static void generar(int actual, int[] vals)
	{
		if(actual == vals.length)
			posibilidades.add(new Posibilidad(vals));
		else
		{
			for(int i = 2; i <= 5; i++)
			{
				vals[actual] = i;
				generar(actual + 1, vals);
			}
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException
	{
		System.setOut(new PrintStream("c-small1.out"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		generar(0, new int[3]);
		for(int caso = 1; caso <= T; caso++)
		{
			System.out.println("Case #" + caso + ":");
			int R = sc.nextInt();
			sc.nextInt();
			sc.nextInt();
			int K = sc.nextInt();
			for(int i = 0; i < R; i++)
			{
				int[] ks = new int[K];
				for(int j = 0; j < K; j++)
					ks[j] = sc.nextInt();
				double mejor = Double.NEGATIVE_INFINITY;
				Posibilidad mejorP = null;
				for(Posibilidad p : posibilidades)
				{
					double acum = 1;
					for(int v : ks)
						acum *= p.darProbabilidad(v);
					if(acum > mejor)
					{
						mejor = acum;
						mejorP = p;
					}
				}
				for(int v : mejorP.vals)
					System.out.print(v);
				System.out.println();
			}
		}
		sc.close();
	}

}
