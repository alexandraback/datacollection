import java.util.*;

public class alarge {

    public static int[] dp;

    public static void main(String[] args) {

        dp = new int[1000001];
        Arrays.fill(dp, 100000000);
        dp[1] = 1;

        for (int i=2; i<dp.length; i++) {
            dp[i] = dp[i-1]+1;
            int myrev = (int)rev(i);
            if (myrev < i && rev(myrev) == i)
                dp[i] = Math.min(dp[i], 1+dp[myrev]);
        }

        Scanner stdin = new Scanner(System.in);
        int numCases = stdin.nextInt();

        // Process all cases.
        for (int loop=1; loop<=numCases; loop++) {
            long n = stdin.nextLong();
            System.out.println("Case #"+loop+": "+solve(n));

        }

    }

    public static long solve(long n) {

        if (n <= 1000000) return dp[(int)n];

        long res = 0, prev = 0;
        while (true) {

            prev = n%10L != 0 ? rev(n) : n-1;
            res++;
            n--;
            if (prev < n) break;
        }
        return res + solve(prev);
    }

    public static long rev(long n) {

        long res = 0L;
        while (n > 0) {
            res = 10*res + n%10L;
            n /= 10L;
        }
        return res;
    }
}
