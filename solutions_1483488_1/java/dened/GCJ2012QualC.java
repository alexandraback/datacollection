import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class GCJ2012QualC {
    static final int MAXB = 2000000;
    int[] minR = new int[MAXB+1];
    int[] count = new int[MAXB+1];

    public void run() throws IOException {
        for (int a = 1; a <= MAXB; a *= 10) {
            for (int x = a; x < 10*a && x <= MAXB; ++x) {
                minR[x] = x;
                int y = x;
                do {
                    y = y % 10 * a + y / 10;
                    if (y / a != 0 && y < minR[x]) {
                        minR[x] = y;
                    }
                }
                while (y != x);
            }
        }
        
        int T = nextInt();
        for (int i = 1; i <= T; ++i) {
            out.println("Case #" + i + ": " + solve());
        }
    }

    private int solve() throws IOException {
        int A = nextInt();
        int B = nextInt();

        Arrays.fill(count, 0, B+1, 0);
        
        for (int i = A; i <= B; ++i) {
            ++count[minR[i]];
        }
        
        int ans = 0;
        
        for (int i = 0; i <= B; ++i) {
            ans += count[i] * (count[i] - 1) / 2;
        }
        
        return ans;
    }

    public static BufferedReader in;
    public static PrintStream out;

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);

        String className = GCJ2012QualC.class.getSimpleName();
        char lastChar = className.charAt(className.length() - 1);
        System.setIn(new FileInputStream(lastChar + ".in"));
        System.setOut(new PrintStream(lastChar + ".out"));

        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintStream(new BufferedOutputStream(System.out));

        new GCJ2012QualC().run();

        out.close();
    }

    public static StringTokenizer tokenizer;

    public static String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(in.readLine());
        }
        return tokenizer.nextToken();
    }

    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}
