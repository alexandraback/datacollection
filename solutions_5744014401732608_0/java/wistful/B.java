import java.io.*;
import java.util.*;

public class B {

    void solve() throws IOException {
        in = new InputReader("B-small-attempt0.in");
        out = new OutputWriter("B-small-attempt0.out");

        int testCount = in.readInt();
        for (int test = 1; test <= testCount; ++test) {
            int n = in.readInt();
            long m = in.readLong();
            if (m > (1l << (n - 2))) {
                out.println("Case #" + test + ": IMPOSSIBLE");
            } else {
                int[][] g = new int[n][n];
                long[] d = new long[n];
                d[0] = 1;
                for (int i = 1; i < n - 1; ++i) {
                    for (int j = 0; j < i; ++j) {
                        g[j][i] = 1;
                        d[i] += d[j];
                    }
                }
                for (int j = n - 2; j >= 0 && m > 0; --j) {
                    if (m >= d[j]) {
                        m -= d[j];
                        g[j][n - 1] = 1;
                    }
                }
                out.println("Case #" + test + ": POSSIBLE");
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        out.print(g[i][j]);
                    }
                    out.println();
                }
            }
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

        void printArray(int[] a) {
            boolean first = true;
            for (int v : a) {
                if (!first) {
                    writer.print(' ');
                } else {
                    first = false;
                }
                writer.print(v);
            }
            writer.println();
        }

        void printArray(int[][] a) {
            for (int[] v : a) {
                printArray(v);
            }
        }

        void flush() {
            writer.flush();
        }

        void close() {
            writer.close();
        }
    }
}
