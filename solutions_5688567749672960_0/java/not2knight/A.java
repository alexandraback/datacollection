import java.io.*;
import java.util.*;

public class A implements Runnable {

    private static final String DIR = "/home/igoradmin/work/develop/competitions/codejam/2015/src/";

    String problemName = A.class.getName();

    static final int inf = (int)1e9;

//  String fileName = String.format(DIR + "%s-statement", problemName);
  String fileName = String.format(DIR + "%s-small-attempt1", problemName);
//	String fileName = String.format(DIR + "%s-large", problemName);

    int[] fv = new int[100000];
    int fc;
    boolean[] du = new boolean[10];

	public void run() {

        int M = (int) 1e6;

        int[] d = new int[M + 1];
        Arrays.fill(d, -1);
        d[1] = 1;
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
                    q.add(xn);
                }
            }
        }

		try {
			int nt = nextInt();
			for (int it = 1; it <= nt; it++) {
                int v = nextInt();
				out.format("Case #%d: %s%n", it, d[v]);
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