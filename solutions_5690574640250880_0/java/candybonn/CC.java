
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class CC {

    private Pipe pipe = null;

    public CC(String args[]) throws FileNotFoundException, IOException {
        this.pipe = new Pipe(args);
    }

    public static void main(String args[]) throws FileNotFoundException, IOException {
        new CC(args).start();
    }

    public void start() throws FileNotFoundException, IOException {
        int roundCount = pipe.ni();
        for (int round = 1; round <= roundCount; round++) {
            String result = solve();
            String outStr = "Case #" + round + ":" + result + "\n";
            pipe.print(outStr);
//            pipe.nline();
        }
        pipe.close();
    }

    private char matrix[][] = null;
    private int R, C, M;

    public String solve() throws IOException {
        R = pipe.ni();
        C = pipe.ni();
        M = pipe.ni();

        int L = R * C - M;
        matrix = new char[R][C];
        List<Cell> startList = new ArrayList<Cell>();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                startList.add(new Cell(i, j));
            }
        }

        for (Cell cell : startList) {
            matrix[cell.row][cell.col] = 'c';
            if(L == 1) {
                return printMatrix();
            }
            if (search(cell, 1, L)) {
                return printMatrix();
            }
            matrix[cell.row][cell.col] = ' ';
        }

        return "\nImpossible";
    }

    private boolean search(Cell cellCenter, int affectedSize, int L) {
        List<Cell> affected = cover(cellCenter);
        int total = affected.size() + affectedSize;
        if (total == L) {
            return true;
        }
        for (Cell cell : affected) {
            if (search(cell, total, L)) {
                return true;
            }
        }

        uncover(affected);
        return false;

    }

    private List<Cell> cover(Cell cellCenter) {
        List<Cell> affected = new ArrayList<Cell>();
        if (check(cellCenter.row - 1, cellCenter.col - 1)) {
            affected.add(new Cell(cellCenter.row - 1, cellCenter.col - 1));
        }
        if (check(cellCenter.row - 1, cellCenter.col)) {
            affected.add(new Cell(cellCenter.row - 1, cellCenter.col));
        }
        if (check(cellCenter.row - 1, cellCenter.col + 1)) {
            affected.add(new Cell(cellCenter.row - 1, cellCenter.col + 1));
        }
        if (check(cellCenter.row, cellCenter.col - 1)) {
            affected.add(new Cell(cellCenter.row, cellCenter.col - 1));
        }
        if (check(cellCenter.row, cellCenter.col + 1)) {
            affected.add(new Cell(cellCenter.row, cellCenter.col + 1));
        }
        if (check(cellCenter.row + 1, cellCenter.col - 1)) {
            affected.add(new Cell(cellCenter.row + 1, cellCenter.col - 1));
        }
        if (check(cellCenter.row + 1, cellCenter.col)) {
            affected.add(new Cell(cellCenter.row + 1, cellCenter.col));
        }
        if (check(cellCenter.row + 1, cellCenter.col + 1)) {
            affected.add(new Cell(cellCenter.row + 1, cellCenter.col + 1));
        }
        return affected;
    }

    private boolean check(int row, int col) {
        if (row < R && row >= 0 && col < C && col >= 0 && matrix[row][col] != '.' && matrix[row][col] != 'c') {
            matrix[row][col] = '.';
            return true;
        }
        return false;
    }

    private String printMatrix() {
        String value = "\n";
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j] == 'c' || matrix[i][j] == '.') {
                    value += matrix[i][j];
                } else {
                    value += '*';
                }
            }
            if (i != R - 1) {
                value += '\n';
            }
        }
        return value;
    }

    private void uncover(List<Cell> affected) {
        for (Cell cell : affected) {
            matrix[cell.row][cell.col] = '\0';
        }
    }

    private class Cell {

        public Cell(int row, int col) {
            this.col = col;
            this.row = row;
        }
        int row = 0;
        int col = 0;
    }

    private class Pipe {

        private BufferedReader reader;
        private BufferedWriter writer;
        private StringTokenizer tokenizer;

        public Pipe(String args[]) throws FileNotFoundException, IOException {
            if (args != null && args.length >= 1) {
                reader = new BufferedReader(new FileReader(args[0]));
                if (args.length == 2) {
                    writer = new BufferedWriter(new FileWriter(args[1]));
                }
            } else {
                reader = new BufferedReader(new InputStreamReader(System.in));
            }
        }

        public String nline() throws IOException {
            tokenizer = null;
            return reader.readLine();
        }

        public String ns() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        public int ni() throws IOException {
            return Integer.parseInt(ns());
        }

        public long nl() throws IOException {
            return Long.parseLong(ns());
        }

        public float nf() throws IOException {
            return Float.parseFloat(ns());
        }

        public double nd() throws IOException {
            return Double.parseDouble(ns());
        }

        public void print(String str) throws IOException {
            System.out.print(str);
            if (writer != null) {
                writer.write(str, 0, str.length());
            }
        }

        public void close() throws IOException {
            if (writer != null) {
                writer.close();
            }
        }
    }
}
