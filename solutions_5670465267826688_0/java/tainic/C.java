package y2015.q;

import java.io.*;
import java.util.Scanner;

/**
 * @author aurel, 4/11/15
 */
public class C {
    //public static final String type = "test";
    public static final String type = "small-attempt0";
    //public static final String type = "large";

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new BufferedInputStream(new FileInputStream(
            "/home/aurel/repos/cuteants/codejam/src/y2015/q/C-" + type + ".in"
        )));
        BufferedWriter out = new BufferedWriter(new FileWriter(
            "/home/aurel/repos/cuteants/codejam/src/y2015/q/C-" + type + ".out"
        ));

        int t = in.nextInt();
        for (int ti = 1; ti <= t; ti++) {
            out.write("Case #" + ti + ": " + (solve(in) ? "YES" : "NO") + "\n");
        }

        in.close();
        out.close();
    }

    private static boolean solve(Scanner in) {
        int n = in.nextInt();
        int x = in.nextInt();
        char[] ch = in.next().toCharArray();

        int[] a = new int[n],
        m = new int[n + 1];
        int p = ONE;
        for (int i = 0; i < n; i++) {
            a[i] = toInt(ch[i]);
            p = MUL[p][a[i]];
            m[i + 1] = p;
        }

        // case 1
        for (int t = 0; t < x && t < 5; t++) {
            if (f(MUL[INV[pow(m[n], t)]][I], J, MUL[K][INV[pow(m[n], x - t - 1)]], m)) {
                return true;
            }
        }

        // case 2
        for (int r1 = 0; r1 < 5; r1++) {
            for (int r2 = 0; r2 < 5; r2++) {
                if (r1 <= x && r2 <= x && x - r1 - r2 >= 2) {
                    for (int i = 1; i < m.length; i++) {
                        int ll = MUL[pow(m[n], r1)][m[i - 1]];
                        if (ll != I) continue;

                        for (int j = 1; j < m.length; j++) {
                            int rr = MUL[INV[m[j]]][m[n]];
                            rr = MUL[rr][pow(m[n], r2)];
                            if (rr != K) continue;

                            int mm = MUL[INV[m[i - 1]]][m[n]];
                            mm = MUL[mm][pow(m[n], x - r1 - r2 - 2)];
                            mm = MUL[mm][m[j]];
                            if (mm != J) continue;

                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    private static boolean f(int left, int middle, int right, int[] m) {
        for (int i = 1; i < m.length; i++) {
            int ll = m[i - 1];
            if (ll != left) continue;
            for (int j = i; j < m.length; j++) {
                int mm = MUL[INV[m[i - 1]]][m[j]];
                if (mm != middle) continue;
                int rr = MUL[INV[m[j]]][m[m.length - 1]];
                if (rr != right) continue;
                return true;
            }
        }
        return false;
    }

    private static int pow(int a, int b) {
        b = b % 4;
        int p = ONE;
        while (b-- > 0) {
            p = MUL[p][a];
        }
        return p;
    }

    private static int toInt(char c) {
        if (c == 'i') return I;
        if (c == 'j') return J;
        return K;
    }

    private static final int ONE = 0;
    private static final int I = 1;
    private static final int J = 2;
    private static final int K = 3;
    private static final int MINUS_ONE = 4;
    private static final int MINUS_I = 5;
    private static final int MINUS_J = 6;
    private static final int MINUS_K = 7;
    private static final int[][] MUL = new int[][] {
        {ONE, I, J, K, MINUS_ONE, MINUS_I, MINUS_J, MINUS_K},
        {I, MINUS_ONE, K, MINUS_J, MINUS_I, ONE, MINUS_K, J},
        {J, MINUS_K, MINUS_ONE, I, MINUS_J, K, ONE, MINUS_I},
        {K, J, MINUS_I, MINUS_ONE, MINUS_K, MINUS_J, I, ONE},

        {MINUS_ONE, MINUS_I, MINUS_J, MINUS_K, ONE, I, J, K},
        {MINUS_I, ONE, MINUS_K, J, I, MINUS_ONE, K, MINUS_J},
        {MINUS_J, K, ONE, MINUS_I, J, MINUS_K, MINUS_ONE, I},
        {MINUS_K, MINUS_J, I, ONE, K, J, MINUS_I, MINUS_ONE}
    };
    private static final int[] INV = new int[] {
        ONE, MINUS_I, MINUS_J, MINUS_K, MINUS_ONE, I, J, K
    };
}
