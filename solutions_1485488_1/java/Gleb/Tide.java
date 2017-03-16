package round1B;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeSet;

public class Tide implements Runnable {
    static String fileName = "round1Bdata//B-large";

    int[] dx = new int[]{0, 1, 0, -1};
    int[] dy = new int[]{1, 0, -1, 0};

    int[][] h;
    int[][] c;
    boolean[][] b;
    int m;
    int n;
    int v;

    boolean can(int x, int y, int d) {
        int a = x + dx[d];
        int b = y + dy[d];
        return h[x][y] <= c[a][b] - 50 && h[a][b] <= c[a][b] - 50 && h[a][b] <= c[x][y] - 50;
    }

    int findTime(int x, int y, int d) {
        int a = x + dx[d];
        int b = y + dy[d];
        return -c[a][b] + 50 + v;
    }

    public void run() {
        try {
            Scanner in = new Scanner(new File(fileName + ".in"));
            PrintWriter out = new PrintWriter(new File(fileName + ".out"));
            int testNum = in.nextInt();
            for (int test = 1; test <= testNum; test++) {
                v = in.nextInt();
                n = in.nextInt();
                m = in.nextInt();
                c = new int[n][m];
                for(int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        c[i][j] = in.nextInt();
                    }
                }
                h = new int[n][m];
                for(int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        h[i][j] = in.nextInt();
                    }
                }
                b = new boolean[n][m];
                TreeSet<State> times = new TreeSet<State>();
                times.add(new State(0, 0, 0));
                int res = -1;
                while (!times.isEmpty()) {
                    State s = times.pollFirst();
                    //System.out.println(s.t);
                    if (s.x == n - 1 && s.y == m - 1) {
                        res = s.t;
                        break;
                    }
                    if (b[s.x][s.y])  continue;
                    b[s.x][s.y] = true;
                    for (int i = 0; i < 4; i++) {
                        int aa = s.x + dx[i];
                        int bb = s.y + dy[i];
                        if (0 <= aa && aa < n && 0 <= bb && bb < m && can(s.x, s.y, i) && !b[aa][bb]) {
                            int t = findTime(s.x, s.y, i);
                            t = Math.max(t, s.t);
                            int dt = 0;
                            if (t > 0) {
                                if (h[s.x][s.y] + 20 <= v - t) {
                                    dt = 10;
                                } else {
                                    dt = 100;
                                }
                            }
                            times.add(new State(t + dt, aa, bb));
                        }
                    }
                }
                out.print("Case #" + test + ": ");
                out.println(1.0 * res / 10);
            }
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Thread(new Tide()).start();
    }

    class State implements Comparable<State> {
        int t;
        int x;
        int y;

        State(int tt, int xx, int yy) {
            t = tt;
            x = xx;
            y = yy;
        }
        public int compareTo(State state) {
            if (t != state.t) return t - state.t;
            if (x != state.x) return x - state.x;
            return y - state.y;
        }
    }
}
