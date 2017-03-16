import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {	
		int numTests = nextInt();
		for (int test = 1; test <= numTests; test++) {
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextWeight();
			}
			int[] b = new int[n];
			for (int i = 0; i < n; i++) {
				b[i] = nextWeight();
			}
			Arrays.sort(a);
			Arrays.sort(b);
			int scoreFairplay = 0;
			int p = 0;
			for (int i = 0; i < n; i++) {
				while (p < n && b[p] < a[i]) {
					++p;
				}
				if (p < n) {
					++p;
				} else {
					++scoreFairplay;
				}
			}
			int scoreCheating = 0;
			p = 0;
			for (int i = 0; i < n; i++) {
				while (p < n && a[p] < b[i]) {
					++p;
				}
				if (p < n) {
					++p;
					++scoreCheating;
				}
			}
			out.println("Case #" + test + ": " + scoreCheating + " " + scoreFairplay);
		}
	}

	private int nextWeight() throws IOException {
		String s = next();
		while (s.length() < 7) {
			s += "0";
		}
		if (!s.substring(0, 2).equals("0.")) throw new AssertionError();
		return Integer.parseInt(s.substring(2));
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
			in = new BufferedReader(new FileReader("D-large.in"));
			out = new PrintWriter(new FileWriter("D-large.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
