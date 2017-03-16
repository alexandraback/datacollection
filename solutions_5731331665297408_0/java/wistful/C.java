import java.io.*;
import java.util.*;

public class C {

    int n;
    String[] zip;
    boolean[][] g;

    boolean[] mask;
    int[] p, s;

    StringBuffer sb = new StringBuffer();
    String best;

    void gen(int i) {
        if (i == n) {
            int t = 0;
            s[t] = p[0];
            boolean flag = true;
            for (int j = 1; j < n && flag; ++j) {
                while (t >= 0 && !g[s[t]][p[j]]) {
                    --t;
                }
                flag = t >= 0;
                if (flag) {
                    s[++t] = p[j];
                }
            }
            if (flag) {
                sb.setLength(0);
                for (int j = 0; j < n; ++j) {
                    sb.append(zip[p[j]]);
                }
                String num = sb.toString();
                if (best.length() == 0 || num.compareTo(best) < 0) {
                    best = num;
                }
            }
        } else {
            for (int j = 0; j < n; ++j) {
                if (!mask[j]) {
                    mask[j] = true;
                    p[i] = j;
                    gen(i + 1);
                    mask[j] = false;
                }
            }
        }
    }

    void solve() throws IOException {
        in = new InputReader("C-small-attempt0.in");
        out = new OutputWriter("C-small-attempt0.out");

        int testCount = in.readInt();
        for (int test = 1; test <= testCount; ++test) {
            n = in.readInt();
            int m = in.readInt();
            zip = new String[n];
            for (int i = 0; i < n; ++i) {
                zip[i] = in.readToken();
            }
            g = new boolean[n][n];
            while (m-- > 0) {
                int i = in.readInt() - 1;
                int j = in.readInt() - 1;
                g[i][j] = g[j][i] = true;
            }
            mask = new boolean[n];
            p = new int[n];
            s = new int[n];
            best = "";
            gen(0);
            out.println("Case #" + test + ": " + best);
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
        new C().solve();
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

        boolean whitespace() {
            return cur == ' ' || cur == '\t' || cur == '\r' || cur == '\n' || cur == -1;
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

        void close() {
            writer.close();
        }
    }
}
