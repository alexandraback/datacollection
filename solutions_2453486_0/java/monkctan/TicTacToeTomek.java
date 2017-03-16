package gcj2013.qual;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TicTacToeTomek {
    private static String folder = "src/gcj2013/qual";
    private static String filename = "A-small-attempt0";

    private static String getGameStatus(String[] board) {
        // Rows
        for (int i = 0; i < 4; ++i) {
            int xSum = 0;
            int oSum = 0;
            for (int j = 0; j < 4; ++j) {
                char c = board[i].charAt(j);
                if (c == 'X' || c == 'T') {
                    ++xSum;
                }
                if (c == 'O' || c == 'T') {
                    ++oSum;
                }
            }
            if (xSum == 4) {
                return "X won";
            } else if (oSum == 4) {
                return "O won";
            }
        }

        // Columns
        for (int i = 0; i < 4; ++i) {
            int xSum = 0;
            int oSum = 0;
            for (int j = 0; j < 4; ++j) {
                char c = board[j].charAt(i);
                if (c == 'X' || c == 'T') {
                    ++xSum;
                }
                if (c == 'O' || c == 'T') {
                    ++oSum;
                }
            }
            if (xSum == 4) {
                return "X won";
            } else if (oSum == 4) {
                return "O won";
            }
        }

        // Diagonal 1
        int xSum = 0;
        int oSum = 0;
        for (int i = 0; i < 4; ++i) {
            char c = board[i].charAt(i);
            if (c == 'X' || c == 'T') {
                ++xSum;
            }
            if (c == 'O' || c == 'T') {
                ++oSum;
            }
        }
        if (xSum == 4) {
            return "X won";
        } else if (oSum == 4) {
            return "O won";
        }

        // Diagonal 2
        xSum = 0;
        oSum = 0;
        for (int i = 0; i < 4; ++i) {
            char c = board[i].charAt(3 - i);
            if (c == 'X' || c == 'T') {
                ++xSum;
            }
            if (c == 'O' || c == 'T') {
                ++oSum;
            }
        }
        if (xSum == 4) {
            return "X won";
        } else if (oSum == 4) {
            return "O won";
        }

        // Check if draw or incomplete
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (board[i].charAt(j) == '.') {
                    return "Game has not completed";
                }
            }
        }

        return "Draw";
    }

    public static void main(String[] args) {
        try {
            File inputFile = new File(folder, filename + ".in");
            File outputFile = new File(folder, filename + ".out");
            BufferedReader reader = new BufferedReader(new FileReader(inputFile));
            PrintWriter pw = new PrintWriter(outputFile);
            int numTestCases = Integer.parseInt(reader.readLine());
            String[] board = new String[4];
            for (int t = 0; t < numTestCases; ++t) {
                for (int line = 0; line < 4; ++line) {
                    board[line] = reader.readLine().trim();
                }
                String gameStatus = getGameStatus(board);

                String result = String
                        .format("Case #%d: %s", t + 1, gameStatus);
                System.out.println(result);
                pw.println(result);
                reader.readLine();
            }
            reader.close();
            pw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (NumberFormatException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
