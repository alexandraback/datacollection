import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class C {
    private final int N, M;
    private final String[] zip;
    private final boolean[][] table;

    // parse
    public C(final Scanner sc) {
        N = sc.nextInt();
        M = sc.nextInt();
        zip = new String[N];
        for (int i = 0; i < N; i++)
            zip[i] = sc.next();
        table = new boolean[N][N];
        for (int i = 0; i < M; i++) {
            final int s = sc.nextInt() - 1;
            final int t = sc.nextInt() - 1;
            table[s][t] = true;
            table[t][s] = true;
        }
    }

    // solve
    @Override
    public String toString() {
        final int[] order = IntStream.range(0, N).toArray();
        String min = "~";
        do {
            if (check(order)) {
                final StringBuilder sb = new StringBuilder();
                for (final int i : order)
                    sb.append(zip[i]);
                final String res = sb.toString();
                if (min.compareTo(res) > 0)
                    min = res;
            }
        } while (nextPermutation(order));
        return min;
    }

    private boolean check(final int[] order) {
        final Deque<Integer> deq = new ArrayDeque<>();
        deq.push(order[0]);
        for (int nid = 1; nid < N; nid++) {
            while (!table[deq.peek()][order[nid]]) {
                deq.pop();
                if (deq.isEmpty())
                    return false;
            }
            deq.push(order[nid]);
        }
        return true;
    }

    private static boolean nextPermutation(final int[] is) {
        final int n = is.length;
        for (int i = n - 1; i > 0; i--) {
            if (is[i - 1] < is[i]) {
                int j = n;
                while (is[i - 1] >= is[--j])
                    ;
                swap(is, i - 1, j);
                rev(is, i, n);
                return true;
            }
        }
        rev(is, 0, n);
        return false;
    }

    private static void swap(final int[] is, final int i, final int j) {
        int t = is[i];
        is[i] = is[j];
        is[j] = t;
    }

    private static void rev(final int[] is, int s, int t) {
        while (s < --t)
            swap(is, s++, t);
    }

    // Template
    public static void main(String... args) throws Exception {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final Object[] solvers = new Object[T];
            for (int i = 0; i < T; i++)
                solvers[i] = new C(sc);
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
