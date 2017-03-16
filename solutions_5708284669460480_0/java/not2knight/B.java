import java.io.*;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.StringTokenizer;

public class B implements Runnable {

    private static final String DIR = "/home/igoradmin/work/develop/competitions/codejam/2015/src/";

    String problemName = B.class.getName();

    static final int inf = (int)1e9;

//  String fileName = String.format(DIR + "%s-statement", problemName);
  String fileName = String.format(DIR + "%s-small-attempt0", problemName);
//	String fileName = String.format(DIR + "%s-large", problemName);

	public void run() {
		try {
			int nt = nextInt();
			for (int it = 1; it <= nt; it++) {
                double res = solve();
				out.format("Case #%d: %.8f%n", it, res);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			out.close();
		}
	}

    public static class N {
        Map<Character, N> e = new HashMap<Character, N>();
    }

    double eps = 1e-8;

    private double solve() throws IOException {
        int k = nextInt();
        int l = nextInt();
        int s = nextInt();
        char[] keys = next().toCharArray();
        double[] pchar = new double[26];
        for (int i = 0; i < k; i++) {
            pchar[keys[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            pchar[i] = pchar[i] / k;
        }

        char[] lwordc = next().toCharArray();
        int[] lword = new int[l];
        for (int i = 0; i < l; i++) {
            lword[i] = lwordc[i] - 'A';
        }

        int[] p = new int[l + 1];
        p[1] = 0;
        int j = 0;
        for (int i = 2; i <= l; i++) {
            int nc = lword[i - 1];
            p[i] = -1;
            while (true) {
                if (lword[j + 1  - 1] == nc) {
                    j++;
                    p[i] = j;
                    break;
                } else {
                    if (j == 0) {
                        break;
                    } else {
                        j = p[j];
                    }
                }
            }
            if (p[i] == -1) {
                p[i] = 0;
            }
        }

        double[][] cp = new double[s + 1][l];
        cp[0][0] = 1;

        double[][] bp = new double[s + 1][l];
        bp[0][0] = 1;


        for (int si = 0; si < s; si++) {
            double[][] cpn = new double[s + 1][l];
            double[][] bpn = new double[s + 1][l];
            for (int dc = 0; dc < s; dc++) {
                for (int ip = 0; ip < l; ip++) {
                    int mj = 0;
                    for (int cki = 0; cki < 26; cki++) {
                        if (pchar[cki] > eps) {
                            j = ip;
                            while (true) {
                                if (lword[j + 1  - 1] == cki) {
                                    j++;
                                    break;
                                } else {
                                    if (j > 0) {
                                        j = p[j];
                                    } else {
                                        break;
                                    }
                                }
                            }
                            if (mj < j) {
                                mj = j;
                            }
                            if  (j == l) {
                                cpn[dc + 1][p[j]] += cp[dc][ip] * pchar[cki];
                            } else {
                                cpn[dc][j] += cp[dc][ip] * pchar[cki];
                            }
                        }
                    }
                    if  (mj == l) {
                        bpn[dc + 1][p[mj]] += bp[dc][ip];
                    } else {
                        bpn[dc][mj] += bp[dc][ip];
                    }
                }
            }
            cp = cpn;
            bp = bpn;
        }

        double br = 0;
        double er = 0;
        for (int dc = 0; dc <= s; dc++) {
            for (int ip = 0; ip < l; ip++) {
                br += dc * bp[dc][ip];
                er += dc * cp[dc][ip];
            }
        }

        return br - er;
    }

    static {
		Locale.setDefault(Locale.US);
	}
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;

	public B() throws FileNotFoundException {
		in = new BufferedReader(new FileReader(new File(fileName + ".in")));
		out = new PrintWriter(fileName + ".out");
		st = new StringTokenizer("");
	}

	public static void main(String[] args) throws FileNotFoundException {
		new Thread(new B()).start();
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