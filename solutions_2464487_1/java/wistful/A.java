import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {

    void solve() throws IOException {
        in("A-large.in"); out("A-large.out");

        int testCount = readInt();
        for (int test = 1; test <= testCount; ++test) {
            long r = readLong();
            long t = readLong();
            long b = r * 2 - 1;
            long left = 0;
            long right = 2000000000;
            while (left < right) {
                long k = (left + right) / 2;
                BigInteger c = BigInteger.valueOf(k).multiply(BigInteger.valueOf(k * 2 + b));
                if (c.compareTo(BigInteger.valueOf(t)) <= 0) {
                    left = k + 1;
                } else {
                    right = k;
                }
            }
            long k = left - 1;
            println("Case #" + test + ": " + k);
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
        new A().solve();
    }
}
