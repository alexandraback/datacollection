import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.BufferedReader;
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
                int len = 32;
                rr = new ArrayList<Long>();
                for (long i = 0; i < (1L << len - 2); ++i) {
                    boolean ok = true;
                    for (int b = 2; b <= 10; ++b) {
                        if (check(1L + (1L << (len - 1)) + (i << 1), len, b)) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        rr.add(1L + (1L << (len - 1)) + (i << 1));
                        if (rr.size() >= 2000) {
                            break;
                        }
                    }
                }
            }
            int cnt = 0;
            for (int i = 0; i < 2000; ++i) {
//            System.err.println(i);

                List<Integer> res = new ArrayList<Integer>();
                for (int j = 2; j <= 10; ++j) {
                    int xx = fill(rr.get(i), 32, j);
                    if (xx == -1) {
                        res.clear();
                        break;
                    } else {
                        res.add(xx);
                    }
                }
                if (res.isEmpty()) {
                    continue;
                }
                ++cnt;
                out.print(toBase(rr.get(i), 32, 10));
                out.print(" ");
                out.println(ArrayUtils.toString(res));
                if (cnt == 500) {
                    break;
                }
            }

        }

        static String toBase(long mask, int n, int base) {
            BigInteger x = BigInteger.ZERO;
            BigInteger p = BigInteger.ONE;
            for (int i = 0; i < n; ++i) {
                if (BitUtils.checkBit(mask, i)) {
                    x = x.add(p);
                }
                p = p.multiply(BigInteger.valueOf(base));
            }
            String s = String.valueOf(x);
            while (s.length() < n) s = "0" + s;
            return s;
        }

        static int fill(long mask, int n, int base) {
            BigInteger x = BigInteger.ZERO;
            BigInteger p = BigInteger.ONE;
            for (int i = 0; i < n; ++i) {
                if (BitUtils.checkBit(mask, i)) {
                    x = x.add(p);
                }
                p = p.multiply(BigInteger.valueOf(base));
            }
            if (x.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO) == 0) {
                return 2;
            }
            for (int i = 3; i < 100000; i += 2) {
                if (x.mod(BigInteger.valueOf(i)).compareTo(BigInteger.ZERO) == 0) {
                    return i;
                }
            }
            return -1;
        }

        static boolean check(long mask, int n, int base) {
            BigInteger x = BigInteger.ZERO;
            BigInteger p = BigInteger.ONE;
            for (int i = 0; i < n; ++i) {
                if (BitUtils.checkBit(mask, i)) {
                    x = x.add(p);
                }
                p = p.multiply(BigInteger.valueOf(base));
            }
            return x.isProbablePrime(50);
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

    static class ArrayUtils {
        public static String toString(Collection<Integer> collection) {
            StringBuilder result = new StringBuilder("");
            for (int x : collection) {
                result.append(x).append(" ");
            }
            return result.substring(0, result.length() - 1);
        }

    }

    static class BitUtils {
        public static boolean checkBit(long mask, int bit) {
            return (mask & (1L << bit)) > 0;
        }

    }
}

