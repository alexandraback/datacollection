import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

/**
 * User: vryzhuk
 * Date: 4/11/15
 * Time: 9:36 PM
 */
public class A {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;
    static int test;
    static int[] prev = new int[1000001];
    static int[] amount = new int[1000001];
    static {
        prev[1] = -1;
        amount[1] = 1;
        for (int i = 2; i < 1000001; i++) {
            if(i%10 != 0) {
                int flip = flip(i);
                if(prev[flip] > 0 && amount[flip] < amount[i-1]) {
                    prev[i] = flip;
                    amount[i] = amount[flip] + 1;
                } else {
                    prev[i] = i-1;
                    amount[i] = amount[i-1] + 1;
                }
            } else {
                prev[i] = i-1;
                amount[i] = amount[i-1] + 1;
            }
        }
    }

    private static int flip(int i) {
        int result = 0;
        while(i > 0) {
            result = result * 10 + i%10;
            i = i /10;
        }
        return result;
    }

    static void solve() throws Exception {
        int n = nextInt();
        //out.print(n + ": " + amount[n] + ": ");
        //while(prev[n] != -1) {
            //out.print(" " + prev[n]);
            //n = prev[n];
        //}

        printCase();
        out.println(amount[n]);
    }

    static void printCase() {
        out.print("Case #" + test + ": ");
    }

    static void printlnCase() {
        out.println("Case #" + test + ":");
    }

    static int nextInt() throws IOException {
        return parseInt(next());
    }

    static long nextLong() throws IOException {
        return parseLong(next());
    }

    static double nextDouble() throws IOException {
        return parseDouble(next());
    }

    static String next() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    public static void main(String[] args) {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));
            int tests = nextInt();
            for (test = 1; test <= tests; test++) {
                solve();
            }
            in.close();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            exit(1);
        }
    }

}
