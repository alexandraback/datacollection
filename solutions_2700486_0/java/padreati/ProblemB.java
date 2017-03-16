package cj2013.R1B;

import java.io.*;
import java.util.Arrays;

public class ProblemB extends PrintWriter {

    private final static String PREFIX = "ProblemB_";
    private final static String INPUT_FILE = PREFIX + "in.txt";
    private final static String OUTPUT_FILE = PREFIX + "out.txt";
    private static final int BUFF_SIZE = 64 * 1024;
    int pos = 0;
    int len = -1;
    final DataInputStream dis;
    final byte[] b = new byte[BUFF_SIZE];

    public static void main(String[] args) throws Exception {
        ProblemB problem = new ProblemB(new BufferedOutputStream(System.out));
        problem.solve();
        problem.flush();
        problem.close();
    }

    public ProblemB(OutputStream os) throws FileNotFoundException {
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
            int n = nextInt();
            int x = nextInt();
            int y = nextInt();
            if (x < 0) {
                x = -x;
            }
            if (x == 0 && y == 0) {
                println(String.format("Case #%d: 1.0", kk));
                continue;
            }
            int s = x + y;
            int ss = 0;
            boolean inside = false;
            while (n > 0) {
                if (ss > s) {
                    inside = true;
                    break;
                }
                if (ss == s) {
                    if (n >= ss * 2 + 1) {
                        inside = true;
                    }
                    break;
                }
                n -= ss * 2 + 1;
                ss += 2;
            }
            if (inside) {
                println(String.format("Case #%d: 1.0", kk));
                continue;
            }
            double[] p = new double[s + 1];
            for (int i = 0; i < Math.min(n, s); i++) {
                for (int j = 0; j <= i; j++) {
                    p[j] += 1. / (2. * (i + 1));
                }
            }
            n -= s;
            for (int i = 0; i < Math.min(n, s); i++) {
                for (int j = i; j <= s - 1; j++) {
                    p[j] += 1. / (2. * (s - i));
                }
            }
            n -= s;
            if (n > 0) {
                p[s] = 1;
            }

            println(String.format("Case #%d: %.10f", kk, p[y]));
        }
    }
}