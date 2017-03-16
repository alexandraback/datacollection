import java.io.*;
import java.util.*;

public class B {
    void solve() throws IOException {
        in("B-large.in"); out("B-large.out");

        int T = readInt();
        for (int t = 1; t <= T; ++t) {
            int n = readInt();
            int[][] p = new int[2][n];
            boolean[][] mask = new boolean[2][n];
            for (int i = 0; i < n; ++i) {
                p[0][i] = readInt();
                p[1][i] = readInt();
            }
            int ans = 0;
            boolean flag = true;
            int c = 0;
            int s = 0;
            while (flag && c < n) {
                ++ans;
                flag = false;
                for (int i = 0; i < n && !flag; ++i) {
                    if (!mask[0][i] && !mask[1][i] && s >= p[1][i]) {
                        s += 2;
                        mask[1][i] = true;
                        flag = true;
                        ++c;
                    }
                }
                for (int i = 0; i < n && !flag; ++i) {
                    if (!mask[1][i] && s >= p[1][i]) {
                        ++s;
                        mask[1][i] = true;
                        flag = true;
                        ++c;
                    }
                }
                if (!flag) {
                    int j = -1;
                    for (int i = 0; i < n; ++i) {
                        if (!mask[0][i] && !mask[1][i] && s >= p[0][i] && (j == -1 || p[1][i] > p[1][j])) {
                            j = i;
                        }
                    }
                    if (j != -1) {
                        ++s;
                        mask[0][j] = true;
                        flag = true;
                    }
                }
            }
            print("Case #%d: ", t);
            println(flag ? ans : "Too Bad");
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
