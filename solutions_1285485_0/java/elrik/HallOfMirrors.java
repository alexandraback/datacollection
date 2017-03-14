import sun.print.PSPrinterJob;

import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.Scanner;

public class HallOfMirrors {
    // -ea –Xmx256M –Xss64M
    int H, W, D;
    String[] S;

    static final double EPS = 1E-12;
    static final double TEST_EPS = 1E-6;

    private boolean test(double x, double y) {
        return S[(int) (y / 2 + EPS)].charAt((int) (x / 2 + EPS)) == '#';
    }

    private boolean mirrors(final double x0, final double y0, double dx, double dy) {
        double norm = Math.hypot(dx, dy);
        dx /= norm;
        dy /= norm;
        double x = 2*x0, y = 2*y0, r = 2*D;
        while (true) {
            double dTestX = Math.signum(dx)*TEST_EPS, dTestY = Math.signum(dy)*TEST_EPS;
            if (Math.abs(x / 2 - Math.round(x / 2)) < EPS) {
                if (Math.abs(y / 2 - Math.round(y / 2)) < EPS) {
                    if (test(x + dTestX, y + dTestY)) {
                        // Corner case
                        if (!test(x + dTestX, y - dTestY) && !test(x - dTestX, y + dTestY)) {
                            return false;
                        }
                        if (test(x + dTestX, y - dTestY)) {
                            dx = -dx;
                        }
                        if (test(x - dTestX, y + dTestY)) {
                            dy = -dy;
                        }
                    }
                } else if (test(x + dTestX, y)) {
                    dx = -dx;
                }
            } else if (Math.abs(y / 2 - Math.round(y / 2)) < EPS) {
                if (test(x, y + dTestY)) {
                    dy = -dy;
                }
            }

            double d1 = 1e10;
            if (dx > EPS) {
                d1 = (Math.ceil(x + EPS) - x) / dx;
            } else if (dx < -EPS) {
                d1 = (Math.floor(x - EPS) - x) / dx;
            }

            double d2 = 1e10;
            if (dy > EPS) {
                d2 = (Math.ceil(y + EPS) - y) / dy;
            } else if (dy < -EPS) {
                d2 = (Math.floor(y - EPS) - y) / dy;
            }

            double d = Math.min(d1, d2);
            x += dx * d;
            y += dy * d;
            r -= d;
            if (r < -EPS) return false;
            if (Math.abs(x - Math.round(x)) < EPS) x = Math.round(x);
            if (Math.abs(y - Math.round(y)) < EPS) y = Math.round(y);
            if (Math.abs(x - x0*2) < EPS && Math.abs(y - y0*2) < EPS) return true;
        }
    }

    private Object solve() throws Exception {
        double x = 0, y = 0;
        for (int i = 0; i < H; i++) {
            int j = S[i].indexOf('X');
            if (j >= 0) {
                x = j + 0.5;
                y = i + 0.5;
                break;
            }
        }

        int result = 0;

        if (mirrors(x, y, 1, 0)) result++;
        if (mirrors(x, y, -1, 0)) result++;
        if (mirrors(x, y, 0, 1)) result++;
        if (mirrors(x, y, 0, -1)) result++;

        int h = H*16, w = W*16;
        for (int i = -h; i <= h; i++) {
            for (int j = -w; j <= w; j++) {
                if (i == 0 || j == 0) continue;
                if (BigInteger.valueOf(Math.abs(i)).gcd(BigInteger.valueOf(Math.abs(j))).compareTo(BigInteger.ONE) == 0) {
                    if (mirrors(x, y, i, j)) {
                        result++;
                    }
                }
            }
        }

        return result;
    }

    private void load() throws Exception {
        H = nextInt();
        W = nextInt();
        D = nextInt();
        nextLine();
        S = nextLineArray(H);

        log.println("H: " + H + ", W: " + W + ", D: " + D);
        for (int i = 0; i < H; i++) {
            log.println(S[i]);
        }
    }


    private static final String PREFIX = "D-small-attempt1";
    private static final String PATH = "d:/gcjam12/qr/";
    private static final String POSTFIX_IN = ".in";
    private static final String POSTFIX_OUT = ".out";
    private static final PrintStream log = System.out;

    public static void main(String args[]) throws Exception {
        Locale.setDefault(Locale.US);
        InputStreamReader reader = new InputStreamReader(new BufferedInputStream(new FileInputStream(PATH + PREFIX + POSTFIX_IN)));
        PrintStream out = new PrintStream(new FileOutputStream(PATH + PREFIX + POSTFIX_OUT));
        Scanner in = new Scanner(reader);

        long t0 = System.nanoTime();
        int testCount = in.nextInt(); in.nextLine();
        for (int testIndex = 1; testIndex <= testCount; testIndex++) {
            log.printf("Data #%d: ", testIndex);

            HallOfMirrors s = new HallOfMirrors();
            s.in = in;
            s.load();
            s.in = null;
            log.println();

            long t1 = System.nanoTime();
            String result = "Case #" + testIndex + ": " + s.solve();

            out.println(result);
            log.println(result);
            log.printf("Time #%d: %.6f sec\n\n", testIndex, (System.nanoTime() - t1) / 1e9);
        }
        log.printf("Total time: %.6f sec", (System.nanoTime() - t0)/1e9);

        reader.close();
        out.close();
    }

    private Scanner in;
    private int nextInt() { return in.nextInt(); }
    private long nextLong() { return in.nextLong(); }
    private double nextDouble() { return Double.parseDouble(in.next()); }
    private String nextLine() { return in.nextLine().trim(); }
    private void skipLine() { in.nextLine(); }
    private String next() { return in.next().trim(); }
    private int[] nextIntArray(int size) { int[] a = new int[size]; for (int i = 0; i < size; i++) a[i] = in.nextInt(); return a; }
    private long[] nextLongArray(int size) { long[] a = new long[size]; for (int i = 0; i < size; i++) a[i] = in.nextLong(); return a; }
    private double[] nextDoubleArray(int size) { double[] a = new double[size]; for (int i = 0; i < size; i++) a[i] = Double.parseDouble(in.next());  return a; }
    private String[] nextLineArray(int size) { String[] a = new String[size]; for (int i = 0; i < size; i++) a[i] = in.nextLine().trim(); return a; }
    private String[] nextTokenArray(int size) { String[] a = new String[size]; for (int i = 0; i < size; i++) a[i] = in.next().trim(); return a; }
}
