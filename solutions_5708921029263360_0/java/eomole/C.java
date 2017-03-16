package gcj2016.r1c;

import java.util.*;

public class C {
    final int J, P, S, K;

    // parse
    public C(final Scanner sc) {
        J = sc.nextInt();
        P = sc.nextInt();
        S = sc.nextInt();
        K = sc.nextInt();
    }

    // solve
    @Override
    public String toString() {
        int max = 0;
        int argmax = 0;
        for (int i = 1; i < 1 << J * P * S; i++)
            if (Integer.bitCount(i) > max && check(i)) {
                max = Integer.bitCount(i);
                argmax = i;
            }
        final StringBuilder sb = new StringBuilder().append(max);
        for (int i = 0, b = 1; b <= argmax; i++, b <<= 1)
            if ((argmax & b) > 0) {
                final int j = i / P / S + 1;
                final int p = i / S % P + 1;
                final int s = i % S + 1;
                sb.append('\n').append(j).append(' ').append(p).append(' ').append(s);
            }
        return sb.toString();
    }

    boolean check(int mask) {
        final HashMap<Integer, Integer> JP = new HashMap<>();
        final HashMap<Integer, Integer> PS = new HashMap<>();
        final HashMap<Integer, Integer> SJ = new HashMap<>();
        for (int i = 0, b = 1; b <= mask; i++, b <<= 1)
            if ((mask & b) > 0) {
                final int j = i / P / S;
                final int p = i / S % P;
                final int s = i % S;
                final int jp = j * P + p;
                final int ps = p * S + s;
                final int sj = s * J + j;
                JP.putIfAbsent(jp, 0);
                PS.putIfAbsent(ps, 0);
                SJ.putIfAbsent(sj, 0);
                if (JP.get(jp) == K || PS.get(ps) == K || SJ.get(sj) == K)
                    return false;
                JP.compute(jp, (k, v) -> v + 1);
                PS.compute(ps, (k, v) -> v + 1);
                SJ.compute(sj, (k, v) -> v + 1);
            }

        return true;
    }

    // Template
    public static void main(String... args) throws Exception {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final Object[] solvers = new Object[T];
            for (int i = 0; i < T; i++)
                solvers[i] = new C(sc);
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
