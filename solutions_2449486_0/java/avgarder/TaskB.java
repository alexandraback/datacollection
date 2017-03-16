import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TaskB implements Runnable {

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

    final int MAXN = 100;
    final int MAXM = 100;
    final int MAXH = 100;

    int[][] a = new int[MAXN][MAXM];
    int[][] b = new int[MAXN][MAXM];

    // File names!!!

    void solve() throws IOException {
        int ct = nextInt();

        for (int nt = 1; nt <= ct; nt++) {
            out.print("Case #" + nt + ": ");

            int n = nextInt();
            int m = nextInt();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = nextInt();
                    b[i][j] = MAXH;
                }
            }

            for (int k = 0; k < n; k++) {
                int max = a[k][0];
                for (int i = 1; i < m; i++) {
                    max = Math.max(max, a[k][i]);
                }
                for (int i = 0; i < m; i++) {
                    b[k][i] = Math.min(b[k][i], max);
                }
            }

            for (int k = 0; k < m; k++) {
                int max = a[0][k];
                for (int i = 1; i < n; i++) {
                    max = Math.max(max, a[i][k]);
                }
                for (int i = 0; i < n; i++) {
                    b[i][k] = Math.min(b[i][k], max);
                }
            }

            boolean correct = true;

            f1:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] != b[i][j]) {
                        correct = false;
                        break f1;
                    }
                }
            }

            out.println(correct ? "YES" : "NO");
        }
    }

    public void run() {
        try {
            in = new BufferedReader(new FileReader("taskb.in"));
            out = new PrintWriter("taskb.out");
            solve();
            out.close();
            in.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        new Thread(new TaskB()).start();
    }
}
