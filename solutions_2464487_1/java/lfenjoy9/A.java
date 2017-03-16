/**
 * Google Code Jam
 * User: lfenjoy9
 */

import java.io.*;
import java.util.StringTokenizer;

public class A {
    private static long f(long r, long t) {
        long a = 2;
        long b = 2 * r - 1;
        long c = -t;

        double tmp = (double) b * (double) b -  4 * (double) a * (double) c;
        double x = (Math.sqrt(tmp) - b) / (2 * a);

        long max = (long) x;

        if (!v(r, t, max))
            max--;

        return max;
    }

    private static void solve(String input, String output) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader(input));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(output)));

        int t = Integer.parseInt(in.readLine());
        for (int i = 1; i <= t; ++i) {
            out.print("Case #" + i + ": ");

            // r t

            StringTokenizer st = new StringTokenizer(in.readLine());
            long r = Long.parseLong(st.nextToken());
            long T = Long.parseLong(st.nextToken());

            long max = f(r, T);

            out.println(max);
        }


        out.close();
    }

    private static boolean v(long r, long t, double n) {
        double a = (2 * n + 2 * r - 1) * n;
        if(a > t)
            return false;

        return true;
    }
    public static void main(String[] args) throws Exception {
//        solve("test/A-sample.in", "test/A-sample.out");
//        solve("test/A-small-attempt0.in", "test/A-small-attempt0.out");
        solve("test/A-large.in", "test/A-large.out");
    }
}