import java.io.*;
import java.util.InputMismatchException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Artem Gilmudinov
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("C-small-attempt0.in");
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
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int T = in.readInt();
            for (int t = 1; t <= T; t++) {
                int n = in.readInt();
                String[][] names = new String[n][2];
                for (int i = 0; i < n; i++) {
                    names[i][0] = in.next();
                    names[i][1] = in.next();
                }
                int cnt = (1 << n);
                int[] dp = new int[cnt];
                for (int i = 1; i < cnt; i++) {
                    for (int j = 0; j < n; j++) {
                        if (isBit(i, j)) {
                            String[] name = names[j];
                            int subMask = i ^ (1 << j);
                            boolean first = false;
                            boolean second = false;
                            for (int z = 0; z < n; z++) {
                                if (isBit(subMask, z)) {
                                    if (names[z][0].equals(name[0])) {
                                        first = true;
                                    }
                                    if (names[z][1].equals(name[1])) {
                                        second = true;
                                    }
                                }
                            }
                            if (first && second) {
                                dp[i] = Math.max(dp[i], dp[subMask] + 1);
                            }
                        }
                    }
                }
                out.println(String.format("Case #%d: %d", t, dp[cnt - 1]));
            }
        }

        public boolean isBit(int a, int pos) {
            return (a & (1 << pos)) != 0;
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

