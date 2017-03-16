import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class TaskCSmall {
    private static int n;
    private static int m;

    private static long[] a, b;
    private static int[] A, B;

    private static Map<State, Long> dp;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int tests = scanner.nextInt();
        for (int test = 1; test <= tests; test++) {
            n = scanner.nextInt();
            m = scanner.nextInt();

            a = new long[n + 1];
            A = new int[n];
            b = new long[m + 1];
            B = new int[m];

            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextLong();
                A[i] = scanner.nextInt();
            }
            for (int i = 0; i < m; i++) {
                b[i] = scanner.nextLong();
                B[i] = scanner.nextInt();
            }

            dp = new HashMap<State, Long>();

            System.out.printf("Case #%d: %d", test, get(new State(0, 0, a[0], b[0])));
            System.out.println();
        }

        scanner.close();
    }

    private static long get(State state) {
        int p1 = state.getP1();
        int p2 = state.getP2();

        if (p1 >= n || p2 >= m) {
            return 0;
        }

        if (dp.containsKey(state)) {
            return dp.get(state);
        }

        long result;

        if (A[p1] == B[p2]) {
            long c1 = state.getC1();
            long c2 = state.getC2();

            result = Math.min(c1, c2);

            if (c1 < c2) {
               result += get(new State(p1 + 1, p2, a[p1 + 1], state.getC2() - c1));
            } else if (c1 > c2) {
                result += get(new State(p1, p2 + 1, state.getC1() - c2, b[p2 + 1]));
            } else {
                result += get(new State(p1 + 1, p2 + 1, a[p1 + 1], b[p2 + 1]));
            }
        } else {
            long t1 = get(new State(p1 + 1, p2, a[p1 + 1], state.getC2()));
            long t2 = get(new State(p1, p2 + 1, state.getC1(), b[p2 + 1]));

            result = Math.max(t1, t2);
        }

        dp.put(state, result);

        return result;
    }

    private static class State {
        private final int p1;
        private final int p2;
        private final long c1;
        private final long c2;

        private State(int p1, int p2, long c1, long c2) {
            this.p1 = p1;
            this.p2 = p2;
            this.c1 = c1;
            this.c2 = c2;
        }

        public int getP1() {
            return p1;
        }

        public int getP2() {
            return p2;
        }

        public long getC1() {
            return c1;
        }

        public long getC2() {
            return c2;
        }

        @SuppressWarnings("RedundantIfStatement")
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            State state = (State) o;

            if (c1 != state.c1) return false;
            if (c2 != state.c2) return false;
            if (p1 != state.p1) return false;
            if (p2 != state.p2) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = p1;
            result = 31 * result + p2;
            result = 31 * result + (int) (c1 ^ (c1 >>> 32));
            result = 31 * result + (int) (c2 ^ (c2 >>> 32));
            return result;
        }
    }
}
