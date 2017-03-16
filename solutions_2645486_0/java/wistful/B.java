import java.io.*;
import java.util.*;

public class B {

    void solve() throws IOException {
        in("B-small-attempt0.in"); out("B-small-attempt0.out");

        int testCount = readInt();
        for (int test = 1; test <= testCount; ++test) {
            int e = readInt();
            int r = readInt();
            int n = readInt();
            int[] v = new int[n];
            for (int i = 0; i < n; ++i) {
                v[i] = readInt();
            }
            int[][] d = new int[n][e + 1];
            int best = 0;
            for (int i = 0; i < n; ++i) {
                for (int ce = 0; ce <= e; ++ce) {
                    int a = ce * v[i];
                    for (int ee = ce; ee <= e; ++ee) {
                        int ne = ee - ce + r;
                        if (ne > e) ne = e;
                        int b = a;
                        if (i > 0) b += d[i - 1][ee];
                        if (b > d[i][ne]) d[i][ne] = b;
                        if (d[i][ne] > best) best = d[i][ne];
                    }
                }
            }
            println("Case #" + test + ": " + best);
        }

        exit();
    }

    void in(String name) throws IOException {
        if (name.equals("__std")) {
            in = new BufferedReader(new InputStreamReader(System.in));
        } else {
            in = new BufferedReader(new FileReader(name));
        }
    }

    void out(String name) throws IOException {
        if (name.equals("__std")) {
            out = new PrintWriter(System.out);
        } else {
            out = new PrintWriter(name);
        }
    }

    void exit() {
        out.close();
        System.exit(0);
    }

    char readChar() throws IOException {
        return (char) in.read();
    }

    int readInt() throws IOException {
        return Integer.parseInt(readToken());
    }

    long readLong() throws IOException {
        return Long.parseLong(readToken());
    }

    double readDouble() throws IOException {
        return Double.parseDouble(readToken());
    }

    String readLine() throws IOException {
        st = null;
        return in.readLine();
    }

    String readToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    boolean eof() throws IOException {
        return !in.ready();
    }

    void print(String format, Object ... args) {
        out.print(new Formatter(Locale.US).format(format, args));
    }

    void println(String format, Object ... args) {
        out.println(new Formatter(Locale.US).format(format, args));
    }

    void print(Object value) {
        out.print(value);
    }

    void println(Object value) {
        out.println(value);
    }

    void println() {
        out.println();
    }

    StringTokenizer st;

    BufferedReader in;
    PrintWriter out;

    public static void main(String[] args) throws IOException {
        new B().solve();
    }
}
