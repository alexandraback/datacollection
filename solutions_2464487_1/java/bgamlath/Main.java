
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer stk;

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new FileReader("in.txt"));
        out = new PrintWriter("out.txt");
        stk = new StringTokenizer(in.readLine());
        // Start of User Code

        int T = ni();
        for (int i = 1; i <= T; i++) {
            long r = nl();
            long t = nl();
            printf("Case #%d: %s\n", i, proc(r, t));
        }


        // End of User Code
        in.close();
        out.close();
    }

    static String proc(long r, long t) {
        return bs(r, t) + "";
    }

    static long bs(long r, long t) {
        BigInteger lo = BigInteger.ZERO;
        BigInteger hi = BigInteger.valueOf(t);
        while (lo.compareTo(hi) < 0) {
            BigInteger tt = lo.add(hi).divide(BigInteger.valueOf(2));
            BigInteger ss = tt.multiply(BigInteger.valueOf(2)).multiply(tt.add(BigInteger.ONE)).add(BigInteger.valueOf(2).multiply(BigInteger.valueOf(r).multiply(tt.add(BigInteger.ONE))));
            ss = ss.add(tt);
            if (ss.compareTo(BigInteger.valueOf(t)) < 0) {
                lo = tt.add(BigInteger.ONE);
            } else {
                hi = tt;
            }
        }
        BigInteger tt = lo;
//
//        BigInteger ss = tt.multiply(BigInteger.valueOf(2)).multiply(tt.add(BigInteger.ONE)).add(BigInteger.valueOf(2).multiply(BigInteger.valueOf(r).multiply(tt.add(BigInteger.ONE))));
//        ss = ss.add(tt);
//        while (ss.compareTo(BigInteger.valueOf(t)) > 0) {
//            tt = tt.subtract(BigInteger.ONE);
//            ss = tt.multiply(BigInteger.valueOf(2)).multiply(tt.add(BigInteger.ONE)).add(BigInteger.valueOf(2).multiply(BigInteger.valueOf(r).multiply(tt.add(BigInteger.ONE))));
//            ss = ss.add(tt);
//        }
        return tt.longValue();
    }

    static void printf(String format, Object... args) {
        System.out.printf(format, args);
        out.printf(format, args);
    }

    static int ni() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(stk.nextToken());
    }

    static long nl() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Long.parseLong(stk.nextToken());
    }

    static double nd() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return Double.parseDouble(stk.nextToken());
    }

    static String ns() throws Exception {
        while (!stk.hasMoreTokens()) {
            stk = new StringTokenizer(in.readLine());
        }
        return stk.nextToken();
    }

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static int max(int a, int b) {
        return a > b ? a : b;
    }

    static long min(long a, long b) {
        return a < b ? a : b;
    }

    static long max(long a, long b) {
        return a > b ? a : b;
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
