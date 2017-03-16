package gcj2014.qual;

import java.io.*;
import java.util.*;

public class C implements Runnable {
    private static final char PROB = C.class.getSimpleName().charAt(0);
    private static boolean ENABLE_PARALLEL = true;
    private static File DIR = new File("contest/gcj2014/qual");
    private static boolean TEST_ALL = false;

    private static class Solver {
        private static final int[] di = {-1, 0, 0, 1, -1, -1, 1, 1};
        private static final int[] dj = {0, -1, 1, 0, 1, -1, 1, -1};
        private final int num;

        final int R, C, M;
        final char[][] map;

        // parse
        public Solver(final int num, final Scanner sc) {
            this.num = num;
            R = sc.nextInt();
            C = sc.nextInt();
            M = sc.nextInt();
            map = new char[R][C];
        }

        // solve
        @Override
        public String toString() {
            final int P = R * C;
            if (P > 30)
                return format(null);

            for (int i = 0; i < 1 << P; i++)
                if (Integer.bitCount(i) == M) {
                    for (int j = 0, k = 0; j < R; j++)
                        for (int l = 0; l < C; l++, k++)
                            map[j][l] = (i & 1 << k) > 0 ? '*' : '.';
                    final String res = find();
                    if (res != null)
                        return format(res);
                }

            return format("Impossible");
        }

        private String find() {
            final boolean[][] check = new boolean[R][C];
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    if (map[i][j] != '*')
                        for (int d = 0; d < 8; d++)
                            if (0 <= i + di[d] && i + di[d] < R && 0 <= j + dj[d] && j + dj[d] < C)
                                check[i][j] |= map[i + di[d]][j + dj[d]] == '*';
            final boolean[][] acc = new boolean[R][C];
            label:
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    if (map[i][j] == '.' && !check[i][j]) {
                        acc[i][j] = true;
                        final Deque<Integer> deq = new ArrayDeque<>();
                        deq.offer(i * C + j);
                        while (!deq.isEmpty()) {
                            final int p = deq.poll();
                            final int r = p / C;
                            final int c = p % C;
                            for (int d = 0; d < 8; d++) {
                                final int nr = r + di[d];
                                final int nc = c + dj[d];
                                if (0 <= nr && nr < R && 0 <= nc && nc < C)
                                    if (!acc[nr][nc]) {
                                        acc[nr][nc] = true;
                                        if (!check[nr][nc])
                                            deq.offer(nr * C + nc);
                                    }
                            }
                        }
                        for (int r = 0; r < R; r++)
                            for (int c = 0; c < C; c++)
                                if (map[r][c] != '*' && !acc[r][c])
                                    return null;
                        map[i][j] = 'c';

                        final String[] ss = new String[R];
                        for (int k = 0; k < R; k++)
                            ss[k] = new String(map[k]);
                        return String.join("\n", ss);
                    }

            int cnt = 0;
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    cnt += check[i][j] ? 1 : 0;
            if (cnt > 1)
                return null;
            debug("lonely");
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    if (check[i][j]) {
                        map[i][j] = 'c';

                        final String[] ss = new String[R];
                        for (int k = 0; k < R; k++)
                            ss[k] = new String(map[k]);
                        return String.join("\n", ss);
                    }
            throw null;
        }

        private String format(final Object result) {
            return String.format("Case #%s:\n%s", num, result);
        }
    }

    // Template
    @Override
    public void run() {
        try (final Scanner sc = new Scanner(System.in)) {
            final int T = sc.nextInt();
            final List<Solver> list = new ArrayList<>();
            for (int i = 1; i <= T; i++)
                list.add(new Solver(i, sc));
            (ENABLE_PARALLEL ? list.parallelStream() : list.stream())
                    .map((Solver s) -> s.toString())
                    .forEachOrdered((String s) -> {
                        debug(s);
                        System.out.println(s);
                    });
            debug("done.");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String... args) throws IOException {
        if (TEST_ALL) {
            for (final String input : seekInputFiles()) {
                debug("INPUT", input);
                System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR, input))));
                System.setOut(new PrintStream("contest/" + input + ".out"));
                new C().run();
            }
        } else {
            final String input = seekInputFile();
            debug("INPUT", input);
            if (input != null) {
                System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR, input))));
                System.setOut(new PrintStream("contest/" + input + ".out"));
            } else {
                ENABLE_PARALLEL = false;
                System.setOut(new PrintStream("/dev/null"));
            }
            new C().run();
        }
    }

    private static String seekInputFile() {
        final String[] names = new String[]{PROB + "-large-practice-2.in", PROB + "-large-practice-1.in",
                PROB + "-large-practice.in", PROB + "-large-2.in", PROB + "-large-1.in", PROB + "-large.in",
                PROB + "-small-practice-2.in", PROB + "-small-practice-1.in", PROB + "-small-practice.in"};
        for (final String s : names)
            if (new File(DIR, s).exists())
                return s;
        for (int k = 2; k >= 0; k--) {
            int max = -1;
            for (int i = 0; new File(DIR, PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + i + ".in").exists(); i++)
                max = i;
            if (max >= 0)
                return PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + max + ".in";
        }
        return null;
    }

    private static List<String> seekInputFiles() {
        final List<String> ret = new ArrayList<>();
        final String[] names = new String[]{PROB + "-large-practice-2.in", PROB + "-large-practice-1.in",
                PROB + "-large-practice.in", PROB + "-large-2.in", PROB + "-large-1.in", PROB + "-large.in",
                PROB + "-small-practice-2.in", PROB + "-small-practice-1.in", PROB + "-small-practice.in"};
        for (final String s : names)
            if (new File(DIR, s).exists())
                ret.add(s);
        for (int k = 2; k >= 0; k--) {
            int max = -1;
            for (int i = 0; new File(DIR, PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + i + ".in").exists(); i++)
                max = i;
            if (max >= 0)
                ret.add(PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + max + ".in");
        }
        return ret;
    }

    private static void debug(Object... os) {
        System.err.println(Arrays.deepToString(os));
    }
}
