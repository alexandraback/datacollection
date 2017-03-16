package GoogleCodeJam_2014_Qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Problem_D_Deceitful_War 
{
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException 
	{
		BufferedReader leer = new BufferedReader(new FileReader("D-large.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("D-large.out"));
		StringBuilder salida = new StringBuilder();
		int casos = Integer.parseInt(leer.readLine());
		int N,puntosNormal,puntosMin,cont = 0;
		ArrayList<Double> naomi, ken;
		while(casos-- != 0)
		{
			N = Integer.parseInt(leer.readLine());
			naomi = lectura(leer.readLine(),N);
			ken = lectura(leer.readLine(),N);
			puntosNormal = guerraNormal(naomi,(ArrayList<Double>)ken.clone());
			puntosMin = guerraMintiendo(naomi,ken);
			salida.append("Case #"+(++cont)+": "+puntosMin+" "+puntosNormal+"\n");
		}
		leer.close();
		out.append(salida);
		out.close();
	}

	private static int guerraMintiendo(ArrayList<Double> naomi,
			ArrayList<Double> ken) 
	{
		int puntos = 0;
		while(!naomi.isEmpty())
		{
			if(naomi.get(0) > ken.get(0))
			{
				puntos++;
				ken.remove(0);
				naomi.remove(0);
			}
			else
			{
				ken.remove(ken.size()-1);
				naomi.remove(0);
			}
		}
		return puntos;
	}

	private static int guerraNormal(ArrayList<Double> naomi,
			ArrayList<Double> ken) 
	{
		int puntos = 0;
		for(double pesoNao : naomi)
		{
			if(pesoNao > ken.get(ken.size()-1))
			{
				puntos++;
				ken.remove(ken.size()-1);
			}
			else
			{
				int aux = ken.size()-1;
				for(int i=ken.size()-2; i>= 0; i--)
				{
					if(pesoNao < ken.get(i))
						aux = i;
					else break;
				}
				ken.remove(aux);
			}
		}
		return puntos;
	}

	private static ArrayList<Double> lectura(String Line, int n) 
	{
		ArrayList<Double> vector = new  ArrayList<Double>();
		StringTokenizer partes = new StringTokenizer(Line);
		for(int i=0; i<n; i++)
			vector.add(Double.parseDouble(partes.nextToken())*1000);
		Collections.sort(vector);
		return vector;
	}
}
