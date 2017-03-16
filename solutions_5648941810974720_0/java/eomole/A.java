package gcj2016.r1b;

import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

public class A {
    private static int[][] tbl = new int[10][];

    static int[] cnt(String s) {
        final int[] r = new int[128];
        for (int i = 0; i < s.length(); i++)
            r[s.charAt(i)]++;
        return r;
    }

    static void sub(int[] self, int[] op, int k) {
        for (int i = 0; i < 128; i++)
            self[i] -= k * op[i];
    }

    // shared table
    static {
        tbl[0] = cnt("ZERO");
        tbl[1] = cnt("ONE");
        tbl[2] = cnt("TWO");
        tbl[3] = cnt("THREE");
        tbl[4] = cnt("FOUR");
        tbl[5] = cnt("FIVE");
        tbl[6] = cnt("SIX");
        tbl[7] = cnt("SEVEN");
        tbl[8] = cnt("EIGHT");
        tbl[9] = cnt("NINE");
    }

    private char[] s;

    // parse
    public A(final Scanner sc) {
        s = sc.next().toCharArray();
    }

    // solve
    @Override
    public String toString() {
        final int[] cnt = new int[128];
        for (final char c : s)
            cnt[c]++;
        final int[] nums = new int[10];
        // stage 1
        sub(cnt, tbl[0], nums[0] = cnt['Z']);
        sub(cnt, tbl[2], nums[2] = cnt['W']);
        sub(cnt, tbl[4], nums[4] = cnt['U']);
        sub(cnt, tbl[6], nums[6] = cnt['X']);
        sub(cnt, tbl[8], nums[8] = cnt['G']);
        // stage 2
        sub(cnt, tbl[1], nums[1] = cnt['O']);
        sub(cnt, tbl[3], nums[3] = cnt['T']);
        sub(cnt, tbl[5], nums[5] = cnt['F']);
        sub(cnt, tbl[7], nums[7] = cnt['S']);
        // stage 3
        sub(cnt, tbl[9], nums[9] = cnt['I']);

        for(int i = 0; i < 128; i++)
            if(cnt[i] > 0)
                throw null;

        final StringBuilder sb = new StringBuilder();
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < nums[i]; j++)
                sb.append(i);

        return sb.toString();
    }

    // Template
    public static void main(String... args) throws Exception {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final Object[] solvers = new Object[T];
            for (int i = 0; i < T; i++)
                solvers[i] = new A(sc);
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
