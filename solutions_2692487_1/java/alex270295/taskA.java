import java.util.*;
import java.io.*;

/**
 * Created with IntelliJ IDEA.
 * User: Alexei
 * Date: 26.02.13
 * Time: 13:41
 * To change this template use File | Settings | File Templates.
 */
public class taskA {
    FastScanner in;
    PrintWriter out;

    class Pair {
        int x, ans;

        Pair() {

        }

        Pair(int x, int ans) {
            this.x = x;
            this.ans = ans;
        }
    }

    Pair calc(int x, int y) {
        if (x == 1) {
            return new Pair(-1, -1);
        }
        Pair tmp = new Pair(x, 0);
        while (tmp.x <= y) {
            tmp.x += tmp.x - 1;
            tmp.ans++;
        }
        tmp.x += y;
        return tmp;
    }

    int solveA(int x, int ans, int q) {
        if (q == n) {
            return ans;
        } else if (ans >= n)
            return Integer.MAX_VALUE;
        else if (x > a[q]) {
            x += a[q];
            return solveA(x, ans, q + 1);
        } else {
            Pair tmp = calc(x, a[q]);
            if (tmp.x == -1 && tmp.ans == -1)
                return solveA(x, ans + 1, q + 1);
            else
                return Math.min(solveA(x, ans + 1, q + 1), solveA(tmp.x, ans + tmp.ans, q + 1));
        }
    }

    int n;
    int a[];

    public void solve() throws IOException {
        int t = in.nextInt();
        for (int q = 0; q < t; q++) {
            int x = in.nextInt();
            n = in.nextInt();
            a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();
            Arrays.sort(a);

            out.printf("Case #%d: %d",q+1,solveA(x, 0, 0));
            out.println();


        }
    }

    public void run() {
        try {
            in = new FastScanner(System.in);
            out = new PrintWriter(new File("out.txt"));

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

        FastScanner(InputStream is) {
            try {
                br = new BufferedReader(new InputStreamReader(is));
            } catch (Exception e) {
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

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] arg) {
        new taskA().run();
    }
}
