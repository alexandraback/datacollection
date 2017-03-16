import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.Scanner;

public class KingdomRush {
    // -ea –Xmx256M –Xss64M
    int N;
    int[] a, b;

    private static class Level {
        int star1, star2;
        int score;

        int weight(int s) {
            if (s >= star2 && score == 0) return 2;
            if (s >= star2 && score == 1) return 1;
            if (s >= star1 && score == 0) return 1;
            return 0;
        }
    }

    private Object solve() throws Exception {
        Level[] levels = new Level[N];
        for (int i = 0; i < N; i++) {
            Level l = new Level();
            l.score = 0;
            l.star1 = a[i];
            l.star2 = b[i];
            levels[i] = l;
        }

        int totalScore = 0;
        int count = 0;

        while (true) {
            Level l = null;
            int w = 0, s2 = -1;
            for (int i = 0; i < N; i++) {
                Level li = levels[i];
                int wi = li.weight(totalScore);
                if (wi == 0) continue;

                if (wi == 2 || li.score > 0) {
                    l = li;
                    w = wi;
                    break;
                }

                if (wi >= w && li.star2 > s2) {
                    l = li;
                    w = wi;
                    s2 = li.star2;
                }
            }
            if (l == null) break;
            l.score += w;
            totalScore += w;
            count++;
        }

        if (totalScore != 2 * N) {
            return "Too Bad";
        }
        return count;
    }

    private void load() throws Exception {
        N = nextInt();
        a = new int[N];
        b = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = nextInt();
            b[i] = nextInt();
        }
        log.print("N: " + N + ", a: " + Arrays.toString(a) + ", b: " + Arrays.toString(b));
    }


    private static final String PREFIX = "B-small-attempt0";
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

            KingdomRush s = new KingdomRush();
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
