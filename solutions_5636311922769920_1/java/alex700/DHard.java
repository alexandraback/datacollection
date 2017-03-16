import java.util.*;
import java.io.*;

public class DHard {
    FastScanner in;
    PrintWriter out;

    long[] sum;

    long get(long from, int c) {
        return from * sum[c];
    }

    long gen(long from, long to, int c, long k) {
        if (from == to) {
            return get(from, c - 1);
        } else {
            long x = gen(from, to - 1, c - 1, k);
            return x * k + to;
        }
    }

    public void solveTest() throws IOException {
        int k = in.nextInt();
        int c = in.nextInt();
        int s = in.nextInt();
        sum = new long[c];
        {
            long ss = 0;
            long p = 1;
            for (int i = 0; i <= c - 1; i++) {
                ss += p;
                p *= k;
                sum[i] = ss;
            }
        }
        if (s * c < k) {
            out.println("IMPOSSIBLE");
        } else {
            List<Long> ans = new ArrayList<>();
            for (int start = 0; start < k; start+= c) {
                if (start + c > k) {
                    ans.add(gen(start, k - 1, c, k));
                    break;
                } else {
                    ans.add(gen(start, start + c - 1, c, k));
                }
            }
            ans.stream().forEach(i -> out.print((i + 1) + " "));
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
            in = new FastScanner(new File("D-large.in"));
            out = new PrintWriter(new File("D-large.out"));
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
        new DHard().run();
    }
}