import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author AlexFetisov
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("input.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("output.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC_GCJ solver = new TaskC_GCJ();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC_GCJ {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            out.println("Case #" + testNumber + ": ");
            List<Long> rr;
            {
                int len = 16;
                rr = new ArrayList<Long>();
                for (long i = 90; i < (1L << len - 2); ++i) {
                    boolean ok = true;
                    for (int b = 2; b <= 10; ++b) {
                        if (check(1L + (1L << (len - 1)) + (i << 1), len, b)) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        rr.add(1L + (1L << (len - 1)) + (i << 1));
                        if (rr.size() >= 50) {
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < 50; ++i) {
                out.print(toBase(rr.get(i), 16, 10));

                for (int j = 2; j <= 10; ++j) {
                    out.print(" " + fill(rr.get(i), 16, j));
                }
                out.println();
            }

        }

        static String toBase(long mask, int n, int base) {
            long x = 0;
            long p = 1;
            for (int i = 0; i < n; ++i) {
                if (BitUtils.checkBit(mask, i)) {
                    x += p;
                }
                p *= base;
            }
            String s = String.valueOf(x);
//        StringBuilder b = new StringBuilder(s);
//        b = b.reverse();
//        s = b.toString();
            while (s.length() < n) s = "0" + s;

            return s;
        }

        static int fill(long mask, int n, int base) {
            long x = 0;
            long p = 1;
            for (int i = 0; i < n; ++i) {
                if (BitUtils.checkBit(mask, i)) {
                    x += p;
                }
                p *= base;
            }
            for (int i = 2; ; ++i) {
                if (x % i == 0) {
                    return i;
                }
            }
        }

        static boolean check(long mask, int n, int base) {
            long x = 0;
            long p = 1;
            for (int i = 0; i < n; ++i) {
                if (BitUtils.checkBit(mask, i)) {
                    x += p;
                }
                p *= base;
            }
            BigInteger t = BigInteger.valueOf(x);
            return t.isProbablePrime(50);
//        return IntegerUtils.isPrime(x);
        }

    }

    static class InputReader {
        private BufferedReader reader;
        private StringTokenizer stt;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        public String nextString() {
            while (stt == null || !stt.hasMoreTokens()) {
                stt = new StringTokenizer(nextLine());
            }
            return stt.nextToken();
        }

        public String next() {
            return nextString();
        }

    }

    static class BitUtils {
        public static boolean checkBit(long mask, int bit) {
            return (mask & (1L << bit)) > 0;
        }

    }
}

