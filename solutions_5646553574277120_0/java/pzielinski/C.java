import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by Piotr Zielinski on 5/10/15.
 */
public final class C {
    public static void main(final String... args) {
        final Scanner sc = new Scanner(System.in);
        final int t = sc.nextInt();
        for (int i = 0; i < t; ++i) {
            System.out.println(String.format("Case #%d: %d", i+1, testcase(sc)));
        }
    }

    private static int testcase(final Scanner sc) {
        final int c = sc.nextInt();
        final int d = sc.nextInt();
        final int v = sc.nextInt();

        final Set<Integer> existing = new HashSet<>();
        for (int i = 0; i < d; ++i) {
            existing.add(sc.nextInt());
        }

        int result = v;

        for (int i = 0; i < (1 << 16); ++i) {
            final Set<Integer> extra = new HashSet<>();
            for (int k = 0; k < 16; ++k) {
                if ((i & (1 << k)) > 0 && !existing.contains(k+1)) {
                    extra.add(k + 1);
                }
            }

            if (ok(existing, extra, v)) {
                result = Math.min(result, extra.size());
            }
        }

        return result;
    }

    private static boolean ok(final Set<Integer> existing, final Set<Integer> extra, final int v) {
        final boolean[] dp = new boolean[v+1];
        Arrays.fill(dp, false);
        dp[0] = true;
        for (final Integer i: existing) {
            for (int a = v; a >= i; --a) {
                dp[a] |= dp[a - i];
            }
        }
        for (final Integer i: extra) {
            for (int a = v; a >= i; --a) {
                dp[a] |= dp[a - i];
            }
        }
        for (final boolean p: dp) {
            if (!p) {
                return false;
            }
        }
        return true;
    }
}
