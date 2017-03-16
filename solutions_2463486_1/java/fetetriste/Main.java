import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {
		int nTests = nextInt();
		List<Long> f = precalc((long)1e15);
		for (int test = 1; test <= nTests; test++) {
			long a = nextLong();
			long b = nextLong();
			int res = 0;
			for (long x : f) {
				if (x >= a && x <= b) {
					++res;
				}
			}
			out.println("Case #" + test + ": " + res);
		}
	}

	private List<Long> precalc(long n) {
		List<Long> res = new ArrayList<Long>();
		for (long i = 1; i*i <= n; i++) {
			if (isPalindrome(i) && isPalindrome(i*i)) {
				res.add(i*i);
			}
		}
		return res;
	}

	private boolean isPalindrome(long x) {
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
			in = new BufferedReader(new FileReader("C-large-1.in"));
			out = new PrintWriter(new FileWriter("C-large-1.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
