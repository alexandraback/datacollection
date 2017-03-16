package gcj2015.r1c;

import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

public class B {
    private static final double EPS = 1e-12;

    private final int K, L, S;
    private final char[] monkey, target;

    // parse
    public B(final Scanner sc) {
        K = sc.nextInt();
        L = sc.nextInt();
        S = sc.nextInt();
        monkey = sc.next().toCharArray();
        target = sc.next().toCharArray();
    }

    // solve
    @Override
    public String toString() {
        final double[] ps = new double[128];
        for (int i = 0; i < K; i++)
            ps[monkey[i]]++;
        for (int i = 0; i < ps.length; i++)
            ps[i] /= K;
        for (int i = 0; i < L; i++)
            if (ps[target[i]] == 0.)
                return "0.0";
        int overwrap = L - 1;
        loop:
        for (; overwrap > 0; overwrap--) {
            for (int i = 0, j = L - overwrap; j < L; i++, j++)
                if (target[i] != target[j])
                    continue loop;
            break loop;
        }
        final int max = (S - L) / (L - overwrap) + 1;
        int all = 1;
        for (int i = 0; i < S; i++)
            all *= K;
        int cnt = 0;
        final char[] cs = new char[S];
        for (int i = 0; i < all; i++) {
            for (int j = 0, k = i; j < S; j++, k /= K)
                cs[j] = monkey[k % K];
            int banana = 0;
            loop:
            for (int j = 0; j + L <= S; j++) {
                for (int k = 0; k < L; k++)
                    if (cs[j + k] != target[k])
                        continue loop;
                banana++;
            }
            cnt += max - banana;
        }
        return "" + (1. * cnt / all);
    }

    // Template
    public static void main(String... args) throws Exception {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final Object[] solvers = new Object[T];
            for (int i = 0; i < T; i++)
                solvers[i] = new B(sc);
            final Iterator<String> results = Arrays.stream(solvers)
                    .map(s -> s.toString())
                    .iterator();
            for (int i = 1; i <= T; i++)
                System.out.printf("Case #%s: %s\n", i, results.next());
        }
    }

    private static void debug(Object... os) {
        System.err.println(Arrays.deepToString(os));
    }
}
