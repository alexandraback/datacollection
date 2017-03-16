import java.io.*;
import java.util.Random;
import java.util.StringTokenizer;

public class Task {

    final String RICHARD = "RICHARD";
    final String GABRIEL = "GABRIEL";

    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        out.printf("Case #%d: ", testNumber);
        int x = in.nextInt();
        int n = in.nextInt();
        int m = in.nextInt();
        if (n > m) {
            int t = n;
            n = m;
            m = t;
        }
        if (n * m % x != 0) {
            out.println(RICHARD);
            return;
        }
        for (int lenX = 1; lenX <= x; lenX++) {
            int lenY = x + 1 - lenX;
            if ((lenX > n || lenY > m) && (lenX > m || lenY > n)) {
                out.println(RICHARD);
                return;
            }
        }
        if (n == 1 || x <= 2) {
            out.println(GABRIEL);
            return;
        }
        if (n == 2 && x >= 5 || x >= 7) {
            out.println(RICHARD);
            return;
        }
        if (2 * n == x) {
            for (int splitPos = 1; splitPos <= n; splitPos++) {
                boolean ok = true;
                for (int pos = 0; pos + n < m; pos++) {
                    int low = pos * n + splitPos * (n - 1);
                    if (low % x == 0)
                        ok = false;
                }
                if (ok) {
                    out.println(RICHARD);
                    return;
                }
            }
        }
        out.println(GABRIEL);
    }


    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(new FileInputStream("input"));
        PrintWriter out = new PrintWriter(new FileOutputStream("output"));
        int testsCount = in.nextInt();
        for (int i = 1; i <= testsCount; i++)
            new Task().solve(i, in, out);
        in.close();
        out.close();
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
                return null;
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public String nextLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            return null;
        }
        return line;
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

    public void close() {
        try {
            reader.close();
        } catch (IOException e) {

        }
    }
}
