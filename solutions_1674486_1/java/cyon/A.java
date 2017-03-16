import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) throws Throwable
	{
		Scanner sc = new Scanner(System.in);
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		for (int c = 1; c <= t; c++)
		{
			System.out.println("Case #" + c + ": " + solve(br));
		}
	}
	
	private static String solve(BufferedReader br) throws Throwable
	{
		int N=Integer.parseInt(br.readLine());
		List<Integer>adj[]=new ArrayList[N];

		boolean rt[]=new boolean[N];
		Arrays.fill(rt,true);
		for(int i=0;i<N;i++)
		{
			StringTokenizer st=new StringTokenizer(br.readLine());
			adj[i]=new ArrayList<Integer>();
			int M=Integer.parseInt(st.nextToken());
			for(int j=0;j<M;j++)
			{
				int v=Integer.parseInt(st.nextToken())-1;
				adj[i].add(v);
				rt[v]=false;
			}
		}
		
		int[]cnt=new int[N];
		boolean[]vis=new boolean[N];
		for(int i=0;i<N;i++)
		{
			if(!rt[i]) continue;
			Arrays.fill(cnt, 0);
			Arrays.fill(vis, false);
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
		if(vis[i])return;
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