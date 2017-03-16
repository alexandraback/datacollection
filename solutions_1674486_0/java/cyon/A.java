import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class A {

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int c = 1; c <= t; c++)
		{
			System.out.println("Case #" + c + ": " + solve(sc));
		}
	}
	
	private static String solve(Scanner sc)
	{
		int N=sc.nextInt();
		List<Integer>adj[]=new ArrayList[N];

		boolean rt[]=new boolean[N];
		Arrays.fill(rt,true);
		for(int i=0;i<N;i++)
		{
			adj[i]=new ArrayList<Integer>();
			int M=sc.nextInt();
			for(int j=0;j<M;j++)
			{
				int v=sc.nextInt()-1;
				adj[i].add(v);
				rt[v]=false;
			}
		}
		
		for(int i=0;i<N;i++)
		{
			if(!rt[i]) continue;
			int[]cnt=new int[N];
			boolean[]vis=new boolean[N];
			dfs(cnt,i,adj,vis);
			for(int j=0;j<N;j++)
				if(cnt[j]>1) 
				{
					return "Yes";
				}
		}
		
		return "No";
	}

	private static void dfs(int[] cnt, int i, List<Integer>[] adj, boolean[] vis)
	{
		vis[i]=true;
		cnt[i]++;
		for(Integer v : adj[i])
		{
			dfs(cnt,v,adj,vis);
		}
	}

	static void debug(Object... objects)
	{
		System.out.println(Arrays.deepToString(objects));
	}

}