import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class b {
    public static class E implements Comparable<E> {
        public int h;
        public int x;
        public int y;

        public E (int h, int x, int y) {
            this.h = h;
            this.x = x;
            this.y = y;
        }

        public int compareTo(E e) {
            return e.h - h;
        }

        public boolean equals(Object o) {
            return h == ((E) o).h;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));

        int T = sc.nextInt();

        for (int casenumber = 1; casenumber <= T; ++casenumber) {

            int H = sc.nextInt();
            int N = sc.nextInt();
            int M = sc.nextInt();

            int[][] c = new int[N][M];
            int[][] f = new int[N][M];

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    c[i][j] = sc.nextInt();
                }
            }

            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    f[i][j] = sc.nextInt();
                }
            }

            int[][] best = new int[N][M];
            best[N - 1][M - 1] = -1;
            boolean[][] visited = new boolean[N][M];

            PriorityQueue<E> pq = new PriorityQueue<E>();
            pq.offer(new E(H, 0, 0));

            while (!pq.isEmpty()) {
                E e = pq.poll();

                // System.out.format("   %d %d %d%n", e.h, e.x, e.y);

                if (visited[e.x][e.y]) continue;
                visited[e.x][e.y] = true;
                best[e.x][e.y] = e.h;

                int x_ = 0;
                int y_ = 0;

                x_ = e.x + 1;
                y_ = e.y;
                if (0 <= x_ && x_ < N && 0 <= y_ && y_ < M) {
                    if (!visited[x_][y_] && (c[x_][y_] - f[x_][y_] >= 50) && (c[x_][y_] - f[e.x][e.y] >= 50) && (c[e.x][e.y] - f[x_][y_] >= 50)) {
                        int h_ = Math.min(e.h, c[x_][y_] - 50);
                        if (h_ == H) {
                            pq.offer(new E(H, x_, y_));
                        } else {
                            if (h_ - f[e.x][e.y] >= 20) {
                                pq.offer(new E(h_ - 10, x_, y_));
                            } else {
                                pq.offer(new E(h_ - 100, x_, y_));
                            }
                        }
                    }
                }

                x_ = e.x - 1;
                y_ = e.y;
                if (0 <= x_ && x_ < N && 0 <= y_ && y_ < M) {
                    if (!visited[x_][y_] && (c[x_][y_] - f[x_][y_] >= 50) && (c[x_][y_] - f[e.x][e.y] >= 50) && (c[e.x][e.y] - f[x_][y_] >= 50)) {
                        int h_ = Math.min(e.h, c[x_][y_] - 50);
                        if (h_ == H) {
                            pq.offer(new E(H, x_, y_));
                        } else {
                            if (h_ - f[e.x][e.y] >= 20) {
                                pq.offer(new E(h_ - 10, x_, y_));
                            } else {
                                pq.offer(new E(h_ - 100, x_, y_));
                            }
                        }
                    }
                }

                x_ = e.x;
                y_ = e.y + 1;
                if (0 <= x_ && x_ < N && 0 <= y_ && y_ < M) {
                    if (!visited[x_][y_] && (c[x_][y_] - f[x_][y_] >= 50) && (c[x_][y_] - f[e.x][e.y] >= 50) && (c[e.x][e.y] - f[x_][y_] >= 50)) {
                        int h_ = Math.min(e.h, c[x_][y_] - 50);
                        if (h_ == H) {
                            pq.offer(new E(H, x_, y_));
                        } else {
                            if (h_ - f[e.x][e.y] >= 20) {
                                pq.offer(new E(h_ - 10, x_, y_));
                            } else {
                                pq.offer(new E(h_ - 100, x_, y_));
                            }
                        }
                    }
                }

                x_ = e.x;
                y_ = e.y - 1;
                if (0 <= x_ && x_ < N && 0 <= y_ && y_ < M) {
                    if (!visited[x_][y_] && (c[x_][y_] - f[x_][y_] >= 50) && (c[x_][y_] - f[e.x][e.y] >= 50) && (c[e.x][e.y] - f[x_][y_] >= 50)) {
                        int h_ = Math.min(e.h, c[x_][y_] - 50);
                        if (h_ == H) {
                            pq.offer(new E(H, x_, y_));
                        } else {
                            if (h_ - f[e.x][e.y] >= 20) {
                                pq.offer(new E(h_ - 10, x_, y_));
                            } else {
                                pq.offer(new E(h_ - 100, x_, y_));
                            }
                        }
                    }
                }

            }

            int result = H - best[N - 1][M - 1];

            System.out.format("Case #%d: %d.%d%n", casenumber, result / 10, result % 10);
        }
    }
}
