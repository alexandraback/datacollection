import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class D implements Runnable {

    private static final String DIR = "/home/igoradmin/work/develop/competitions/codejam/2015/src/";

    String problemName = D.class.getName();

    static final int inf = (int) 1e9;

//    String fileName = String.format(DIR + "%s-statement", problemName);
//  String fileName = String.format(DIR + "%s-small-attempt0", problemName);
  String fileName = String.format(DIR + "%s-small-attempt1", problemName);
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
        int k = nextInt();
        int c = nextInt();
        int s = nextInt();


        StringBuilder sb = new StringBuilder();

        int lk = -1;
        int cs = 0;
        while (lk < k - 1) {
            long v = 0;
            for (int j = 0; j < c; j++) {
                if (lk < k - 1) {
                    lk++;
                }
                v = k * v + lk;
            }
            sb.append(v + 1).append(' ');
            cs++;
        };
        if (cs > s) {
            return "IMPOSSIBLE";
        } else {
            return sb.toString();
        }
    }

    static {
        Locale.setDefault(Locale.US);
    }

    BufferedReader in;
    PrintWriter out;
    StringTokenizer st;

    public D() throws FileNotFoundException {
        in = new BufferedReader(new FileReader(new File(fileName + ".in")));
        out = new PrintWriter(fileName + ".out");
        st = new StringTokenizer("");
    }

    public static void main(String[] args) throws FileNotFoundException {
        new Thread(new D()).start();
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