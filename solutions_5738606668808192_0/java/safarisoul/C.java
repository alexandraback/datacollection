import java.io.*;
import java.util.*;

public class C {
    private static final String FIN = "C-small-attempt0.in";
    private static final String FOUT = "C-small-attempt0.out";
    // private static final String FIN = "C-large.in";
    // private static final String FOUT = "C-large.out";

    public static void solution(BufferedReader reader, PrintWriter out)
            throws IOException {
        In in = new In(reader);
        in.nextInt();
        N = in.nextInt();
        J = in.nextInt();
        out.println("Case #1:");
        init();
        for (String s : store)
            out.println(s);
    }

    private static int N, J;
    private static HashSet<Long> nums = new HashSet<Long>();
    private static HashSet<String> store = new HashSet<String>();

    private static void init() {
        for (long i = 3; i <= 65535 && nums.size() < J; i += 2) {
            res[0] = i;
            String s = Long.toBinaryString(i);
            if (test(s)) {
                if (s.length() == N && nums.size() < J && !nums.contains(i)) {
                    nums.add(i);
                    store.add(getString());
                }
                int bitcount = Long.bitCount(i) * 2;
                if (s.length() < N && nums.size() < J) {
                    int shift = N - s.length();
                    long j = (i << shift) | i;
                    if (Long.bitCount(j) == bitcount && !nums.contains(j)) {
                        nums.add(j);
                        res[0] = j;
                        store.add(getString());
                    }
                }
            }
        }
    }

    private static long[] res = new long[10];

    private static String getString() {
        String s = Long.toBinaryString(res[0]);
        for (int i = 1; i < 10; i++)
            s += " " + res[i];
        return s;
    }

    private static boolean test(String s) {
        for (int b = 2; b <= 10; b++) {
            res[b - 1] = prime(value(s, b));
            if (res[b - 1] == -1)
                return false;
        }
        return true;
    }

    private static long value(String s, int b) {
        long v = 0, w = 1;
        for (int i = s.length() - 1; i >= 0; i--, w *= b)
            if (s.charAt(i) == '1')
                v += w;
        return v;
    }

    private static long prime(long v) {
        if (v % 2 == 0)
            return 2;
        if (v % 3 == 0)
            return 3;
        for (long i = 5; i * i <= v; i += 6) {
            if (v % i == 0)
                return i;
            if (v % (i + 2) == 0)
                return i + 2;
        }
        return -1;
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