import java.io.*;
import java.util.Comparator;
import java.util.Locale;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class GCJ2012Round1B_B {

    private int[][] time;
    private int[][] floor;
    private int[][] ceiling;

    public void run() throws IOException {
        int T = nextInt();
        for (int i = 1; i <= T; ++i) {
            int t = solve();
            out.println("Case #" + i + ": " + t/10 + '.' + t%10);
        }
    }

    private int solve() throws IOException {
        int H = nextInt();
        int N = nextInt();
        int M = nextInt();
        floor = new int[N][M];
        ceiling = new int[N][M];

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                ceiling[i][j] = nextInt();
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                floor[i][j] = nextInt();
            }
        }

        time = new int[N][M];

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                time[i][j] = Integer.MAX_VALUE;
            }
        }

        PriorityQueue<Integer> Q = new PriorityQueue<Integer>(1, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                int a = time[o1/100][o1%100];
                int b = time[o2/100][o2%100];
                return a - b;
            }
        });

        boolean[][] vis = new boolean[N][M];

        time[0][0] = 0;
        Q.add(0);
        while (true) {
            int p = Q.remove();
            int x = p/100;
            int y = p%100;
            if (vis[x][y]) {
                continue;
            }
            vis[x][y] = true;
            int t = time[x][y];
            if (x == N - 1 && y == M - 1) {
                return t;
            }
            int h = Math.max(0, H - t);
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if ((dx == 0 || dy == 0) && (dx != 0 || dy != 0)) {
                        if (x + dx >= 0 && x + dx < N && y + dy >= 0 && y + dy < M) {
                            if (passable(x, y, x + dx, y + dy)) {
                                int d = Math.max(0, h - (ceiling[x + dx][y + dy] - 50));
                                if (t + d == 0) {
                                    if (time[x + dx][y + dy] > 0) {
                                        time[x + dx][y + dy] = 0;
                                        Q.add((x + dx)*100 + y + dy);
                                    }
                                }
                                else if (floor[x][y] + 20 <= h - d) {
                                    if (time[x + dx][y + dy] > t + d + 10) {
                                        time[x + dx][y + dy] = t + d + 10;
                                        Q.add((x + dx)*100 + y + dy);
                                    }
                                }
                                else {
                                    if (time[x + dx][y + dy] > t + d + 100) {
                                        time[x + dx][y + dy] = t + d + 100;
                                        Q.add((x + dx)*100 + y + dy);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    private boolean passable(int x1, int y1, int x2, int y2) {
        int f1 = floor[x1][y1];
        int f2 = floor[x2][y2];
        int c1 = ceiling[x1][y1];
        int c2 = ceiling[x2][y2];
        if (f2 + 50 > c2) {
            return false;
        }
        if (f1 + 50 > c2) {
            return false;
        }
        if (f2 + 50 > c1) {
            return false;
        }
        return true;
    }

    public static BufferedReader in;
    public static PrintStream out;

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);

        String className = GCJ2012Round1B_B.class.getSimpleName();
        char lastChar = className.charAt(className.length() - 1);
        System.setIn(new FileInputStream(lastChar + ".in"));
        System.setOut(new PrintStream(lastChar + ".out"));

        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintStream(new BufferedOutputStream(System.out));

        new GCJ2012Round1B_B().run();

        out.close();
    }

    public static StringTokenizer tokenizer;

    public static String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(in.readLine());
        }
        return tokenizer.nextToken();
    }

    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}
