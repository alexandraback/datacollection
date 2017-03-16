import java.util.*;
import java.io.*;
public class d {
	public static void main(String[] args) throws IOException {
		in.init(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int t = in.nextInt();
		for(int z = 1; z <= t; z ++)
		{
			int original = in.nextInt();
			int complex = in.nextInt();
			int checks = in.nextInt();
			out.print("Case #" + z + ":");
			if(complex == 1)
			{
				for(int i = 1; i <= original; i++)
					out.print(" " + i);
				out.println();
				continue;
			}
			long len = (long)Math.pow((long)original, complex);
			long jump = len/original;
			for(long i = 0; i <= len; i += jump)
			{
				i++;
				out.print(" " + i);
			}
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
