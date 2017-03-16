import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * User: aartika
 * Date: 5/3/14
 */
public class NewLotteryGame {

    long[][][][] dp;
    int A;
    int B;
    int C;

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            NewLotteryGame game = new NewLotteryGame();
            game.dp = new long[31][2][2][2];
            String[] line = sc.nextLine().split(" ");
            game.A = Integer.parseInt(line[0]) - 1;
            game.B = Integer.parseInt(line[1]) - 1;
            game.C = Integer.parseInt(line[2]) - 1;
            for (int j = 0; j < 31; j++) {
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++)
                        Arrays.fill(game.dp[j][k][l], -1);
                }
            }

            long ans = game.rec(30, 1, 1, 1);
            System.out.println("Case #" + i + ": " + ans);
        }
    }

    public long rec(int t, int eqA, int eqB, int eqC) {
        long res = dp[t][eqA][eqB][eqC];
        if ( res == -1) {
            res = 0;
            if (t == 0)
                res = 1;
            else {
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        int z = x & y;
                        if (    (!bitcheck(eqA, 0)|| (x <= bit(A, t - 1)) )
                                && (!bitcheck(eqB, 0) || (y <= bit(B, t - 1)) )
                                && (!bitcheck(eqC, 0) || (z <= bit(C, t - 1)) )
                                ) {
                            // procceed:
                            res += rec(
                                    t-1,
                                    bitcheck(eqA, 0) && (x == bit(A, t - 1) ) ? 1 : 0,
                                    bitcheck(eqB, 0) && (y == bit(B, t - 1) ) ? 1 : 0,
                                    bitcheck (eqC, 0) && (z == bit(C, t - 1)) ? 1 : 0
                            );
                        }
                    }
                }
            }
        }
        dp[t][eqA][eqB][eqC] = res;
        return res;
    }

    public boolean bitcheck(int number, int bit) {
        return ((number & (1 << bit)) == (1 << bit));
    }

    public int bit(int number, int bit) {
        return (number & (1 << bit)) >> bit;
    }

    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }

}
