import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int placed = 0;

    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int trials = sc.nextInt();
        for (int t = 1; t <= trials; t++) {
            int rows = sc.nextInt();
            int columns = sc.nextInt();
            int mines = sc.nextInt();
            placed = (rows * columns) - mines;

            // Create the board and fill the entire thing with mines
            // Create a backup to reset to
            char[][] board = new char[rows + 2][columns + 2];
            char[][] original = new char[rows + 2][columns + 2];
            char[][] unfilled = new char[rows + 2][columns + 2];
            for (int i = 1; i < board.length - 1; i++) {
                for (int j = 1; j < board[i].length - 1; j++) {
                    board[i][j] = '*';
                    original[i][j] = '*';
                }
            }

            boolean placedClick = false;
            int numClicks = 0;
            // Find a position to place the click, so that it spreads using
            // flood fill
            // The number of mines decreasing each time
            for (int i = 1; i < board.length - 1; i++) {
                for (int j = 1; j < board[i].length - 1; j++) {
                    if (board[i][j] == '*') {
                        // Try at this position
                        // System.out.printf("Filling board from [%d, %d]%n", i,
                        // j);
                        fillBoard(board, i, j);

                        unfilled = new char[board.length][];
                        for (int k = 0; k < board.length; k++) {
                            unfilled[k] = board[k].clone();
                        }

                        numClicks++;
                        // showBoard(board);
                        // Stop, the number of placed mines is sufficient
                        if ((placed == 0) && (board[i][j] != '*')) {
                            // System.out.printf("Clicking at [%d, %d]%n", i,
                            // j);
                            // Verify the board is solveable
                            playBoard(board, i, j);
                            // showBoard(board);
                            if ((numClicks == 1) && verifyBoard(board)) {
                                unfilled[i][j] = 'c';
                                i = board.length - 1;
                                j = board[i].length;
                                placedClick = true;
                            } else {
                                // Reset the board, try the next position
                                // System.out.printf("Resetting board%n");
                                board = new char[board.length][];
                                for (int k = 0; k < board.length; k++) {
                                    board[k] = original[k].clone();
                                }
                                placed = (rows * columns) - mines;
                                numClicks = 0;
                            }
                        }
                    }
                }
            }

            System.out.printf("Case #%d:%n", t);
            if ((placedClick == false) || (numClicks > 1)) {
                System.out.printf("Impossible%n");
                // showBoard(board);
            } else {
                showBoard(unfilled);
            }
        }
        sc.close();
    }

    private static boolean verifyBoard (char[][] board) {
        for (int i = 1; i < board.length - 1; i++) {
            for (int j = 1; j < board[i].length - 1; j++) {
                if (board[i][j] == '.') {
                    return false;
                }
            }
        }
        return true;
    }

    private static void showBoard (char[][] board) {
        for (int i = 1; i < board.length - 1; i++) {
            for (int j = 1; j < board[i].length - 1; j++) {
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }

    // BFS
    private static int fillBoard (char[][] board, int y, int x) {
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(y);
        queue.add(x);
        while (!queue.isEmpty()) {
            int currentY = queue.remove();
            int currentX = queue.remove();
            // Verify coordinates
            if ((currentY >= 1) && (currentX >= 1)
                    && (currentY < board.length - 1)
                    && (currentX < board[0].length - 1)) {
                // System.out.printf("Going to [%d, %d]%n", currentY, currentX);
                if (board[currentY][currentX] == '*') {
                    if (placed != 0) {
                        // showBoard(board);
                        // System.out.println(placed);
                        board[currentY][currentX] = '.';
                        placed--;
                        // Up-left
                        queue.add(currentY - 1);
                        queue.add(currentX - 1);
                        // Up
                        queue.add(currentY - 1);
                        queue.add(currentX);
                        // Up-right
                        queue.add(currentY - 1);
                        queue.add(currentX + 1);
                        // Right
                        queue.add(currentY);
                        queue.add(currentX + 1);
                        // Down-right
                        queue.add(currentY + 1);
                        queue.add(currentX + 1);
                        // Down
                        queue.add(currentY + 1);
                        queue.add(currentX);
                        // Left-down
                        queue.add(currentY + 1);
                        queue.add(currentX - 1);
                        // Left
                        queue.add(currentY);
                        queue.add(currentX - 1);
                    }
                } else {
                    // System.out.printf("[%d, %d] %c%n", currentY, currentX,
                    // board[currentY][currentX]);
                }
            }
        }
        return 0;
    }

    /*
     * private static int fillBoard (char[][] board, int y, int x) {
     * // showBoard(board);
     * if ((y >= 1) && (x >= 1) && (y < board.length - 1)
     * && (x < board[0].length - 1)) {
     * if ((board[y][x] == '*') && (placed != 0)) {
     * board[y][x] = '.';
     * placed--;
     * fillBoard(board, y - 1, x - 1);
     * fillBoard(board, y - 1, x);
     * fillBoard(board, y - 1, x + 1);
     * fillBoard(board, y, x + 1);
     * fillBoard(board, y + 1, x + 1);
     * fillBoard(board, y + 1, x);
     * fillBoard(board, y + 1, x - 1);
     * fillBoard(board, y, x - 1);
     * }
     * }
     * return 0;
     * }
     */

    private static int playBoard (char[][] board, int y, int x) {
        if ((y >= 1) && (x >= 1) && (y < board.length - 1)
                && (x < board[0].length - 1)) {
            if (board[y][x] == '.') {
                if (countMines(board, y, x) > 0) {
                    board[y][x] = '1';
                } else {
                    board[y][x] = '0';
                }
                // board[y][x] = Integer.toString(countMines(board, y,
                // x)).charAt(
                // 0);
                if (board[y][x] == '0') {
                    playBoard(board, y + 1, x);
                    playBoard(board, y - 1, x);
                    playBoard(board, y, x + 1);
                    playBoard(board, y, x - 1);
                    playBoard(board, y + 1, x + 1);
                    playBoard(board, y + 1, x - 1);
                    playBoard(board, y - 1, x + 1);
                    playBoard(board, y - 1, x - 1);
                }
                // board[y][x] = Integer.toString(count + 1).charAt(0);
            } else if (board[y][x] == '*') {
                return 1;
            } else {
                return 0;
            }
        }
        return 0;
    }

    private static int countMines (char[][] board, int y, int x) {
        int mines = 0;
        if ((y >= 0) && (x >= 0) && (y < board.length) && (x < board[0].length)) {
            if (board[y - 1][x] == '*') {
                mines++;
            }
            if (board[y + 1][x] == '*') {
                mines++;
            }
            if (board[y][x - 1] == '*') {
                mines++;
            }
            if (board[y][x + 1] == '*') {
                mines++;
            }
            if (board[y - 1][x - 1] == '*') {
                mines++;
            }
            if (board[y + 1][x + 1] == '*') {
                mines++;
            }
            if (board[y + 1][x - 1] == '*') {
                mines++;
            }
            if (board[y - 1][x + 1] == '*') {
                mines++;
            }
        }
        return mines;
    }
}
