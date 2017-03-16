import java.io.*;
import java.util.StringTokenizer;

public class Main {

    int V;

    boolean[] add(boolean[] can, int val) {
        boolean[] res = new boolean[V + 1];
        for (int i = 0; i <= V; i++) {
            res[i] = can[i];
            if (i >= val)
                res[i] |= can[i - val];
        }
        return res;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        out.printf("Case #%d: ", testNumber);
        int c = in.nextInt();
        int d = in.nextInt();
        V = in.nextInt();
        int[] a = new int[d];
        for (int i = 0; i < d; i++)
            a[i] = in.nextInt();
        boolean[] can = new boolean[V + 1];
        can[0] = true;
        for (int i = 0; i < d; i++)
            can = add(can, a[i]);
        int res = 0;
        for (;;) {
            int first = -1;
            for (int i = 0; i <= V; i++)
                if (!can[i]) {
                    first = i;
                    break;
                }
            if (first == -1)
                break;
            res++;
            can = add(can, first);
        }
        out.println(res);
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
