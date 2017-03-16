import java.util.*;
import java.io.*;
public class BFFs {
	public static void main(String[] args) throws IOException {
		in.init(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int t = in.nextInt();
		for(int z = 1; z <= t; z ++)
		{
			int n = in.nextInt();
			int[] bff = new int[n];
			for(int i = 0; i < n; i ++)
				bff[i] = in.nextInt() - 1;
			
			ArrayList<Integer>[] adj = new ArrayList[n];
			for(int i = 0; i < n; i ++)
				adj[i] = new ArrayList<Integer>();
			
			for(int i = 0; i < n; i ++)
				adj[bff[i]].add(i);
			
			int cycle = 0;
			int chain = 0;
			boolean[] vis = new boolean[n];
			
			for(int i = 0; i < n; i ++)
			{
				if(vis[i])
					continue;
				int[] depth = new int[n];
				Arrays.fill(depth,  -1);
				int dist = 0;
				int at = i;
				vis[at] = true;
				depth[at] = 0;
				while(true)
				{
					at = bff[at];
					dist++;
					if(depth[at] != -1)
					{
						cycle = Math.max(dist - depth[at], cycle);
						vis[at] = true;
						break;
					}
					if(vis[at])
						break;
					vis[at] = true;
					depth[at] = dist;
				}
			}
			vis = new boolean[n];
			for(int i = 0; i < n; i ++)
			{
				int[] dist = new int[n];
				Arrays.fill(dist,  -1);
				if(vis[i])
					continue;
				if(bff[bff[i]] == i)
				{
					int best1 = 0;
					int best2 = 0;
					ArrayDeque<Integer> q = new ArrayDeque<Integer>();
					q.add(i);
					dist[i] = 0;
					vis[bff[i]] = true;
					vis[i] = true;
					while(!q.isEmpty())
					{
						int at = q.poll();
						for(int e: adj[at])
						{
							if(vis[e])
								continue;
							dist[e] = dist[at]+1;
							best1 = Math.max(best1,  dist[e]);
							vis[e] = true;
							q.add(e);
						}
					}
					
					q.add(bff[i]);
					Arrays.fill(dist,  -1);
					dist[bff[i]] = 0;
					while(!q.isEmpty())
					{
						int at = q.poll();
						for(int e: adj[at])
						{
							if(vis[e])
								continue;
							dist[e] = dist[at]+1;
							best2 = Math.max(best2,  dist[e]);
							vis[e] = true;
							q.add(e);
						}
					}
					chain += best1+best2 + 2;
				}
			}				
			out.println("Case #" + z + ": " + Math.max(chain,  cycle));
		}

		out.close();
	}

	public static class in {
		static BufferedReader reader;
		static StringTokenizer tokenizer;

		static void init(InputStream in) {
			reader = new BufferedReader(new InputStreamReader(in));
			tokenizer = new StringTokenizer("");
		}

		static String next() throws IOException {
			while (!tokenizer.hasMoreTokens()) {
				tokenizer = new StringTokenizer(reader.readLine());
			}
			return tokenizer.nextToken();
		}

		static int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		static double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		static long nextLong() throws IOException {
			return Long.parseLong(next());
		}
	}
}
