
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer stk;
    static int[] v = new int[10010];
    static long[] tt = new long[10010];
    static long[] ss = new long[10010];
    static int E, R, N;

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new FileReader("in.txt"));
        out = new PrintWriter("out.txt");
        stk = new StringTokenizer(in.readLine());
        // Start of User Code

        int T = ni();
        for (int i = 1; i <= T; i++) {
            E = ni();
            R = ni();
            N = ni();
            for (int j = 0; j < N; j++) {
                v[j] = ni();
            }
            printf("Case #%d: %s\n", i, proc());
        }


        // End of User Code
        in.close();
        out.close();
    }

    static String proc() {
        return get(0, N - 1, E, 0, R) + "";
    }

    static BigInteger get(int start, int end, long startEnergy, long minEndEnergy, long regain) {
        if (end < start) {
            return BigInteger.ZERO;
        }
        if (start == end) {
            if (regain >= minEndEnergy) {
                //System.out.printf("of activity %3d - %5d joules\n", start, startEnergy);
                return BigInteger.valueOf(v[start] * startEnergy);
            } else {
                long t = minEndEnergy - regain;
                //System.out.printf("of activity %3d - %5d joules\n", start, (startEnergy - t));
                return BigInteger.valueOf(v[start] * (startEnergy - t));
            }
        }
        long maxGain = v[start];
        int maxIndex = start;
        tt[start] = Math.min(startEnergy, E);
        for (int i = start + 1; i <= end; i++) {
            if (v[i] > maxGain) {
                maxGain = v[i];
                maxIndex = i;
            }
            tt[i] = Math.min(E, tt[i - 1] + R);
        }
        ss[end] = Math.max(0, minEndEnergy);
        for (int i = end - 1; i >= maxIndex; i--) {
            ss[i] = Math.max(0, ss[i + 1] - R);
        }
        BigInteger res = BigInteger.ZERO;
        if (R >= ss[maxIndex]) {
            //System.out.printf("of activity %3d - %5d joules\n", maxIndex, tt[maxIndex]);
            res = BigInteger.valueOf(maxGain * tt[maxIndex]);
            res = res.add( get(start, maxIndex - 1, startEnergy, tt[maxIndex], R));
            res= res.add( get(maxIndex + 1, end, R, minEndEnergy, R));
        } else {
            //System.out.printf("of activity %3d - %5d joules\n", maxIndex, tt[maxIndex] - (ss[maxIndex] - R));
            res = BigInteger.valueOf(maxGain * (tt[maxIndex] - (ss[maxIndex] - R)));
            res =res.add( get(start, maxIndex - 1, startEnergy, tt[maxIndex], R));
            res = res.add(get(maxIndex + 1, end, ss[maxIndex], minEndEnergy, R));
        }
        return res;
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
