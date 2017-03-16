/**
 * Created with IntelliJ IDEA.
 * User: jsu
 * Date: 13/04/13
 * Time: 1:09 AM
 * To change this template use File | Settings | File Templates.
 */

/**
 * Google Code Jam
 * User: jsu
 */

import java.io.*;
import java.util.StringTokenizer;

public class FairAndSquare {
    private static long f(long a, long b) {
        long ra = (long)Math.sqrt(a);
        if(ra * ra < a)
            ra++;

        long rb = (long)Math.sqrt(b);

        long n = 0;

        for(long root = ra; root * root <= b; ++root) {
            long square = root * root;
            if(check(root) && check(square)) {
//                System.out.println(root + ":" + square);
                n++;
            }
        }

        return n;
    }

    private static boolean check(long num) {
        long r = 0;

        long tmp = num;

        while (tmp > 0) {
            int d = (int) (tmp % 10);
            r = r * 10 + d;
            tmp /= 10;
        }

        return r == num;
    }

    private static void solve(String input, String output) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader(input));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(output)));

        int t = Integer.parseInt(in.readLine());
        for (int i = 1; i <= t; ++i) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            long n = f(a, b);

            out.print("Case #" + i + ": ");
            out.println(n);
        }

        out.close();
    }

    public static void main(String[] args) throws Exception {
        solve("test/C-sample.in", "test/C-sample.out");
        solve("test/C-small-attempt0.in", "test/C-small-attempt0.out");
//        solve("test/A-large-practice.in", "test/A-large-practice.out");
    }
}