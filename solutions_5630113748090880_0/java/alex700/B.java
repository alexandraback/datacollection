import java.util.*;
import java.io.*;

public class B {
    FastScanner in;
    PrintWriter out;

    public void solveTest() throws IOException {
        SortedMap<Integer, Integer> map = new TreeMap<>();
        int n = in.nextInt();
        for (int i = 0; i < n * (2 * n - 1); i++) {
            int a = in.nextInt();
            map.compute(a, (k, v) -> v == null ? 1 : v + 1);
        }
        System.out.println(map);
        map.entrySet().stream().filter(p -> (p.getValue() & 1) != 0).forEachOrdered(p -> {
            out.print(p.getKey() + " ");
        });
        out.println();
    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 1; test <= tests; test++) {
            out.print("Case #" + test + ": ");
            System.out.println("test " + test);
            long start = System.currentTimeMillis();
            solveTest();
            System.out.println("passed in " + (System.currentTimeMillis() - start) + " ms");
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("B-small-attempt0.in"));
            out = new PrintWriter(new File("B-small-attempt0.out"));
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
        new B().run();
    }
}