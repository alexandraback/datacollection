import javax.swing.*;
import java.io.*;
import java.util.Arrays;
import java.util.HashMap;

public class Minesweeper {
    static class CacheKey {
        final int rows, cols, mines;
        CacheKey(int rows, int cols, int mines) {
            this.rows = rows;
            this.cols = cols;
            this.mines = mines;
        }

        @Override
        public int hashCode() {
            return mines * 10000 + rows * 100 + cols;
        }

        @Override
        public boolean equals(Object obj) {
            CacheKey other = (CacheKey)obj;
            return rows == other.rows && cols == other.cols && mines == other.mines;
        }

        CacheKey flip() {
            return new CacheKey(cols, rows, mines);
        }
    }

    HashMap<CacheKey, char[][]> cache = new HashMap<>();

    char[][] result(int rows, int cols, int mines) {
        CacheKey key = new CacheKey(rows, cols, mines);
        if (cache.containsKey(key))
            return cache.get(key);

        CacheKey flippedKey = key.flip();
        if (cache.containsKey(flippedKey)) {
            char[][] res = flip(cache.get(flippedKey));
            cache.put(key, res);
            return res;
        }

        if (mines == rows * cols - 1) {
            char[][] res = new char[rows][cols];
            for (char[] row : res)
                Arrays.fill(row, '*');
            res[0][0] = '.';
            cache.put(key, res);
            return res;
        }

        if (mines == 0) {
            char[][] res = new char[rows][cols];
            for (char[] row : res)
                Arrays.fill(row, '.');
            cache.put(key, res);
            return res;
        }

        if (rows == 1 || cols == 1) {
            if (rows > 1) {
                char[][] res = flip(result(cols, rows, mines));
                cache.put(key, res);
                return res;
            }

            char[][] res = new char[1][cols];
            Arrays.fill(res[0], '.');
            for (int a = 1; a <= mines; a++)
                res[0][cols - a] = '*';
            cache.put(key, res);
            return res;
        }

        if (rows == 2 || cols == 2) {
            if (rows > 2) {
                char[][] res = flip(result(cols, rows, mines));
                cache.put(key, res);
                return res;
            }

            if ((mines & 1) != 0) {
                cache.put(key, null);
                return null;
            }

            int half = mines / 2;
            if (half == cols - 1) {
                cache.put(key, null);
                return null;
            }

            char[][] res = new char[2][cols];
            for (char[] row : res)
                Arrays.fill(row, '.');
            for (int a = 1; a <= half; a++) {
                res[0][cols - a] = '*';
                res[1][cols - a] = '*';
            }
            cache.put(key, res);
            return res;
        }

        if (cols == 3 && rows == 3) {
            char[][] res = null;
            switch (mines) {
                case 1: res = quickRes("...", "...", "..*"); break;
                case 3: res = quickRes("...", "...", "***"); break;
                case 5: res = quickRes("..*", "..*", "***"); break;
            }
            cache.put(key, res);
            return res;
        }

        if (mines >= (rows + cols - 1)) {
            char[][] tmp = result(rows - 1, cols - 1, mines - rows - cols + 1);
            if (tmp != null) {
                char[][] res = add(tmp, 1, 1);
                cache.put(key, res);
                return res;
            }
        }

        if (mines >= rows) {
            char[][] tmp = result(rows, cols - 1, mines - rows);
            if (tmp != null) {
                char[][] res = add(tmp, 1, 0);
                cache.put(key, res);
                return res;
            }
        }

        if (mines >= cols) {
            char[][] tmp = result(rows - 1, cols, mines - cols);
            if (tmp != null) {
                char[][] res = add(tmp, 0, 1);
                cache.put(key, res);
                return res;
            }
        }

        if (mines >= Math.min(cols, rows)) {
            cache.put(key, null);
            return null;
        }

        if (rows > cols) {
            char[][] res = flip(result(cols, rows, mines));
            cache.put(key, res);
            return res;
        }

        char[][] res = new char[rows][cols];
        for (char[] row: res)
            Arrays.fill(row, '.');
        for (int a = 1; a <= mines; a++)
            res[rows - 1][cols - a] = '*';

        if (res[rows - 1][0] == '.' && res[rows - 1][1] == '*') {
            res[rows - 1][1] = '.';
            res[rows - 2][cols - 1] = '*';
        }

        cache.put(key, res);
        return res;
    }

    private char[][] quickRes(String... rows) {
        char[][] res = new char[rows.length][];
        for (int a = 0; a < rows.length; a++)
            res[a] = rows[a].toCharArray();
        return res;
    }

