
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Bohdan Dzoba
 */
public class TaskA {

    final static String path = "data\\A-large.in";
    final static String output = "data\\A-large.out";
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

    public static void main(String[] args) throws FileNotFoundException, IOException {
        scanner = new Scanner(new File(path));
        BufferedWriter out = new BufferedWriter(new FileWriter(output));
        int nTests = scanner.nextInt();
        for (int i = 1; i <= nTests; ++i) {
            out.write("Case #" + i + ": " + solve());
            out.newLine();
        }
        out.close();
        scanner.close();
    }
}
