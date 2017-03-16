import java.io.*;
import java.util.*;

public class A implements Runnable {

    private static final String DIR = "/home/igoradmin/work/develop/competitions/codejam/2015/src/";

    String problemName = A.class.getName();

    static final int inf = (int)1e9;

    int depth = 0;

//  String fileName = String.format(DIR + "%s-statement", problemName);
//    String fileName = String.format(DIR + "%s-all", problemName);
//  String fileName = String.format(DIR + "%s-small-attempt1", problemName);
	String fileName = String.format(DIR + "%s-large", problemName);

    int[] fv = new int[100000];
    int fc;
    boolean[] du = new boolean[10];
    private int[] d;

    Map<Long, Long> sbc = new HashMap<Long, Long>();

    long solveBig(long n) {

        depth++;

        if (depth == 10000) {
//            System.out.println("here");
        }

        if (n <= 100) {
            return d[((int) n)];
        }
        if (sbc.containsKey(n)){
            return sbc.get(n);
        }
        char[] cn = Long.toString(n).toCharArray();
        int l = cn.length;
        long d10 = 1;
        for (int i = 0; i < l - 1; i++) {
            d10 *= 10;
        }
        long d99 = d10 - 1;
        long r1 = Math.min(n, solveBig(d99) + (n - d99));
        long res = r1;
        for (int cutpoint = (l + 1) / 2 - 1; cutpoint >= 0; cutpoint -= l) {
            boolean hasNonzeroToRight = false;
            for (int i = cutpoint + 1; i < l; i++) {
                if (cn[i] > '0') {
                    hasNonzeroToRight = true;
                    break;
                }
            }
            if (!hasNonzeroToRight) {
                continue;
            }
            long d = 0;
            for (int i = cutpoint + 1; i < l; i++) {
                d = d * 10 + (cn[i] - '0');
            }
            long v = 1;
            for (int i = l - 1; i >= 0; i--) {
                if (i < l - 1) {
                    v *= 10;
                }
                if (i <= cutpoint) {
                    v += (cn[i] - '0');
                }
            }
            if (v < n) {
                res = Math.min(res, solveBig(v) + d - 1 + 1);
            }
        }
        if (res >= r1 && depth < 10000) {
            res = Math.min(res, solveBig(n - 1) + 1);
        }
        sbc.put(n, res);

        depth--;

        return res;
    }

	public void run() {

        int M = (int) 1e6;

        d = new int[M + 1];
        List[] da = new List[100001];
        Arrays.fill(d, -1);
        d[1] = 1;
        da[1] = new ArrayList();
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(1);
        int ii = 0;
        while (!q.isEmpty()) {
            int x = q.poll();
            char[] dv = Integer.toString(x).toCharArray();
            Arrays.fill(du, false);
            fc = 1;
            fv[0] = x + 1;
            findPerm(dv, du, 0, 0);
            ii++;
//            if (ii % 1000 == 0) {
//                out.flush();
//            }
//            out.println("Permutations for " + x + " found " + fc + " options");

            for (int i = 0; i < fc; i++) {
                int xn = fv[i];
                if (xn <= M && d[xn] == -1) {
                    d[xn] = d[x] + 1;
                    if (xn <= 100000) {
                        da[xn] = new ArrayList();
                        da[xn].addAll(da[x]);
                        if (xn != x + 1) {
                            da[xn].add(x);
                        }
                    }

                    q.add(xn);
                }
            }
        }

		try {
			int nt = nextInt();
//            int nt = 10000;
			for (int it = 1; it <= nt; it++) {
                long v = nextLong();
//                int v = it;
//                int dv = d[v];
                long dv1 = solveBig(v);
//                if (dv != dv1) {
                    out.format("Case #%d: %d %n", it, dv1);
//                }
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			out.close();
		}
	}

//    private void findPerm(char[] dv, boolean[] du, int taken, int curv) {
//        int l = dv.length;
//        if (taken == l) {
//            fv[fc++] = curv;
//            return;
//        }
//        for (int i = 0; i < l; i++) {
//            if (!du[i]) {
//                du[i] = true;
//                findPerm(dv, du, taken + 1, curv * 10 + (dv[i] - '0'));
//                du[i] = false;
//            }
//        }
//    }
    private void findPerm(char[] dv, boolean[] du, int taken, int curv) {
        int l = dv.length;
//        if (taken == l) {
//            fv[fc++] = curv;
//            return;
//        }
        int cv = 0;
        for (int i = 0; i < l; i++) {
//            if (!du[i]) {
//                du[i] = true;
//                findPerm(dv, du, taken + 1, curv * 10 + (dv[i] - '0'));
//                du[i] = false;
//            }
            cv = cv * 10 + (dv[l - i - 1] - '0');
        }
        fv[fc++] = cv;
    }

    private int solve() {
        return 0;
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