
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
        int T = in.nextInt(), max = 2500;
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            int[] cnt = new int[2500 + 1];
            for (int i = 0; i < 2 * N - 1; i++)
                for (int j = 0; j < N; j++)
                    cnt[in.nextInt()]++;
            out.printf("Case #%d:", t);
            for (int i = 1; i <= max; i++)
                if (cnt[i] % 2 == 1)
                    out.print(" " + i);
            out.println();
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
