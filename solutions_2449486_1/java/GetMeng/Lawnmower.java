import gcj.GCJ;

import java.util.Scanner;

public class Lawnmower {

    int[][] g;

    int n;

    int m;

    static final String yes = "YES";

    static final String no = "NO";

    public Lawnmower(int[][] g) {
        this.g = g;
        n = g.length;
        m = g[0].length;
    }

    public String check() {
        for (int h = 100; h > 0; h--) {
            if (!check(h)) {
                return no;
            }
        }
        return yes;
    }

    private boolean check(int h) {
        boolean[][] v = new boolean[n][m];
        checkRow(v, h);
        checkCol(v, h);
        return verify(v, h);
    }

    private void checkRow(boolean[][] v, int h) {
        for (int i = 0; i < n; i++) {
            boolean ok = true;
            for (int j = 0; j < m; j++) {
                if (g[i][j] > h) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int j = 0; j < m; j++) {
                    if (g[i][j] == h) {
                        v[i][j] = true;
                    }
                }
            }
        }
    }

    private void checkCol(boolean[][] v, int h) {
        for (int j = 0; j < m; j++) {
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                if (g[i][j] > h) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int i = 0; i < n; i++) {
                    if (g[i][j] == h) {
                        v[i][j] = true;
                    }
                }
            }
        }
    }

    private boolean verify(boolean[][] v, int h) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == h && !v[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner s = GCJ.createScanner('B', true);
        int t = s.nextInt();
        for (int i = 1; i <= t; i++) {
            int n = s.nextInt();
            int m = s.nextInt();
            int[][] g = new int[n][m];
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    g[x][y] = s.nextInt();
                }
            }
            Lawnmower lm = new Lawnmower(g);
            GCJ.out(i, lm.check());
        }
    }

}
