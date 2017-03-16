import java.io.*;
import java.util.StringTokenizer;

public class ProblemBNew {

    public static void main(String[] args) throws Exception {
        new ProblemBNew();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "B-small-attempt4";

    public ProblemBNew() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    double ok = 0, total = 0;

    private void solve() throws Exception {
        int T = nextInt();
        for (int ii = 1; ii <= T; ++ii) {
            out.print("Case #" + ii + ": ");
            int n = nextInt();
            int x = Math.abs(nextInt());
            int y = nextInt();
            go(n, x, y, new boolean[2000][1000], 1000, 0);
            out.println(ok / total);
            ok = total = 0;
        }
    }

    void go(int n, int x0, int y0, boolean[][] a, int x, int y) {
        if (n == 0) {
            total++;
            if (x0 + 1000 > a.length || y0 > a[x0 + 1000].length) {
                return;
            }
            if (a[x0 + 1000][y0]) {
                ok++;
            }
            return;
        }
        int xt = x;
        int yt = y;
        while (yt > 0 && !a[xt - 1][yt - 1]) {
            xt--;
            yt--;
        }
        if (xt != x) {
            a[xt][yt] = true;
            go(n - 1, x0, y0, a, x, y);
            a[xt][yt] = false;
        }
        xt = x;
        yt = y;
        while (yt > 0 && !a[xt + 1][yt - 1]) {
            xt++;
            yt--;
        }
        if (xt != x) {
            a[xt][yt] = true;
            go(n - 1, x0, y0, a, x, y);
            a[xt][yt] = false;
        }
        if (y == 0 || a[x - 1][y - 1] && a[x + 1][y - 1]) {
            a[x][y] = true;
            go(n - 1, x0, y0, a, x, y + 2);
            a[x][y] = false;
        }
    }



    private void init() throws FileNotFoundException {
        if (fileName.equals("#Console")) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else if (fileName.equals("#IOtxt")) {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } else {
            in = new BufferedReader(new FileReader(fileName + ".in"));
            out = new PrintWriter(fileName + ".out");
        }
    }


    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }


    private String nextToken() throws IOException {
        while (!tok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            tok = new StringTokenizer(s);
        }
        return tok.nextToken();
    }

}
            