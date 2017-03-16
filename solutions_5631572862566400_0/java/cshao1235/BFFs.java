import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BFFs {
	public static int longestCycle(int[] ids)
	{
		boolean[] checked = new boolean[ids.length];
		int maxCycle = 0;
		for(int i = 0; i < ids.length; i++)
		{
			if(checked[i])
				continue;
			boolean[] visited = new boolean[ids.length];
			visited[i] = true;
			int next = ids[i];
			int numInCycle = 1;
			while(!visited[next])
			{
				visited[next] = true;
				next = ids[next];
				numInCycle++;
			}
			int secondNext = i;
			//int secondVisited = 1;
			while(secondNext != next)
			{
				secondNext = ids[secondNext];
				numInCycle--;
			}
			if(maxCycle < numInCycle)
				maxCycle = numInCycle;
			for(int j = 0; j < ids.length; j++)
			{
				if(visited[j])
					checked[j] = true;
			}
		}
		return maxCycle;
	}
	public static int longestCircle(ArrayList<ArrayList<Integer>> reversed, int u, int v)
	{
		return 2 + longestPath(reversed, u, v) + longestPath(reversed, v, u);
	}
	public static int longestPath(ArrayList<ArrayList<Integer>> reversed, int source, int avoid)
	{
		Queue<Pair> q = new LinkedList<Pair>();
		q.offer(new Pair(source, 0));
		boolean[] visited = new boolean[reversed.size()];
		visited[avoid] = true;
		int longestPath = 0;
		while(!q.isEmpty())
		{
			Pair p = q.poll();
			visited[p.vertex] = true;
			if(p.pathLength > longestPath)
				longestPath = p.pathLength;
			ArrayList<Integer> neighbors = reversed.get(p.vertex);
			for(int a : neighbors)
			{
				if(!visited[a])
				{
					q.offer(new Pair(a, p.pathLength + 1));
				}
			}
		}
		return longestPath;
	}
	static class Pair
	{
		int vertex;
		int pathLength;
		public Pair(int v, int l)
		{
			vertex = v;
			pathLength = l;
		}
	}
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("bffs.out");
			for(int i = 1; i <= t; i++)
			{
				int n = Integer.parseInt(f.readLine());
				StringTokenizer st = new StringTokenizer(f.readLine());
				int[] ids = new int[n];
				for(int j = 0; j < n; j++)
					ids[j] = Integer.parseInt(st.nextToken()) - 1;
				int output = longestCycle(ids);
				//System.out.println("Longest Cycle: " + output);
				ArrayList<ArrayList<Integer>> reversed = new ArrayList<ArrayList<Integer>>();
				for(int j = 0; j < n; j++)
					reversed.add(new ArrayList<Integer>());
				for(int j = 0; j < n; j++)
					reversed.get(ids[j]).add(j);
				for(int j = 0; j < n; j++)
				{
					if(j == ids[ids[j]])
					{
						int longestCircle = longestCircle(reversed, j, ids[j]);
						if(longestCircle > output)
							output = longestCircle;
					}
				}
				System.out.println("Case #" + i + ": " + output);
				fout.write("Case #" + i + ": " + output + "\n");
			}
			f.close();
			fout.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}


	}

}
