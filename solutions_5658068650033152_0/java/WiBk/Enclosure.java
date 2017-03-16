import java.util.*;
import java.io.*;

public class Enclosure {
    FastScanner in;
    PrintWriter out;

    int n, m;
    boolean[][] stone;
    boolean[][] was;
    boolean[][] free;
    int ans = 1000;
    int count, k;

    public boolean dfs(int row, int col) {
        //out.println(row + " " + col);
        if (row == n || col == m || row == -1 || col == -1) {
            return true;
        }

        if (was[row][col]) {
            return free[row][col];
        }
        was[row][col] = true;
        if (stone[row][col]) {
            count++;
            free[row][col] = false;
            return false;
        }

        if (dfs(row + 1, col) || dfs(row - 1, col) || dfs(row, col + 1) || dfs(row, col - 1)) {
            free[row][col] = true;
            return true;
        } else {
            count++;
            free[row][col] = false;
            return false;
        }
    }

    public void brute(int row, int col, int cnt) {
        if (col >= m) {
            brute(row + 1, 0, cnt);
            return;
        }

        if (row >= n) {
            //out.println(stone[0][0]);
            was = new boolean[n][m];
            free = new boolean[n][m];
            count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!was[i][j]) {
                        dfs(i, j);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!free[i][j]) {
                        was[i][j] = false;
                    }
                }
            }
            count = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!was[i][j]) {
                        dfs(i, j);
                    }
                }
            }
            //out.println(count);
            if (count >= k) {
                /*if (cnt == 7 && ans != 7) {
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (stone[i][j]) {
                                out.print("o");
                            } else {
                                out.print("#");
                            }
                        }
                        out.println();
                    }
                    out.println();

                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            if (free[i][j]) {
                                out.print("F");
                            } else {
                                out.print("B");
                            }
                        }
                        out.println();
                    }
                    out.println();

                    out.println(count);
                }*/
                ans = Math.min(ans, cnt);
            }
            return;
        }

        stone[row][col] = true;
        brute(row, col + 1, cnt + 1);
        stone[row][col] = false;
        brute(row, col + 1, cnt);
    }

    public void solve() throws IOException {
        int t = in.nextInt();
        for (int test = 1; test <= t; test++) {
            ans = 1000;
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            stone = new boolean[n][m];
            brute(0, 0, 0);
            out.println("Case #" + test + ": " + ans);
            System.out.println(test);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("enclosure.in"));
            out = new PrintWriter(new File("enclosure.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new Enclosure().run();
    }
}