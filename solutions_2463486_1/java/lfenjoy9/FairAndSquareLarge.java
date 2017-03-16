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

public class FairAndSquareLarge {
    private static long[] tbl = {
            1,
            4,
            9,
            121,
            484,
            10201,
            12321,
            14641,
            40804,
            44944,
            1002001,
            1234321,
            4008004,
            100020001,
            102030201,
            104060401,
            121242121,
            123454321,
            125686521,
            400080004,
            404090404,
            10000200001L,
            10221412201L,
            12102420121L,
            12345654321L,
            40000800004L,
            1000002000001L,
            1002003002001L,
            1004006004001L,
            1020304030201L,
            1022325232201L,
            1024348434201L,
            1210024200121L,
            1212225222121L,
            1214428244121L,
            1232346432321L,
            1234567654321L,
            4000008000004L,
            4004009004004L
    };

    private static long f(long a, long b) {
        assert tbl.length == 39;

        int i;
        for(i = 0; i < tbl.length && tbl[i] < a; i++);

        int j;
        for(j = tbl.length - 1; j >= 0 && tbl[j] > b; --j);

        return j - i + 1;
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
        solve("test/C-large-1.in", "test/C-large-1.out");
    }
}