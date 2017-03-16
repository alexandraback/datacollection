import java.io.*;
import java.util.StringTokenizer;

public class ProblemB {

    public static void main(String[] args) throws Exception {
        new ProblemB();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "B-small-attempt0";

    public ProblemB() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    private void solve() throws Exception {
        int T = nextInt();
        TEST:
        for (int it = 1; it <= T; ++it) {
            out.print("Case #" + it + ": ");
            int n = nextInt();
            int m = nextInt();
            int[][] a = new int[n][m];
            int[][] res = new int[n][m];
            int[] max1 = new int[n];
            int[] max2 = new int[m];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    a[i][j] = nextInt();
                    res[i][j] = 1000;
                    max1[i] = Math.max(max1[i], a[i][j]);
                    max2[j] = Math.max(max2[j], a[i][j]);
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (a[i][j] != Math.min(max1[i], max2[j])) {
                        out.println("NO");
                        continue TEST;
                    }
                }
            }
            out.println("YES");
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
            