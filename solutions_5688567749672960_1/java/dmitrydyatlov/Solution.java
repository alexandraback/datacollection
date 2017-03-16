import java.io.*;
import java.util.*;

public class Solution {
    // TODO: do not forget
    private static final int READ_FROM_FILE = 1;
    private static final int WRITE_TO_FILE = 1;
    private static final String INPUT_FILE = "A-large.in";
    private static final String OUTPUT_FILE = "A-large.out";

    static long q = 1;

    private void run(InputReader in, PrintWriter out) {
       //long n = q++;
        long n = in.nextLong();
        if (n <= 20) {
            out.print(n);
            return;
        }
        long x = n;
        int cnt = 0;
        long mas[] = new long[16];
        while (x > 0) {
            mas[cnt] = x % 10;
            cnt++;
            x /= 10;
        }

        boolean spec = true;
        for (int i = 0; i < (cnt + 1) / 2; ++i) {
            if (mas[i] > 0) {
                spec = false;
                break;
            }
        }
        if (spec) {
            n--;
            x = n;
            cnt = 0;
            while (x > 0) {
                mas[cnt] = x % 10;
                cnt++;
                x /= 10;
            }
        }

        long ten[] = new long[16];
        ten[0] = 1;
        for (int i = 1; i < ten.length; ++i) {
            ten[i] = ten[i - 1] * 10L;
        }
        long ans = spec ? 1 : 0;
        for (int i = 1; i < cnt; ++i) {
            int p1 = (i + 1) / 2;
            int p2 = i - p1;
            ans += ten[p1] + ten[p2] - 1;
        }

        int p1 = (cnt + 1) / 2;
        int p2 = cnt - p1;

        long n1 = 0;
        for (int i = p2; i < cnt; ++i) {
            n1 = n1 * 10l + mas[i];
        }
        long n2 = 0;
        for (int i = p2 - 1; i >= 0; --i) {
            n2 = n2 * 10 + mas[i];
        }
        ans += Math.min(n1 + n2, n - ten[cnt - 1]);

        out.print(ans);
    }

    public static void main(String[] args) {
        InputReader in;
        PrintWriter out;
        try {
            if (READ_FROM_FILE == 1) {
                in = new InputReader(new FileInputStream(INPUT_FILE));
            } else {
                in = new InputReader(System.in);
            }
            if (WRITE_TO_FILE == 1) {
                out = new PrintWriter(OUTPUT_FILE);
            } else {
                out = new PrintWriter(System.out);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        Solution solution = new Solution();
        int cases = in.nextInt();
        for(int i = 1; i <= cases; ++i) {
            out.print("Case #" + i + ": ");
            solution.run(in, out);
            out.println();
        }

        out.println();
        out.flush();
        out.close();
    }

    private static class InputReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public char nextCharacter() {
            return next().charAt(0);
        }
    }
}