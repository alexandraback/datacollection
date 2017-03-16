import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class A implements Runnable {

    private static final String DIR = "/home/igoradmin/work/develop/competitions/codejam/2015/src/";

    String problemName = A.class.getName();

    static final int inf = (int)1e9;

//  String fileName = String.format(DIR + "%s-statement", problemName);
  String fileName = String.format(DIR + "%s-small-attempt0", problemName);
//	String fileName = String.format(DIR + "%s-large", problemName);

	public void run() {
		try {
			int nt = nextInt();
			for (int it = 1; it <= nt; it++) {
                String res = solve();
				out.format("Case #%d: %s%n", it, res);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			out.close();
		}
	}

    private String solve() throws IOException {
		int n = nextInt();
		if (n == 0) {
			return "INSOMNIA";
		}
		boolean[] u = new boolean[10];
		int uc = 10;
		int v = 0;
		for (int i = 1; ;i++) {
			v += n;
			for (char c : Integer.toString(v).toCharArray()) {
				if (!u[c - '0']) {
					u[c - '0'] = true;
					uc--;
				}
			}
			if (uc == 0) {
				System.out.format("%d %d%n", n, i);
				return Integer.toString(v);
			}
		}
    }

    static {
		Locale.setDefault(Locale.US);
	}
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	public A() throws FileNotFoundException {
		in = new BufferedReader(new FileReader(new File(fileName + ".in")));
		out = new PrintWriter(fileName + ".out");
		st = new StringTokenizer("");
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Thread(new A()).start();
	}

	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(next());
	}
	double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(next());
	}
	long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(next());
	}
}