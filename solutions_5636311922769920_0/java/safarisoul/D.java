import java.io.*;
import java.util.*;

public class D {
    private static final String FIN = "D-small-attempt0.in";
    private static final String FOUT = "D-small-attempt0.out";
    // private static final String FIN = "D-large.in";
    // private static final String FOUT = "D-large.out";

    public static void solution(BufferedReader reader, PrintWriter out)
            throws IOException {
        In in = new In(reader);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int K = in.nextInt(), C = in.nextInt(), S = in.nextInt();
            out.printf("Case #%d:", t);
            for (int i = 0; i < S; i++) {
                long a = 0;
                for (int j = 0; j < C; j++)
                    a = a * K + i;
                a++;
                out.print(" " + a);
            }
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
