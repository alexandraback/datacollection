import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class CounterCultureDP {

    private void processInput() throws IOException {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        for (int testCase = 1; testCase <= T; testCase++) {
            long N = in.nextLong();

            solve(testCase, N);

        }

        in.close();
    }

    long N;
    private void solve(int testCase, long N) {
        this.N = N;
        memo = new long[(int)N + 1];
        Arrays.fill(memo, -1);
        for (int i = (int)N; i >= 1; i--) {
            go(i);
        }
        long res = go(0);

        System.out.printf(Locale.ENGLISH, "Case #%d: %d\n", testCase, res);
    }

    long[] memo;
    long go(int val) {
        if (memo[val] != -1) {
            return memo[val];
        }
        if (val == N) {
            return memo[val] = 0;
        } else {
            long res = 1 + go(val + 1);
            long rev = reverse(val);
            if (rev <= N && rev > val) {
                res = Math.min(res, 1 + go((int)rev));
            }
            return memo[val] = res;
        }
    }

    long reverse(long val) {
        StringBuilder sb = new StringBuilder(String.valueOf(val));
        return Long.valueOf(sb.reverse().toString());
    }

    public static void main(String[] args) throws Exception {
        CounterCultureDP main = new CounterCultureDP();
        main.processInput();
    }
}
