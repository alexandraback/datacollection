import java.util.*;
import java.io.*;
public class RankAndFile {
	public static void main(String[] args) throws IOException {
		in.init(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int t = in.nextInt();
		for(int z = 1; z <= t; z ++)
		{
			int n = in.nextInt();
			int nn = 2*n-1;
			ArrayList<Integer> ans = new ArrayList<Integer>();
			int b = 2501;
			int[] f = new int[b];
			
			for(int i = 0; i < nn; i ++)
				for(int j = 0; j < n; j ++)
					f[in.nextInt()]++;
			for(int i = 0; i < b; i ++)
				if(f[i]%2!=0)
					ans.add(i);
			Collections.sort(ans);
			out.print("Case #" + z + ":");
			for(int e: ans)
				out.print(" "+ e);
			out.println();
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
