package gcj2016.r1c;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;

public class CLarge {
    final int J, P, S, K;

    // parse
    public CLarge(final Scanner sc) {
        J = sc.nextInt();
        P = sc.nextInt();
        S = sc.nextInt();
        K = sc.nextInt();
    }

    // solve
    @Override
    public String toString() {
        int cnt = 0;
        final int[][] js = new int[J + 1][S + 1];
        final int[][] ps = new int[P + 1][S + 1];
        final StringBuilder sb = new StringBuilder();
        for (int j = 1; j <= J; j++)
            for (int p = 1; p <= P; p++)
                for (int s = 1, k = 0; s <= S && k < K; s++)
                    if (js[j][s] < K && ps[p][s] < K) {
                        js[j][s]++;
                        ps[p][s]++;
                        cnt++;
                        k++;
                        sb.append('\n').append(j).append(' ').append(p).append(' ').append(s);
                    }
        return cnt + sb.toString();
    }

    // Template
    public static void main(String... args) throws Exception {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final Object[] solvers = new Object[T];
            for (int i = 0; i < T; i++)
                solvers[i] = new CLarge(sc);
            final Iterator<String> results = Arrays.stream(solvers)
                    .map(Object::toString)
                    .iterator();
            for (int i = 1; i <= T; i++)
                System.out.printf("Case #%s: %s\n", i, results.next());
        }
    }

    private static void debug(Object... os) {
        System.err.println(Arrays.deepToString(os));
    }
}
