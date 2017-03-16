import java.io.*;
import java.util.*;

public class A {
    // private static final String FIN = "A-small-attempt0.in";
    // private static final String FOUT = "A-small-attempt0.out";
    private static final String FIN = "A-large.in";
    private static final String FOUT = "A-large.out";

    public static void solution(BufferedReader reader, PrintWriter out)
            throws IOException {
        In in = new In(reader);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int n = in.nextInt();
            if (n == 0)
                out.printf("Case #%d: INSOMNIA\n", t);
            else
                out.printf("Case #%d: %d\n", t, get(n));
        }
    }

    private static int get(int n) {
        int cnt = 0;
        boolean[] check = new boolean[10];
        for (int i = 1;; i++) {
            int a = i * n;
            while (a > 0) {
                int d = a % 10;
                if (!check[d]) {
                    check[d] = true;
                    cnt++;
                }
                a /= 10;
            }
            if (cnt == 10)
                return i * n;
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
