import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class C implements Runnable {

    private static final String DIR = "/home/igoradmin/work/develop/competitions/codejam/2015/src/";

    String problemName = C.class.getName();

    static final int inf = (int)1e9;

    private int[] f;
    private int leftV;
    private int v;
    private boolean[] denu;


//    String fileName = String.format(DIR + "%s-statement", problemName);
    String fileName = String.format(DIR + "%s-small-attempt0", problemName);
//	String fileName = String.format(DIR + "%s-large", problemName);
//
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
        int c = nextInt();
        int dn = nextInt();
        v = nextInt();
        int[] d = new int[dn];
        denu = new boolean[v + 1];
        for (int i = 0; i < dn; i++) {
            d[i] = nextInt();
            denu[d[i]] = true;
        }

        f = new int[v + 1];
        int D = 1 << dn;
        leftV = v;
        for (int ID = 0; ID < D; ID++) {
            int ct = 0;
            for (int i = 0; i < dn; i++) {
                if ((ID & (1 << i)) > 0) {
                    ct += d[i];
                }
            }
            if (ct <= v) {
                if (ct > 0 && f[ct] == 0) {
                    leftV--;
                }
                f[ct]++;
            }
        }
        if (leftV == 0) {
            return 0;
        }

        for (int limit = 1; limit < 7; limit++) {
            if (find(limit)) {
                return limit;
            }
        }

        return -1;
    }

    public boolean find(int limit) {
        int mi;
        for (mi = 1; mi <= v; mi++) {
            if (f[mi] == 0) {
                break;
            }
        }

        for (int newden = 1; newden <= mi; newden++) {
            if (denu[newden]) {
                continue;
            }

            denu[newden] = true;
            for (int i = v; i >= newden; i--) {
                int p = (i > newden) ? f[i - newden] : 1;
                if (p > 0) {
                    if (f[i] == 0) {
                        leftV--;
                    }
                    f[i] += p;
                }
            }

            if (leftV == 0 || (limit > 1 && find(limit - 1))) {
                return true;
            }

            for (int i = newden; i <= v; i++) {
                int p = (i > newden) ? f[i - newden] : 1;
                if (p > 0) {
                    f[i] -= p;
                    if (f[i] == 0) {
                        leftV++;
                    }
                }
            }
            denu[newden] = false;
        }
        return false;
    }

    static {
		Locale.setDefault(Locale.US);
	}
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	public C() throws FileNotFoundException {
		in = new BufferedReader(new FileReader(new File(fileName + ".in")));
		out = new PrintWriter(fileName + ".out");
		st = new StringTokenizer("");
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Thread(new C()).start();
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