import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

import java.io.*;
import java.util.*;

public class Main {

    final static int MAX_N = 1000 * 1000;

    static int[] dp = new int[MAX_N + 1];

    static void init() {
        for (int i = 1; i <= MAX_N; i++)
            dp[i] = i;
        TreeSet<Pair> queue = new TreeSet<>();
        for (int i = 1; i <= MAX_N; i++)
            queue.add(new Pair(dp[i], i));
        while (queue.size() > 0) {
            Pair p = queue.pollFirst();
            int v = p.second;
            int to = v + 1;
            if (to <= MAX_N) {
                if (dp[to] > dp[v] + 1) {
                    queue.remove(new Pair(dp[to], to));
                    dp[to] = dp[v] + 1;
                    queue.add(new Pair(dp[to], to));
                }
            }
            to = Integer.parseInt(new StringBuilder(Integer.toString(v)).reverse().toString());
            if (to <= MAX_N) {
                if (dp[to] > dp[v] + 1) {
                    queue.remove(new Pair(dp[to], to));
                    dp[to] = dp[v] + 1;
                    queue.add(new Pair(dp[to], to));
                }
            }
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        out.printf("Case #%d: ", testNumber);
        int n = in.nextInt();
        out.println(dp[n]);
    }

    public static void main(String[] args)throws IOException {
        FastScanner in = new FastScanner(new FileInputStream("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int t = in.nextInt();
        init();
        for (int test = 1; test <= t; test++)
            new Main().solve(test, in, out);
        in.close();
        out.close();
    }

    public static final class Pair implements Comparable<Pair> {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair p) {
            if (first != p.first)
                return Integer.compare(first, p.first);
            return Integer.compare(second, p.second);
        }

        @Override
        public int hashCode() {
            return first * 1_000_003 + second;
        }

        @Override
        public boolean equals(Object o) {
            if (o == null || !(o instanceof Pair))
                return false;
            Pair p = (Pair) o;
            return first == p.first && second == p.second;
        }
    }
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
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

    public String nextLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        tokenizer = null;
        return line;
    }

    public void close() {
        try {
            reader.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
