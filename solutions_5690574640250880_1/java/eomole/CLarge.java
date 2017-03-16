package gcj2014.qual;

import java.io.*;
import java.util.*;

public class CLarge implements Runnable {
    private static final char PROB = CLarge.class.getSimpleName().charAt(0);
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
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    map[i][j] = '.';
        }

        // solve
        @Override
        public String toString() {
            int m = M;
            for (int i = R - 1; i >= 3 && m > 0; i--)
                for (int j = C - 1; j >= 3 && m > 0; j--, m--)
                    map[i][j] = '*';
            for (int i = R - 1; i >= 3 && m > 0; i--)
                if (m == Math.min(C - 1, 2)) {
                    map[i][m] = '*';
                    m--;
                } else
                    for (int j = Math.min(C - 1, 2); j >= 0 && m > 0; j--, m--)
                        map[i][j] = '*';
            for (int j = C - 1; j >= 3 && m > 0; j--)
                if (m == Math.min(R - 1, 2)) {
                    map[m][j] = '*';
                    m--;
                } else
                    for (int i = Math.min(R - 1, 2); i >= 0 && m > 0; i--, m--)
                        map[i][j] = '*';

            final String ans = find(m);
            return ans == null ? format("Impossible") : format(ans);
        }

        private String find(final int MM) {
            final int RR = Math.min(R, 3);
            final int CC = Math.min(C, 3);
            final int P = RR * CC;
            loop:
            for (int pat = 0; pat < 1 << P; pat += 2)
                if (Integer.bitCount(pat) == MM) {
                    for (int j = 0, k = 0; j < RR; j++)
                        for (int l = 0; l < CC; l++, k++)
                            map[j][l] = (pat & 1 << k) > 0 ? '*' : '.';
                    final boolean[][] check = new boolean[R][C];
                    for (int i = 0; i < R; i++)
                        for (int j = 0; j < C; j++)
                            if (map[i][j] != '*')
                                for (int d = 0; d < 8; d++)
                                    if (0 <= i + di[d] && i + di[d] < R && 0 <= j + dj[d] && j + dj[d] < C)
                                        check[i][j] |= map[i + di[d]][j + dj[d]] == '*';
                    final boolean[][] acc = new boolean[R][C];
                    if (!check[0][0]) {
                        acc[0][0] = true;
                        final Deque<Integer> deq = new ArrayDeque<>();
                        deq.offer(0);
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
                                    continue loop;

                        return build();
                    }

                    int cnt = 0;
                    for (int i = 0; i < R; i++)
                        for (int j = 0; j < C; j++)
                            cnt += check[i][j] ? 1 : 0;
                    if (cnt > 1)
                        continue loop;

                    debug("lonely");
                    return build();
                }
            return null;
        }

        private String build() {
            map[0][0] = 'c';
            final String[] ss = new String[R];
            for (int k = 0; k < R; k++)
                ss[k] = new String(map[k]);
            return String.join("\n", ss);
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
                System.setOut(new PrintStream("contest/" + input + ".large.out"));
                new CLarge().run();
            }
            ENABLE_PARALLEL = false;
            System.setIn(new BufferedInputStream(new FileInputStream("/dev/stdin")));
            System.setOut(new PrintStream("/dev/null"));
            new CLarge().run();
        } else {
            final String input = seekInputFile();
            debug("INPUT", input);
            if (input != null) {
                System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR, input))));
                System.setOut(new PrintStream("contest/" + input + ".large.out"));
            } else {
                ENABLE_PARALLEL = false;
                System.setOut(new PrintStream("/dev/null"));
            }
            new CLarge().run();
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

        for (int k = 2; k >= 0; k--)
            for (int i = 0; new File(DIR, PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + i + ".in").exists(); i++)
                ret.add(PROB + "-small" + (k > 0 ? "-" + k : "") + "-attempt" + i + ".in");
        return ret;
    }

    private static void debug(Object... os) {
        System.err.println(Arrays.deepToString(os));
    }
}
