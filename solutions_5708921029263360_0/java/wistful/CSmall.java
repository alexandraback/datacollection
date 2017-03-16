import java.io.*;
import java.util.*;

public class CSmall {

    int j, p, s;
    int k;

    int total;
    int[][] jp, js, ps;
    boolean[][][] jps;
    List<int[]> cur, best;

    List<int[]>[][][][] cache = new List[3][3][3][10];

    void work(int v) {
        if (v == total) {
            if (cur.size() > best.size()) {
                best = new ArrayList<>(cur);
            }
            return;
        }

        int jj = v % j;
        int pp = v / j % p;
        int ss = v / j / p;
        if (jp[jj][pp] < k && js[jj][ss] < k && ps[pp][ss] < k && !jps[jj][pp][ss]) {
            jp[jj][pp]++;
            js[jj][ss]++;
            ps[pp][ss]++;
            jps[jj][pp][ss] = true;
            cur.add(new int[] {jj + 1, pp + 1, ss + 1});

            work(v + 1);

            cur.remove(cur.size() - 1);
            jp[jj][pp]--;
            js[jj][ss]--;
            ps[pp][ss]--;
            jps[jj][pp][ss] = false;
        }

        work(v + 1);
    }

    void solve() throws IOException {
        in = new InputReader("C-small-attempt0.in");
        out = new OutputWriter("C-small-attempt0.out");

        int testCount = in.readInt();
        for (int test = 1; test <= testCount; ++test) {
            j = in.readInt();
            p = in.readInt();
            s = in.readInt();
            k = in.readInt();
            best = cache[j - 1][p - 1][s - 1][k - 1];
            if (best == null) {
                total = j * p * s;
                jp = new int[j][p];
                js = new int[j][s];
                ps = new int[p][s];
                jps = new boolean[j][p][s];
                cur = new ArrayList<>();
                best = new ArrayList<>();
                work(0);
                cache[j - 1][p - 1][s - 1][k - 1] = best;
            }
            out.println("Case #" + test + ": " + best.size());
            for (int[] v : best) {
                out.println(v[0] + " " + v[1] + " " + v[2]);
            }

            System.err.println("Case #" + test + ": " + best.size());
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
        new CSmall().solve();
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
