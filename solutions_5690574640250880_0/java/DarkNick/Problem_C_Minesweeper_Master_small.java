package GoogleCodeJam_2014_Qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Problem_C_Minesweeper_Master_small 
{
	static Map<String, String> tableros = new HashMap<String, String>();
	public static void main(String[] args) throws IOException 
	{
		BufferedReader leer = new BufferedReader(new FileReader("C-small-attempt2.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C-small-attempt2.out"));
		StringBuilder salida = new StringBuilder();
		StringTokenizer partes;
		String linea;
		int casos = Integer.parseInt(leer.readLine());
		int R,C,M,cont = 0;
		generar();
		while(casos-- != 0)
		{
			partes = new StringTokenizer(leer.readLine());
			R = Integer.parseInt(partes.nextToken());
			C = Integer.parseInt(partes.nextToken());
			M = Integer.parseInt(partes.nextToken());
			salida.append("Case #"+(++cont)+":\n");
			if(M == 0)
			{
				boolean ban = true;
				for(int i=0; i<R; i++)
				{
					for(int j=0; j<C; j++)
					{
						if(ban)
						{
							salida.append("c");
							ban = false;
						}
						else salida.append(".");
					}
					salida.append("\n");
				}
				continue;
			}
			if(R == 1 || C == 1)
			{
				for(int i=0; i<R; i++)
				{
					for(int j=0; j<C; j++)
					{
						if(M-- > 0)salida.append("*");
						else
						{
							if(i == R-1 && j == C-1)salida.append("c");
							else salida.append(".");
						}
					}
					salida.append("\n");
				}
				continue;
			}
			if(C > R)
			{
				int aux = C;
				C = R;
				R = aux;
				linea = C+" "+R+" "+M;
				if(tableros.containsKey(linea))
				{
					linea = tableros.get(linea);
					partes = new StringTokenizer(linea,"\n");
					char tab[][] = new char[R][C];
					for(int i=0; i<R; i++)
					{
						linea = partes.nextToken();
						for(int j=0; j<C; j++)
							tab[i][j] = linea.charAt(j);
					}
					for(int i=0; i<C; i++)
					{
						for(int j=0; j<R; j++)
							salida.append((char)(tab[j][i]));
						salida.append("\n");
					}
				}
				else salida.append("Impossible\n");
			}
			else
			{
				linea = C+" "+R+" "+M;
				if(tableros.containsKey(linea))
					salida.append(tableros.get(C+" "+R+" "+M));
				else salida.append("Impossible\n");
			}
		}
		leer.close();
		out.append(salida);
		out.close();
	}
	private static void generar() 
	{
		tableros.put("2 2 3", "**\n*c\n");
		tableros.put("2 3 2", "**\n..\n.c\n");
		tableros.put("2 3 5", "**\n**\n*c\n");
		tableros.put("2 4 2", "**\n..\n..\n.c\n");
		tableros.put("2 4 4", "**\n**\n..\n.c\n");
		tableros.put("2 4 7", "**\n**\n**\n*c\n");
		tableros.put("2 5 2", "**\n..\n..\n..\n.c\n");
		tableros.put("2 5 4", "**\n**\n..\n..\n.c\n");
		tableros.put("2 5 6", "**\n**\n**\n..\n.c\n");
		tableros.put("2 5 9", "**\n**\n**\n**\n*c\n");
		tableros.put("3 3 1", "*..\n...\n..c\n");
		tableros.put("3 3 3", "***\n...\n..c\n");
		tableros.put("3 3 5", "***\n*..\n*.c\n");
		tableros.put("3 3 8", "***\n***\n**c\n");
		tableros.put("3 4 1", "*..\n...\n...\n..c\n");
		tableros.put("3 4 2", "*..\n*..\n...\n..c\n");
		tableros.put("3 4 3", "***\n...\n...\n..c\n");
		tableros.put("3 4 4", "***\n*..\n...\n..c\n");
		tableros.put("3 4 6", "***\n***\n...\n..c\n");
		tableros.put("3 4 8", "***\n***\n*..\n*.c\n");
		tableros.put("3 4 11", "***\n***\n***\n**c\n");
		tableros.put("3 5 1", "*..\n...\n...\n...\n..c\n");
		tableros.put("3 5 2", "*..\n*..\n...\n...\n..c\n");
		tableros.put("3 5 3", "***\n...\n...\n...\n..c\n");
		tableros.put("3 5 4", "***\n*..\n...\n...\n..c\n");
		tableros.put("3 5 5", "***\n*..\n*..\n...\n..c\n");
		tableros.put("3 5 6", "***\n***\n...\n...\n..c\n");
		tableros.put("3 5 7", "***\n***\n*..\n...\n..c\n");
		tableros.put("3 5 9", "***\n***\n***\n...\n..c\n");
		tableros.put("3 5 11", "***\n***\n***\n*..\n*.c\n");
		tableros.put("3 5 14", "***\n***\n***\n***\n**c\n");
		tableros.put("4 4 1", "*...\n....\n....\n...c\n");
		tableros.put("4 4 2", "**..\n....\n....\n...c\n");
		tableros.put("4 4 3", "**..\n*...\n....\n...c\n");
		tableros.put("4 4 4", "****\n....\n....\n...c\n");
		tableros.put("4 4 5", "****\n*...\n....\n...c\n");
		tableros.put("4 4 6", "****\n**..\n....\n...c\n");
		tableros.put("4 4 7", "****\n*...\n*...\n*..c\n");
		tableros.put("4 4 8", "****\n****\n....\n...c\n");
		tableros.put("4 4 10", "****\n****\n*...\n*..c\n");
		tableros.put("4 4 12", "****\n****\n**..\n**.c\n");
		tableros.put("4 4 15", "****\n****\n****\n***c\n");
		tableros.put("4 5 1", "*...\n....\n....\n....\n...c\n");
		tableros.put("4 5 2", "**..\n....\n....\n....\n...c\n");
		tableros.put("4 5 3", "**..\n*...\n....\n....\n...c\n");
		tableros.put("4 5 4", "****\n....\n....\n....\n...c\n");
		tableros.put("4 5 5", "****\n*...\n....\n....\n...c\n");
		tableros.put("4 5 6", "****\n**..\n....\n....\n...c\n");
		tableros.put("4 5 7", "****\n**..\n*...\n....\n...c\n");
		tableros.put("4 5 8", "****\n****\n....\n....\n...c\n");
		tableros.put("4 5 9", "****\n****\n*...\n....\n...c\n");
		tableros.put("4 5 10", "****\n****\n**..\n....\n...c\n");
		tableros.put("4 5 11", "****\n****\n*...\n*...\n*..c\n");
		tableros.put("4 5 12", "****\n****\n****\n....\n...c\n");
		tableros.put("4 5 14", "****\n****\n****\n*...\n*..c\n");
		tableros.put("4 5 16", "****\n****\n****\n**..\n**.c\n");
		tableros.put("4 5 19", "****\n****\n****\n****\n***c\n");
		tableros.put("5 5 1", "*....\n.....\n.....\n.....\n....c\n");
		tableros.put("5 5 2", "**...\n.....\n.....\n.....\n....c\n");
		tableros.put("5 5 3", "***..\n.....\n.....\n.....\n....c\n");
		tableros.put("5 5 4", "***..\n*....\n.....\n.....\n....c\n");
		tableros.put("5 5 5", "*****\n.....\n.....\n.....\n....c\n");
		tableros.put("5 5 6", "*****\n*....\n.....\n.....\n....c\n");
		tableros.put("5 5 7", "*****\n**...\n.....\n.....\n....c\n");
		tableros.put("5 5 8", "*****\n***..\n.....\n.....\n....c\n");
		tableros.put("5 5 9", "*****\n***..\n*....\n.....\n....c\n");
		tableros.put("5 5 10", "*****\n*****\n.....\n.....\n....c\n");
		tableros.put("5 5 11", "*****\n*****\n*....\n.....\n....c\n");
		tableros.put("5 5 12", "*****\n*****\n**...\n.....\n....c\n");
		tableros.put("5 5 13", "*****\n*****\n***..\n.....\n....c\n");
		tableros.put("5 5 14", "*****\n*****\n**...\n*....\n*...c\n");
		tableros.put("5 5 15", "*****\n*****\n*****\n.....\n....c\n");
		tableros.put("5 5 16", "*****\n*...*\n*.c.*\n*...*\n*****\n");
		tableros.put("5 5 17", "*****\n*****\n*****\n*....\n*...c\n");
		tableros.put("5 5 19", "*****\n*****\n*****\n**...\n**..c\n");
		tableros.put("5 5 21", "*****\n*****\n*****\n***..\n***.c\n");
		tableros.put("5 5 24", "*****\n*****\n*****\n*****\n****c\n");
	}
}
