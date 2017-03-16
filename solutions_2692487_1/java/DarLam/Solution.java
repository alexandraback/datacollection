import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution implements Runnable {
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private int solve(int a, int[] b) {
		int n = b.length;
		Arrays.sort(b);
		
		int[][] maxSize = new int[n + 1][n];
		maxSize[0][0] = a;
		for (int killed = 0; killed < n; killed++) {
			for (int ops = 0; ops < n; ops++) {
				if (ops + 1 < n && maxSize[killed][ops] > 0) {
					if (maxSize[killed][ops] < 1000000000) {
						maxSize[killed][ops + 1] = Math.max(maxSize[killed][ops + 1], 2 * maxSize[killed][ops] - 1);
					}
					maxSize[killed + 1][ops + 1] = Math.max(maxSize[killed + 1][ops + 1], maxSize[killed][ops]);
				}
				if (maxSize[killed][ops] > b[killed]) {
					maxSize[killed + 1][ops] = Math.max(maxSize[killed + 1][ops], maxSize[killed][ops] + b[killed]);
				}
			}
		}
		
		for (int ops = 0; ops < n; ops++) {
			if (maxSize[n][ops] > 0) {
				return ops;
			}
		}
		return n;
	}
	
	private void solve() throws IOException {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			int a = nextInt();
			int n = nextInt();
			int[] b = new int[n];
			for (int i = 0; i < n; i++) {
				b[i] = nextInt();
			}
			int answer = solve(a, b);
			out.println("Case #" + test + ": " + answer);
		}
	}
	
	@Override
	public void run() {
		try {
			solve();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		} finally {
			out.close();
		}
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	public Solution(String filename) {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(filename + ".out"));
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Solution("data").run();
	}
}
