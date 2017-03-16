import java.util.*;
import java.io.*;

public class A {
    FastScanner in;
    PrintWriter out;

    public int get(int dif, int x, int cnt, boolean[] used) {
        int y = x;
        while (y > 0) {
            int d = y % 10;
            if (!used[d]) {
                used[d] = true;
                cnt++;
            }
            y /= 10;
        }
        if (cnt == 10) {
            return x;
        } else {
            return get(dif, x + dif, cnt, used);
        }
    }

    public void solveTest() throws IOException {
        int n = in.nextInt();
        if (n == 0) {
            out.println("INSOMNIA");
        } else {
            out.println(get(n, n, 0, new boolean[10]));
        }
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
            in = new FastScanner(new File("A-large.in"));
            out = new PrintWriter(new File("A-large.out"));
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
        new A().run();
    }
}