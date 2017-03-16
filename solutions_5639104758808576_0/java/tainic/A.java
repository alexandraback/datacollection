package y2015.q;

import java.io.*;
import java.util.Scanner;

/**
 * @author aurel, 4/11/15
 */
public class A {

    public static final String type = "small-attempt0";

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new BufferedInputStream(new FileInputStream(
            "/home/aurel/repos/cuteants/codejam/src/y2015/q/A-" + type + ".in"
        )));
        BufferedWriter out = new BufferedWriter(new FileWriter(
            "/home/aurel/repos/cuteants/codejam/src/y2015/q/A-" + type + ".out"
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
        char[] ch = in.next().toCharArray();
        int up = 0, add = 0;
        for (int i = 0; i <= n; i++) {
            int p = ch[i] - '0';
            if (up < i) {
                add += i - up;
                up = i;
            }
            up += p;
        }
        return add;
    }
}
