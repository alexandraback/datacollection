package round1B;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class Equal implements Runnable {
    static String fileName = "round1Bdata//C-small-attempt0";

    boolean[][][] rr;
    int[][] bb;
    int[] pp;

    int[] res;
    long[] a;

    boolean find(int k, int[] pos) {
        if (k < 0) {
            long[] s = new long[3];
            for (int i = 0; i < a.length; i++) {
                s[res[i]] += a[i];
            }
            return s[1] != 0 && s[1] == s[2];
        }

        for (int i = 0; i < rr.length; i++) {
            if (!rr[i][k + 1][pos[i]]) {
                throw new RuntimeException();
            }
        }
        int[] np = new int[pos.length];
        res[k] = 0;
        boolean f = true;
        for (int i = 0; i < rr.length; i++) {
            if (!rr[i][k][pos[i]]) {
                f = false;
                break;
            }
        }
        if (f && find(k - 1, pos)) return true;

        res[k] = 1;
        f = true;
        for (int i = 0; i < rr.length; i++) {
            np[i] = (pos[i] - bb[i][k] + pp[i]) % pp[i];
            if (!rr[i][k][np[i]]) {
                f = false;
                break;
            }
        }
        if (f && find(k - 1, np)) return true;

        res[k] = 2;
        f = true;
        for (int i = 0; i < rr.length; i++) {
            np[i] = (pos[i] + bb[i][k]) % pp[i];
            if (!rr[i][k][np[i]]) {
                f = false;
                break;
            }
        }
        if (f && find(k - 1, np)) return true;
        return false;
    }

    public void run() {
        try {
            Scanner in = new Scanner(new File(fileName + ".in"));
            PrintWriter out = new PrintWriter(new File(fileName + ".out"));
            int N = 50000;
            boolean[] pr = new boolean[N + 1];
            for (int i = 2; i <= N; i++) {
                if (!pr[i]) {
                    int k = i * 2;
                    while (k <= N) {
                        pr[k] = true;
                        k += i;
                    }
                }
            }
            int numP = 20;
            pp = new int[numP];
            int c = 0;
            int cc = N;
            while (c < pp.length) {
                while (pr[cc]) cc--;
                pp[c++] = cc;
                cc--;
            }
            for (int i = 0; i < numP; i++) {
                System.out.println(pp[i]);
            }
            int testNum = in.nextInt();
            for (int test = 1; test <= testNum; test++) {
                int n = in.nextInt();
                a = new long[n];
                for (int i = 0; i < n; i++) {
                    a[i] = in.nextLong();
                }
                boolean f = false;
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (a[i] == a[j] && !f) {
                            out.print("Case #" + test + ":");
                            out.println(a[i]);
                            out.println(a[j]);
                            f = true;
                        }
                    }
                }
                if (f) continue;
                rr = new boolean[numP][][];
                bb = new int[numP][];
                for (int curP = 0; curP < numP; curP++) {
                    int p = pp[curP];
                    int[] b = new int[n];
                    for (int j = 0; j < n; j++) {
                        b[j] = (int)(a[j] % p);
                    }
                    boolean[][] r = new boolean[n + 1][p + 1];
                    r[0][0] = true;
                    for (int j = 0; j < n; j++) {
                        for (int k = 0; k <= p; k++) {
                            if (r[j][k]) {
                                r[j + 1][k] = true;
                                r[j + 1][(k + b[j]) % p] = true;
                                r[j + 1][(k - b[j] + p) % p] = true;
                            }
                        }
                    }
                    rr[curP] = r;
                    bb[curP] = b;
                }
                res = new int[n];
                int[] pos = new int[numP];
                boolean s = find(n - 1, pos);
                // solve a problem
                out.print("Case #" + test + ": ");
                if (!s) {
                    out.println("Impossible");
                } else {
                    out.println();
                    boolean kk = false;
                    for (int i = 0; i < n; i++) if (res[i] == 1) {
                        if (kk) out.print(" ");
                        kk = true;
                        out.print(a[i]);
                    }
                    out.println();
                    kk = false;
                    for (int i = 0; i < n; i++) if (res[i] == 2) {
                        if (kk) out.print(" ");
                        kk = true;
                        out.print(a[i]);
                    }
                    out.println();
                }
                // print an answer
            }
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Thread(new Equal()).start();
    }
}
