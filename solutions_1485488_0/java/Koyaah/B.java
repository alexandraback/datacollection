import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * User: Igor Kirov
 * Date: 05.05.12
 */
public class B implements Runnable {
    int[][] up, down;
    int h, n, m;
    int[][] d;

    int[] dx = new int[]{-1, 0, 1, 0};
    int[] dy = new int[]{0, -1, 0, 1};

    class Cell {
        int i;
        int j;
    }

    private boolean invalid(int i, int j) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    private boolean ok(int i, int j, int ii, int jj, int h) {
        int r1 = up[ii][jj] - h;
        if (r1 < 50) {
            return false;
        }
        int r2 = up[ii][jj] - down[i][j];
        if (r2 < 50) {
            return false;
        }
        int r3 = up[ii][jj] - down[ii][jj];
        if (r3 < 50) {
            return false;
        }
        int r4 = up[i][j] - down[ii][jj];
        if (r4 < 50) {
            return false;
        }
        return true;
    }

    private void dfs(int i, int j, boolean[][] used) {
        used[i][j] = true;
        for (int dir = 0; dir < 4; dir++) {
            int ii = i + dx[dir];
            int jj = j + dy[dir];
            if (invalid(ii, jj)) {
                continue;
            }
            if (used[ii][jj]) {
                continue;
            }
            if (ok(i, j, ii, jj, h)) {
                d[ii][jj] = 0;
                dfs(ii, jj, used);
            }
        }
    }

    private Cell getMin(boolean[][] used) {
        int min = Integer.MAX_VALUE;
        Cell ret = null;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!used[i][j] && d[i][j] < min) {
                    min = d[i][j];
                    ret = new Cell();
                    ret.i = i;
                    ret.j = j;
                }
            }
        }
        return ret;
    }

    //todo faster
    private int fit(int i, int j, int ii, int jj, int curh) {
        if (curh <= 0) {
            if (ok(i, j, ii, jj, 0)) {
                return 100;
            }
        }
        for (int hh = curh; hh >= 0; hh--) {
            if (ok(i, j, ii, jj, hh)) {
                int r = hh - down[i][j];
                if (r >= 20) {
                    return curh - hh + 10;
                } else {
                    return curh - hh + 100;
                }
            }
        }
        return Integer.MIN_VALUE;
    }

    private void solve() throws Exception {
        h = nextInt();
        n = nextInt();
        m = nextInt();

        up = new int[n][m];
        down = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                up[i][j] = nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                down[i][j] = nextInt();
            }
        }

        d = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[i][j] = Integer.MAX_VALUE;
            }
        }
        d[0][0] = 0;
        boolean[][] used = new boolean[n][m];
        dfs(0, 0, used);

        if (d[n - 1][m - 1] == 0) {
            writer.println("0.0");
            return;
        }

        used = new boolean[n][m];
        while (true) {
            Cell k = getMin(used);
            if (k == null) {
                break;
            }
            used[k.i][k.j] = true;
            for (int dir = 0; dir < 4; dir++) {
                int ii = k.i + dx[dir];
                int jj = k.j + dy[dir];
                if (invalid(ii, jj)) {
                    continue;
                }
                if (used[ii][jj]) {
                    continue;
                }
                int curh = h - d[k.i][k.j];
                int fith = fit(k.i, k.j, ii, jj, curh);
                if (fith == Integer.MIN_VALUE) {
                    continue;
                }
                if (fith + d[k.i][k.j] < d[ii][jj]) {
                    d[ii][jj] = fith + d[k.i][k.j];
                }
            }
        }

        writer.printf("%.1f", (d[n - 1][m - 1] * 1.0 / 10));
        writer.println();
    }

    public static void main(String[] args) {
        new Thread(null, new B(), "", 64 * 1024 * 1024).start();
    }

    StringTokenizer tokenizer;
    BufferedReader reader;
    PrintWriter writer;

    public void run() {
        try {
            try {
                Locale.setDefault(Locale.US);
            } catch (Exception ignored) {
            }

            reader = new BufferedReader(new FileReader("/home/useruser/datacollection/input/1485488_0.in"));
            writer = new PrintWriter(new FileWriter("B.out"));
            tokenizer = null;

            int tests = nextInt();
            for (int i = 0; i < tests; i++) {
                writer.printf("Case #%d: ", i + 1);
                solve();
                writer.flush();
            }

            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private BigInteger nextBigInteger() throws IOException {
        return new BigInteger(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}