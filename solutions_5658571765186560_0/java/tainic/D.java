package y2015.q;

import java.io.*;
import java.util.Scanner;

/**
 * @author aurel, 4/11/15
 */
public class D {
    //public static final String type = "test";
    public static final String type = "small-attempt1";

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new BufferedInputStream(new FileInputStream(
            "/home/aurel/repos/cuteants/codejam/src/y2015/q/D-" + type + ".in"
        )));
        BufferedWriter out = new BufferedWriter(new FileWriter(
            "/home/aurel/repos/cuteants/codejam/src/y2015/q/D-" + type + ".out"
        ));

        int t = in.nextInt();
        for (int ti = 1; ti <= t; ti++) {
            out.write("Case #" + ti + ": " + (solve(in) == 1 ? "RICHARD" : "GABRIEL") + "\n");
        }

        in.close();
        out.close();
    }

    private static int solve(Scanner in) {
        int x = in.nextInt(),
            r = in.nextInt(),
            c = in.nextInt();
        if (x >= 7) return 1;
        if (r * c % x != 0) return 1;
        if (x == 1) return 2;
        if (x == 2) return r * c % 2 == 0 ? 2 : 1;
        if (x == 3) return (r == 1 || c == 1) ? 1 : 2;
        if (x == 4) return (r < 3 || c < 3) ? 1 : 2;
        return 1; // todo
    }
}
