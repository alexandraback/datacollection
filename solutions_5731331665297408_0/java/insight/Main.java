import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class Main 
{

	public static void main(String[] args) throws IOException 
	{
		new Main().doIt();
	}
	int n,m;
	int[] zip;
	int[][] g;
	BigInteger best;
	private void doIt() throws IOException 
	{
		Scanner sc = new Scanner(new File("in.txt"));
		PrintStream ps = new PrintStream(new File("out.txt"));
		
		int T = sc.nextInt();
		
		int u,v;
		for(int c=1;c<=T;c++)
		{
			n = sc.nextInt();
			m = sc.nextInt();
			zip = new int[n];
			g = new int[n][n];
			for(int i=0;i<n;i++)
				zip[i] = sc.nextInt();
			for(int i=0;i<m;i++)
			{
				u = sc.nextInt()-1;
				v = sc.nextInt()-1;
				g[u][v] = g[v][u] = 1;
			}
			
			boolean[] visited;
			boolean[][] ret;
			best = null;
			for(int i=0;i<n;i++)
			{
				//System.out.println(i);
				visited = new boolean[n];
				ret = new boolean[n][n];
				visited[i] = true;
				solve(i,visited,ret,zip[i]+"");
				
			}
			
			ps.println("Case #"+c+": "+best.toString());
		}
		
		sc.close();
		ps.close();
		
	}
	private void solve(int i, boolean[] visited, boolean[][] ret,String sofar)
	{
		boolean stop = true;
		for(int j=0;j<n&stop;j++)
		{
			if(!visited[j])
				stop = false;
		}
		if(stop)
		{
//			boolean f = true;
//			for(int j=0;j<n&f;j++)
//				for(int k=0;k<n&f;k++)
//					if(ret[j][k])
//						f = false;
//			
			BigInteger aux = new BigInteger(sofar);
			if(best == null)
				best = aux;
			else if(best.compareTo(aux) > 0)
				best = aux;
			
			return;
		}
		
		for(int j=0;j<n;j++)
		{
			if(g[i][j]==1&&!visited[j])
			{
				ret[j][i] = true;
				visited[j] = true;
				solve(j,visited,ret,sofar+zip[j]);
				visited[j] = false;
				ret[j][i] = false;
			}
			if(g[i][j]==1&&visited[j]&&ret[i][j])
			{
				ret[i][j] = false;
				solve(j,visited,ret,sofar);
				ret[i][j] = true;
			}			
		}
		
	}
	
	
}
