import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.Random;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashSet;
import java.security.SecureRandom;
import java.io.Writer;
import java.util.Optional;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jacob Jiang
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
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public static final SecureRandom random = new SecureRandom();
        private static final BigInteger TWO = BigInteger.valueOf(2);

        public static BigInteger rho(BigInteger N) {
            if (N.mod(TWO).equals(BigInteger.ZERO)) {
                return TWO;
            }
            BigInteger divisor;
            BigInteger c = new BigInteger(N.bitLength(), random);
            BigInteger x = new BigInteger(N.bitLength(), random);
            BigInteger y = x;
            int loopCount = 0;
            do {
                x = x.multiply(x).add(c).mod(N);
                y = y.multiply(y).add(c).mod(N);
                y = y.multiply(y).add(c).mod(N);
                divisor = x.subtract(y).gcd(N);
                loopCount++;
                if (loopCount > 10000) {
                    return null;
                }
            } while (divisor.equals(BigInteger.ONE));
            return divisor;

        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            out.println("Case #" + testNumber + ":");
            int n = in.nextInt();
            int count = in.nextInt();
            Set<Integer> visited = new HashSet<>();
            loop:
            while (count > 0) {
                int digits;
                do {
                    digits = random.nextInt(1 << (n - 2));
                } while (visited.contains(digits));
                visited.add(digits);
                String numStr = "1" + toBinary(digits, n - 2) + "1";
                StringBuilder answer = new StringBuilder(numStr);
                for (int base = 2; base <= 10; base++) {
                    Optional<String> result = calc(numStr, base);
                    if (!result.isPresent()) {
                        continue loop;
                    }
                    answer.append(' ').append(result.get());
                }
                System.out.println(numStr);
                System.out.println("visited.size() = " + visited.size());
                out.println(answer);
                count--;
            }
        }

        private String toBinary(int digits, int len) {
            String s = Integer.toBinaryString(digits);
            StringBuilder result = new StringBuilder();
            while (result.length() + s.length() < len) {
                result.append('0');
            }
            result.append(s);
            return result.toString();
        }

        private Optional<String> calc(String numStr, int base) {
            BigInteger num = new BigInteger(numStr, base);
            if (num.isProbablePrime(50)) {
                return Optional.empty();
            }
            BigInteger result = rho(num);
            if (result == null) {
                return Optional.empty();
            }
            return Optional.of(result.toString());
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

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

        public int nextInt() {
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
                res += c & 15;
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class OutputWriter {
        private PrintWriter writer;

        public OutputWriter(OutputStream stream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(stream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void println(Object x) {
            writer.println(x);
        }

        public void println(String x) {
            writer.println(x);
        }

        public void close() {
            writer.close();
        }

    }
}

