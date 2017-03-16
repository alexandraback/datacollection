import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created with IntelliJ IDEA.
 * User: 1
 * Date: 25.02.13
 * Time: 3:21
 * To change this template use File | Settings | File Templates.
 */
public class Template {
    private StringTokenizer tokenizer;
    private BufferedReader reader;
    private PrintWriter writer;

    public static void main(String[] args) throws IOException {
        new Template().run();
    }




    private void run() throws IOException {
//        reader = new BufferedReader(new InputStreamReader(System.in));
//        writer = new PrintWriter(System.out);
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter("output.txt");
        solve();
        writer.flush();
    }

    private void solve() throws IOException {
        int tc = nextInt();
        for (int iter = 1; iter <= tc; ++iter) {
            int E = nextInt();
            int R = nextInt();
            int n = nextInt();
            int[]v = new int[n];
            for (int i = 0; i < n; ++i)
                v[i] = nextInt();
            int[][]dp = new int[n + 1][E + 1];
            for (int[]x:dp)
                Arrays.fill(x, -1);
            dp[0][E] = 0;
            for (int i = 0; i < n; ++i)
                for (int dj = 0; dj <= E; ++dj) {
                    int cur = dp[i][dj];
                    if (cur == -1)
                        continue;
                    for (int spend = 0; spend <= dj; ++spend) {
                        dp[i + 1][Math.min(E, dj - spend + R)] = Math.max(dp[i + 1][Math.min(E, dj - spend + R)], cur + v[i] * spend);
                    }
                }
            int ans = 0;
            for (int i = 0; i <= E; ++i)
                ans = Math.max(ans, dp[n][i]);
            writer.print("Case #" + Integer.toString(iter) + ": " + Long.toString(ans) + "\n");
        }
    }



    private int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    private double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
    private long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    private String next() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine()) ;
        }
        return tokenizer.nextToken();
    }
}