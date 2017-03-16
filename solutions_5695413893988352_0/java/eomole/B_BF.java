package gcj2016.r1b;

import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

public class B_BF {
    private char[] C, J;

    // parse
    public B_BF(final Scanner sc) {
        C = sc.next().toCharArray();
        J = sc.next().toCharArray();
    }

    // solve
    @Override
    public String toString() {
        int max = 1;
        for (int i = 0; i < C.length; i++)
            max *= 10;
        int best_c = 0;
        int best_j = 0;
        int best_diff = Integer.MAX_VALUE;
        for (int c = 0; c < max; c++)
            if (check(C, c))
                for (int j = 0; j < max; j++)
                    if (check(J, j))
                        if (best_diff > Math.abs(c - j)) {
                            best_c = c;
                            best_j = j;
                            best_diff = Math.abs(c - j);
                        }
        return String.format("%0" + C.length + "d %0" + J.length + "d", best_c, best_j);
    }

    boolean check(char[] cs, int num) {
        final char[] ncs = String.format("%0" + cs.length + "d", num).toCharArray();
        for (int i = 0; i < cs.length; i++)
            if (cs[i] != '?' && ncs[i] != cs[i])
                return false;
        return true;
    }

    // Template
    public static void main(String... args) throws Exception {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final Object[] solvers = new Object[T];
            for (int i = 0; i < T; i++)
                solvers[i] = new B_BF(sc);
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
