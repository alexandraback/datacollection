
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
            String S = in.next();
            String res = solve(S);
            out.printf("Case #%d: ", t);
            out.println(res);
        }
    }

    private static String solve(String s) {
        int n = s.length(), imax = n - 1;
        if (n == 0)
            return "";
        for (int i = n - 1; i >= 0; i--)
            if (s.charAt(i) > s.charAt(imax))
                imax = i;
        String res = s.charAt(imax) + solve(s.substring(0, imax))
                + s.substring(imax + 1);
        return res;
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
