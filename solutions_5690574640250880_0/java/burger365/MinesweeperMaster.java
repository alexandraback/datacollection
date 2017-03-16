import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by burger on 4/12/14.
 */
public class MinesweeperMaster {
    private int[][] memo;

    public static void main(String[] args) {
        Scanner sc = null;
        try {
            sc = new Scanner(new File("small.in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        try {
            PrintWriter writer = new PrintWriter("answer.out", "UTF-8");

            int T = sc.nextInt();
            for (int t = 1; t <= T; t++) {
                int R = sc.nextInt();
                int C = sc.nextInt();
                int M = sc.nextInt();
                writer.write("Case #" + t + ":\n");
                writer.write(new MinesweeperMaster().solve(R, C, M) + "\n");
            }
            writer.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    private String solve(int R, int C, int M) {
        char[][] cells = new char[R][C];
        memo = new int[R + 1][C + 1];
        for (int[] values : memo)
            Arrays.fill(values, Integer.MAX_VALUE);

        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                cells[r][c] = '.';

        int numCells = R * C;
        if (M == numCells - 1) {
            for (int r = 0; r < R; r++)
                for (int c = 0; c < C; c++)
                    cells[r][c] = '*';
            cells[0][0]= 'c';
        } else if (R == 1 || C == 1) {
            if (cells_1(cells, R, C, M) < 0) {
                return "Impossible";
            }
        } else if (R == 2 || C == 2) {
            if (cells_2(cells, R, C, M) < 0) {
                return "Impossible";
            }
        } else {
            if (M > R * C - 4) return "Impossible";

            if (cells_others(cells, R, C, M) < 0) {
                return "Impossible";
            }
            cells[0][0] = 'c';
        }

        String res = "";
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                res += cells[r][c];
            }
            if (r != R - 1) res += "\n";
        }
        return res;
    }

    private int cells_1(char[][] cells, int R, int C, int M) {
        int numCells = R * C;
        if (numCells >= M + 2) {
            cells[0][0] = 'c';
            if (R == 1) {
                for (int i = C - 1; i > C - 1 - M; i--) cells[0][i] = '*';
            } else {
                for (int i = R - 1; i > R - 1 - M; i--) cells[i][0] = '*';
            }
        } else {
            return -1;
        }

        return 0;
    }

    private int cells_2(char[][] cells, int R, int C, int M) {
        if (M % 2 == 1) return -1;
        int numCells = R * C;
        if (numCells >= M + 3) {
            cells[0][0] = 'c';
            if (R == 2) {
                for (int i = C - 1; i > C - 1 - (M / 2); i--) { cells[0][i] = cells[1][i] = '*'; }
            } else {
                for (int i = R - 1; i > R - 1 - (M / 2); i--) { cells[i][0] = cells[i][1] = '*'; }
            }
        } else {
            return -1;
        }

        return 0;
    }

    private int cells_others(char[][] cells, int R, int C, int M) {
        if (memo[R][C] != Integer.MAX_VALUE) return memo[R][C];
        if (M == 0) return memo[R][C] = 0;

        int res;
        if (C > 2 && M >= R) {
            for (int r = R - 1; r >= 0; r--) cells[r][C - 1] = '*';
            res = cells_others(cells, R, C - 1, M - R);
            if (res == 0) return memo[R][C] = res;
            for (int r = R - 1; r >= 0; r--) cells[r][C - 1] = '.';
        }

        if (R > 2 && M >= C) {
            for (int c = C - 1; c >= 0; c--) cells[R - 1][c] = '*';
            res = cells_others(cells, R - 1, C, M - C);
            if (res == 0) return memo[R][C] = res;
            for (int c = C - 1; c >= 0; c--) cells[R - 1][c] = '.';
        }

        // Check vertical lines.
        if (C > 2) {
            if (M < R - 1) {
                for (int r = R - 1; r >= 0 && M != 0; r--, M--) cells[r][C - 1] = '*';
                return memo[R][C] = 0;
            } else {
                for (int r = R - 1; r > 1; r--) cells[r][C - 1] = '*';
                res = cells_others(cells, R, C - 1, M - (R - 2));
                if (res == 0) return memo[R][C] = res;
                for (int r = R - 1; r > 1; r--) cells[r][C - 1] = '.';
            }
        }

        // Check horizontal lines.
        if (R > 2) {
            if (M < C - 1) {
                for (int c = C - 1; c >= 0 && M != 0; c--, M--) cells[R - 1][c] = '*';
                return memo[R][C] = 0;
            } else {
                for (int c = C - 1; c > 1; c--) cells[R - 1][c] = '*';
                res = cells_others(cells, R - 1, C, M - (C - 2));
                if (res == 0) return memo[R][C] = res;
                for (int c = C - 1; c > 1; c--) cells[R - 1][c] = '.';
            }
        }

        return memo[R][C] = -1;
    }
}
