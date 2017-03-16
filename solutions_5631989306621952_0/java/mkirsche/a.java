import java.io.*;
import java.util.*;
public class a {
public static void main(String[] args) throws IOException {
	input.init(System.in);
	PrintWriter out = new PrintWriter(System.out);
	//input.init(new FileInputStream(new File("a.txt")));
	//PrintWriter out = new PrintWriter(new File("out.txt"));
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		String s = input.next();
		int n = s.length();
		String res = "";
		for(int i = 0; i<n; i++)
		{
			char c = s.charAt(i);
			if(res.length() == 0 || c >= res.charAt(0)) res = c + res;
			else res = res + c;
		}
		out.println("Case #" + (t+1)+": "+res);
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

