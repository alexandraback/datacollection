import java.util.*;
import java.io.*;
public class TheLastWord {
	public static void main(String[] args) throws IOException {
		in.init(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int t = in.nextInt();
		for(int z = 1; z <= t; z ++)
		{
			String s = in.next();
			String best = "";
			for(int i = 0; i < s.length(); i ++)
			{
				String s1 = best + s.charAt(i);
				String s2 = s.charAt(i) + best;
				best = s1.compareTo(s2) > 0 ? s1 : s2;
			}
			out.println("Case #" + z + ": " +best);
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
