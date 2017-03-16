import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B implements Runnable {

	int n;
	int[][] memo;
	int[] v;
	int R, E;
	
	private int go(int i, int curGain) {
		if (i == n)
			return 0;
		
		if (memo[i][curGain] != -1)
			return memo[i][curGain];
		
		int res = -1 << 29;
		
		for (int j = 0; j <= curGain; j++) {
			if ((curGain - j) + R <= E)
				res = Math.max(res, (j * v[i]) + go(i + 1, (curGain - j) + R));
		}
		
		return memo[i][curGain] = res;
	}
	
	private void solve() throws IOException {
		int t = nextInt();
		
		while (t-- > 0) {
			E = nextInt();
			R = nextInt();
			n = nextInt();
			
			v = new int[n];
			
			for (int i = 0; i < n; i++)
				v[i] = nextInt();
			
			memo = new int[15][15];
			for (int[] m : memo) Arrays.fill(m, -1);
			
			pf();
			pl(go(0, E));
		}
	}

	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
//			reader = new BufferedReader(new InputStreamReader(System.in));
			reader = new BufferedReader(new FileReader("B-small-attempt0.in"));
//			reader = new BufferedReader(new FileReader("B-large.in"));
//			writer = new PrintWriter(System.out);
			writer = new PrintWriter("B-small.out");
//			writer = new PrintWriter("B-large.out");
			tokenizer = null;
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	void p(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	void pl(Object... objects) {
		p(objects);
		writer.println();
	}

	int cc;

	void pf() {
		writer.printf("Case #%d: ", ++cc);
	}

}