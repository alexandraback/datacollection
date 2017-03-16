import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author George Marcus
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "C-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("c.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        private static final int CERTAINTY = 40;
        private static final int MAX_DIVISOR = 1000;
        int N;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            out.println("Case #" + testNumber + ":");

            N = in.readInt();
            int J = in.readInt();

            int[] D = new int[11];
            int need = J;
            int iter = 10000;
            BigInteger highBit = BigInteger.ZERO.setBit(N - 1);
            for (BigInteger mid = BigInteger.ZERO; need > 0 && iter > 0; mid = mid.add(BigInteger.ONE), iter--) {
                BigInteger n = highBit.or(mid.shiftLeft(1)).or(BigInteger.ONE);

                boolean ok = true;
                for (int b = 2; b <= 10; b++) {
                    BigInteger nb = calcInBase(n, b);
                    int d = getDivisor(nb);
                    D[b] = d;

                    if (d == -1) {
                        ok = false;
                    }
                }

                if (ok) {
                    out.print(n.toString(2));
                    for (int b = 2; b <= 10; b++) {
                        out.print(" " + D[b]);
                    }
                    out.println();
                    need--;
                }
            }

//        System.out.println(need);
            if (need > 0) {
                throw new RuntimeException();
            }
        }

        private int getDivisor(BigInteger nb) {
            if (!nb.isProbablePrime(CERTAINTY)) {
                for (int d = 2; d < MAX_DIVISOR; d++) {
                    if (nb.mod(BigInteger.valueOf(d)).compareTo(BigInteger.ZERO) == 0) {
                        return d;
                    }
                }
            }
            return -1;
        }

        private BigInteger calcInBase(BigInteger n, int b) {
            BigInteger ret = BigInteger.ZERO;
            for (int i = N - 1; i >= 0; i--) {
                ret = ret.multiply(BigInteger.valueOf(b));
                if (n.testBit(i)) {
                    ret = ret.add(BigInteger.ONE);
                }
            }
            return ret;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String readString() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c))
                    res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

