import java.util.*;
import java.io.*;
public class a {
	public static void main(String[] args) throws IOException {
		in.init(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int t = in.nextInt();
		for(int z = 1; z <=t; z++)
		{
			int n = in.nextInt();
			HashSet<Integer> seen = new HashSet<Integer>();
			int b = 10000000;
			long at = n;
			while(seen.size() < 10 && b > -1)
			{
				String s = Long.toString(at);
				for(int i = 0; i < s.length(); i ++)
					seen.add(s.charAt(i) - '0');
				
				at += n;
				b--;
			}
			at-=n;
			out.println("Case #" + z + ": " + (b == -1 ? "INSOMNIA" : at));
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
