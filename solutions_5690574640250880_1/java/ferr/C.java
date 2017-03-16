import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.time.Duration;
import java.time.LocalTime;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Roman Nefyodov
 */
public class C {

    int[][][] dp;
    char[][] result;

    int R, C, M;
    int expected;

    boolean go(int row, int col, int used) {
        if (used == expected)
            return true;
        if (row == R + 1) return false;
        if (dp[row][col][used] != -1)
            return dp[row][col][used] == 1;
        for (int j = 2; j <= col; ++j)
            if (go(row + 1, j, used + j)) {
                for (int k = 0; k < j; ++k)
                    result[row - 1][k] = '.';
                return true;
            }
        dp[row][col][used] = 0;
        return false;
    }

    int inc;


    int check_qty(int startx, int starty, int[][] power, boolean[][] visited) {
        int ans = 1;
        visited[startx][starty] = true;
        if (power[startx][starty] == 0) {
            for (int dx = -1; dx <= 1; ++dx)
                for (int dy = -1; dy <= 1; ++dy)
                    if (Math.abs(dx) + Math.abs(dy) != 0) {
                        int nx = dx + startx, ny = dy + starty;
                        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                            if (!visited[nx][ny]) {
                                ans += check_qty(nx, ny, power, visited);
                            }
                        }
                    }
        }
        return ans;
    }

    boolean verify() {
        int[][] power = new int[R][C];

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; j++)
                for (int dx = -1; dx <= 1; ++dx)
                    for (int dy = -1; dy <= 1; ++dy)
                        if (Math.abs(dx) + Math.abs(dy) != 0) {
                            int nx = dx + i, ny = dy + j;
                            if (nx >= 0 && nx < R && ny >= 0 && ny < C && result[nx][ny] == '*')
                                power[i][j]++;
                        }

        int minpower = Integer.MAX_VALUE;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (result[i][j] == '.')
                    minpower = Math.min(minpower, power[i][j]);

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; j++) {
                if (result[i][j] == '.' && power[i][j] == minpower) {
                    boolean[][] visited = new boolean[R][C];
                    boolean res = check_qty(i, j, power, visited) == R * C - M;
                    if (res) {
                        result[i][j] = 'c';
                    }
                    return res;
                }
            }
        }
        return false;
    }

    boolean go2(int x, int y, int used) {
        if (y == C) {
            return go2(x + 1, 0, used);
        }
        if (x == R) {
            if (used == M) {
                return verify();
            }
            return false;
        }

        if (used < M) {
            result[x][y] = '*';
            if (go2(x, y + 1, used + 1))
                return true;
            result[x][y] = '.';
        }
        return go2(x, y + 1, used);
    }

    public boolean solveCase(int r, int c, int m) {
        R = r;
        C = c;
        M = m;
        expected = R * C - M;

        result = new char[R][C];
        inc = 0;
        for (int i = 0; i < R; ++i) {
            Arrays.fill(result[i], '.');
        }
//        pw.println();
        if (go2(0, 0, 0)) {
            for (int i = 0; i < R; ++i)
                pw.println(result[i]);
//            pw.print("Possible");
            return true;
        } else {
            pw.print("Impossible");
            return false;
        }
    }


    public boolean solveCase0(int r, int c, int m) {
        R = r;
        C = c;
        M = m;
        expected = R * C - M;

        dp = new int[R + 1][C + 1][R * C + 1];
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[i].length; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        boolean ok = false;
        result = new char[R][C];
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                result[i][j] = '*';
        if (expected == 1) {
            ok = true;
        }
        else if (R == 1) {
            for (int i = 1; i < C - M; ++i)
                result[0][i] = '.';
            ok = true;
        } else if (C == 1) {
            for (int i = 1; i < R - M; ++i)
                result[i][0] = '.';
            ok = true;
        } else {
            for (int i = 2; i <= C; ++i)
                if (go(3, i, i * 2)) {
                    for (int k = 0; k < i; k++) {
                        result[0][k] = result[1][k] = '.';
                    }
                    ok = true;
                    break;
                }
        }
        result[0][0] = 'c';
//        pw.println(R + " " + C + " " + M);
        pw.println();
        if (!ok) {
            pw.println("Impossible");
            return false;
        } else {
            for (int i = 0; i < R; ++i)
                pw.println(result[i]);
//            pw.print("Possible");
            return true;
        }
    }

    public void solve() {
        int T = nextInt();
        for (int i = 0; i < T; ++i) {
            pw.printf("Case #%d:", i + 1);
            LocalTime start = LocalTime.now();
//            pwerr.printf("Case %d started..\n", i + 1);
            pwerr.flush();
            int R = nextInt(), C = nextInt(), M = nextInt();
            boolean r2 = solveCase0(R, C, M);
            Duration duration = Duration.between(start, LocalTime.now());
            pwerr.printf("Case %d finished (%ds)..\n", i + 1, duration.getSeconds());
            pwerr.flush();
            pw.flush();
        }
    }

    public static void main(String[] args) {
        new C().run(args);
    }

    public void run(String[] args) {
        try {
            if (args.length == 1) {
                String filename = args[0];
                in = new BufferedReader(new FileReader(filename + ".in.txt"));
                pw = new PrintWriter(filename + ".out.txt");
            } else {
                in = new BufferedReader(new InputStreamReader(System.in));
                pw = new PrintWriter(System.out);
            }
            pwerr = new PrintWriter(System.err);
            st = new StringTokenizer("");
            solve();
            pw.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    private StringTokenizer st;
    private BufferedReader in;
    private PrintWriter pw;
    private PrintWriter pwerr;

    int curCase;

    boolean hasNext() {
        try {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null)
                    return false;
                st = new StringTokenizer(line);
            }
            return st.hasMoreTokens();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    String next() {
        return hasNext() ? st.nextToken() : null;
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }
}

