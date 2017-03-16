package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class MinesweeperMaster {
    final static String PROBLEM_NAME = "minesweeper";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void fill(int M, char[][] board) {
        if (board.length <= board[0].length) {
            for (int c = board[0].length - 1; c >= 0; c--) {
                for (int r = board.length - 1; r >= 0; r--) {
                    if (M > 0) {
                        M--;
                        board[r][c] = '*';
                    }
                }
            }
        } else {
            for (int r = board.length - 1; r >= 0; r--) {
                for (int c = board[0].length - 1; c >= 0; c--) {
                    if (M > 0) {
                        M--;
                        board[r][c] = '*';
                    }
                }
            }
        }
    }

    static void go(int i, int j, boolean[][] used, int[][] cnt) {
        if (i < 0 || i >= used.length || j < 0 || j >= used[0].length) return;
        if (used[i][j]) return;
        if (cnt[i][j] != 0) return;
        used[i][j] = true;
        for (int di=-1; di<=1; di++) for (int dj=-1; dj <= 1; dj++) go(i+di, j+dj, used, cnt);
    }

    boolean verify(int R, int C, int M, char[][] board) {
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (board[i][j] == '*') {
                    M--;
                }
            }
        }
        if (M != 0) {
            return false;
        }

        int[][] cnt = new int[R][C];
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (board[i][j] == '*') {
                    cnt[i][j] = -1;
                    continue;
                }
                for (int di=-1; di<=1; di++) {
                    for (int dj=-1; dj<=1; dj++) {
                        if (i+di>=0 && i+di<R && j+dj>=0 && j+dj<C && board[i+di][j+dj] == '*') {
                            cnt[i][j]++;
                        }
                    }
                }
            }
        }

        int compCnt = 0;
        boolean[][] used = new boolean[R][C];
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (cnt[i][j] == 0 && !used[i][j]) {
                    compCnt++;
                    go(i, j, used, cnt);
                }
            }
        }

        int cntNoNeighbour = 0;
        for (int i=0; i<R; i++) for (int j=0; j<C; j++) if (cnt[i][j] > 0) {
            boolean find = false;
            for (int di=-1; di<=1; di++) for (int dj=-1; dj<=1; dj++) {
                if (i+di>=0 && i+di<R && j+dj>=0 && j+dj<C && cnt[i+di][j+dj] == 0) {
                    find = true;
                }
            }
            if (!find) cntNoNeighbour++;
        }

        return cntNoNeighbour == 0 && compCnt == 1 || cntNoNeighbour == 1 && compCnt == 0;
    }

    void solve(Scanner sc, PrintWriter pw) {
        int R = sc.nextInt();
        int C = sc.nextInt();
        int M = sc.nextInt();
        char[][] board = new char[R][C];
        for (int i=0; i<R; i++) {
            Arrays.fill(board[i], '.');
        }
        board[0][0] = 'c';
        boolean possible = true;
        if (R == 1 || C == 1) {
            fill(M, board);
        } else if (R == 2 || C == 2) {
            if (M == R * C - 2 || M % 2 == 1 && M != R * C - 1) {
                possible = false;
            } else {
                fill(M, board);
            }
        } else if (M == R * C - 2 || M == R * C - 3 || M == R * C - 5 || M == R * C - 7) {
            possible = false;
        } else if (M == R * C - 1) {
            fill(M, board);
        } else {
            int empty = R * C - M;
            boolean find = false;
            for (int h = 2; h <= R && !find; h++) {
                for (int w = 2; w <= C && !find; w++) {
                    int min = h * w - (h - 2) * (w - 2);
                    int max = h * w;
                    if (empty >= min && empty <= max) {
                        for (int i=0; i < R; i++) {
                            Arrays.fill(board[i], '*');
                        }
                        for (int i=0; i < h; i++) {
                            for (int j=0; j < w; j++) {
                                if (i < 2 || j < 2) {
                                    empty--;
                                    board[i][j] = '.';
                                }
                            }
                        }
                        for (int i=0; i < h; i++) {
                            for (int j=0; j < w; j++) {
                                if (i >= 2 && j >= 2 && empty > 0) {
                                    empty--;
                                    board[i][j] = '.';
                                }
                            }
                        }
                        board[0][0] = 'c';
                        find = true;
                    }
                }
            }
            if (!find) {
                System.out.println("FAILURE " + R + " " + C + " " + M);
            }
        }
        if (possible) {
            if (!verify(R, C, M, board)) {
                System.out.println("FAILURE " + R + " " + C + " " + M);
                for (int i=0; i < R; i++) {
                    System.out.println(new String(board[i]));
                }
            }
            for (int i=0; i < R; i++) {
                pw.println(new String(board[i]));
            }
        } else {
            pw.println("Impossible");
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.println("Case #" + (caseNum + 1) + ":");
            new MinesweeperMaster().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
