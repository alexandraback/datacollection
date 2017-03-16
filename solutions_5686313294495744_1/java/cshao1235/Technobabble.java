import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Technobabble {
	public static ArrayList<Integer> augmentingPath(int[][] residual, int size, int src, int snk)
	{
		Queue<Integer> q = new LinkedList<Integer>();
		q.offer(src);
		boolean[] visited = new boolean[size];
		int[] parent = new int[size];
		for(int i = 0; i < size; i++)
			parent[i] = -1;
		visited[src] = true;
		while(!q.isEmpty())
		{
			int next = q.poll();
			//System.out.println(next);
			for(int i = 0; i < size; i++)
			{
				if(!visited[i] && residual[next][i] > 0)
				{
					parent[i] = next;
					visited[i] = true;
					q.offer(i);
				}
			}
		}
		ArrayList<Integer> backwardsPath = new ArrayList<Integer>();
		int end = snk;
		while(end != -1)
		{
			backwardsPath.add(end);
			end = parent[end];
			//System.out.println(end);
		}
		ArrayList<Integer> path = new ArrayList<Integer>();
		for(int i = backwardsPath.size() - 1; i >= 0; i--)
			path.add(backwardsPath.get(i));
		return path;
	}
	public static int[][] edmondsKarp(int[][] graph, int size, int src, int snk)
	{
		int[][] residual = new int[size][size];
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size; j++)
				residual[i][j] = graph[i][j];
		}
		int flow = 0;
		ArrayList<Integer> path = augmentingPath(residual, size, src, snk);
		while(path.size() != 1)
		{
			int minCapacity = Integer.MAX_VALUE;
			for(int i = 1; i < path.size(); i++)
				minCapacity = Math.min(residual[path.get(i - 1)][path.get(i)], minCapacity);
			for(int i = 1; i < path.size(); i++)
			{
				residual[path.get(i - 1)][path.get(i)] -= minCapacity;
				residual[path.get(i)][path.get(i - 1)] += minCapacity;
			}
			flow += minCapacity;
			/*for(int i = 0; i < size; i++)
			{
				System.out.println(Arrays.toString(residual[i]));
			}
			System.out.println();*/
			path = augmentingPath(residual, size, src, snk);
			//System.out.println(path.toString());
		}
		return residual;
	}
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("technobabble.out");
			for(int i = 1; i <= t; i++)
			{
				int n = Integer.parseInt(f.readLine());
				String[][] words = new String[n][2];
				HashMap<String, Integer> first = new HashMap<String, Integer>();
				HashMap<String, Integer> second = new HashMap<String, Integer>();
				int firstCounter = 0;
				int secondCounter = 0;
				for(int j = 0; j < n; j++)
				{
					StringTokenizer st = new StringTokenizer(f.readLine());
					words[j][0] = st.nextToken();
					words[j][1] = st.nextToken();
					if(!first.containsKey(words[j][0]))
					{
						first.put(words[j][0], firstCounter);
						firstCounter++;
					}
					if(!second.containsKey(words[j][1]))
					{
						second.put(words[j][1], secondCounter);
						secondCounter++;
					}
				}
				int numVertices = firstCounter + secondCounter;
				int[][] graph = new int[numVertices + 2][numVertices + 2]; //0 is src, numVertices + 1 is snk
				for(int j = 1; j <= firstCounter; j++)
					graph[0][j] = 1;
				for(int j = firstCounter + 1; j < numVertices + 1; j++)
					graph[j][numVertices + 1] = 1;
				for(int j = 0; j < n; j++)
					graph[first.get(words[j][0]) + 1][second.get(words[j][1]) + firstCounter + 1] = 1;
				/*for(int j = 0; j < numVertices + 2; j++)
				{
					System.out.println(Arrays.toString(graph[j]));
				}
				System.out.println();*/
				int[][] residual = edmondsKarp(graph, numVertices + 2, 0, numVertices + 1);
				int minEdgeCover = firstCounter;
				for(int j = firstCounter + 1; j < numVertices + 1; j++)
				{
					if(residual[j][numVertices + 1] == 1)
						minEdgeCover++;
				}
				int duplicates = n - minEdgeCover;
				System.out.println("Case #" + i + ": " + duplicates);
				fout.write("Case #" + i + ": " + duplicates + "\n");
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
