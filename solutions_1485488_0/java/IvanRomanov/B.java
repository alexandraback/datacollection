import com.sun.xml.internal.bind.v2.TODO;

import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class B {

    private int n;
    private int m;
    private int h;
    private int[][] ceil;
    private int[][] floor;
    private boolean[][] reachable;
    private static final double EPS = 1e-8;

    private String solve() throws IOException {
        h = nextInt();
        n = nextInt();
        m = nextInt();
        ceil = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ceil[i][j] = nextInt();
            }
        }
        floor = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                floor[i][j] = nextInt();
            }
        }
        reachable = new boolean[n][m];
        rec(0, 0);
        if (reachable[n - 1][m - 1]) {
            return "0.0";
        }
        double ans = Double.POSITIVE_INFINITY;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (reachable[i][j]) {
                    double res = calc(i, j);
                    ans = Math.min(ans, res);
                }
            }
        }
        return String.format("%.6f", ans);
    }

    private double calc(int si, int sj) {
        double[][] d = new double[n][m];
        boolean[][] was = new boolean[n][m];
        for (double[] v : d) {
            for (int i = 0; i < v.length; i++) {
                v[i] = Double.POSITIVE_INFINITY;
            }
        }
        d[si][sj] = 0.0;
        while (true) {
            double time = Double.POSITIVE_INFINITY;
            int pi = -1;
            int pj = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!was[i][j] && time > d[i][j]) {
                        time = d[i][j];
                        pi = i;
                        pj = j;
                    }
                }
            }
            if (pi < 0) {
                break;
            }
            was[pi][pj] = true;
            double h = this.h - 10 * time;
            double oneMoreTime = Double.POSITIVE_INFINITY;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if ((di == 0) ^ (dj == 0)) {
                        // You can never move off the edge of the map.
                        if (pi + di >= 0 && pi + di < n && pj + dj >= 0 && pj + dj < m) {
                            // The floor height of the adjacent square must be at least 50 centimeters below
                            // the ceiling height of your current square as well.
                            if (floor[pi + di][pj + dj] + 50 - EPS <= ceil[pi][pj]) {

                                // The water level, the floor height of your current square,
                                // and the floor height of the adjacent square must all be at least 50 centimeters lower
                                // than the ceiling height of the adjacent square.
                                int constLevel = Math.max(floor[pi][pj], floor[pi + di][pj + dj]);
                                double max = Math.max(h, constLevel);
                                if (max + 50 - EPS <= ceil[pi + di][pj + dj]) {
                                    // When moving from one square to another, if there are at least 20 centimeters of
                                    // water remaining on the current square when you start moving from it,
                                    // it takes 1 second to complete the move (you can use your kayak)
                                    int seconds;
                                    if (floor[pi][pj] + 20 - EPS <= h) {
                                        seconds = 1;
                                    } else {
                                        // Otherwise, it takes 10 seconds (you have to drag your kayak).
                                        seconds = 10;
                                    }
                                    d[pi + di][pj + dj] = Math.min(d[pi + di][pj + dj], d[pi][pj] + seconds);
                                } else {
                                    int waterLevel = ceil[pi + di][pj + dj] - 50;
                                    if (waterLevel >= constLevel) {
                                        double nextTime = (this.h - waterLevel) * 0.1;
                                        if (nextTime > time) {
                                            oneMoreTime = Math.min(oneMoreTime, nextTime);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!Double.isInfinite(oneMoreTime)) {
                was[pi][pj] = false;
                d[pi][pj] = oneMoreTime;
            }
        }
        return d[n - 1][m - 1];
    }

    private void rec(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return;
        }
        if (!reachable[i][j]) {
            reachable[i][j] = true;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if ((di == 0) ^ (dj == 0)) {
                        // You can never move off the edge of the map.
                        if (i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m) {
                            // The water level, the floor height of your current square,
                            // and the floor height of the adjacent square must all be at least 50 centimeters lower
                            // than the ceiling height of the adjacent square.
                            int max = Math.max(h, Math.max(floor[i][j], floor[i + di][j + dj]));
                            if (max + 50 <= ceil[i + di][j + dj]) {
                                // The floor height of the adjacent square must be at least 50 centimeters below
                                // the ceiling height of your current square as well.
                                if (floor[i + di][j + dj] + 50 <= ceil[i][j]) {
                                    rec(i + di, j + dj);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        Locale.setDefault(Locale.US);
        String problem = "B-small-attempt0";
        reader = new BufferedReader(new FileReader(problem + ".in"));
        PrintWriter writer = new PrintWriter(new File(problem + ".out"));
        try {
            int n = nextInt();
            for (int tc = 1; tc <= n; tc++) {
                writer.print("Case #" + tc + ": ");
                writer.println(solve());
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new B().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}