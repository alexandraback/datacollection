import java.util.Scanner;

public class Minesweeper {
    public static class Solver {

        int rows;
        int columns;
        int mines;
        int tiles;
        int remainingClears;

        char[][] board;


        public Solver(int rows, int columns, int mines) {
            this.rows = rows;
            this.columns = columns;
            this.mines = mines;

            board = new char[rows][columns];

            tiles = rows * columns;
            remainingClears = tiles - mines;

            // Initialize the board as all mines
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    board[i][j] = '*';
                }
            }
        }

        public void open(int row, int column) {
            if (board[row][column] != '.') {
                board[row][column] = '.';
                remainingClears--;
            }
        }

        // Return true if possible
        public boolean solve() {

            // Linear horizontal
            if (rows == 1) {
                for (int i = 0; i < remainingClears; i++) {
                    board[0][i] = '.';
                }

                return true;
            }

            // Linear vertical
            else if (columns == 1) {
                for (int i = 0; i < remainingClears; i++) {
                    board[i][0] = '.';
                }

                return true;
            }

            // Trivial clear space
            if (remainingClears == 1) {
                board[0][0] = '*';
                return true;
            }

            // Impossibles
            if (remainingClears == 2 || remainingClears == 3 || remainingClears == 5 || remainingClears == 7) {
                return false;
            }

            open(0, 0);
            open(0, 1);
            open(1, 0);
            open(1, 1);

            if (remainingClears == 0) {
                return true;
            }

            if (columns > 2) {
                open(0, 2);
                open(1, 2);
            }


            if (remainingClears == 0) {
                return true;
            }

            if (rows > 2) {
                open(2, 0);
                open(2, 1);
            }

            if (remainingClears == 0) {
                return true;
            }

            for (int col = 3; col < columns && remainingClears > 1; col++) {
                open(0, col);
                open(1, col);
            }
            for (int row = 3; row < rows && remainingClears > 1; row++) {
                open(row, 0);
                open(row, 1);
            }

            if (remainingClears == 0) {
                return true;
            }


            for (int col = 2; col < columns; col++) {
                for (int row = 2; row < rows; row++) {
                    open(row, col);
                    if (remainingClears == 0) {
                        return true;
                    }
                }
            }

            return false;
        }
    }

    public static void main(String[] args) {
        final Scanner in = new Scanner(System.in);
        final int testCases = in.nextInt();
        for (int testCase = 1; testCase <= testCases; testCase++) {
            Solver s = new Solver(in.nextInt(), in.nextInt(), in.nextInt());

            System.out.println("Case #" + testCase + ":");

            if (s.solve()) {
                char[][] board = s.board;
                board[0][0] = 'C';

                for (char[] row : board) {
                    System.out.println(new String(row));
                }
            } else {
                System.out.println("Impossible");
            }
        }
    }
}
