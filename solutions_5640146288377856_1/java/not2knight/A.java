import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class A implements Runnable {

    private static final String DIR = "/home/igoradmin/work/develop/competitions/codejam/2015/src/";

    String problemName = A.class.getName();

    static final int inf = (int)1e9;

//  String fileName = String.format(DIR + "%s-statement", problemName);
//  String fileName = String.format(DIR + "%s-small-attempt0", problemName);
	String fileName = String.format(DIR + "%s-large", problemName);

	public void run() {
		try {
			int nt = nextInt();
			for (int it = 1; it <= nt; it++) {
                int res = solve();
				out.format("Case #%d: %s%n", it, res);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			out.close();
		}
	}

    private int solve() throws IOException {
        int r = nextInt();
        int c = nextInt();
        int w = nextInt();

        if (w == 1) {
            return r * c;
        }

        int res = 0;
        int m = c / w;
        res += r * m;
        res += w;
        if (m * w == c) {
            res--;
        }
        return res;
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