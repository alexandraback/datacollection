import java.io.*;
import java.util.*;

public class BSmall {

    char[] a, b;

    int best;
    int ba, bb;

    void go(int i, int va, int vb) {
        if (i == a.length) {
            int d = Math.abs(va - vb);
            if (best == -1 || (d < best || (d == best && va < ba))) {
                best = d;
                ba = va;
                bb = vb;
            }
            return;
        }
        if (a[i] == '?' && b[i] == '?') {
            for (int da = 0; da < 10; ++da) {
                for (int db = 0; db < 10; ++db) {
                    go(i + 1, va * 10 + da, vb * 10 + db);
                }
            }
        } else if (a[i] == '?') {
            for (int da = 0; da < 10; ++da) {
                go(i + 1, va * 10 + da, vb * 10 + b[i] - '0');
            }
        } else if (b[i] == '?') {
            for (int db = 0; db < 10; ++db) {
                go(i + 1, va * 10 + a[i] - '0', vb * 10 + db);
            }
        } else {
            go(i + 1, va * 10 + a[i] - '0', vb * 10 + b[i] - '0');
        }
    }

    String pr(int v) {
        String s = String.valueOf(v);
        while (s.length() < a.length) s = '0' + s;
        return s;
    }

    void solve() throws IOException {
        in = new InputReader("B-small-attempt2.in");
        out = new OutputWriter("B-small-attempt2.out");

        int testCount = in.readInt();
        for (int test = 1; test <= testCount; ++test) {
            a = in.readToken().toCharArray();
            b = in.readToken().toCharArray();
            best = -1;
            go(0, 0, 0);
            out.println("Case #" + test + ": " + pr(ba) + " " + pr(bb));
        }

        exit();
    }

    void exit() {
        //System.err.println((System.currentTimeMillis() - startTime) + " ms");
        out.close();
        System.exit(0);
    }

    InputReader in;
    OutputWriter out;

    //long startTime = System.currentTimeMillis();

    public static void main(String[] args) throws IOException {
        new BSmall().solve();
    }

    class InputReader {

        private InputStream stream;

        private byte[] buffer = new byte[1024];
        private int pos, len;

        private int cur;

        private StringBuilder sb = new StringBuilder(32);

        InputReader(String name) throws IOException {
            if (name.equals("__std")) {
                stream = System.in;
            } else {
                stream = new FileInputStream(name);
            }
            cur = read();
        }

        private int read() throws IOException {
            if (len == -1) {
                throw new EOFException();
            }
            if (pos >= len) {
                pos = 0;
                len = stream.read(buffer);
                if (len == -1) return -1;
            }
            return buffer[pos++];
        }

        private boolean whitespace() {
            return cur == ' ' || cur == '\t' || cur == '\r' || cur == '\n' || cur == -1;
        }

        char readChar() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            char res = (char) cur;
            cur = read();
            return res;
        }

        int readInt() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            while (whitespace()) {
                cur = read();
            }
            if (cur == -1) {
                throw new EOFException();
            }
            int sign = 1;
            if (cur == '-') {
                sign = -1;
                cur = read();
            }
            int res = 0;
            while (!whitespace()) {
                if (cur < '0' || cur > '9') {
                    throw new NumberFormatException();
                }
                res *= 10;
                res += cur - '0';
                cur = read();
            }
            return res * sign;
        }

        long readLong() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            return Long.parseLong(readToken());
        }

        double readDouble() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            return Double.parseDouble(readToken());
        }

        String readLine() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            sb.setLength(0);
            while (cur != -1 && cur != '\r' && cur != '\n') {
                sb.append((char) cur);
                cur = read();
            }
            if (cur == '\r') {
                cur = read();
            }
            if (cur == '\n') {
                cur = read();
            }
            return sb.toString();
        }

        String readToken() throws IOException {
            if (cur == -1) {
                throw new EOFException();
            }
            while (whitespace()) {
                cur = read();
            }
            if (cur == -1) {
                throw new EOFException();
            }
            sb.setLength(0);
            while (!whitespace()) {
                sb.append((char) cur);
                cur = read();
            }
            return sb.toString();
        }

        boolean eof() {
            return cur == -1;
        }
    }

    class OutputWriter {

        private PrintWriter writer;

        OutputWriter(String name) throws IOException {
            if (name.equals("__std")) {
                writer = new PrintWriter(System.out);
            } else {
                writer = new PrintWriter(name);
            }
        }

        void print(String format, Object ... args) {
            writer.print(new Formatter(Locale.US).format(format, args));
        }

        void println(String format, Object ... args) {
            writer.println(new Formatter(Locale.US).format(format, args));
        }

        void print(Object value) {
            writer.print(value);
        }

        void println(Object value) {
            writer.println(value);
        }

        void println() {
            writer.println();
        }

        void flush() {
            writer.flush();
        }

        void close() {
            writer.close();
        }
    }
}
