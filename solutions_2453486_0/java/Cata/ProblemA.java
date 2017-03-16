import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemA {

    public static final char NONE = ' ';

    private String[] board = new String[4];

    public static void main(String[] args) throws Exception {
        //Scanner scanner = new Scanner(System.in);
        Scanner scanner = new Scanner(new File("/home/cata/Downloads/A-small-attempt0.in"));
        PrintStream out = new PrintStream("output.txt");
        int T = scanner.nextInt();
        for (int test = 1; test <= T; test++) {
            ProblemA instance = new ProblemA();
            instance.read(scanner);
            out.println("Case #" + test + ": " + instance.getMessage());
            System.out.println("Case #" + test + ": " + instance.getMessage());
        }
    }

    private void read(Scanner scanner) {
        for (int i = 0; i < 4; i++) {
            board[i] = scanner.nextLine();
            if (i == 0 && board[i].isEmpty()) {
                board[i] = scanner.nextLine();
            }
        }
    }

    private String getMessage() {
        char win = checkWin();
        if (win != NONE) {
            return win + " won";
        } else if (checkEmptyCells()) {
            return "Game has not completed";
        } else {
            return "Draw";
        }
    }

    private char checkWin() {
        char win = checkHorizontal();
        if (win != NONE) {
            return win;
        }
        win = checkVertical();
        if (win != NONE) {
            return win;
        } else {
            return checkDiagonal();
        }
    }

    private boolean checkEmptyCells() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i].charAt(j) == '.') {
                    return true;
                }
            }
        }
        return false;
    }

    private char checkHorizontal() {
        for (int i = 0; i < 4; i++) {
            if (sameChar(i, 0, i, 1) && sameChar(i, 0, i, 2) && sameChar(i, 0, i, 3) && sameChar(i, 1, i, 2) && sameChar(i, 2, i, 3)) {
                return (board[i].charAt(0) == 'T' ? board[i].charAt(1) : board[i].charAt(0));
            }
        }
        return NONE;
    }

    private char checkVertical() {
        for (int j = 0; j < 4; j++) {
            if (sameChar(0, j, 1, j) && sameChar(0, j, 2, j) && sameChar(0, j, 3, j) && sameChar(1, j, 2, j) && sameChar(2, j, 3, j)) {
                return (board[0].charAt(j) == 'T' ? board[1].charAt(j) : board[0].charAt(j));
            }
        }
        return NONE;
    }

    private char checkDiagonal() {
        if (sameChar(0, 0, 1, 1) && sameChar(0, 0, 2, 2) && sameChar(0, 0, 3, 3) && sameChar(1, 1, 2, 2) && sameChar(2, 2, 3, 3)) {
            return (board[0].charAt(0) == 'T' ? board[1].charAt(1) : board[0].charAt(0));
        }
        if (sameChar(0, 3, 1, 2) && sameChar(0, 3, 2, 1) && sameChar(0, 3, 3, 0) && sameChar(1, 2, 2, 1) && sameChar(2, 1, 3, 0)) {
            return (board[0].charAt(3) == 'T' ? board[1].charAt(2) : board[0].charAt(3));
        }
        return NONE;
    }

    private boolean sameChar(int i, int j, int x, int y) {
        return board[i].charAt(j) != '.'
                && board[x].charAt(y) != '.'
                && (
                board[i].charAt(j) == board[x].charAt(y)
                        || board[i].charAt(j) == 'T'
                        || board[x].charAt(y) == 'T'
        );
    }

}
