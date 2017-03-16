import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {
		int nTests = nextInt();
		boolean[] f = precalc();
		for (int test = 1; test <= nTests; test++) {
			int a = nextInt();
			int b = nextInt();
			int res = 0;
			for (int i = a; i <= b; i++) {
				if (f[i]) {
					++res;
				}
			}
			out.println("Case #" + test + ": " + res);
		}
	}

	private boolean[] precalc() {
		final int N = 1000;
		boolean[] res = new boolean[N + 1];
		for (int i = 1; i*i <= N; i++) {
			if (isPalindrome(i) && isPalindrome(i*i)) {
				res[i*i] = true;
			}
		}
		return res;
	}

	private boolean isPalindrome(int x) {
		String s = "" + x;
		return s.equals(new StringBuilder(s).reverse().toString());
	}


	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String rl = in.readLine();
			if (rl == null)
				return null;
			st = new StringTokenizer(rl);
		}
		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader("C-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("C-small-attempt0.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
