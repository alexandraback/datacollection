import java.io.*;
import java.util.*;

public class Solution {
    // TODO: do not forget
    private static final int READ_FROM_FILE = 1;
    private static final int WRITE_TO_FILE = 1;
    private static final String INPUT_FILE = "B-large.in";
    private static final String OUTPUT_FILE = "B-large.out";

    private void run(InputReader in, PrintWriter out) {
        int a, b, k;
        a = in.nextInt();
        b = in.nextInt();
        k = in.nextInt();
        int ma[] = new int[30];
        int mb[] = new int[30];
        int mk[] = new int[30];
        for(int i = 0; i < 30; ++i) {
            ma[i] = (a & (1 << i)) > 0 ? 1 : 0;
            mb[i] = (b & (1 << i)) > 0 ? 1 : 0;
            mk[i] = (k & (1 << i)) > 0 ? 1 : 0;
        }

        long dp[][][][] = new long[31][2][2][2];
        dp[30][0][0][0] = 1;
        for(int i = 30; i > 0; --i) {
            for(int j = 0; j < 2; ++j)
                for(int l = 0; l < 2; ++l)
                    for(int ia = 0; ia < 2; ++ia)
                        for(int ib = 0; ib < 2; ++ib)
                            for(int ik = 0; ik < 2; ++ik) {
                                if(dp[i][ia][ib][ik] == 0)
                                    continue;

                                if(ia == 0 && j == 1 && ma[i - 1] == 0)
                                    continue;
                                if(ib == 0 && l == 1 && mb[i - 1] == 0)
                                    continue;
                                if(ik == 0 && j == 1 && l == 1 && mk[i - 1] == 0)
                                    continue;
                                dp[i - 1]
                                        [(ia == 0 && j == ma[i - 1] ? 0 : 1)]
                                        [(ib == 0 && l == mb[i - 1] ? 0 : 1)]
                                        [(ik == 0 && (j & l) == mk[i - 1] ? 0 : 1)]
                                        += dp[i][ia][ib][ik];
                            }
        }
        out.println(dp[0][1][1][1]);
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