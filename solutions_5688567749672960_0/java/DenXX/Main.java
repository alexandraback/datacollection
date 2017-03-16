//package denxx;

import java.util.*;

public class Main {

    public static int reverse(int d) {
        int res = 0;
        while (d != 0) {
            res = res * 10 + d % 10;
            d /= 10;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            int N = in.nextInt();
            int[] dp = new int[10000000];
            dp[1] = 1;
            Queue<Integer> q = new LinkedList<Integer>();
            q.add(1);
            while (!q.isEmpty() && q.peek() != N) {
                int cur = q.poll();
                if (cur < 10000000 - 1 && dp[cur + 1] == 0) {
                    dp[cur + 1] = dp[cur] + 1;
                    q.add(cur + 1);
                }
                int rev = reverse(cur);
                if (rev < dp.length && dp[rev] == 0) {
                    dp[rev] = dp[cur] + 1;
                    q.add(rev);
                }
            }

            System.out.println("Case #" + t + ": " + dp[N]);
        }
    }

}
