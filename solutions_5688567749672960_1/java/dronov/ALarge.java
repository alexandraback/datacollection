import java.util.*;
import java.io.*;

public class ALarge {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {

        int test = in.nextInt();
        for (int t = 1; t <= test; t++) {
            long n = in.nextLong();

            long ans = 0;
            if (n <= 20) {
                printResult(t, n);
                continue;
            }

            int curCount = 2;
            int count = 0;
            long x = n;
            while (x != 0) {
                count++;
                x /= 10;
            }
            ans = 10;
            for (int i = curCount; i < count; i++) {
                long best = Long.MAX_VALUE;
                for (int j = 1; j < i; j++) {
                    long q1 = (int)Math.pow(10, j) - 1;
                    int p = i - j;
                    long q2 = (long) (Math.pow(10, p) - 1);

                    best = Math.min(best, q1 + q2 + 1);
                }
                ans += best;
            }

            long q = 1;
            for (int i = 0; i < count - 1; i++)
                q *= 10;

            if (q == n) {
                printResult(t, ans);
                continue;
            }

            String str = String.valueOf(n);
            long best = Long.MAX_VALUE;
            for (int i = 0; i < str.length(); i++) {
                String newStr = str.substring(0, i + 1);
                Long strLong = 0L;
                if (newStr.charAt(newStr.length() - 1) == '0') {
                    Long qq = Long.valueOf(newStr);
                    qq--;
                    strLong = Long.valueOf(new StringBuilder(String.valueOf(qq)).reverse().toString());
                    newStr = String.valueOf(qq);
                } else {
                    strLong = Long.valueOf(new StringBuilder(newStr).reverse().toString());
                }

                long current = strLong;
                StringBuilder pq = new StringBuilder(String.valueOf(newStr));
                for (int j = i + 1; j < count - 1; j++) {
                    pq.append("0");
                }
                pq.append("1");

                long result = Long.valueOf(pq.toString());
                if (result > n) {
                    continue;
                }
                best = Math.min(best, (n - result) + current + (i + 1 < str.length() ? 1 : 0));
            }

            printResult(t, best + ans);
        }
    }

    private void printResult(int test, long n) {
        out.println("Case #" + test + ": " + n);
    }

    private int reverse(int i) {
        String str = String.valueOf(i);
        String reverse = new StringBuilder(str).reverse().toString();
        int q = Integer.parseInt(reverse);
        return q;
    }

    public void run() {
        try {
            in = new FastScanner(new File("input.txt"));
            out = new PrintWriter(new File("output.txt"));

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

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] arg) {
        new ALarge().run();
    }
}