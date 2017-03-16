import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ProbC2 {
    boolean eof;
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new ProbC2().run();
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "-1";
            }
        }
        return st.nextToken();
    }

    void run() throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        String name = "name";
        try {
            File f = new File(name + ".in");
            if (f.exists() && f.canRead()) {
                input = new FileInputStream(f);
                output = new PrintStream(name + ".out");
            }
        } catch (Throwable e) {
            e.printStackTrace();
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solve();
        br.close();
        out.close();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }


    int[][] edges;
    String[] a;
    int[] us;
    int n;


    void rec(int u, String way, int kol, String cur) {
        System.err.print((u + 1) + " ");
        if (kol == 0) {
            ans.add(cur);
            System.err.println();
            return;
        }
        us[u] = 1;
        for (int i = 0; i < n; ++i) {
            if (us[i] == 0) {
                if (edges[u][i] == 1) {
                    rec(i, way + (i), kol - 1, cur + a[i]);
                } else {
                    for (int j = 0; j < n; ++j) {
                        if (way.indexOf((char) (j + '0')) >= 0 && edges[j][i] == 1) {
                            rec(i, way.substring(0, way.indexOf((char) (j + '0')) + 1) + (i), kol - 1, cur + a[i]);
                        }
                    }
                }
            }
        }
        us[u] = 0;
    }

    ArrayList<String> ans;

    void solve() {
        main:
        for (int test_id = 1, test_num = nextInt(); test_id <= test_num; ++test_id, out.println()) {
            out.print("Case #" + test_id + ": ");
            n = nextInt();
            int m = nextInt();
            a = new String[n];
            edges = new int[n][n];
            for (int i = 0; i < n; ++i) {
                a[i] = nextToken();
            }
            us = new int[n];

            for (int i = 0; i < m; ++i) {
                int x = nextInt() - 1, y = nextInt() - 1;
                edges[x][y] = edges[y][x] = 1;
            }
            ans = new ArrayList<String>();
            for (int i = 0; i < n; ++i) {
                rec(i, (i) + "", n - 1, a[i] + "");
            }


            String s = ans.get(0);
            for (String t : ans) {
                if (t.compareTo(s) < 0) {
                    s = t;
                }
            }
            out.print(s);
        }
    }
}