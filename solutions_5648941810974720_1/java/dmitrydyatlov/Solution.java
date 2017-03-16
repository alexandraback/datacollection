import java.io.*;
import java.util.*;

public class Solution {
    // TODO: do not forget
    private static final int READ_FROM_FILE = 1;
    private static final int WRITE_TO_FILE = 1;
    private static final String INPUT_FILE = "A-large.in";
    private static final String OUTPUT_FILE = "A-large.out";

    private void run(InputReader in, PrintWriter out) {
        String s = in.next();
        int dig[] = new int[10];
        int cnt[] = new int[26];
        for(int i = 0; i < s.length(); ++i) {
            cnt[s.charAt(i) - 'A']++;
        }
        dig[0] = cnt['Z' - 'A'];
        dig[2] = cnt['W' - 'A'];
        dig[4] = cnt['U' - 'A'];
        dig[6] = cnt['X' - 'A'];
        dig[8] = cnt['G' - 'A'];
        dig[1] = cnt['O' - 'A'] - dig[0] - dig[2] - dig[4];
        dig[3] = cnt['H' - 'A'] - dig[8];
        dig[5] = cnt['F' - 'A'] - dig[4];
        dig[7] = cnt['S' - 'A'] - dig[6];
        dig[9] = cnt['I' - 'A'] - dig[5] - dig[6] - dig[8];
        for(int i = 0; i <= 9; ++i) {
            for(int j = 0; j < dig[i]; ++j) {
                out.print(i);
            }
        }
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