/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejamreg;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Rupsbant
 */
public class CodeJamReg {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        String input = "data/small.txt";
        String output = "data/smallO.txt";
        Scanner sc = new Scanner(new File(input));
        PrintStream out = new PrintStream(output);
        int cases = sc.nextInt();
        for (int i = 0; i < cases; i++) {
            out.print("Case #" + (i + 1) + ": ");
            exec(sc, out);
        }
    }

    private static void exec(Scanner sc, PrintStream out) {
        int[][] field = new int[4][4];
        for (int i = 0; i < field.length; i++) {
            String word = sc.next();
            for (int j = 0; j < field[0].length; j++) {
                char character = word.charAt(j);
                int value = (character == 'X' ? 1 : -1);
                value = (character == 'O' ? 2 : value);
                value = (character == 'T' ? 3 : value);
                value = (character == '.' ? 0 : value);
                field[i][j] = value;
            }
        }
        System.out.println(Arrays.deepToString(field));
        for (int i = 1; i < 3; i++) {
            if (isDiagonal(field, i) || isVertical(field, i) || isHorizontal(field, i)) {
                out.println((i==1?'X':'O')+" won");
                return;
            }
        }
        boolean filled = isFilled(field);
        if(filled){
            out.println("Draw");
        } else {
            out.println("Game has not completed");
        }
    }

    private static boolean isHorizontal(int[][] field, int player) {
        for (int i = 0; i < field.length; i++) {
            boolean isWon = true;
            for (int j = 0; j < field[i].length; j++) {
                isWon &= (field[i][j] & player) != 0;
            }
            if (isWon) {
                return true;
            }
        }
        return false;
    }

    private static boolean isVertical(int[][] field, int player) {
        for (int i = 0; i < field[0].length; i++) {
            boolean isWon = true;
            for (int j = 0; j < field.length; j++) {
                isWon &= (field[j][i] & player) != 0;
            }
            if (isWon) {
                return true;
            }
        }
        return false;
    }

    private static boolean isDiagonal(int[][] field, int player) {
        boolean isWon = true;
        for (int j = 0; j < field.length; j++) {
            isWon &= (field[j][j] & player) != 0;
        }
        if (isWon) {
            return true;
        }
        isWon = true;
        for (int j = 0; j < field.length; j++) {
            isWon &= (field[j][3 - j] & player) != 0;
        }
        if (isWon) {
            return true;
        }
        return false;
    }

    private static boolean isFilled(int[][] field) {
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field[i].length; j++) {
                if(field[i][j] == 0){
                    return false;
                }
            }
        }
        return true;
    }
}
