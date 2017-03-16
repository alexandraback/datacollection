import java.io.*;
import java.util.HashSet;
import java.util.StringTokenizer;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

/**
 * User: vryzhuk
 * Date: 4/18/15
 * Time: 3:59 AM
 */
public class C {

    static BufferedReader in;
    static PrintWriter out;
    static StringTokenizer tok;
    static int test;
    static final double EPS = 0.00000000001;

    static void solve() throws Exception {
        int c = nextInt();
        int d = nextInt();
        int v = nextInt();

        int[] mustExistCoins = new int[d];
        for (int i = 0; i < d; i++) {
            mustExistCoins[i] = nextInt();
        }

        int variants = 1 << (v-2);
        int minAmount = calcMin(v);
        int result = minAmount + d;
        boolean[] coins = new boolean[v + 1];
        for (int i = 0; i < variants; i++) {
            int realI = i * 4 + 3;
            int amountOfCoins = amountOfCoins(realI);
            if (amountOfCoins >= minAmount && amountOfCoins < result) {
                fillCoins(realI, coins);
                if (isMustExistAll(coins, mustExistCoins)) {
                    if (isAllCovered(coins, v, amountOfCoins)) {
                        result = amountOfCoins;
                    }
                }
            }
        }


        printCase();
        out.println(result - d);
    }

    private static int calcMin(int v) {
        int result = 0;
        while(v > 0) {
            result++;
            v = v >> 1;
        }
        return result;
    }

    private static int amountOfCoins(int i) {
        int result = 0;
        while(i > 0) {
            result += (i & 1);
            i = i >> 1;
        }
        return result;
    }

    private static boolean isAllCovered(boolean[] coins, int v, int amount) {
        if(!coins[1] || !coins[2]) {
            return false;
        }
        int[] values = new int[amount];
        int pos = 0;
        for(int i = 1; i < coins.length; i++) {
            if(coins[i]) {
                values[pos] = i;
                ++pos;
            }
        }
        int combinations = 1 << amount;
        boolean[] covered = new boolean[v + 1];
        for(int i = 1; i < combinations; i++) {
            int sum = 0;
            int cur = i;
            pos = 0;
            while(cur > 0) {
                if((cur & 1) == 1) {
                    sum+=values[pos];
                }
                cur = cur >> 1;
                ++pos;
            }
            if(sum <= v ) {
                covered[sum] = true;
            }
        }
        for(int i = 1; i < covered.length; i++) {
            if(!covered[i])
                return false;
        }
        return true;
    }

    private static boolean isMustExistAll(boolean[] coins, int[] mustExistCoins) {
        for (int i : mustExistCoins) {
            if (!coins[i])
                return false;
        }
        return true;
    }

    private static void fillCoins(int value, boolean[] coins) {
        for (int i = 1; i < coins.length && value > 0; i++) {
            coins[i] = (1 == (value & 1));
            value = value >> 1;
        }
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
                System.out.println(test);
            }
            in.close();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            exit(1);
        }
    }
}
