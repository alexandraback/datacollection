import javax.print.attribute.IntegerSyntax;
import java.io.*;
import java.util.*;

public class Main {

    static long reverse(long n) {
        return Long.parseLong(new StringBuilder(Long.toString(n)).reverse().toString());
    }

    static long calc(long n) {
        long res = 0;
        while (n > 1) {
            long rev;
            if (((n % 10 == 1 && n < 1000) || (n % 100 == 1)) && (rev = reverse(n)) < n)
                n = rev;
            else
                n--;
            res++;
        }
        return res + 1;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        out.printf("Case #%d: ", testNumber);
        long n = in.nextLong();
        out.println(calc(n));
    }

    public static void main(String[] args)throws IOException {
        FastScanner in = new FastScanner(new FileInputStream("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int t = in.nextInt();
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
