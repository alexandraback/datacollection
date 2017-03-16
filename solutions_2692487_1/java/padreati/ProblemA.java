package cj2013.R1B;

import java.io.*;
import java.text.NumberFormat;
import java.util.Arrays;

public class ProblemA extends PrintWriter {

    private final static String PREFIX = "ProblemA_";
    private final static String INPUT_FILE = PREFIX + "in.txt";
    private final static String OUTPUT_FILE = PREFIX + "out.txt";
    private static final int BUFF_SIZE = 64 * 1024;
    int pos = 0;
    int len = -1;
    final DataInputStream dis;
    final byte[] b = new byte[BUFF_SIZE];

    public static void main(String[] args) throws Exception {
        ProblemA problem = new ProblemA(new BufferedOutputStream(System.out));
        problem.solve();
        problem.flush();
        problem.close();
    }

    public ProblemA(OutputStream os) throws FileNotFoundException {
        super(new BufferedOutputStream(new FileOutputStream(OUTPUT_FILE)));
        dis = new DataInputStream(new BufferedInputStream(new FileInputStream(INPUT_FILE)));
    }

    public int read() {
        if (pos >= len) {
            pos = 0;
            len = -1;
            try {
                len = dis.read(b);
            } catch (IOException ex) {
            }
        }
        return pos < len ? b[pos++] : -1;
    }

    public int nextInt() throws IOException {
        int ret = 0;
        int ch = skipWhite();
        int sign = 1;
        if (ch == '-') {
            sign = -1;
            ch = read();
        }
        while (!isSpaceChar(ch) && ch != -1) {
            ret *= 10;
            ret += ch - '0';
            ch = read();
        }
        return ret * sign;
    }

    public long nextLong() throws IOException {
        long ret = 0;
        int ch = skipWhite();
        int sign = 1;
        if (ch == '-') {
            sign = -1;
            ch = read();
        }
        while (!isSpaceChar(ch) && ch != -1) {
            ret *= 10;
            ret += ch - '0';
            ch = read();
        }
        return ret * sign;
    }

    public int skipWhite() throws IOException {
        int ch = read();
        while (true) {
            if (ch == -1) {
                return -1;
            }
            if (!isSpaceChar(ch)) {
                return ch;
            }
            ch = read();
        }
    }

    public boolean isSpaceChar(int c) {
        return c <= 32 && c >= 0;
    }

    public int next(char[] buff) throws IOException {
        int c = skipWhite();
        int len = 0;
        while (!isSpaceChar(c) && c != -1) {
            buff[len++] = (char) c;
            c = read();
        }
        return len;
    }

    public String next() throws IOException {
        int c = skipWhite();
        StringBuilder res = new StringBuilder();
        while (!isSpaceChar(c) && c != -1) {
            res.appendCodePoint(c);
            c = read();
        }
        return res.toString();
    }

    public String nextLine() throws IOException {
        int c = skipWhite();
        StringBuilder res = new StringBuilder();
        while (c != '\n' && c != '\r' && c != -1) {
            res.appendCodePoint(c);
            c = read();
        }
        return res.toString();
    }

    void debug(Object... obj) {
        println("-->" + Arrays.deepToString(obj));
    }

    void solve() throws Exception {
        int cases = nextInt();
        for (int kk = 1; kk <= cases; kk++) {
            long a = nextLong();
            int n = nextInt();
            long[] v = new long[n];
            for (int i = 0; i < n; i++) {
                v[i] = nextLong();
            }
            Arrays.sort(v);

            int min = n;
            int p = 0;
            int steps = 0;
            while (p < n) {
                if (v[p] < a) {
                    a += v[p];
                    p++;
                    min = Math.min(min, steps + n - p);
                    continue;
                }
                steps++;
                a += a - 1;
                if (a == 1) {
                    break;
                }
            }

            println(String.format("Case #%d: %d", kk, min));
        }
    }
}