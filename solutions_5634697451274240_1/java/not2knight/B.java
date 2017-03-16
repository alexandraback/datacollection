import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class B implements Runnable {

    private static final String DIR = "/home/igoradmin/work/develop/competitions/codejam/2015/src/";

    String problemName = B.class.getName();

    static final int inf = (int) 1e9;

//    String fileName = String.format(DIR + "%s-statement", problemName);
//  String fileName = String.format(DIR + "%s-small-attempt0", problemName);
	String fileName = String.format(DIR + "%s-large", problemName);

    public void run() {
        try {
            int nt = nextInt();
            for (int it = 1; it <= nt; it++) {
                int res = solve();
                out.format("Case #%d: %d%n", it, res);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            out.close();
        }
    }

    private int solve() throws IOException {
        String s = next();
        char lc = '+';
        int r = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) != lc) {
                lc = s.charAt(i);
                r++;
            }
        }
        return r;
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