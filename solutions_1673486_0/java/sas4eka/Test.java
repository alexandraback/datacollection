import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Test {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream("asm.in")));
		tokenizer = null;
		writer = new PrintWriter("asm.out");
		solve();
		reader.close();
		writer.close();
	}

	private static void test() throws IOException
	{
		int a = nextInt();
		int b = nextInt();
		double mas[] = new double[a];
		for(int i=0;i<a;i++)
		{
			mas[i]=nextDouble();
		}
		double res=b+2;
		
		double cp = 1.0;
		for(int i=0;i<=a;i++)
		{
			double cand = (a-i) + (b-i+1) + (1.0-cp)*(b+1);
			if(cand<res)
				res=cand;
			if(i==a)
				break;
			cp*=mas[i];
		}
		writer.print(res);
	}
	
	private static void solve() throws IOException {		
		int t = nextInt();
		for(int i=1;i<=t;i++)
		{
			writer.print("Case #"+i+": ");
			test();
			writer.println();
		}
	}
}
