import java.util.*;
import java.io.*;
import java.util.stream.IntStream;

public class C {
    FastScanner in;
    PrintWriter out;

    public void solveTest() throws IOException {
        out.println();
        int n = in.nextInt();
        int cnt = in.nextInt();
        for (int mask = 0; mask < cnt; mask++) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i * 2 < n; i++) {
                if (i == 0 || i == n / 2 - 1 || (((mask >> (i - 1)) & 1) != 0)) {
                    sb.append('1').append('1');
                } else {
                    sb.append('0').append('0');
                }
            }
            out.print(sb);
            IntStream.range(3, 12).forEach(i -> out.print(" " + i));
            out.println();
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
            in = new FastScanner(new File("C-large.in"));
            out = new PrintWriter(new File("C-large.out"));
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
        new C().run();
    }
}