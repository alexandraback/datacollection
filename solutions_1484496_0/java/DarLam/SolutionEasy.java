import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class SolutionEasy implements Runnable {
	
	private static final String IMPOSSIBLE = "Impossible";
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private String solve(int[] a) {
		int n = a.length;
		int m = 1;
		for (int i = 0; i < n; i++) {
			m += a[i];
		}
		int[] wasMask = new int[m];
		for (int mask = (1 << n) - 1; mask > 0; mask--) {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				if ((mask & (1 << i)) != 0) {
					sum += a[i];
				}
			}
			if (wasMask[sum] > 0) {
				return buildAnswer(a, mask, wasMask[sum]);
			} else {
				wasMask[sum] = mask;
			}
		}
		return IMPOSSIBLE;
	}
	
	private String buildAnswer(int[] a, int mask1, int mask2) {
		int[] b1 = extract(a, mask1, mask2);
		int[] b2 = extract(a, mask2, mask1);
		String b1s = toString(b1);
		String b2s = toString(b2);
		return b1s + "\n" + b2s;
	}

	private String toString(int[] b) {
		StringBuilder buf = new StringBuilder();
		for (int i = 0; i < b.length; i++) {
			if (i > 0) {
				buf.append(" ");
			}
			buf.append(b[i]);
		}
		return buf.toString();
	}

	private int[] extract(int[] a, int need, int not) {
		int cnt = 0;
		for (int i = 0; i < a.length; i++) {
			if ((need & (1 << i)) != 0 && (not & (1 << i)) == 0) {
				cnt++;
			}
		}
		int[] result = new int[cnt];
		cnt = 0;
		for (int i = 0; i < a.length; i++) {
			if ((need & (1 << i)) != 0 && (not & (1 << i)) == 0) {
				result[cnt++] = a[i];
			}
		}
		return result;
	}

	private void solve() throws IOException {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			String answer = solve(a);
			out.println("Case #" + test + ":");
			out.println(answer);
		}
	}

	@Override
	public void run() {
		try {
			solve();
		} catch (Throwable e) {
			apstenu(e);
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
	
	private void apstenu(Throwable e) {
		e.printStackTrace();
		System.exit(1);
	}
	
	public SolutionEasy(String filename) {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(filename + ".out"));
		} catch (IOException e) {
			apstenu(e);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new SolutionEasy("data").run();
	}
	
}
