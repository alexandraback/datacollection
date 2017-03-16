import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SkyStupid {
    FastScanner in;
    PrintWriter out;

    int MAXN = 23;

    double[][][] ans = new double[MAXN][2 * MAXN][2 * MAXN];

    public void solve() throws IOException {
        int cases = in.nextInt();
        for (int test = 1; test <= cases; test++) {
            int n = in.nextInt();
            int x = in.nextInt();
            int y = in.nextInt();

            out.println("Case #" + test + ": " + get(n, MAXN + x, y));
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-small-attempt0.in"));
            out = new PrintWriter(new File("B-small.out"));

            precalc();
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void precalc() {
        for (int num = 1; num < MAXN; num++) {
            for (int y = 0; y < MAXN; y++) {
                for (int x = 0; x < 2 * MAXN; x++) {
                    ans[num][x][y] = ans[num - 1][x][y];
                }
            }

            int y = 0;
            while (ans[num][MAXN][y] == 1) {
                y += 2;
            }

            int dx = y;
            while (ans[num][MAXN - dx][y - dx] == 1) {
                dx--;
            }

            double v = ans[num][MAXN - dx][y - dx];
            if (v == 0 || dx == 1) {
                ans[num][MAXN - dx][y - dx] += 0.5;
                ans[num][MAXN + dx][y - dx] += 0.5;
            } else {
                ans[num][MAXN - dx][y - dx] += 0.25;
                ans[num][MAXN - dx + 1][y - dx + 1] += 0.25;
                ans[num][MAXN + dx][y - dx] += 0.25;
                ans[num][MAXN + dx - 1][y - dx + 1] += 0.25;
            }

//            for (double [] x : ans[num]) {
//                System.out.println(Arrays.toString(x));
//            }
//            System.out.println("---------------------");
        }
    }

    private double get(int num, int x, int y) {
        if (x < 0 || x >= 2 * MAXN) {
            return 0;
        }
        if (y < 0 || y > MAXN) {
            return 0;
        }
        return ans[num][x][y];
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
        new SkyStupid().run();
    }
}