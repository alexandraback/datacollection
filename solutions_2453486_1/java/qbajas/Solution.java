import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Qba
 * Date: 13.04.13
 * Time: 13:02
 * To change this template use File | Settings | File Templates.
 */
public class Solution {

    public static void main(String[] args) {
        Solution s = new Solution();
        s.parse();
    }


    char[][] board = new char[4][4];

    public void parse() {
        Scanner scanner;
        try {
            scanner = new Scanner(new File("files/input.in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return;
        }
        String line;

        int linesNo = scanner.nextInt();

        for (int k = 0; k < linesNo; k++) {
            for (int i = 0; i < 4; i++) {
                line = scanner.next();
                for (int j = 0; j < 4; j++) {
                    board[i][j] = line.charAt(j);
                }
            }
            System.out.println(solve(k + 1));
        }
    }


    public String solve(int caseNo) {
        String msg = null;
        msg = checkRows(msg);
        msg = checkColumns(msg);
        msg = checkDiagonal1(msg);
        msg = checkDiagonal2(msg);
        if (msg == null) {
            if (boardContainsDot()) {
                msg = "Game has not completed";
            } else {
                msg = "Draw";
            }
        }
        return "Case #" + caseNo + ": " + msg;
    }

    private boolean boardContainsDot() {
        boolean contains = false;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == '.') {
                    return true;
                }
            }
        }
        return contains;
    }

    private String checkDiagonal1(String msg) {
        boolean xWon = true;
        boolean oWon = true;
        for (int i = 0; i < 4; i++) {
            xWon &= isX(i, i);
            oWon &= isO(i, i);
        }
        if (xWon) {
            msg = "X won";
        }
        if (oWon) {
            msg = "O won";
        }
        return msg;
    }

    private String checkDiagonal2(String msg) {
        boolean xWon = true;
        boolean oWon = true;
        for (int i = 0; i < 4; i++) {
            xWon &= isX(i, 3 - i);
            oWon &= isO(i, 3 - i);
        }
        if (xWon) {
            msg = "X won";
        }
        if (oWon) {
            msg = "O won";
        }
        return msg;
    }

    private String checkRows(String msg) {
        for (int i = 0; i < 4; i++) {
            boolean xWon = true;
            boolean oWon = true;
            for (int j = 0; j < 4; j++) {
                xWon &= isX(i, j);
                oWon &= isO(i, j);
            }
            if (xWon) {
                msg = "X won";
            }
            if (oWon) {
                msg = "O won";
            }
        }
        return msg;
    }


    private String checkColumns(String msg) {
        for (int i = 0; i < 4; i++) {
            boolean xWon = true;
            boolean oWon = true;
            for (int j = 0; j < 4; j++) {
                xWon &= isX(j, i);
                oWon &= isO(j, i);
            }
            if (xWon) {
                msg = "X won";
            }
            if (oWon) {
                msg = "O won";
            }
        }
        return msg;
    }


    public void setBoard(char[][] board) {
        this.board = board;
    }

    private boolean isX(int row, int column) {
        return board[row][column] == 'X' || board[row][column] == 'T';
    }

    private boolean isO(int row, int column) {
        return board[row][column] == 'O' || board[row][column] == 'T';
    }
}
