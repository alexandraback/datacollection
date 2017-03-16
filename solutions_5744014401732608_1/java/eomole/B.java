package gcj2016.r1c;

import java.util.Arrays;
import java.util.BitSet;
import java.util.Iterator;
import java.util.Scanner;

public class B {
    private static final double EPS = 1e-12;
    private static final int INF = 1 << 20;
    private static final int[] di = {-1, 0, 0, 1};
    private static final int[] dj = {0, -1, 1, 0};

    // shared table
    static {
        // :TODO
    }

    final int B;
    final long M;
    final static String possible = "POSSIBLE";
    final static String impossible = "IMPOSSIBLE";

    // parse
    public B(final Scanner sc) {
        B = sc.nextInt();
        M = sc.nextLong();
    }

    // solve
    @Override
    public String toString() {
        if (M > 1L << B - 2)
            return impossible;
        final boolean[][] m = new boolean[B][B];
        for (int i = 0; i < B; i++)
            for (int j = i + 1; j < B - 1; j++)
                m[i][j] = true;
        if (M == 1L << B - 2)
            for (int i = 0; i < B - 1; i++)
                m[i][B - 1] = true;
        else
            for (int i = 1; i < B - 1; i++)
                m[i][B - 1] = (M & 1L << i - 1) > 0;
        validate(m);
        final StringBuilder sb = new StringBuilder(possible);
        for (final boolean[] bs : m) {
            sb.append('\n');
            for (final boolean b : bs)
                sb.append(b ? '1' : '0');
        }
        return sb.toString();
    }

    public void validate(final boolean[][] m) {
        final long[] nums = new long[B];
        nums[0] = 1;
        for(int j = 1; j < B; j++)
            for(int i = 0; i < j; i++)
                if(m[i][j])
                    nums[j] += nums[i];
        if(nums[B - 1] != M) {
            debug(B, M, nums);
            throw null;
        }
    }

    // Template
    public static void main(String... args) throws Exception {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final Object[] solvers = new Object[T];
            for (int i = 0; i < T; i++)
                solvers[i] = new B(sc);
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
