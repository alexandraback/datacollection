/**
 * Created by IntelliJ IDEA.
 * User: SONY
 * Date: 19.02.12
 * Time: 13:12
 * To change this template use File | Settings | File Templates.
 */

import java.io.*;
import java.util.*;


public class Main extends Thread {
    public Main(String inputFileName, String outputFileName) {
        try {
            this.input = new BufferedReader(new FileReader(inputFileName));
            this.output = new PrintWriter(outputFileName);
            this.setPriority(Thread.MAX_PRIORITY);
        } catch (Throwable e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(666);
        }
    }

    static long[] a, b;
    static int[] A, B;


    static int n, m;

    static long cache[][];

    static final long go(int at1, int at2) {
        if (at1 >= n || at2 >= m) return 0L;
        long stored = cache[at1][at2];
        if (stored != -1) return stored;
        stored = 0;
        long can = 0;
        if (A[at1] == B[at2]) {
            can = Math.min(a[at1], b[at2]);
            a[at1] -= can;
            b[at2] -= can;
        }
        stored = Math.max(stored, can + go(at1, at2 + 1));
        stored = Math.max(stored, can + go(at1 + 1, at2));
        stored = Math.max(stored, can + go(at1 + 1, at2 + 2));
        return cache[at1][at2] = stored;
    }


    final long doit2() throws Throwable {
        int N = nextInt();
        int M = nextInt();
        ArrayList<Integer> A1 = new ArrayList<Integer>(), B1 = new ArrayList<Integer>();
        ArrayList<Long> a1 = new ArrayList<Long>(), b1 = new ArrayList<Long>();

        for (int i = 0; i < N; ++i) {
            a1.add(nextLong());
            A1.add(nextInt());
        }
        for (int i = 0; i < M; ++i) {
            b1.add(nextLong());
            B1.add(nextInt());
        }
        int last = -1;
        for (int i = 0; i < N; ++i) {
            if (A1.get(i) != last) {
                ++n;
                last = A1.get(i);
            }
        }
        last = -1;
        for (int i = 0; i < M; ++i) {
            if (B1.get(i) != last) {
                ++m;
                last = B1.get(i);
            }
        }
        a = new long[n + 1];
        A = new int[n];
        b = new long[m + 1];
        B = new int[m];

        for (int i = 0, at = 0; i < N; ) {
            int actual = A1.get(i);
            int j = i;
            long accum = 0;
            while (j < N && A1.get(i) == A1.get(j)) {
                accum += a1.get(i);
                ++j;
            }
            i = j;
            a[at] = accum;
            A[at++] = actual;
        }
        for (int i = 0, at = 0; i < M; ) {
            int actual = B1.get(i);
            int j = i;
            long accum = 0;
            while (j < M && B1.get(i) == B1.get(j)) {
                accum += b1.get(i);
                ++j;
            }
            i = j;
            b[at] = accum;
            B[at++] = actual;
        }

        cache = new long[n][m];
        for (long t[] : cache) Arrays.fill(t, -1);
        return go(0, 0);


    }


    final String doit(int ID) throws Throwable {
        return String.format("Case #%d: ", ID) + Long.toString(doit2());
    }


    private void solve() throws Throwable {
        int testCases = nextInt();
        for (int i = 1; i <= testCases; ++i) {
            output.println(doit(i));
        }
    }

    public void run() {
        try {
            solve();
        } catch (Throwable e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(666);
        } finally {
            output.close();
        }
    }

    public static void main(String... args) {
        new Main("input.txt", "output.txt").start();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    private String next() throws IOException {
        while (tokens == null || !tokens.hasMoreTokens()) {
            tokens = new StringTokenizer(input.readLine());
        }
        return tokens.nextToken();
    }

    private StringTokenizer tokens;
    private BufferedReader input;
    private PrintWriter output;
}
