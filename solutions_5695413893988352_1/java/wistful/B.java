import java.io.*;
import java.util.*;

public class B {

    char[] a, b;
    long ba, bb;
    String sa, sb;

    void go(int i, long va, long vb) {
        if (i == a.length) {
            long d = Math.abs(va - vb);
            long bd = Math.abs(ba - bb);
            if (ba == -1 || d < bd || (d == bd && va < ba) || (d == bd && va == ba && vb < bb)) {
                ba = va;
                bb = vb;
                sa = String.valueOf(a);
                sb = String.valueOf(b);
            }
            return;
        }
        char ta = a[i];
        char tb = b[i];
        if (a[i] == '?' && b[i] == '?') {
            if (va < vb) {
                a[i] = '9';
                b[i] = '0';
            } else if (va > vb) {
                a[i] = '0';
                b[i] = '9';
            } else {
                a[i] = '1';
                b[i] = '0';
                go(i + 1, va * 10 + 1, vb * 10);

                a[i] = '0';
                b[i] = '1';
                go(i + 1, va * 10, vb * 10 + 1);

                a[i] = b[i] = '0';
            }
        } else if (a[i] == '?') {
            if (va < vb) {
                a[i] = '9';
            } else if (va > vb) {
                a[i] = '0';
            } else {
                int db = b[i] - '0';
                if (db > 0) {
                    a[i] = (char) (db - 1 + '0');
                    go(i + 1, va * 10 + db - 1, vb * 10 + db);
                }
                if (db < 9) {
                    a[i] = (char) (db + 1 + '0');
                    go(i + 1, va * 10 + db + 1, vb * 10 + db);
                }
                a[i] = b[i];
            }
        } else if (b[i] == '?') {
            if (vb < va) {
                b[i] = '9';
            } else if (vb > va) {
                b[i] = '0';
            } else {
                int da = a[i] - '0';
                if (da > 0) {
                    b[i] = (char) (da - 1 + '0');
                    go(i + 1, va * 10 + da, vb * 10 + da - 1);
                }
                if (da < 9) {
                    b[i] = (char) (da + 1 + '0');
                    go(i + 1, va * 10 + da, vb * 10 + da + 1);
                }
                b[i] = a[i];
            }
        }
        go(i + 1, va * 10 + a[i] - '0', vb * 10 + b[i] - '0');
        a[i] = ta;
        b[i] = tb;
    }

    void solve() throws IOException {
        in = new InputReader("B-large.in");
        out = new OutputWriter("B-large.out");

        int testCount = in.readInt();
        for (int test = 1; test <= testCount; ++test) {
            a = in.readToken().toCharArray();
            b = in.readToken().toCharArray();
            ba = -1;
            go(0, 0, 0);
            out.println("Case #" + test + ": " + sa + " " + sb);
            System.err.println("Case #" + test + ": " + sa + " " + sb);
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
        new B().solve();
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