    boolean allWillOpen(char[][] board) {
        int rows = board.length;
        int cols = board[0].length;

        for (int r = 0; r < rows; r++) {
            next:
            for (int c = 0; c < cols; c++) {
                if (r == 0 && c == 0)
                    continue;
                if (board[r][c] != '.')
                    continue;

                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (!onBoard(board, r + dr, c + dc))
                            continue;
                        if (board[r + dr][c + dc] != '.')
                            continue;
                        if (n(board, r + dr, c + dc) == 0)
                            continue next;
                    }
                }

                return false;
            }
        }

        return true;
    }

    int newNonZeros(char[][] board, int r, int c) {
        if (board[r][c] != '.')
            throw new IllegalStateException();

        int res = 0;
        for (int pass = 1; pass >= -1; pass -=2) {
            board[r][c] = pass == 1 ? '*' : '.';
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0)
                        continue;

                    if (!onBoard(board, r + dr, c + dc))
                        continue;
                    if (board[r + dr][c + dc] != '.')
                        continue;
                    if (n(board, r + dr, c + dc) > 0)
                        res += pass;
                }
            }
        }

        return res;
    }

    int n(char[][] board, int r, int c) {
        int res = 0;
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dc == 0 && dr == 0)
                    continue;

                if (onBoard(board, r + dr, c + dc))
                    if (board[r + dr][c + dc] == '*')
                        res++;
            }
        }
        return res;
    }

    boolean onBoard(char[][] board, int r, int c) {
        if (r < 0 || c < 0 || r >= board.length || c >= board[0].length)
            return false;
        return true;
    }

    char[][] flip(char[][] in) {
        if (in == null)
            return null;

        char[][] res = new char[in[0].length][in.length];
        for (int a = 0; a < in.length; a++)
            for (int b = 0; b < in[a].length; b++)
                res[b][a] = in[a][b];

        return res;
    }

    char[][] add(char[][] in, int cols, int rows) {
        if (in == null)
            return null;

        char[][] res = new char[in.length + rows][in[0].length + cols];
        for (int a = 0; a < in.length; a++) {
            Arrays.fill(res[a], '*');
            System.arraycopy(in[a], 0, res[a], 0, in[a].length);
        }
        for (int a = in.length; a < res.length; a++) {
            res[a] = res[0].clone();
            Arrays.fill(res[a], '*');
        }

        return res;
    }

    void process() throws IOException {
        int nCases = readInt();
        for (int c = 1; c <= nCases; c++) {
            int[] in = readInts();

            int rows = in[0];
            int cols = in[1];
            int mines = in[2];

            char[][] res = result(rows, cols, mines);

            writeln("Case #" + c + ":");
            if (res == null) {
                writeln("Impossible");
            } else {
                res[0][0] = 'c';
                for (char[] line : res)
                    writeln(new String(line));
                res[0][0] = '.';
            }
        }

        done();
    }

    public Minesweeper(File inputFile) throws FileNotFoundException {
        this.inputFile = inputFile;
        this.outputFile = new File(inputFile.getParentFile(), inputFile.getName() + ".out");
        this.reader = new LineNumberReader(new FileReader(inputFile));
        this.result = new StringBuilder();
    }

    private StringBuilder result;
    private File inputFile;
    private LineNumberReader reader;
    private File outputFile;

    void done() throws IOException {
        FileOutputStream fos = new FileOutputStream(outputFile);
        fos.write(result.toString().getBytes("UTF-8"));
        fos.close();

        System.out.println(inputFile + " => " + outputFile);
    }

    void writeln(String s) {
        write(s + "\n");
    }

    void write(String s) {
        System.out.print(s);
        result.append(s);
    }

    int readInt() throws IOException {
        return readInts()[0];
    }

    int[][] readIntMatrix(int nLines) throws IOException {
        int[][] res = new int[nLines][];
        for (int a = 0; a < nLines; a++)
            res[a] = readInts();
        return res;
    }

    double[] readDoubles() throws IOException {
        String l = reader.readLine().trim();
        String[] parts = l.split(" ");
        double[] res = new double[parts.length];
        for (int a = 0; a < res.length; a++)
            res[a] = Double.parseDouble(parts[a]);
        return res;
    }

    int[] readInts() throws IOException {
        String l = reader.readLine().trim();
        String[] parts = l.split(" ");
        int[] res = new int[parts.length];
        for (int a = 0; a < res.length; a++)
            res[a] = Integer.parseInt(parts[a]);
        return res;
    }

    public static void main(String[] args) throws Exception {
        JFileChooser jfc = new JFileChooser();
        jfc.setCurrentDirectory(new File("/home/mitja/codejam"));
        if (jfc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
            new Minesweeper(jfc.getSelectedFile()).process();
        }
    }
}
