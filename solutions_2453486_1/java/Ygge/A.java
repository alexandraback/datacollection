import java.io.*;

public class A {

    private static final String FILE_NAME = "A-large";

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            char[][] board = readBoard(in);
            int result = won(board, 0, 0, 1, 0);
            result |= won(board, 0, 0, 0, 1);
            result |= won(board, 0, 0, 1, 1);

            result |= won(board, 0, 1, 1, 0);
            result |= won(board, 0, 2, 1, 0);
            result |= won(board, 0, 3, 1, 0);

            result |= won(board, 1, 0, 0, 1);
            result |= won(board, 2, 0, 0, 1);
            result |= won(board, 3, 0, 0, 1);

            result |= won(board, 3, 0, -1, 1);

            String str;
            if (result == 0) {
                if (allOccupied(board)) {
                    str = "Draw";
                } else {
                    str = "Game has not completed";
                }
            } else if (result == 1) {
                str = "O won";
            } else if (result == 2) {
                str = "X won";
            } else {
                throw new RuntimeException("Strange result: " + result);
            }
            out.write(String.format("Case #%d: %s\n", c, str));
            in.readLine();
        }
        out.close();
    }

    private static boolean allOccupied(char[][] board) {
        for (char[] row : board) {
            for (char cell : row) {
                if (cell == '.') {
                    return false;
                }
            }
        }
        return true;
    }

    private static int won(char[][] board, int x, int y, int dx, int dy) {
        int t = 0;
        for (int i = 0; i < 4; ++i) {
            if (board[x][y] == 'O') {
                if (t == 2) {
                    return 0;
                }
                t = 1;
            } else if (board[x][y] == 'X') {
                if (t == 1) {
                    return 0;
                }
                t = 2;
            } else if (board[x][y] != 'T') {
                return 0;
            }
            x += dx;
            y += dy;
        }
        return t;
    }

    private static char[][] readBoard(BufferedReader in) throws IOException {
        char[][] board = new char[4][];
        for (int i = 0; i < 4; ++i) {
            board[i] = in.readLine().toCharArray();
        }
        return board;
    }
}
