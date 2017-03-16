import java.io.*;
import java.util.*;

public class TaskA implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer stok;

    String nextToken() {
        try {
            while (stok == null || !stok.hasMoreTokens()) {
                stok = new StringTokenizer(in.readLine());
            }
            return stok.nextToken();
        } catch (IOException e) {
            return null;
        }
    }

    int nextInt() {
        return Integer.parseInt(nextToken());
    }

    long nextLong() {
        return Long.parseLong(nextToken());
    }

    double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    char[][] a;

    char get(int x, int y) {
        if (x < 0 || x >= 4 || y < 0 || y >= 4) {
            return '\0';
        }
        return a[x][y];
    }

    // File names!!!

    void solve() throws IOException {
        a = new char[4][4];

        int ct = nextInt();
        tests: for (int tn = 1; tn <= ct; tn++) {
            out.print("Case #" + tn + ": ");

            boolean hasDots = false;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    a[i][j] = (char) in.read();
                    if (a[i][j] == '.') {
                        hasDots = true;
                    }
                }
                in.readLine();
            }
            in.readLine();

            boolean flc, flr, fld, fld2;

            char winner = '\0';

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (a[i][j] == '.') {
                        continue;
                    }
                    flc = flr = fld = fld2 = true;
                    for (int k = 1; k < 4; k++) {
                        if (get(i, j + k) != 'T' && get(i, j + k) != get(i, j)) {
                            flr = false;
                        }

                        if (get(i + k, j) != 'T' && get(i + k, j) != get(i, j)) {
                            flc = false;
                        }

                        if (get(i + k, j + k) != 'T' && get(i + k, j + k) != get(i, j)) {
                            fld = false;
                        }

                        if (get(i + k, j - k) != 'T' && get(i + k, j - k) != get(i, j)) {
                            fld2 = false;
                        }
                    }
                    if (flc) {
                        winner = get(i, j) == 'T' ? get(i + 1, j) : get(i, j);
                    }
                    if (flr) {
                        winner = get(i, j) == 'T' ? get(i, j + 1) : get(i, j);
                    }
                    if (fld) {
                        winner = get(i, j) == 'T' ? get(i + 1, j + 1) : get(i, j);
                    }
                    if (fld2) {
                        winner = get(i, j) == 'T' ? get(i + 1, j - 1) : get(i, j);
                    }
                    if (winner != '\0') {
                        out.println(winner + " won");
                        continue tests;
                    }
                }
            }
            out.println(hasDots ? "Game has not completed" : "Draw");
        }
    }

    public void run() {
        try {
            in = new BufferedReader(new FileReader("taska.in"));
            out = new PrintWriter("taska.out");
            solve();
            out.close();
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        new Thread(new TaskA()).start();
    }
}
