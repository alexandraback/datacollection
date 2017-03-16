import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
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
            inputStream = new FileInputStream("A-small-attempt0.in");
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
            Digit[] digits = {new Digit("SIX", 6, 'X'), new Digit("EIGHT", 8, 'G'), new Digit("SEVEN", 7, 'S'),
                    new Digit("FIVE", 5, 'V'), new Digit("NINE", 9, 'I'), new Digit("ZERO", 0, 'Z'), new Digit("FOUR", 4, 'F'),
                    new Digit("THREE", 3, 'R'), new Digit("TWO", 2, 'W'), new Digit("ONE", 1, 'E')};
            for (int t = 1; t <= T; t++) {
                String s = in.readLine();
                int[] cnt = new int[26];
                for (int i = 0; i < s.length(); i++) {
                    cnt[s.charAt(i) - 'A']++;
                }
                ArrayList<Integer> ans = new ArrayList<>();
                for (Digit digit : digits) {
                    process(ans, cnt, digit);
                }
                Collections.sort(ans);
                out.print(String.format("Case #%d: ", t));
                for (Integer v : ans) {
                    out.print(v);
                }
                out.println();

            }
        }

        public void process(ArrayList<Integer> ans, int[] cnt, Digit digit) {
            int c = cnt[digit.unique - 'A'];
            for (int i = 0; i < c; i++) {
                ans.add(digit.digit);
                String val = digit.value;
                for (int j = 0; j < val.length(); j++) {
                    cnt[val.charAt(j) - 'A']--;
                }
            }
        }

        class Digit {
            String value;
            int digit;
            char unique;

            public Digit(String value, int digit, char unique) {
                this.value = value;
                this.digit = digit;
                this.unique = unique;
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

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        private String readLine0() {
            StringBuilder buf = new StringBuilder();
            int c = read();
            while (c != '\n' && c != -1) {
                if (c != '\r')
                    buf.appendCodePoint(c);
                c = read();
            }
            return buf.toString();
        }

        public String readLine() {
            String s = readLine0();
            while (s.trim().length() == 0)
                s = readLine0();
            return s;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}

