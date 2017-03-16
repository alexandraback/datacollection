import sun.security.util.BigInt;

import java.math.BigInteger;
import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {

    //
    // boilerplate
    //
    static String path = "/Users/liwen/Downloads/";
    static String fname = "B-small-attempt0";

    static BufferedWriter bw;
    static BufferedReader br;


    public static void init() throws IOException {

        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        br = new BufferedReader(new FileReader(path + fname + ".in"));
        bw = new BufferedWriter(new FileWriter(path + fname + ".txt"));

    }


    ///////////////////////////////////
    // code starts from here
    //

    public static int n;
    public static String [] buf;

    static boolean isValid(int state, int idx, int nidx) {
        if (idx < 0)
            return true;

        boolean [] past = new boolean[30];

        char last = buf[idx].charAt(buf[idx].length()-1);

        for (int i = 0; i < n; i++) {
            if (((1 << i) & state) > 0) {
                for (int j = 0; j < buf[i].length(); j++) {
                    past[buf[i].charAt(j) - 'a'] = true;
                }
            }
        }

        int i = 0;
        while (i < buf[nidx].length() && buf[nidx].charAt(i) == last) {
            i++;
        }

      //  if (i == 0)
        //    return false;


        while (i < buf[nidx].length()) {
            if (past[buf[nidx].charAt(i) - 'a']) {
                return false;
            }
            i++;
        }

        return true;
    }

    public static long dp[][] = new long[5000][200];

    static long dfs(int state, int last) {
        if (last >= 0 && dp[state][last] >= 0) {
            return dp[state][last];
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (((1<<i) & state) > 0) {
                cnt++;
            }
        }

        if (cnt == n)
            return 1L;

        long res = 0;
        for (int i = 0; i < n; i++) {
            if ( ((1<<i) & state) == 0 && isValid(state, last, i)) {
                res = (res + dfs(state | (1<<i), i)) % 1000000007;
            }
        }

        if (last >= 0)
            dp[state][last] = res;
        return res;

    }

    //
    // code ends here
    //////////////////////////////////

    public static void main(String[] args) throws IOException {
        //
        // boilerplate
        //

        init();
        int N = Integer.parseInt(br.readLine());

        ///////////////////////////////////
        // code starts here
        //




        //
        // code ends here
        //////////////////////////////////

        for (int l = 1; l <= N; ++l) {
            bw.write("Case #" + l + ":");
            /////////////////////////////////////
            /// code starts here
            ///

            n = Integer.parseInt(br.readLine());

            buf = br.readLine().split(" ");

            for (int i = 0; i < 5000; i++) {
                for (int j = 0; j < 200; j++)
                    dp[i][j] = -1;
            }

            bw.write(" " + dfs(0, -1) + "\n");

            ///
            /// code ends here
            ////////////////////////////////////

        }

        bw.close();
    }
}
