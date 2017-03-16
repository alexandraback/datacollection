import java.util.*;
import java.io.*;
public class b {
	public static void main(String[] args) throws IOException {
		in.init(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int t = in.nextInt();
		for(int z = 1; z <= t; z++)
		{
			String s = in.next();
			int n = s.length();
			boolean[] a = new boolean[n];
			for(int i = 0; i < n; i ++)
				a[i] = s.charAt(i)=='+';
			
			int ans = 0;
			boolean last = a[0];
			for(int i = 1; i < n; i ++)
			{
				if(last == a[i])
					continue;
				ans++;
				last = !last;
			}
			if(!a[n-1])
				ans++;
			out.println("Case #" + z + ": " + ans);
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
