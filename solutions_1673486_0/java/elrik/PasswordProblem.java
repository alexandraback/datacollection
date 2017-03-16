import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class PasswordProblem {
    // -ea –Xmx256M –Xss64M
    int A, B;
    double[] p;

    private Object solveSmall() throws Exception {
        double E = B + 2;
        double q = 1;
        for (int k = 0; k < A; k++) {
            int s = A - k - 1;
            q *= p[k];
            E = Math.min(E, (B - A + 2*s + 1)*q + (2*B - A + 2*s + 2)*(1-q));
        }
        return E;
    }

    private Object solve() throws Exception {
        return solveSmall();
    }

    private void load() throws Exception {
        A = nextInt();
        B = nextInt();
        p = nextDoubleArray(A);
        log.print("A: " + A + ", B: " + B + ", p: " + Arrays.toString(p));
    }


    private static final String PREFIX = "A-small-attempt0";
    private static final String PATH = "d:/gcjam12/r1a/";
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

            PasswordProblem s = new PasswordProblem();
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
