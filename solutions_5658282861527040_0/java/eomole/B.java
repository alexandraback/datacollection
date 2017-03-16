import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;
import java.util.stream.Stream;

public class B {
    private final int A, B, K;

    // parse
    public B(final Scanner sc) {
        A = sc.nextInt();
        B = sc.nextInt();
        K = sc.nextInt();
    }

    // solve
    @Override
    public String toString() {
        int ans = 0;
        for (int a = 0; a < A; a++)
            for (int b = 0; b < B; b++)
                if ((a & b) < K)
                    ans++;
        return "" + ans;
    }

    // Template
    public static void main(String... args) throws Exception {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final Object[] solvers = new Object[T];
            for (int i = 0; i < T; i++)
                solvers[i] = new B(sc);
            final Iterator<String> results = Arrays.stream(solvers)
                    .parallel()
                    .map(s -> s.toString())
                    .map(Stream::of)
                    .reduce((stream1, stream2) -> Stream.concat(stream1, stream2))
                    .orElse(Stream.empty())
                    .iterator();
            for (int i = 1; i <= T; i++)
                System.out.printf("Case #%s: %s\n", i, results.next());
        }
    }

    private static void debug(Object... os) {
        System.err.println(Arrays.deepToString(os));
    }
}
