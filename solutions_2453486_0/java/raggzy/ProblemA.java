package qulifying;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created with IntelliJ IDEA.
 * User: raggzy
 * Date: 13.04.13
 * Time: 2:23
 * To change this template use File | Settings | File Templates.
 */
public class ProblemA {

    public static final int GAME_SIZE = 4;

    private static char[][] readGame(Scanner in) {
        char[][] result = new char[GAME_SIZE][];
        in.nextLine();
        for (int i = 0; i < GAME_SIZE; i++) {
            result[i] = in.nextLine().toCharArray();
        }
        return result;
    }


    private static Set<Character> set(char... chars) {
        HashSet<Character> res = new HashSet<Character>();
        for (char c : chars) {
            res.add(c);
        }
        return res;
    }

    private static boolean checkDirection(char[][] game, int startRow, int startCol, int rowInc, int colInc, Set<Character> symbols) {
        for (int step = 0; step < GAME_SIZE; step++) {
            if (!symbols.contains(game[startRow + rowInc * step][startCol + colInc * step])) {
                return false;
            }
        }
        return true;
    }

    private static boolean checkAll(char[][] game, Set<Character> symbols) {
        for (int row = 0; row < GAME_SIZE; row++) {
            for (int col = 0; col < GAME_SIZE; col++) {
                if (!symbols.contains(game[row][col])) {
                    return false;
                }
            }
        }
        return true;
    }

    private static boolean checkWon(char[][] game, Set<Character> symbols) {
        // rows check
        for (int row = 0; row < GAME_SIZE; row++) {
            if (checkDirection(game, row, 0, 0, 1, symbols)) {
                return true;
            }
        }
        // cols check
        for (int col = 0; col < GAME_SIZE; col++) {
            if (checkDirection(game, 0, col, 1, 0, symbols)) {
                return true;
            }
        }
        // diag check
        if (checkDirection(game, 0, 0, 1, 1, symbols)) {
            return true;
        }

        if (checkDirection(game, GAME_SIZE - 1, 0, -1, 1, symbols)) {
            return true;
        }

        return false;
    }


    public static final Set<Character> X_SET = set('X', 'T');
    public static final Set<Character> O_SET = set('O', 'T');
    public static final Set<Character> SOMEONE_SET = set('X', 'O', 'T');

    private static String solve(char[][] game) {
        if (checkWon(game, X_SET)) {
            return "X won";
        }
        if (checkWon(game, O_SET)) {
            return "O won";
        }
        if (checkAll(game, SOMEONE_SET)) {
            return "Draw";
        }
        return "Game has not completed";
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileInputStream("C:/Temp/gcj/a-in.txt"));
        PrintStream out = new PrintStream(new FileOutputStream("C:/Temp/gcj/a-out.txt"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            char[][] game = readGame(in);
            out.println(String.format("Case #%d: %s", i + 1, solve(game)));
        }
        in.close();
        out.close();
    }
}
