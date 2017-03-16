import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

/**
 * User: vryzhuk
 * Date: 4/18/15
 * Time: 3:59 AM
 */
public class C {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;
    static int test;
    static final double EPS = 0.00000000001;

    static void solve() throws Exception {
        int n = nextInt();
        int[] d = new int[10];
        int[] m = new int[10];
        int size = 0;
        for(int i = 0; i < n; i++) {
            int di = nextInt();
            int hi = nextInt();
            int mi = nextInt();
            for(int o = 0; o < hi; o++) {
                m[size] = mi;
                d[size] = di;
                ++size;
                ++mi;
            }
        }

        int result = 0;
        if(size > 1) {
            double time11 = (360.0 - d[0]) / (360.0*m[0]);
            double time12 = (720.0 - d[0]) / (360.0*m[0]);
            double time21 = (360.0 - d[1]) / (360.0*m[1]);
            double time22 = (720.0 - d[1]) / (360.0*m[1]);
            if(time11 >= (time22-EPS) || time21 >= (time12-EPS)) {
                result = 1;
            }
        }

        printCase();
        out.println(result);
    }

    static void printCase() {
        out.print("Case #" + test + ": ");
    }

    static void printlnCase() {
        out.println("Case #" + test + ":");
    }

    static int nextInt() throws IOException {
        return parseInt(next());
    }

    static long nextLong() throws IOException {
        return parseLong(next());
    }

    static double nextDouble() throws IOException {
        return parseDouble(next());
    }

    static String next() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    public static void main(String[] args) {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));
            int tests = nextInt();
            for (test = 1; test <= tests; test++) {
                solve();
            }
            in.close();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            exit(1);
        }
    }
}
