import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * User: Igor Kirov
 * Date: 13.04.13
 */
public class C implements Runnable {
    private boolean edgeCases(String low, String high) {
        if (low.length() == 1 && high.length() == 1) {
            int lowInt = Integer.parseInt(low);
            int highInt = Integer.parseInt(high);
            int res = 0;
            if (lowInt <= 1 && highInt >= 1) {
                res++;
            }
            if (lowInt <= 4 && highInt >= 4) {
                res++;
            }
            if (lowInt <= 9 && highInt >= 9) {
                res++;
            }
            writer.println(res);
            return true;
        }
        return false;
    }

    private boolean checkMoreEquals(int[] a, String s) {
        int i = 0;
        for (char c : s.toCharArray()) {
            int cur = c - '0';
            if (a[i] > cur) {
                return true;
            }
            if (a[i] < cur) {
                return false;
            }
            i++;
        }
        return true;
    }

    private boolean checkLessEquals(int[] a, String s) {
        int i = 0;
        for (char c : s.toCharArray()) {
            int cur = c - '0';
            if (a[i] < cur) {
                return true;
            }
            if (a[i] > cur) {
                return false;
            }
            i++;
        }
        return true;
    }

    private int checkBoundaries(int[] a, int len, String low, String high) {
        if (len > low.length() && len < high.length()) {
            return 1;
        }
        if (len == low.length() && len == high.length()) {
            if (checkMoreEquals(a, low) && checkLessEquals(a, high)) {
                return 1;
            }
            return 0;
        }
        if (len == low.length()) {
            if (checkMoreEquals(a, low)) {
                return 1;
            }
            return 0;
        }
        if (checkLessEquals(a, high)) {
            return 1;
        }
        return 0;
    }

    private int rec(int[] a, int offset, int len, int j1, int j2, String low, String high) {
        if (j1 + j2 == 0) {
            return checkBoundaries(a, len, low, high);
        }
        if (offset >= len / 2) {
            return 0;
        }
        int ret = 0;
        if (j1 >= 2) {
            a[offset] = 1;
            a[len - offset - 1] = 1;
            ret += rec(a, offset + 1, len, j1 - 2, j2, low, high);
            a[offset] = 0;
            a[len - offset - 1] = 0;
        }
        if (j2 >= 2) {
            a[offset] = 2;
            a[len - offset - 1] = 2;
            ret += rec(a, offset + 1, len, j1, j2 - 2, low, high);
            a[offset] = 0;
            a[len - offset - 1] = 0;
        }
        return ret + rec(a, offset + 1, len, j1, j2, low, high);
    }

    private int solve(int len, int j1, int j2, String low, String high) {
        if (j1 + 4 * j2 > 9) {
            return 0;
        }
        if (j1 % 2 == 1 && j2 % 2 == 1) {
            return 0;
        }
        int res = 0;
        int[] a = new int[len];
        if (j1 % 2 == 1) {
            if (len % 2 == 0) {
                return 0;
            }
            a[len / 2] = 1;
            j1--;
        }
        if (j2 % 2 == 1) {
            if (len % 2 == 0) {
                return 0;
            }
            a[len / 2] = 2;
            j2--;
        }
        if (j1 >= 2) {
            a[0] = 1;
            a[len - 1] = 1;
            res += rec(a, 1, len, j1 - 2, j2, low, high);
        }
        if (j2 >= 2) {
            a[0] = 2;
            a[len - 1] = 2;
            res += rec(a, 1, len, j1, j2 - 2, low, high);
        }
        return res;
    }

    private String findSquare(String q, boolean add) {
        BigInteger two = new BigInteger("2");
        BigInteger qq = new BigInteger(q);
        BigInteger low = BigInteger.ONE;
        BigInteger high = new BigInteger(q);
        while (low.compareTo(high) < 0) {
            BigInteger med = low.add(high).divide(two);
            BigInteger medSquare = med.multiply(med);
            if (medSquare.compareTo(qq) > 0) {
                high = med;
            } else {
                low = med.add(BigInteger.ONE);
            }
        }
        if (add) {
            return high.subtract(BigInteger.ONE).toString();
        } else {
            BigInteger t = high.subtract(BigInteger.ONE);
            if (t.multiply(t).compareTo(qq) >= 0) {
                return t.toString();
            }
            return high.toString();
        }
    }

    private void solve() throws IOException {
        String lowSq = nextToken();
        String highSq = nextToken();

        if (edgeCases(lowSq, highSq)) {
            return;
        }

        String low = findSquare(lowSq, false);
        String high = findSquare(highSq, true);

        int res = 0;
        for (int i = low.length(); i <= high.length(); i++) {
            if (i == 1) {
                int t = Integer.parseInt(low);
                if (t <= 1) {
                    res++;
                }
                if (t <= 2) {
                    res++;
                }
                if (t <= 3) {
                    res++;
                }
                continue;
            }
            for (int j1 = 0; j1 <= 9; j1++) {
                for (int j2 = 0; j2 <= 2; j2++) {
                    res += solve(i, j1, j2, low, high);
                }
            }
        }
        writer.println(res);
    }

    public static void main(String[] args) {
        new Thread(null, new C(), "", 64 * 1024 * 1024).start();
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

            reader = new BufferedReader(new FileReader("C.in"));
            writer = new PrintWriter(new FileWriter("C.out"));
            tokenizer = null;

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