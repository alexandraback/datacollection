import java.io.*;
import java.util.*;

public class Clarge {

	ArrayList<Long> good = new ArrayList<>();

	boolean isPalin(long val) {
		return (val + "").equals(new StringBuilder(val + "").reverse()
				.toString());
	}

	void init() {
		for (long i = 1; i * i <= (long) (1e+14); i++) {
			if (isPalin(i) && isPalin(i * i)) {
				good.add(i * i);
				System.err.println(i);
			}
		}
	}

	void solve() throws IOException {
		long a = nextLong();
		long b = nextLong();
		long res = 0;
		for (long c : good) {
			if (c >= a && c <= b) {
				res++;
			}
		}
		out.println(res);

	}

	public void run() throws IOException {
		init();
		br = new BufferedReader(new FileReader("c.in"));
		out = new PrintWriter("c.out");
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			out.print("Case #" + i + ": ");
			solve();
		}
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Clarge().run();
	}

	BufferedReader br;
	StringTokenizer str;
	PrintWriter out;

	String next() throws IOException {
		while (str == null || !str.hasMoreTokens()) {
			String s = br.readLine();
			if (s != null) {
				str = new StringTokenizer(s);
			} else {
				return null;
			}
		}
		return str.nextToken();
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

}
