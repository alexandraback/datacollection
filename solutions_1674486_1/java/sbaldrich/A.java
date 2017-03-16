package codejam.round1.a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;

public class A {
	
	private static BufferedReader bf;
	private static File f;
	private static ArrayList<ArrayList<Integer>> g;
	private static boolean[] visit;
	private static boolean done;
	public static void main(String[] args) throws Exception{
		f = new File("A.in");
		bf = new BufferedReader(new FileReader(f));
		String line, pars[];
		int nums[];
		line = bf.readLine();
		int t = Integer.parseInt(line.trim());
		for(int test=1;test<=t;test++)
		{
			visit = null;
			nums = null;
			done = false;
			g = null;
			int N = Integer.parseInt(bf.readLine().trim());
			visit = new boolean[N+1];
			g = new ArrayList<ArrayList<Integer>>();
			Arrays.fill(visit, false);
			for(int i=0;i<=N;i++)
				g.add(new ArrayList<Integer>());
			for(int i=1;i<=N;i++)
			{
				line = bf.readLine();
				pars = line.split("[ ]+");
				nums = new int[pars.length];
				for(int j=0;j<pars.length;j++)
					nums[j] = Integer.parseInt(pars[j]);
				for(int j=1;j<=nums[0];j++)
					g.get(i).add(nums[j]);
			}
			for(int j=1;j<=N && !done;j++)
			{
				Arrays.fill(visit, false);
				done = false;
				dfs(j);
			}
			System.out.printf("Case #%d: %s\n" , test, (done?"Yes":"No"));
		}
			
	}
	private static void dfs(int x)
	{
		if(visit[x])
		{
			done = true;
			return;
		}
		visit[x] = true;
		for(int next : g.get(x))
			dfs(next);
	}
}
