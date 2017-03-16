import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        new Main().solve();
    }

    //String iFile = "sample";
    String iFile = "C-large.in";
    String oFile = "out" + System.currentTimeMillis() % (1000 * 60 * 60) + ".txt";

    void solve() {
        FastScanner in = null;
        PrintWriter out = null;
        try {
            in = new FastScanner(new FileInputStream(iFile));
            out = new PrintWriter(new FileOutputStream(oFile));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println("Input : " + iFile);
        System.out.println("Output : " + oFile);

        int T = in.nextInt();
        L:
        for (int ti = 0; ti < T; ti++) {
            int L = in.nextInt();
            long X = in.nextLong();

            String s = in.next();
            int idx = 0;
            int cur = 1;
            // i
            while (cur != 'i') {
                if (idx > L * 9) {
                    // ng
                    out.println(outs(ti, "NO"));
                    continue L;
                }
                cur = mul(cur, s.charAt(idx % L));
                idx++;
            }

            // j
            cur = 1;
            while (cur != 'j') {
                if (idx > L * 9) {
                    // ng
                    out.println(outs(ti, "NO"));
                    continue L;
                }
                cur = mul(cur, s.charAt(idx % L));
                idx++;
            }

            // k
            cur = 1;
            while (idx % L != 0) {
                cur = mul(cur, s.charAt(idx % L));
                idx++;
            }
            long xx = X - idx / L;
            if (xx < 0) {
                // ng
                out.println(outs(ti, "NO"));
                continue L;
            }

            xx %= 4;
            for (int i = 0; i < L * xx; i++) {
                cur = mul(cur, s.charAt(i % L));
            }
            if (cur == 'k') {
                // ok
                out.println(outs(ti, "YES"));
            } else {
                // ng
                out.println(outs(ti, "NO"));
            }
        }
        out.close();
    }

    int mul(int a, int b) {
        if (a < 0) {
            return -mul(-a, b);
        } else if (b < 0) {
            return -mul(a, -b);
        } else if (a == 1 || b == 1) {
            return a * b;
        } else if (a == b) {
            return -1;
        } else {
            if (b == a + 1 || b == a - 2) {
                return 'i' + 'j' + 'k' - a - b;
            } else {
                return -('i' + 'j' + 'k' - a - b);
            }
        }
    }

    String outs(int ti, String ret) {
        return "Case #" + (ti + 1) + ": " + ret;
    }

    class FastScanner {
        private InputStream _stream;
        private byte[] _buf = new byte[1024];
        private int _curChar;
        private int _numChars;
        private StringBuilder _sb = new StringBuilder();

        FastScanner(InputStream stream) {
            this._stream = stream;
        }

        public int read() {
            if (_numChars == -1) throw new InputMismatchException();
            if (_curChar >= _numChars) {
                _curChar = 0;
                try {
                    _numChars = _stream.read(_buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (_numChars <= 0) return -1;
            }
            return _buf[_curChar++];
        }

        public String next() {
            int c = read();
            while (isWhitespace(c)) {
                c = read();
            }
            _sb.setLength(0);
            do {
                _sb.appendCodePoint(c);
                c = read();
            } while (!isWhitespace(c));
            return _sb.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = read();
            while (isWhitespace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isWhitespace(c));
            return res * sgn;
        }

        public boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}
