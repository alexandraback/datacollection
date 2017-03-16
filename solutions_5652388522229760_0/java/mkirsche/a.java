import java.io.*;
import java.util.*;
public class a {
public static void main(String[] args) throws IOException {
	input.init(System.in);
	PrintWriter out = new PrintWriter(System.out);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		int n = input.nextInt();
		out.print("Case #" + (t+1)+": ");
		if(n == 0)
		{
			out.println("INSOMNIA");
			continue;
		}
		boolean[] used = new boolean[10];
		int c = 0;
		int at = n;
		while(true)
		{
			int copy = at;
			while(copy > 0)
			{
				if(!used[copy%10]) c++;
				used[copy%10] = true;
				copy /= 10;
			}
			if(c == 10)
			{
				out.println(at);
				break;
			}
			at += n;
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

