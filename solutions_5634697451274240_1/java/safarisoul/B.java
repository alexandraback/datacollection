import java.io.*;
import java.util.*;

public class B {
    // private static final String FIN = "B-small-attempt0.in";
    // private static final String FOUT = "B-small-attempt0.out";
    private static final String FIN = "B-large.in";
    private static final String FOUT = "B-large.out";

    public static void solution(BufferedReader reader, PrintWriter out)
            throws IOException {
        In in = new In(reader);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            char[] s = in.next().toCharArray();
            int cnt = 0;
            for (int j = s.length - 1; j >= 0; j--)
                if (j < s.length - 1 && s[j] == s[j + 1])
                    continue;
                else {
                    if (s[j] == '-')
                        cnt++;
                    if (s[j] == '+' && cnt > 0)
                        cnt++;
                }
            out.printf("Case #%d: %d\n", t, cnt);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(FIN));
        PrintWriter out = new PrintWriter(
                new BufferedWriter(new FileWriter(FOUT)));
        solution(reader, out);
        out.close();
    }

    protected static class In {
        private BufferedReader reader;
        private StringTokenizer tokenizer = new StringTokenizer("");

        public In(BufferedReader reader) {
            this.reader = reader;
        }

        public String next() throws IOException {
            while (!tokenizer.hasMoreTokens())
                tokenizer = new StringTokenizer(reader.readLine());
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}
