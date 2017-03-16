package gcj2015.r1c;

import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

public class A {
    private final int R, C, W;

    // parse
    public A(final Scanner sc) {
        R = sc.nextInt();
        C = sc.nextInt();
        W = sc.nextInt();
    }

    // solve
    @Override
    public String toString() {
        final int b = R * ((C + W - 1) / W);
        final int r = W;
        return "" + (b + r - 1);
    }

    // Template
    public static void main(String... args) throws Exception {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final Object[] solvers = new Object[T];
            for (int i = 0; i < T; i++)
                solvers[i] = new A(sc);
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
