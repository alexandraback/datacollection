import gcj.GCJ;

import java.util.Scanner;

public class TicTacToeTomek {

    final String X = "X won";

    final String O = "O won";

    final String D = "Draw";

    final String N = "Game has not completed";

    String[] board;

    public TicTacToeTomek(String[] board) {
        this.board = board;
    }

    public String getState() {
        if (isXWon()) {
            return X;
        } else if (isOWon()) {
            return O;
        } else if (isCompleted()) {
            return D;
        } else {
            return N;
        }
    }

    private boolean isCompleted() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i].charAt(j) == '.') {
                    return false;
                }
            }
        }
        return true;
    }

    private boolean isXWon() {
        return isRowFull('X') || isColFull('X') || isDiagFull('X');
    }

    private boolean isOWon() {
        return isRowFull('O') || isColFull('O') || isDiagFull('O');
    }

    private boolean isRowFull(char c) {
        for (int i = 0; i < 4; i++) {
            int total = 0;
            for (int j = 0; j < 4; j++) {
                if (board[i].charAt(j) == c || board[i].charAt(j) == 'T') {
                    total++;
                }
            }
            if (total == 4) {
                return true;
            }
        }
        return false;
    }

    private boolean isColFull(char c) {
        for (int i = 0; i < 4; i++) {
            int total = 0;
            for (int j = 0; j < 4; j++) {
                if (board[j].charAt(i) == c || board[j].charAt(i) == 'T') {
                    total++;
                }
            }
            if (total == 4) {
                return true;
            }
        }
        return false;
    }

    private boolean isDiagFull(char c) {
        int total1 = 0;
        int total2 = 0;
        for (int i = 0; i < 4; i++) {
            if (board[i].charAt(i) == c || board[i].charAt(i) == 'T') {
                total1++;
            }
            if (board[i].charAt(3 - i) == c || board[i].charAt(3 - i) == 'T') {
                total2++;
            }
        }
        return total1 == 4 || total2 == 4;
    }

    public static void main(String[] args) {
        Scanner s = GCJ.createScanner('A', true);
        int t = s.nextInt();
        for (int i = 1; i <= t; i++) {
            s.nextLine();
            String[] b = new String[4];
            for (int j = 0; j < 4; j++) {
                b[j] = s.nextLine();
            }
            TicTacToeTomek tttt = new TicTacToeTomek(b);
            GCJ.out(i, tttt.getState());
        }
    }

}
