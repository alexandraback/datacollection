import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    private static InputStream inputStream;
    private static OutputStream outputStream;
    private static PrintWriter writer;
    private static InputReader reader;
    private static final int MAXN = 1000000;

    public static void main(String[] args) throws IOException {
        inputStream = new FileInputStream("E:\\B-large.in");
        outputStream = new FileOutputStream("E:\\out.txt");
        reader = new InputReader(inputStream);
        writer = new PrintWriter(outputStream);
        new Main().main();
        writer.close();
    }

    private void main() {
        int T = reader.nextInt();
        for (int cas = 1; cas <= T; ++cas) {
            String cakes = reader.next();
            String result = String.format("Case #%d: %s\n", cas, run(cakes));
            writer.print(result);
        }
    }

    private String run(String pancakes) {
        int n = pancakes.length();
        int[] cakes = new int[n + 1];
        int[][] dp = new int[n + 1][2];
        for (int i = 0; i < n; ++i) {
            char ch = pancakes.charAt(i);
            if (ch == '-') {
                cakes[i] = 0;
            } else {
                cakes[i] = 1;
            }
        }
        if (cakes[0] == 0) {
            dp[0][1] = 1;
        } else {
            dp[0][0] = 1;
        }
        for (int i = 1; i < n; ++i) {
            if (cakes[i] == 0) {
                dp[i][0] = Math.min(dp[i - 1][0], dp[i - 1][1] + 1);
                dp[i][1] = Math.min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
            } else {
                dp[i][0] = Math.min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
                dp[i][1] = Math.min(dp[i - 1][0] + 1, dp[i - 1][1]);
            }
        }
        return Integer.toString(dp[n - 1][1]);
    }


}

class InputReader {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public InputReader(InputStream inputStream) {
        tokenizer = null;
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }


    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}
