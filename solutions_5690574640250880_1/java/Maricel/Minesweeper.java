package A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

class Minesweeper {

    Scanner in;
    BufferedWriter out;

    Minesweeper(String input, String output) throws Exception {
        in = new Scanner(new File(input));
        FileWriter fstream = new FileWriter(output);
        out = new BufferedWriter(fstream);
    }

    public static void main(String[] args) throws Exception {
        Minesweeper tictactoe = new Minesweeper("src/A/in.txt", "src/A/out.txt");
        tictactoe.solve();
        System.out.println("finished");
        tictactoe.close();
    }
    int k, n, m;
    char[][] a;
    
    public void solveBack() throws IOException {
        int T = in.nextInt();

        for (int t = 1; t <= T; t++) {
            out.flush();
            System.out.println("running test " + t);
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            a = new char[n][m];
            
            if (back(0, 0, 0)) {
                printSol(t, a);
            } else {
                checkWithBackAndPrintImpossible(t);
            }
        }
    }
    
    private boolean back(int i, int j, int count) {
        if (i == n && j == 0) {
            if (isSolvableByOneClick()) {
                return true;
            }
        } else {
            if ((m - j - 1 + (n - i - 1) * m) >= (k-count)) {
                a[i][j] = '.';
                if (back(i + (j+1)/m, (j+1) % m, count)) {
                    return true;
                }
            }
            if (count < k) {
                a[i][j] = '*';
                if (back(i + (j+1)/m, (j+1) % m, count + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    private boolean isSolvableByOneClick() {
        if (k == m*n - 1) { 
            return true;
        }
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j <a[0].length; j++) {
                if (a[i][j] != '*' && hasNoNeighborBombs(i, j)) {
                    if (isOneClickAway(i, j)) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
        return false;
    }
    
    private boolean hasNoNeighborBombs(int i, int j) {
        for (int k = 0; k < 8; k++) {
            int ii = i + dx[k];
            int jj = j + dy[k];
            if (0 <= ii && ii < n && 0 <= jj && jj < m
                    && a[ii][jj] == '*') {
                return false;
            }
        }
        return true;
    }
    
    private boolean isOneClickAway(int x, int y) {
        boolean[][] viz = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '*') {
                    viz[i][j] = true;
                }
            }
        }
        viz[x][y] = true;
        fill(viz, x, y);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!viz[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    private static final int[] dx = {-1, 0, 1, 1, 1, 0, -1, -1};
    private static final int[] dy = {-1, -1, -1, 0, 1, 1, 1, 0};
    
    private void fill(boolean[][] viz, int i, int j) {
        for (int k = 0; k <8; k++) {
            int ii = i + dx[k];
            int jj = j + dy[k];
            if (0 <= ii && ii < n && 0 <= jj && jj < m) {
                boolean go = !viz[ii][jj] && hasNoNeighborBombs(ii, jj);
                viz[ii][jj] = true;
                if (go) {
                    fill(viz, ii, jj);
                }
            }
        }
    }

    public void solve() throws IOException {
        int T = in.nextInt();

        for (int t = 1; t <= T; t++) {
            out.flush();
            System.out.println("running test " + t);
            n = in.nextInt();
            m = in.nextInt();
            int min = Math.min(m, n);
            k = in.nextInt();

            a = new char[n][m];
            fill(a, '.');
            if (m == 1) {
                int i;
                for (i = 0; i < k; i++) {
                    a[i][0] = '*';
                }
                a[n - 1][0] = 'c';
                printSol(t, a);
                continue;
            }
            if (n == 1) {
                int i;
                for (i = 0; i < k; i++) {
                    a[0][i] = '*';
                }
                a[0][m - 1] = 'c';
                printSol(t, a);
                continue;
            }
            if (min == 2 && k % 2 == 1 && k != m*n-1) {
                checkWithBackAndPrintImpossible(t);
                continue;
            }
            if (k == m * n - 2 * min
                    || k < m * n - 2 * min - 1) {

                int i, j = 0;
                int mines = 0;
                int row = -1, col = -1;

                if (min == m) {
                    for (i = 0; i < n && mines < k; i++) {
                        for (j = 0; j < m && mines < k; j++) {
                            row = i;
                            col = j;
                            a[row][col] = '*';
                            mines++;
                        }
                    }
                } else {
                    for (j = 0; j < m && mines < k; j++) {
                        for (i = 0; i < n && mines < k; i++) {
                            row = i;
                            col = j;
                            a[row][col] = '*';
                            mines++;
                        }
                    }
                }

                if ((m * n - 1 - k) % min == 0) {
                    a[row][col] = '.';
                    if (min == m) {
                        a[row + 1][0] = '*';
                    } else {
                        a[0][col + 1] = '*';
                    }
                }
                a[n - 1][m - 1] = 'c';
                printSol(t, a);
                continue;
            }
            int e = m * n - k;
            if (e == 2 || e == 3 || e == 5 || e == 7) {
                checkWithBackAndPrintImpossible(t);
                continue;
            }

            fill(a, '*');
            
            if (e == 6 || e == 8) {
                int ii = 2, jj = e/2;
                for (int i = 0; i < ii; i++) {
                    for (int j = 0; j < jj; j++) {
                        a[i][j] = '.';
                    }
                }
                a[0][0]='c';
                printSol(t, a);
                continue;
            }

            int f = (int) Math.sqrt(e);
            for (int i = 0; i < f; i++) {
                for (int j = 0; j < f; j++) {
                    a[i][j] = '.';
                }
            }
            a[0][0] = 'c';
            int r = e - f * f;
            if (r == 0) {
                printSol(t, a);
                continue;
            }
            if (r == 1) {
                a[0][f] = '.';
                a[1][f] = '.';
                a[f - 1][f - 1] = '*';
                printSol(t, a);
                continue;
            }
            if (r > 1 && r <= f) {
                for (int i = 0; i < r; i++) {
                    a[i][f] = '.';
                }
                printSol(t, a);
                continue;
            }
            if (r == f+1) {
                for (int i = 0; i < f-1; i++) {
                    a[i][f] = '.';
                }
                a[f][0] = '.';
                a[f][1] = '.';
                printSol(t, a);
                continue;
            }
            if (r == f + 2) {
                for (int i = 0; i < f; i++) {
                    a[i][f] = '.';
                }
                a[f][0] = '.';
                a[f][1] = '.';
                printSol(t, a);
                continue;
            }

            for (int i = 0; i < f; i++) {
                a[i][f] = '.';
            }

            for (int i = r; i > f; i--) {
                a[f][i - f] = '.';
            }
            printSol(t, a);

        }
    }

    private void fill(char[][] a, char c) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                a[i][j] = c;
            }
        }
    }

    private void print(String s) throws IOException {
        out.write(s);
    }

    private void checkWithBackAndPrintImpossible(int test) throws IOException {        
        print("Case #" + test + ":\nImpossible\n");
    }

    private void printSol(int test, char[][] a) throws IOException {        
        print("Case #" + test + ":\n"); // " + a.length + "x" + a[0].length + ", " + k + "\n");
        for (int i = 0; i < a.length; i++) {
            print(new String(a[i]) + "\n");
        }
    }

    private void close() throws IOException {
        this.in.close();
        this.out.close();
    }
}