import java.util.*;
import java.io.*;

public class D {
    FastScanner in;
    PrintWriter out;

    public void solveTest() throws IOException {
        long k = in.nextInt();
        long c = in.nextInt();
        long s = in.nextInt();
        if (s != k) {
            throw new AssertionError(":(");
        }
        long sum = 0;
        long p = 1;
        for (int i = 0; i <= c - 1; i++) {
            sum += p;
            p *= k;
        }
        for (long i = 0; i < k; i++) {
            out.print(i * sum + 1 + " ");
        }
        out.println();

    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            out.print("Case #" + (test + 1) + ": ");
            System.out.println("test " + (test + 1));
            solveTest();
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("D-small-attempt0.in"));
            out = new PrintWriter(new File("D-small-attempt0.out"));
            Locale.setDefault(Locale.US);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new D().run();
    }
}