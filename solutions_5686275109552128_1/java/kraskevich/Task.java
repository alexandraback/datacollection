import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class Task {

    final int INF = 1000 * 1000 * 1000;
    final int N = 1111;

    boolean check(int ans, int[] a) {
        boolean ok = false;
        for (int spec = 0; spec <= Math.min(ans - 1, N) && !ok; spec++) {
            int toEat = ans - spec;
            int groups = 0;
            for (int i = 0; i < a.length; i++)
                groups += (a[i] - 1) / toEat;
            if (groups <= spec)
                ok = true;
        }
        return ok;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        out.printf("Case #%d: ", testNumber);
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        int low = 0;
        int high = INF;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (check(mid, a))
                high = mid;
            else
                low = mid;
        }
        out.println(high);
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
