import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Solution {
    public static void main(String args[]) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new File("output"));
        //PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();
        for (int curTest = 1; curTest <= T; curTest++) {
            int n = in.nextInt();
            int m = in.nextInt();
            int mines = in.nextInt();

            out.println("Case #" + curTest + ":");
            process(n, m, mines, out);
            out.flush();
        }
        in.close();
        out.close();
    }

    private static void print(PrintWriter out, char[][] board) {
        for (int i = 0; i < board.length; i++) {
            out.println(new String(board[i]));
        }
    }

    private static void process(int n, int m, int mines, PrintWriter out) {
        int i, j, k, l;
        if (n == 1) {
            print(out, getBoard(n, m, 1, n * m - mines, 0, 0));
            return;
        }
        if (m == 1) {
            print(out, getBoard(n, m, n * m - mines, 1, 0, 0));
            return;
        }
        if (mines == n * m - 1) {
            print(out, getBoard(n, m, 1, 1, 0, 0));
            return;
        }

        for (i = 2; i <= n; i++) {
            for (j = 2; j <= m; j++) {
                if (i * j == n * m - mines) {
                    print(out, getBoard(n, m, i, j, 0, 0));
                    return;
                }

                for (k = 0; k <= j; k++) {
                    if (k > 0 && i == n) {
                        continue;
                    }
                    for (l = 0; l <= i; l++) {
                        if (l > 0 && j == m) {
                            continue;
                        }
                        if (k != 1 && l != 1 && i * j + k + l == n * m - mines) {
                            print(out, getBoard(n, m, i, j, k, l));
                            return;
                        }
                    }
                }
            }
        }
        out.println("Impossible");
    }

    private static char[][] getBoard(int r, int c, int n, int m, int hor, int ver) {
        char[][] ret = new char[r][c];
        for (int i = 0; i < ret.length; i++) {
            Arrays.fill(ret[i], '*');
        }
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                ret[i][j] = '.';
            }
        }
        for (i = 0; i < hor; i++) {
            ret[n][i] = '.';
        }
        for (i = 0; i < ver; i++) {
            ret[i][m] = '.';
        }
        ret[0][0] = 'c';
        return ret;
    }
}