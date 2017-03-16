import java.io.*;
import java.util.*;

public class CLarge {

    int[] primes = new int[1229];

    int mod(long n, int l, int b, int p) {
        int res = 0;
        for (int i = l - 1; i >= 0; --i) {
            int d = (n & (1L << i)) > 0 ? 1 : 0;
            res = (res * b + d) % p;
        }
        return res;
    }

    int findPrime(long n, int l, int b) {
        for (int p : primes) {
            if (mod(n, l, b, p) == 0) {
                return p;
            }
        }
        return -1;
    }

            void solve() throws IOException {
                in = new InputReader("C-large.in");
                out = new OutputWriter("C-large.out");

                boolean[] mask = new boolean[10000];
                int k = 0;
                for (int i = 2; i < mask.length; ++i) {
                    if (!mask[i]) {
                        primes[k++] = i;
                        int j = 2 * i;
                        while (j < mask.length) {
                            mask[j] = true;
                            j += i;
                        }
                    }
                }

                int testCount = in.readInt();
                for (int test = 1; test <= testCount; ++test) {
                    int n = in.readInt();
                    int j = in.readInt();

                    out.println("Case #" + test + ":");
                    int[] a = new int[9];
                    for (long i = (1 << (n - 1)) + 1; j > 0; i += 2) {
                        boolean flag = true;
                        for (int b = 2; b <= 10 && flag; ++b) {
                            a[b - 2] = findPrime(i, n, b);
                            flag = a[b - 2] != -1;
                        }

                        if (flag) {
                            --j;
                            for (int l = n - 1; l >= 0; --l) {
                                out.print((i & (1L << l)) > 0 ? 1 : 0);
                            }
                            for (int d : a) {
                                out.print(" " + d);
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
            new CLarge().solve();
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
