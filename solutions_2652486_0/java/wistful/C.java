import java.io.*;
import java.util.*;

public class C {

    void solve() throws IOException {
        in("C-small-1-attempt0.in"); out("C-small-1-attempt0.out");

        int testCount = readInt();
        int r = readInt();
        int n = readInt();
        int m = readInt();
        int k = readInt();
        println("Case #1:");
        while (r-- > 0) {
            int[] v = new int[k];
            for (int i = 0; i < k; ++i) {
                v[i] = readInt();
            }
            boolean flag = false;
            for (int a = 2; a <= m && !flag; ++a) {
                for (int b = a; b <= m && !flag; ++b) {
                    for (int c = b; c <= m && !flag; ++c) {
                        flag = true;
                        for (int i = 0; i < k && flag; ++i) {
                            flag =
                                v[i] == 1 ||
                                v[i] == a || v[i] == b || v[i] == c ||
                                v[i] == a * b || v[i] == a * c || v[i] == b * c ||
                                v[i] == a * b * c;
                        }
                        if (flag) {
                            println(a + "" + b + "" + c);
                        }
                    }
                }
            }
            if (!flag) {
                println("damn");
            }
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
        new C().solve();
    }
}
