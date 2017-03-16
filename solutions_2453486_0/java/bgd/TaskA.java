
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author Bohdan Dzoba
 */
public class TaskA {

    final static String path = "data\\A-small-attempt.in";
    static Scanner scanner;

    static String solve() {
        String[] board = new String[10];
        for (int i = 0; i < 6; ++i) {
            board[4 + i] = "";
        }
        for (int i = 0; i < 4; ++i) {
            board[i] = scanner.next();
            board[4] += board[i].charAt(i);
            board[5] += board[i].charAt(3 - i);
            for (int j = 0; j < 4; ++j) {
                board[6 + j] += board[i].charAt(j);
            }
        }
        for (int i = 0; i < 10; ++i) {
            if (board[i].matches("[XT]{4}")) {
                return "X won";
            }
            if (board[i].matches("[OT]{4}")) {
                return "O won";
            }
        }
        for (int i = 0; i < 4; ++i) {
            if (board[i].contains(".")) {
                return "Game has not completed";
            }
        }
        return "Draw";
    }

    public static void main(String[] args) throws FileNotFoundException {
        scanner = new Scanner(new File(path), "UTF-8");
        int nTests = scanner.nextInt();
        for (int i = 1; i <= nTests; ++i) {
            System.out.println("Case #" + i + ": " + solve());
        }
        scanner.close();
    }
}
