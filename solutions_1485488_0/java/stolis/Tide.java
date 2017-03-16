package round1;

import java.awt.Point;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Tide {
    static int T;
    static int H;
    static int N;
    static int M;
    static int[][] ceiling;
    static int[][] floor;
    static int[][] time;
    static boolean[][] done;
    static int[] results;

    public static void main(String[] args) throws IOException {
        read();
        write();
    }

    static void read() throws IOException {
        File input = new File("input.txt");
        Scanner scanner = new Scanner(input);
        T = scanner.nextInt();
        results = new int[T];
        for (int t=0; t<T; t++) {
            H = scanner.nextInt();
            N = scanner.nextInt();
            M = scanner.nextInt();
            ceiling = new int[N][M];
            floor = new int[N][M];
            time = new int[N][M];
            done = new boolean[N][M];
            for (int n=0; n<N; n++) {
                for (int m=0; m<M; m++) {
                    ceiling[n][m] = scanner.nextInt();
                    time[n][m] = Integer.MAX_VALUE;
                }
            }
            for (int n=0; n<N; n++) {
                for (int m=0; m<M; m++) {
                    floor[n][m] = scanner.nextInt();
                }
            }
            process(t);
        }
    }

    static int[][] steps = new int[][] {{1,0},{0,1},{-1,0},{0,-1}};
    static void process(int t) {
        List<Point> cands = new LinkedList<Point>();
        time[0][0] = 0;
        cands.add(new Point());
        while (true) {
            Point best = null;
            for (Point p : cands) {
                if (best == null) {
                    best = p;
                } else if (time[p.x][p.y] < time[best.x][best.y]) {
                    best = p;
                }
            }

            done[best.x][best.y] = true;
            cands.remove(best);

            if (best.x == N-1 && best.y == M-1) {
                results[t] = time[best.x][best.y];
                return;
            }

            for (int[] step : steps) {
                int x = best.x+step[0];
                int y = best.y+step[1];
                if (x<0 || x>=N) continue;
                if (y<0 || y>=M) continue;
                if (done[x][y]) continue;
                if (ceiling[best.x][best.y]<50+floor[x][y]) continue;
                if (ceiling[x][y]<50+floor[best.x][best.y]) continue;
                if (ceiling[x][y]<50+floor[x][y]) continue;
                int current = H-time[best.x][best.y];
                int when = 50-(ceiling[x][y]-current);
                if (when <= 0) {
                    if (time[best.x][best.y] == 0) {
                        // special case
                        time[x][y] = 0;
                        Point cand = new Point(x,y);
                        if (!cands.contains(cand)) {
                            cands.add(cand);
                        }
                    } else {
                        int delta = (current-floor[best.x][best.y] >= 20) ? 10 : 100;
                        int candTime = time[best.x][best.y]+delta;
                        if (time[x][y] > candTime) {
                            time[x][y] = candTime;
                            Point cand = new Point(x,y);
                            if (!cands.contains(cand)) {
                                cands.add(cand);
                            }
                        }
                    }
                } else {
                    int delta = (current-when-floor[best.x][best.y] >= 20) ? 10 : 100;
                    int candTime = time[best.x][best.y]+delta+when;
                    if (time[x][y] > candTime) {
                        time[x][y] = candTime;
                        Point cand = new Point(x,y);
                        if (!cands.contains(cand)) {
                            cands.add(cand);
                        }
                    }
                }
            }
        }
    }

    static void write() throws IOException {
        File output = new File("output.txt");
        PrintWriter pw = new PrintWriter(output);

        for (int t=0; t<T; t++) {
            pw.println("Case #"+(t+1)+": "+(results[t]/10.0));
        }

        pw.close();
    }

}
