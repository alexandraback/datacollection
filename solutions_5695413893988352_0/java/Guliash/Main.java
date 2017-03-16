import java.io.*;
import java.util.ArrayList;
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
            inputStream = new FileInputStream("B-small-attempt0.in");
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
                String s = in.next();
                String j = in.next();
                ArrayList<Integer> varsS = new ArrayList<>();
                gen(s.toCharArray(), varsS, 0);
                ArrayList<Integer> varsJ = new ArrayList<>();
                gen(j.toCharArray(), varsJ, 0);

                int minDiff = Integer.MAX_VALUE;
                Integer ansS, ansJ;
                ansS = ansJ = null;
                for (Integer ss : varsS) {
                    for (Integer jj : varsJ) {
                        int abs = Math.abs(ss - jj);
                        if (abs < minDiff) {
                            ansS = ss;
                            ansJ = jj;
                            minDiff = abs;
                        } else if (abs == minDiff) {
                            if (ss < ansS) {
                                ansS = ss;
                                ansJ = jj;
                            } else if (ansS.equals(ss)) {
                                if (jj < ansJ) {
                                    ansJ = jj;
                                }
                            }
                        }
                    }
                }
                String strS, strJ;
                strS = ansS.toString();
                strJ = ansJ.toString();
                int ds = s.length() - strS.length();
                for (int i = 0; i < ds; i++) {
                    strS = '0' + strS;
                }
                int dj = j.length() - strJ.length();
                for (int i = 0; i < dj; i++) {
                    strJ = '0' + strJ;
                }
                out.println(String.format("Case #%d: %s %s", t, strS, strJ));

            }
        }

        public void gen(char[] a, ArrayList<Integer> vars, int pos) {
            if (pos == a.length) {
                vars.add(new Integer(new String(a)));
                return;
            }
            if (Character.isDigit(a[pos])) {
                gen(a, vars, pos + 1);
            } else {
                for (int j = 0; j < 10; j++) {
                    a[pos] = Character.forDigit(j, 10);
                    gen(a, vars, pos + 1);
                }
                a[pos] = '?';
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

