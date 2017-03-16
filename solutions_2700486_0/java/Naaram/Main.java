import com.google.common.base.Splitter;
import com.google.common.collect.Lists;

import java.io.*;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class Main {
    public static final int BOARD_SIZE = 20;
    private static final String TEST_INPUT = "7\n" +
            "1 0 0\n" +
            "1 0 2\n" +
            "3 0 0\n" +
            "3 2 0\n" +
            "3 1 1\n" +
            "4 1 1\n" +
            "4 0 2\n";


    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new FileReader("c:\\comp\\small.in"));
        //BufferedReader bufferedReader = new BufferedReader(new StringReader(TEST_INPUT));
        final PrintStream outStream = new PrintStream(new FileOutputStream("c:\\comp\\small.out"));
        int numCases = Integer.valueOf(bufferedReader.readLine());

        for (int i = 1; i <= numCases; i++) {
            String line = bufferedReader.readLine();
            Iterator<String> lineTokens = Splitter.on(" ").split(line).iterator();
            long n = Long.valueOf(lineTokens.next());
            int x = Integer.valueOf(lineTokens.next());
            int y = Integer.valueOf(lineTokens.next());

            double[][] board = buildGameBoard(n);

            double result;
            try {
                result = board[x + BOARD_SIZE][y];
            } catch (IndexOutOfBoundsException e) {
                result = 0.0;
            }


            System.out.println("Case #" + i + ": " + result);
            outStream.println("Case #" + i + ": " + result);
        }
    }

    private static double[][] buildGameBoard(long n) {
        double[][] result = new double[BOARD_SIZE * 2][BOARD_SIZE];


        int[][] currentBoard = new int[BOARD_SIZE * 2][BOARD_SIZE];

        fallDiamond(result, currentBoard, 1d, BOARD_SIZE, BOARD_SIZE, n - 1);

        return result;
    }

    private static void fallDiamond(double[][] result, int[][] currentBoard, double factor, int x, int y, long diamondsRemaining) {
        if(diamondsRemaining == -1) {
            return;
        }

        if (y == 0) {
            currentBoard[x][y] = 1;
            result[x][y] += factor;
            fallDiamond(result, currentBoard, factor, BOARD_SIZE, BOARD_SIZE, diamondsRemaining - 1);
        } else if ((y > 1 && currentBoard[x][y - 2] == 0) && currentBoard[x - 1][y - 1] == 0 && currentBoard[x + 1][y - 1] == 0) {
            fallDiamond(result, currentBoard, factor, x, y - 2, diamondsRemaining);
        } else {
            if (y == 1 || currentBoard[x][y - 2] == 1) {
                if (currentBoard[x - 1][y - 1] == 0 && currentBoard[x + 1][y - 1] == 0) {
                    fallDiamond(result, cloneArray(currentBoard), factor / 2d, x - 1, y - 1, diamondsRemaining);
                    fallDiamond(result, cloneArray(currentBoard), factor / 2d, x + 1, y - 1, diamondsRemaining);
                } else if (currentBoard[x - 1][y - 1] == 0) {
                    fallDiamond(result, currentBoard, factor, x - 1, y - 1, diamondsRemaining);
                } else if (currentBoard[x + 1][y - 1] == 0) {
                    fallDiamond(result, currentBoard, factor, x + 1, y - 1, diamondsRemaining);
                } else {
                    currentBoard[x][y] = 1;
                    result[x][y] += factor;
                    fallDiamond(result, currentBoard, factor, BOARD_SIZE, BOARD_SIZE, diamondsRemaining - 1);
                }
            } else {
                if (currentBoard[x - 1][y - 1] == 1 && currentBoard[x + 1][y - 1] == 1) {
                    currentBoard[x][y] = 1;
                    result[x][y] += factor;
                    fallDiamond(result, currentBoard, factor, BOARD_SIZE, BOARD_SIZE, diamondsRemaining - 1);
                } else if (currentBoard[x - 1][y - 1] == 0) {
                    fallDiamond(result, currentBoard, factor, x - 1, y - 1, diamondsRemaining);
                } else if (currentBoard[x + 1][y - 1] == 0) {
                    fallDiamond(result, currentBoard, factor, x + 1, y - 1, diamondsRemaining);
                }
            }
        }
    }

    public static int[][] cloneArray(int[][] src) {
        int length = src.length;
        int[][] target = new int[length][src[0].length];
        for (int i = 0; i < length; i++) {
            System.arraycopy(src[i], 0, target[i], 0, src[i].length);
        }
        return target;
    }

}
