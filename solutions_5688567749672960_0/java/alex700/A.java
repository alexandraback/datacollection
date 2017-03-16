import java.util.*;
import java.io.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int rev(int n) {
        return Integer.parseInt(String.valueOf(new StringBuilder(n+"").reverse()));

    }

    public void solveTest() throws IOException {
        int n = in.nextInt();
        int[] a = new int[n + 1];
        Arrays.fill(a, 1000000000);
        a[1] = 1;
        for (int i = 1; i < n; i++) {
            a[i + 1] = Math.min(a[i] + 1, a[i + 1]);
            int x = rev(i);
            if (x > i && x < n + 1) {
                a[x] = Math.min(a[i] + 1, a[x]);
            }
        }
        out.println(a[n]);
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
            in = new FastScanner(new File("A-small-attempt0.in"));
            out = new PrintWriter(new File("A-small-attempt0.out"));
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

        long nextLong() { return Long.parseLong(next()); }
    }

    public static void main(String[] arg) {
        new A().run();
    }
}