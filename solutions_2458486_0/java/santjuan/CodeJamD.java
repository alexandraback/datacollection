import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class CodeJamD 
{
	static boolean debug = false;
	static int n;
	static Boolean[] dp = new Boolean[1 << 20];
	static int[] siguiente = new int[1 << 20];
	static int[] tipos;
	static int[][][] cuales;
	
	static boolean agregar(int[] actuales, int cual, boolean quitar)
	{
		if(!quitar && actuales[tipos[cual]] == 0)
			return false;
		if(quitar)
			actuales[tipos[cual]]++;
		else
			actuales[tipos[cual]]--;
		for(int[] val : cuales[cual])
			actuales[val[0]] += val[1] * (quitar ? -1 : 1);
		return true;
	}
	
	static boolean dp(int mascara, int[] actuales)
	{
		if(dp[mascara] != null)
			return dp[mascara];
		if(Integer.bitCount(mascara) == n)
			return dp[mascara] = true;
		for(int i = 0; i < n; i++)
		{
			if(((mascara & (1 << i)) == 0) && agregar(actuales, i, false))
			{
				boolean res = dp(mascara | (1 << i), actuales);
				agregar(actuales, i, true);
				if(res)
				{
					siguiente[mascara] = i;
					return dp[mascara] = true;
				}
			}
		}
		return dp[mascara] = false;
	}
	
	public static void main(String[] args) throws FileNotFoundException
	{
		if(!debug)
		{
			System.setIn(new FileInputStream("D-small-attempt1.in"));
			System.setOut(new PrintStream("D-small-attempt1.out"));
		}
		Scanner sc = new Scanner(System.in);
		int t = Integer.parseInt(sc.nextLine());
		for(int caso = 1; caso <= t; caso++)
		{
			int k = sc.nextInt();
			n = sc.nextInt();
			int[] actuales = new int[201];
			for(int i = 0; i < k; i++)
				actuales[sc.nextInt()]++;
			tipos = new int[n];
			cuales = new int[n][][];
			int[] cuentas = new int[201];
			String res = null;
			for(int i = 0; i < n; i++)
			{
				tipos[i] = sc.nextInt();
				Arrays.fill(cuentas, 0);
				int numero = sc.nextInt();
				for(int j = 0; j < numero; j++)
					cuentas[sc.nextInt()]++;
				ArrayList <int[]> esta = new ArrayList <int[]> ();
				for(int j = 0; j < 201; j++)
				{
					if(cuentas[j] != 0)
						esta.add(new int[]{j, cuentas[j]});
				}
				cuales[i] = esta.toArray(new int[0][]);
			}
			Arrays.fill(dp, null);
			for(int i = 0; i < n; i++)
			{
				if(agregar(actuales, i, false))
				{
					if(dp(1 << i, actuales))
					{
						res = " " + (i + 1);
						int mascaraActual = 1 << i;
						while(Integer.bitCount(mascaraActual) != n)
						{
							res += " " + (1 + siguiente[mascaraActual]);
							mascaraActual |= 1 << siguiente[mascaraActual];
						}
						break;
					}
					else
						agregar(actuales, i, true);
				}
			}
			if(res != null)
				System.out.println("Case #" + caso + ":" + res);
			else
				System.out.println("Case #" + caso + ": IMPOSSIBLE");
		}
		sc.close();
		if(debug)
		{
			System.out.flush();
			System.out.close();
		}
	}

}
