package y2015.q;

import java.io.*;
import java.util.Scanner;

/**
 * @author aurel, 4/11/15
 */
public class B {
    public static final String type = "small-attempt2";
    //public static final String type = "test";

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new BufferedInputStream(new FileInputStream(
            "/home/aurel/repos/cuteants/codejam/src/y2015/q/B-" + type + ".in"
        )));
        BufferedWriter out = new BufferedWriter(new FileWriter(
            "/home/aurel/repos/cuteants/codejam/src/y2015/q/B-" + type + ".out"
        ));

        int t = in.nextInt();
        for (int ti = 1; ti <= t; ti++) {
            out.write("Case #" + ti + ": " + solve(in) + "\n");
        }

        in.close();
        out.close();
    }

    private static int solve(Scanner in) {
        int n = in.nextInt();
        int[] a = new int[1001];
        for (int i = 0; i < n; i++) {
            a[in.nextInt()]++;
        }

        int base = 0, min = 1001;
        for (int i = 1000; i > 0; i--) {
            if (a[i] != 0) {
                if (base + i < min) {
                    min = base + i;
                }
                base += a[i];
                a[i / 2] += a[i];
                a[i / 2 + i % 2] += a[i];
            }
        }
        return min;
    }
}
