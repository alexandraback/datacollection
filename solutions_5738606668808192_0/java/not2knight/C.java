import java.io.*;
import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;

public class C implements Runnable {

    private static final String DIR = "/home/igoradmin/work/develop/competitions/codejam/2015/src/";

    String problemName = C.class.getName();

    static final int inf = (int) 1e9;

//    String fileName = String.format(DIR + "%s-statement", problemName);
  String fileName = String.format(DIR + "%s-small-attempt0", problemName);
//	String fileName = String.format(DIR + "%s-large", problemName);

    int[] p;

    public void run() {
        try {
//            int nt = nextInt();
//            for (int it = 1; it <= nt; it++) {
//                int res = solve();
//                out.format("Case #%d: %s%n", it, res);
//            }

            {
                boolean[] pu = new boolean[1 << 20];
                ArrayList<Integer> pl = new ArrayList<Integer>();
                for (int i = 2; i < pu.length; i++) {
                    if (pu[i]) {
                        continue;
                    }
                    pl.add(i);
                    for (int j = 2 * i; j < pu.length; j += i) {
                        pu[j] = true;
                    }
                }
                p = new int[pl.size()];
                for (int i = 0; i < pl.size(); i++) {
                    p[i] = pl.get(i);
                }
            }

            out.format("Case #1:%n");
            solve();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.close();
        }
    }

    private void solve() {
        int N = 1 << 14;
        StringBuilder sb = new StringBuilder();

        int c = 0;

nloop:
        for (int I = 0; I < N && c < 50; I++) {
            sb.setLength(0);
            sb.append('1');
            String v = Integer.toString(I, 2);
            for (int i = 1; i + v.length() <= 14; i++) {
                sb.append('0');
            }
            sb.append(v);
            sb.append(1);
            String si = sb.toString();

            sb.setLength(0);

            for (int r = 2; r <= 10; r++) {
                long rn = Long.valueOf(si, r);
                boolean rf = false;
                for (int pi : p) {
                    if (pi >= rn) {
                        break;
                    }
                    if (rn % pi == 0) {
                        rf = true;
                        sb.append(' ').append(pi);
                        break;
                    }
                }
                if (!rf) {
                    continue nloop;
                }
            }
            out.format("%s%s%n", si, sb.toString());
            c++;
        }

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