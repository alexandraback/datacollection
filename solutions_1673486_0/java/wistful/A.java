import java.io.*;
import java.util.*;

public class A {

    void solve() throws IOException {
        in("A-small-attempt0.in"); out("A-small-attempt0.out");

        int T = readInt();
        for (int t = 1; t <= T; ++t) {
            int a = readInt();
            int b = readInt();
            double[] p = new double[a + 1];
            p[0] = 1.0;
            for (int i = 1; i <= a; ++i) {
                p[i] = p[i - 1] * readDouble();
            }
            double ans = b + 2;
            for (int i = 0; i <= a; ++i) {
                int n = b - a + 1 + i * 2;
                double r = p[a - i] * n + (1.0 - p[a - i]) * (n + b + 1);
                if (r < ans) ans = r;
            }
            println("Case #%d: %.6f", t, ans);
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
        out.println(new Formatter(Locale.US).format(format, args));
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
        new A().solve();
    }
}
