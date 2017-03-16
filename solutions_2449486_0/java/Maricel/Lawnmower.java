package B;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

class LawnMower {

    Scanner in;
    BufferedWriter out;
    private int m;
    private int n;
    private int[][] table;
    private int[] rows, cols;

    LawnMower(String input, String output) throws Exception {
        in = new Scanner(new File(input));
        FileWriter fstream = new FileWriter(output);
        out = new BufferedWriter(fstream);
    }

    public static void main(String[] args) throws Exception {
        LawnMower lawnmower = new LawnMower("src/B/in", "src/B/out");
        lawnmower.solve();
        lawnmower.close();
    }

    public void solve() throws IOException {
        int tests = in.nextInt();

        for (int i = 1; i <= tests; i++) {
            table = readTable();

            if (back(0, 0)) {
                printYes(i);
            } else {
                printNo(i);
            }
        }
    }

    private boolean back(int i, int j) {
        if (i == n) {
            return true;
        }

        if (alreadyMown(i, j)) {
            return back(i + (j + 1) / m, (j + 1) % m);
        }

        if (canMowRow(i, table[i][j])) {
            rows[i] = table[i][j];
            if (back(i + (j + 1) / m, (j + 1) % m)) {
                return true;
            }
            rows[i] = 0;
        }

        if (canMowCol(j, table[i][j])) {
            cols[j] = table[i][j];
            return back(i + (j + 1) / m, (j + 1) % m);
        }
        
        return false;
    }
    
    private boolean alreadyMown(int i, int j) {
        return Math.min(rows[i], cols[j]) == table[i][j];
    }

    private boolean canMowRow(int row, int h) {
        for (int j = 0; j < m; j++) {
            if (table[row][j] > h) {
                return false;
            }
        }
        return true;
    }

    private boolean canMowCol(int col, int h) {
        for (int i = 0; i < n; i++) {
            if (table[i][col] > h) {
                return false;
            }
        }
        return true;
    }

    private int[][] readTable() {
        n = in.nextInt();
        m = in.nextInt();
        table = new int[n][m];
        rows = new int[n];
        cols = new int[m];
        
        Arrays.fill(rows, 100);
        Arrays.fill(cols, 100);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                table[i][j] = in.nextInt();
            }
        }
        return table;
    }

    private void printYes(int test) throws IOException {
        String s = "Case #" + test + ": YES\n";
        out.write(s);
    }

    private void printNo(int test) throws IOException {
        String s = "Case #" + test + ": NO\n";
        out.write(s);
    }

    private void close() throws IOException {
        this.in.close();
        this.out.close();
    }

}
