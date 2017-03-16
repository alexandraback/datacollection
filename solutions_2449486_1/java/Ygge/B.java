import java.io.*;
import java.util.*;

public class B {

    private static final String FILE_NAME = "B-large";

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            int[][] board = readBoard(in);
            out.write(String.format("Case #%d: %s\n", c, canCut(board) ? "YES" : "NO"));
        }
        out.close();
    }

    private static boolean canCut(int[][] board) {
        TreeMap<Integer, List<Cell>> heights = new TreeMap<Integer, List<Cell>>(Collections.reverseOrder());
        for (int y = 0; y < board.length; ++y) {
            for (int x = 0; x < board[0].length; ++x) {
                int height = board[y][x];
                List<Cell> cells = heights.get(height);
                if (cells == null) {
                    cells = new ArrayList<Cell>();
                    heights.put(height, cells);
                }
                cells.add(new Cell(x, y));
            }
        }

        boolean[][] cutCorrectly = new boolean[board.length][board[0].length];
        for (List<Cell> cells : heights.values()) {
            for (Cell cell : cells) {
                if (!canCutShorter(cell, cutCorrectly)) {
                    return false;
                }
            }
            for (Cell cell : cells) {
                cutCorrectly[cell.y][cell.x] = true;
            }
        }
        return true;
    }

    private static boolean canCutShorter(Cell cell, boolean[][] cutCorrectly) {
        return checkCut(cell.x, 0, 0, 1, cutCorrectly) || checkCut(0, cell.y, 1, 0, cutCorrectly);
    }

    private static boolean checkCut(int x, int y, int dx, int dy, boolean[][] cutCorrectly) {
        while (true) {
            if (y >= cutCorrectly.length || x >= cutCorrectly[y].length) {
                return true;
            }
            if (cutCorrectly[y][x]) {
                return false;
            }
            x += dx;
            y += dy;
        }
    }

    private static int[][] readBoard(BufferedReader in) throws IOException {
        String[] first = in.readLine().split(" ");
        int n = Integer.parseInt(first[0]);
        int m = Integer.parseInt(first[1]);
        int[][] board = new int[n][m];
        for (int i = 0; i < n; ++i) {
            String[] row = in.readLine().split(" ");
            for (int j = 0; j < m; ++j) {
                board[i][j] = Integer.parseInt(row[j]);
            }
        }
        return board;
    }

    private static class Cell {
        private final int x, y;

        private Cell(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Cell{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }
}
