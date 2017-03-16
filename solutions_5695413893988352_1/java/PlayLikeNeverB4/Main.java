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
            final String regex = "B-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("b.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        char[] A;
        char[] B;
        int N;
        BigInteger ansA;
        BigInteger ansB;
        BigInteger ansDiff;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            A = in.readString().toCharArray();
            B = in.readString().toCharArray();
            N = B.length;
            ansDiff = null;

            for (int i = 0; i < N; i++) {
                if (Character.isDigit(A[i]) && Character.isDigit(B[i])) {
                    // d
                    // d
                    if (A[i] != B[i]) {
                        if (A[i] < B[i]) {
                            goMaxMin(i);
                        } else {
                            goMinMax(i);
                        }
                    }
                } else if (Character.isDigit(A[i]) || Character.isDigit(B[i])) {
                    // d
                    // ?
                    if (Character.isDigit(A[i])) {
                        int d = A[i] - '0';
                        if (d > 0) {
                            B[i] = (char) ('0' + (d - 1));
                            goMinMax(i);
                        }
                        if (d < 9) {
                            B[i] = (char) ('0' + (d + 1));
                            goMaxMin(i);
                        }
                        B[i] = A[i];
                    } else {
                        int d = B[i] - '0';
                        if (d > 0) {
                            A[i] = (char) ('0' + (d - 1));
                            goMaxMin(i);
                        }
                        if (d < 9) {
                            A[i] = (char) ('0' + (d + 1));
                            goMinMax(i);
                        }
                        A[i] = B[i];
                    }
                } else {
                    // ?
                    // ?
                    for (char a = '0', b = '1'; a < '2'; a++, b--) {
                        A[i] = a;
                        B[i] = b;

                        if (A[i] < B[i]) {
                            goMaxMin(i);
                        } else {
                            goMinMax(i);
                        }
                    }

                    A[i] = '0';
                    B[i] = '0';
                }
            }

            goMinMax(N);

            System.out.format("Case #%d: %s %s\n", testNumber, transf(ansA), transf(ansB));
//        out.format("Case #%d: %s %s\n", testNumber, transf(ansA), transf(ansB));
        }

        private String transf(BigInteger b) {
            String ret = b.toString();
            StringBuilder sb = new StringBuilder();
            int need = N - ret.length();
            while (need-- > 0) {
                sb.append('0');
            }
            sb.append(ret);
            return sb.toString();
        }

        private BigInteger calc(char[] C, int pos, char val) {
            char[] D = new char[N];
            System.arraycopy(C, 0, D, 0, N);
            for (int i = pos; i < N; i++) {
                if (D[i] == '?') {
                    D[i] = val;
                }
            }
            BigInteger ret = new BigInteger(new String(D));
            return ret;
        }

        private BigInteger calcMin(char[] C, int pos) {
            return calc(C, pos, '0');
        }

        private BigInteger calcMax(char[] C, int pos) {
            return calc(C, pos, '9');
        }

        private void goMinMax(int pos) {
            BigInteger Amin = calcMin(A, pos + 1);
            BigInteger Bmax = calcMax(B, pos + 1);
            check(Amin, Bmax);
        }

        private void goMaxMin(int pos) {
            BigInteger Amax = calcMax(A, pos + 1);
            BigInteger Bmin = calcMin(B, pos + 1);
            check(Amax, Bmin);
        }

        private void check(BigInteger a, BigInteger b) {
            BigInteger diff = a.subtract(b).abs();
            if (ansDiff == null ||
                    diff.compareTo(ansDiff) < 0 ||
                    diff.compareTo(ansDiff) == 0 && a.compareTo(ansA) < 0 ||
                    diff.compareTo(ansDiff) == 0 && a.compareTo(ansA) == 0 && b.compareTo(ansB) < 0
                    ) {
                ansDiff = diff;
                ansA = a;
                ansB = b;
            }
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

