package c1;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class Task3 {

    static int[] a;
    static long[] ac;
    static int[] b;
    static long[] bc;

    static long max = -1;

    public static void go(int ia, int ib, long count) {
        if (ia >= a.length || ib >= b.length) {
            max = Math.max(max, count);
            return;
        }
        if (a[ia] == b[ib]) {
            long diff = Math.min(ac[ia], bc[ib]);
            count += diff;
            if (ac[ia] < bc[ib]) {
                bc[ib] -= ac[ia];
                ac[ia] = 0;
                go(ia + 1, ib, count);
            } else {
                ac[ia] -= bc[ib];
                bc[ib] = 0;
                go(ia, ib + 1, count);
            }
            ac[ia] += diff;
            bc[ib] += diff;
        } else {
            go(ia + 1, ib, count);
            go(ia, ib + 1, count);
        }
    }

    public static void doTheJob(int t, Scanner scanner) {
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        a = new int[n];
        ac = new long[n];
        bc = new long[m];
        b = new int[m];
        max = -1;
        for (int i = 0; i < n; i++) {
            ac[i] = scanner.nextLong();
            a[i] = scanner.nextInt();
        }
        for (int i = 0; i < m; i++) {
            bc[i] = scanner.nextLong();
            b[i] = scanner.nextInt();
        }
        long map[][] = new long[n][m];
        long remA[][] = new long[n][m];
        long remB[][] = new long[n][m];
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                remA[j][i] = ac[j];
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                remB[j][i] = bc[i];
            }
        }
        go(0, 0, 0);
        System.out.println("Case #" + t + ": " + max);
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new FileInputStream("1b_task1.txt"));
        scanner.useLocale(Locale.US);
        int T = scanner.nextInt();
        for (int i = 0; i < T; i++) {
            doTheJob(i + 1, scanner);
        }
    }
}
