import java.io.*;
import java.util.*;
public class c {
public static void main(String[] args) throws IOException {
	input.init(System.in);
	PrintWriter out = new PrintWriter(System.out);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		out.println("Case #" + (t+1)+":");
		int n = input.nextInt(), k = input.nextInt();
		for(int i = 0; i<k; i++)
		{
			for(int j = 0; j<n/2; j++)
			{
				if(j == 0 || j == n/2 - 1) out.print("11");
				else if((i & (1<<(j-1))) > 0) out.print("11");
				else out.print("00");
			}
			out.println(" 3 4 5 6 7 8 9 10 11");
		}
	}
	out.close();
}

public static class input {
	static BufferedReader reader;
	static StringTokenizer tokenizer;

	static void init(InputStream input) {
		reader = new BufferedReader(new InputStreamReader(input));
		tokenizer = new StringTokenizer("");
	}

	static String next() throws IOException {
		while (!tokenizer.hasMoreTokens())
			tokenizer = new StringTokenizer(reader.readLine());
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

