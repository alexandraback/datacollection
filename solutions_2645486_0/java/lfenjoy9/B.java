/**
 * Google Code Jam
 * User: lfenjoy9
 */

import java.io.*;
import java.util.StringTokenizer;

public class B {
    // TODO: arguments and return

    private static int f(int E, int R, int n, int[] a) {
        return g(0, E, E, R, n, a);
    }

    private static int g(int i, int e,  int E, int R, int n, int[] a) {
        assert (e <= E);

        if(i == n)
            return 0;

        int max = 0;

        for(int x = 0; x <= e; x++) {
            int v = x * a[i] + g(i + 1, Math.min(E, e - x + R), E, R, n, a);
            max = Math.max(max, v);
        }

        return max;
    }

    private static void solve(String input, String output) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader(input));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(output)));

        int t = Integer.parseInt(in.readLine());
        for (int i = 1; i <= t; ++i) {
            out.print("Case #" + i + ": ");

            // E, R, n
            // vi

            StringTokenizer st = new StringTokenizer(in.readLine());
            int E = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());

            int[] a = new int[n];
            st = new StringTokenizer(in.readLine());
            for(int j = 0; j < n; ++j) {
                a[j] = Integer.parseInt(st.nextToken());
            }

            int max = f(E, R, n, a);

            out.println(max);
        }

        out.close();
    }

    public static void main(String[] args) throws Exception {
        solve("test/B-sample.in", "test/B-sample.out");
        solve("test/B-small-attempt0.in", "test/B-small-attempt0.out");
        //solve("test/B-large-practice.in", "test/B-large-practice.out");
    }
}