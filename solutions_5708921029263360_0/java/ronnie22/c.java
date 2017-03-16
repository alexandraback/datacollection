import java.io.*;
import java.util.*;


public class c 
{

	public static void main(String[] args) throws FileNotFoundException 
	{
		Scanner sc = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter("output.txt");
		
		int n_case = sc.nextInt();
		for(int i=1;i<=n_case;i++)
		{
			int j = sc.nextInt();
			int p = sc.nextInt();
			int s = sc.nextInt();
			int k = sc.nextInt();
			String ris = solve(j,p,s,k);
			out.println("Case #"+i+": "+ris);
		}
		
		sc.close();
		out.close();
	}
	
	public static String solve(int j,int p,int s,int k)
	{
		int aus1[][] = new int [j][p];
		int aus2[][] = new int [j][s];
		int aus3[][] = new int [p][s];
		
		
		String sol = new String();
		int cont = 0;
		
		for(int a=0;a<j;a++)
		{
			for(int b=0;b<p;b++)
			{
				for(int c=0;c<s;c++)
				{
					if ( (aus1[a][b] < k) && (aus2[a][c] < k) && (aus3[b][c] < k) )
					{
						cont++;
						aus1[a][b]++;
						aus2[a][c]++;
						aus3[b][c]++;
						sol += (a+1)+" "+(b+1)+" "+(c+1)+"\n";
					}
				}
			}
		}
		sol = sol.substring(0, sol.length()-1);
		return ""+cont+"\n"+sol;
	}

}
