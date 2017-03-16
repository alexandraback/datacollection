import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class A {

	void solve() throws IOException {
		int T=nextInt();
		for(int testCase=0;testCase<T;testCase++){
			long r=nextLong();
			long t=nextLong();
			double a=2;
			double b=2.0*r-1;
			double c=-t;
			double d=Math.sqrt(b*b-4*a*c);
			double n=(-b+d)/2/a;
			long res=Math.round(Math.floor(n));
			out.printf("Case #%d: %d\n",testCase+1 ,res);
		}

	}

	public static void main(String[] args) throws IOException {
		new A().run();
	}

	void run() throws IOException {
		reader = new BufferedReader(new FileReader("input.txt"));
		tokenizer = null;
		out = new PrintWriter(new FileWriter("output.txt"));
		solve();
		reader.close();
		out.flush();

	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter out;

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}
