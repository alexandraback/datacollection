package gcj2015.r1c;

import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

public class C {

    private final int C, D, V, denominations[];

    // parse
    public C(final Scanner sc) {
        C = sc.nextInt();
        D = sc.nextInt();
        V = sc.nextInt();
        denominations = new int[D];
        for (int i = 0; i < D; i++)
            denominations[i] = sc.nextInt();
    }

    // solve
    @Override
    public String toString() {
        final boolean[] bs = new boolean[V + 1];
        bs[0] = true;
        for (int i = 0; i < D; i++)
            for (int j = V; j >= denominations[i]; j--)
                for (int k = 1; !bs[j] && k <= C && j - k * denominations[i] >= 0; k++)
                    if (bs[j - k * denominations[i]])
                        bs[j] = true;
        int dmask = 0;
        for (int i = 0; i < D; i++)
            dmask |= 1 << (denominations[i] - 1);
        int min = 5;
        loop:
        for (int i = 0; i < 1 << V; i++) {
            if (Integer.bitCount(i) > min || (dmask & i) > 0)
                continue;
            final boolean[] bbs = Arrays.copyOf(bs, bs.length);
            for (int d = 1, mask = 1; mask <= i; d++, mask <<= 1)
                if ((i & mask) > 0)
                    for (int j = V; j >= d; j--)
                        for (int k = 1; !bbs[j] && k <= C && j - k * d >= 0; k++)
                            if (bbs[j - k * d])
                                bbs[j] = true;
            for (int j = 0; j < bbs.length; j++)
                if (!bbs[j])
                    continue loop;
            min = Math.min(min, Integer.bitCount(i));
        }
        return "" + min;
    }

    // Template
    public static void main(String... args) throws Exception {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final Object[] solvers = new Object[T];
            for (int i = 0; i < T; i++)
                solvers[i] = new C(sc);
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
