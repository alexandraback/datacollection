package qulifying;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: raggzy
 * Date: 13.04.13
 * Time: 3:05
 * To change this template use File | Settings | File Templates.
 */
public class ProblemB {

    static boolean canBeObtained(int rows, int cols, int[][] grass) {
        int[] maxPerRow = new int[rows];
        int[] maxPerCol = new int[cols];
        Arrays.fill(maxPerCol, Integer.MIN_VALUE);
        Arrays.fill(maxPerRow, Integer.MIN_VALUE);

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                maxPerRow[row] = Math.max(maxPerRow[row], grass[row][col]);
                maxPerCol[col] = Math.max(maxPerCol[col], grass[row][col]);
            }
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grass[row][col] < maxPerCol[col] && grass[row][col] < maxPerRow[row]) {
                    return false;
                }
            }
        }

        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("C:/Temp/gcj/b-in.txt"));
        PrintStream out = new PrintStream(new FileOutputStream("C:/Temp/gcj/b-out.txt"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            int rows = in.nextInt();
            int cols = in.nextInt();
            int[][] grass = new int[rows][cols];
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    grass[row][col] = in.nextInt();
                }
            }
            out.println(String.format("Case #%d: %s", i + 1, canBeObtained(rows, cols, grass) ? "YES" : "NO"));
        }
        in.close();
        out.close();
    }
}
