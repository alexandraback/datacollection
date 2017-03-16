import java.io.*;
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

    static void solve() throws Exception {
        int k = nextInt();
        int l = nextInt();
        int s = nextInt();
        char[] keys = next().toCharArray();
        String word = next();
        char[] string = new char[s];
        int variants = calc(k, s);
        int max = 0;
        int[] amounts = new int[s+1];
        for(int variant = 0; variant < variants; variant++) {
            int cur = variant;
            for(int i = 0; i < s; i++) {
                string[i] = keys[cur%k];
                cur = cur / k;
            }
            int curAmount = contains(string, word);
            max = Math.max(max, curAmount);
            amounts[curAmount]++;
        }
        double result = 0;
        for(int amount = 1; amount <= s; amount++) {
            result += 1.0 * amounts[amount] * amount;
        }

        printCase();
        out.println(max - (result / variants));
    }

    private static int contains(char[] string, String w) {
        String s = new String(string);
        int pos = 0;
        int nextPos = s.indexOf(w, pos);
        int result = 0;
        while(nextPos > -1) {
            pos = nextPos;
            nextPos = s.indexOf(w, pos+1);
            ++result;
        }
        return result;
    }

    private static int calc(int k, int s) {
        int result = 1;
        while(s > 0) {
            result *= k;
            --s;
        }
        return result;
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
