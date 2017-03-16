package gcj2012.r1.b;

import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.LinkedList;
import java.util.Scanner;

public class B_Tide_Goes_In_Tide_Goes_Out {

    private static boolean SMALL = false;
    private static String PROBLEM = "B";

    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(new File(String.format("%s-%s.in", PROBLEM, (SMALL ? "small" : "large"))));
            PrintWriter pw = new PrintWriter(new File(String.format("%s-%s.out", PROBLEM, (SMALL ? "small" : "large"))));

            int NUM_CASES = scan.nextInt();
            scan.nextLine();
            System.out.println(String.format("%d test cases:", NUM_CASES));
            long start = System.currentTimeMillis(), t1, left;
            for (int CASE = 1; CASE <= NUM_CASES; ++CASE) {
                t1 = System.currentTimeMillis();
                System.out.print(String.format("%d.[%s] ", CASE, new SimpleDateFormat("HH:mm:ss.SSS").format(new Date(t1))));

                final int H = scan.nextInt(), N = scan.nextInt(), M = scan.nextInt();
                final int[][] ceiling = new int[N][M], floor = new int[N][M];
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < M; ++j) {
                        ceiling[i][j] = scan.nextInt();
                    }
                }
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < M; ++j) {
                        floor[i][j] = scan.nextInt();
                    }
                }
                final String res = String.format("%.12f", solve(H, N, M, ceiling, floor));

                pw.println(String.format("Case #%d: %s", CASE, res));
                left = (System.currentTimeMillis() - start) * (NUM_CASES - CASE) / CASE;
                System.out.println(String.format("%s (%dms, ~%dms left)", res, (System.currentTimeMillis() - t1), left));
            }
            pw.close();
            scan.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private final static double BIG_NUMBER = 1234567890.0;
    private final static double HUGE_NUMBER = 8 * BIG_NUMBER;
    private final static double ENORMOUS_NUMBER = 10 * BIG_NUMBER;

    private static double solve(final int H, final int N, final int M, final int[][] C, final int[][] F) {
        final double[][] bestTime = new double[N][M];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                bestTime[i][j] = BIG_NUMBER;
            }
        }
        final LinkedList<P> queue = new LinkedList<P>();
        bestTime[0][0] = 0.0;
        queue.add(new P(0, 0));
        while (!queue.isEmpty()) {
            P p = queue.removeFirst();
            if (p.row > 0) {
                double t = getPossiblePassTime(p.row, p.col, p.row - 1, p.col, H, C, F);
                if (t == 0.0 && bestTime[p.row][p.col] == 0.0) {
                    if (bestTime[p.row][p.col] < bestTime[p.row - 1][p.col]) {
                        queue.add(new P(p.row - 1, p.col));
                        bestTime[p.row - 1][p.col] = bestTime[p.row][p.col];
                    }
                } else if (t < HUGE_NUMBER) {
                    t = Math.max(bestTime[p.row][p.col], t);
                    if (H - t * 10 - F[p.row][p.col] >= 20) {
                        if (t + 1 < bestTime[p.row - 1][p.col]) {
                            bestTime[p.row - 1][p.col] = t + 1;
                            queue.add(new P(p.row - 1, p.col));
                        }
                    } else {
                        if (t + 10 < bestTime[p.row - 1][p.col]) {
                            bestTime[p.row - 1][p.col] = t + 10;
                            queue.add(new P(p.row - 1, p.col));
                        }
                    }
                }
            }
            if (p.row < N - 1) {
                double t = getPossiblePassTime(p.row, p.col, p.row + 1, p.col, H, C, F);
                if (t == 0.0 && bestTime[p.row][p.col] == 0.0) {
                    if (bestTime[p.row][p.col] < bestTime[p.row + 1][p.col]) {
                        queue.add(new P(p.row + 1, p.col));
                        bestTime[p.row + 1][p.col] = bestTime[p.row][p.col];
                    }
                } else if (t < HUGE_NUMBER) {
                    t = Math.max(bestTime[p.row][p.col], t);
                    if (H - t * 10 - F[p.row][p.col] >= 20) {
                        if (t + 1 < bestTime[p.row + 1][p.col]) {
                            bestTime[p.row + 1][p.col] = t + 1;
                            queue.add(new P(p.row + 1, p.col));
                        }
                    } else {
                        if (t + 10 < bestTime[p.row + 1][p.col]) {
                            bestTime[p.row + 1][p.col] = t + 10;
                            queue.add(new P(p.row + 1, p.col));
                        }
                    }
                }
            }
            if (p.col > 0) {
                double t = getPossiblePassTime(p.row, p.col, p.row, p.col - 1, H, C, F);
                if (t == 0.0 && bestTime[p.row][p.col] == 0.0) {
                    if (bestTime[p.row][p.col] < bestTime[p.row][p.col - 1]) {
                        queue.add(new P(p.row, p.col - 1));
                        bestTime[p.row][p.col - 1] = bestTime[p.row][p.col];
                    }
                } else if (t < HUGE_NUMBER) {
                    t = Math.max(bestTime[p.row][p.col], t);
                    if (H - t * 10 - F[p.row][p.col] >= 20) {
                        if (t + 1 < bestTime[p.row][p.col - 1]) {
                            bestTime[p.row][p.col - 1] = t + 1;
                            queue.add(new P(p.row, p.col - 1));
                        }
                    } else {
                        if (t + 10 < bestTime[p.row][p.col - 1]) {
                            bestTime[p.row][p.col - 1] = t + 10;
                            queue.add(new P(p.row, p.col - 1));
                        }
                    }
                }
            }
            if (p.col < M - 1) {
                double t = getPossiblePassTime(p.row, p.col, p.row, p.col + 1, H, C, F);
                if (t == 0.0 && bestTime[p.row][p.col] == 0.0) {
                    if (bestTime[p.row][p.col] < bestTime[p.row][p.col + 1]) {
                        queue.add(new P(p.row, p.col + 1));
                        bestTime[p.row][p.col + 1] = bestTime[p.row][p.col];
                    }
                } else if (t < HUGE_NUMBER) {
                    t = Math.max(bestTime[p.row][p.col], t);
                    if (H - t * 10 - F[p.row][p.col] >= 20) {
                        if (t + 1 < bestTime[p.row][p.col + 1]) {
                            bestTime[p.row][p.col + 1] = t + 1;
                            queue.add(new P(p.row, p.col + 1));
                        }
                    } else {
                        if (t + 10 < bestTime[p.row][p.col + 1]) {
                            bestTime[p.row][p.col + 1] = t + 10;
                            queue.add(new P(p.row, p.col + 1));
                        }
                    }
                }
            }
        }
        return bestTime[N - 1][M - 1]; // TODO: maybe also check when this one opens!
    }
    
    private static double getPossiblePassTime(final int r1, final int c1, final int r2, final int c2, final int H, final int[][] C, final int[][] F) {
        if (C[r2][c2] - F[r2][c2] < 50 || C[r1][c1] - F[r2][c2] < 50 || C[r2][c2] - F[r1][c1] < 50) {
            return ENORMOUS_NUMBER;
        }
        if (C[r2][c2] - H >= 50) {
            return 0.0;
        }
        return (50 - (C[r2][c2] - H)) / 10.0;
    }

    static class P {

        int row, col;

        P(final int row, final int col) {
            this.row = row;
            this.col = col;
        }
    }
}
