/**
 * Created with IntelliJ IDEA.
 * User: jsu
 * Date: 12/04/13
 * Time: 10:03 PM
 * To change this template use File | Settings | File Templates.
 */

/**
 * Google Code Jam
 * User: jsu
 */

import java.io.*;

public class TicTacToeTomek {

    private static int f(int[][] a) {
        if(check(a, 1))
            return 1;
        else if(check(a, 2))
            return 2;
        else
            return 0;
    }

    private static boolean check(int[][] a, int player) {
        assert player == 1 || player == 2;

        for(int row = 0; row < 4; ++row) {
            boolean wonRow = true;
            for(int col = 0; col < 4; ++col) {
                if(a[row][col] != 3 && a[row][col] != player) {
                    wonRow = false;
                    break;
                }
            }
            if(wonRow)
                return true;
        }

        for(int col = 0; col < 4; ++col) {
            boolean wonCol = true;
            for(int row = 0; row < 4; ++row) {
                if(a[row][col] != 3 && a[row][col] != player) {
                    wonCol = false;
                    break;
                }
            }
            if(wonCol)
                return true;
        }

        boolean wonDiag1 = true;
        for(int rc = 0; rc < 4; ++rc) {
            if(a[rc][rc] != 3 && a[rc][rc] != player) {
                wonDiag1 = false;
                break;
            }
        }

        if(wonDiag1)
            return true;

        boolean wonDiag2 = true;
        for(int rc = 0; rc < 4; ++rc) {
            if(a[rc][3 - rc] != 3 && a[rc][3 - rc] != player) {
                wonDiag2 = false;
                break;
            }
        }

        if(wonDiag2)
            return true;

        return false;
    }

    private static void solve(String input, String output) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader(input));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(output)));

        int t = Integer.parseInt(in.readLine());
        for (int i = 1; i <= t; ++i) {
            int[][] a = new int[4][4];

            int emptyCells = 0;

            for(int j = 0; j < 4; ++j) {
                String line = in.readLine();
                for(int k = 0; k < 4; ++k) {
                    if(line.charAt(k) == 'T') {
                        a[j][k] = 3;
                    } else if(line.charAt(k) == 'X') {
                        a[j][k] = 1;
                    } else if(line.charAt(k) == 'O') {
                        a[j][k] = 2;
                    } else {
                        emptyCells++;
                    }
                }
            }
            in.readLine();

            out.print("Case #" + i + ": ");

            int r = f(a);

            switch (r) {
                case 1:
                    out.println("X won");
                    break;
                case 2:
                    out.println("O won");
                    break;
                case 0:
                    if(emptyCells > 0) {
                        out.println("Game has not completed");
                    } else {
                        out.println("Draw");
                    }
                    break;
                default:
                    break;
            }

        }

        out.close();
    }

    public static void main(String[] args) throws Exception {
        solve("test/A-sample.in", "test/A-sample.out");
        solve("test/A-small-attempt0.in", "test/A-small-attempt0.out");
        //solve("A-large-practice.in", "A-large-practice.out");
    }
}