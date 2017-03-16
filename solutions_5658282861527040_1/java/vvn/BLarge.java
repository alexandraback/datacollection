import java.io.*;
import java.util.StringTokenizer;

public class BLarge {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int cases = in.nextInt();
        for (int testcase = 1; testcase <= cases; testcase++) {
            out.print("Case #" + testcase + ": ");

            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            int k = in.nextInt() - 1;

            out.println(calc(a, b, k));
        }
    }

    private long calc(long a, long b, long k) {
        if (a < b) {
            return calc(b, a, k);
        }

        long hiA = Long.highestOneBit(a);
        long hiB = Long.highestOneBit(b);
        long hiK = Long.highestOneBit(k);

        if (hiA == hiB) {
            if (hiK == hiA) {
                if (hiA == 0) {
                    return 1;
                }
                // 1 & 1
                long res = calc(a - hiA, b - hiB, k - hiK);
                // 1 & 0
                res += (a - hiA + 1) * hiB;
                // 0 & 1
                res += (b - hiB + 1) * hiA;
                // 0 & 0
                res += hiA * hiB;
                return res;
            } else if (hiK < hiA) {
                long res = 0;
                // 1 & 0
                res += calc(a - hiA, hiB - 1, k);
                // 0 & 1
                res += calc(hiA - 1, b - hiB, k);
                // 0 & 0
                res += calc2(hiA - 1, hiB - 1, k);
                return res;
            } else {
                return (a + 1) * (b + 1);
            }
        } else { // hiA > hiB
            if (hiK == hiA) {
                return (a + 1) * (b + 1);
            } else {
                long res = 0;
                // 1 & 0
                res += calc(a - hiA, b, k);
                // 0 & 0
                res += calc(hiA - 1, b, k);
                return res;
            }
        }
    }

    long calc2(long a, long b, long k) {
        if (a != b) {
            throw new IllegalStateException();
        }

        long hi = Long.highestOneBit(a);
        long hiK = Long.highestOneBit(k);

        if (hiK == hi) {
            if (hi == 0) {
                return 1;
            }
            // 1 & 1
            long res = calc2(a - hi, a - hi, k - hiK);
            // 1 & 0
            res += (a - hi + 1) * hi;
            // 0 & 1
            res += (b - hi + 1) * hi;
            // 0 & 0
            res += hi * hi;
            return res;
        } else {
            long res = 0;
            // 1 & 0
            res += 3 * calc2(hi - 1, hi - 1, k);
            return res;
        }
    }

    public void run() {
        try {
            in = new FastScanner(new FileInputStream("b-large.in"));
            out = new PrintWriter(new FileOutputStream("b-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
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
        new BLarge().run();
    }
}