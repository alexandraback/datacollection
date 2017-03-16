import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * User: Igor Kirov
 * Date: 04.05.13
 */
public class FallingDiamonds implements Runnable {
    BigInteger[] factCache = new BigInteger[3000];

    private boolean inside(int side, int x, int y) {
        return ((Math.abs(x) + Math.abs(y)) < side);
    }

    private boolean outside(int side, int x, int y) {
        return !inside(side, x, y);
    }

    private boolean ontop(int side, int x, int y) {
        return (x == 0 && y == side - 1);
    }

    private boolean onedge(int side, int left, int right, int x, int y) {
        int t = Math.abs(x) + Math.abs(y);
        if (t != side - 1) {
            return false;
        }
        if (x == 0) {
            return false;
        }
        if (x < 0) {
            int ll = y + 1;
            return ll <= left;
        } else {
            int rr = y + 1;
            return rr <= right;
        }
    }

    private BigInteger cnk(int n, int k) {
        if (k == 0 || n == k) {
            return BigInteger.ONE;
        }
        BigInteger nFact = factCache[n];
        BigInteger kFact = factCache[k];
        BigInteger nkFact = factCache[n - k];
        return nFact.divide(kFact).divide(nkFact);
    }

    private void solve() throws IOException {
        int n = nextInt();
        int x = nextInt();
        int y = nextInt();

        if (n == 1) {
            if (x == 0 && y == 0) {
                writer.println(1f);
            } else {
                writer.println(0f);
            }
            return;
        }

        int prev = 1;
        int cur = 1;
        int side = 1;
        while (n >= cur) {
            side += 2;
            prev = cur;
            cur = cur + side * 2 - 1;
        }

        int rest = n - prev;
        if (inside(side - 2, x, y)) {
            writer.println(1f);
            return;
        }
        if (outside(side, x, y)) {
            writer.println(0f);
            return;
        }
        if (ontop(side, x, y) && rest > 0) {
            writer.println(0f);
            return;
        }
        if (ontop(side, x, y) && rest == 0) {
            writer.println(1f);
            return;
        }
        int left = Math.min(side - 1, rest);
        int right = rest - left;
        int qqq = right;
        left = left - right;
        right = 0;
        BigInteger sum = BigInteger.ZERO;
        BigInteger ans = BigInteger.ZERO;
        while (left >= 0) {
            sum = sum.add(cnk(left + right, left));
            if (onedge(side, left + qqq, right + qqq, x, y)) {
                ans = ans.add(cnk(left + right, left));
            }
            left--;
            right++;
        }
        BigDecimal res = new BigDecimal(ans);
        res = res.divide(new BigDecimal(sum), MathContext.DECIMAL64);
        writer.println(res.toPlainString());
    }

    public static void main(String[] args) {
        new Thread(null, new FallingDiamonds(), "", 64 * 1024 * 1024).start();
    }

    StringTokenizer tokenizer;
    BufferedReader reader;
    PrintWriter writer;

    public void run() {
        try {
            try {
                Locale.setDefault(Locale.US);
            } catch (Exception ignored) {
            }

            reader = new BufferedReader(new FileReader("FallingDiamonds.in"));
            writer = new PrintWriter(new FileWriter("FallingDiamonds.out"));
            tokenizer = null;

            BigInteger f = BigInteger.ONE;
            for (int i = 1; i < 3000; i++) {
                f = f.multiply(new BigInteger(String.valueOf(i)));
                factCache[i] = f;
            }

            int tests = nextInt();
            for (int i = 0; i < tests; i++) {
                writer.printf("Case #%d: ", i + 1);
                solve();
                writer.flush();
            }

            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private BigInteger nextBigInteger() throws IOException {
        return new BigInteger(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}