import java.io.*;
import java.util.*;

public class B {

    void solve() throws IOException {
        in("B-small-attempt1.in"); out("B-small-attempt1.out");

        boolean[][] surprising = new boolean[31][11];
        boolean[][] plain = new boolean[31][11];

        for (int t = 0; t <= 30; ++t) {
            //plain
            // a a   a
            // a a-1 a
            // a a-1 a-1
            for (int best = 10; best >= 0; --best) {
                int v = 3 * best;
                if (v == t || v - 1 == t || v - 2 == t) {
                    for (int i = best; i >= 0; --i) {
                        plain[t][i] = true;
                    }
                    break;
                }
            }

            //surprising
            // a a-2 a
            // a a-2 a-1
            // a a-2 a-2
            for (int best = 10; best >= 2; --best) {
                int v = 3 * best;
                if (v - 2 == t || v - 3 == t || v - 4 == t) {
                    for (int i = best; i >= 0; --i) {
                        surprising[t][i] = true;
                    }
                    break;
                }
            }
        }

        int t = readInt();
        for (int cs = 1; cs <= t; ++cs) {
            int ans = 0;
            int n = readInt();
            int s = readInt();
            int p = readInt();
            int[] v = new int[n];
            int[] mask = new int[n];
            for (int i = 0; i < n; ++i) {
                v[i] = readInt();
                if (s > 0) {
                    if (surprising[v[i]][p]) {
                        mask[i] = 2;
                        --s;
                        ++ans;
                    } else if (plain[v[i]][p])  {
                        mask[i] = 1;
                        ++ans;
                    }
                } else {
                    if (plain[v[i]][p]) {
                        mask[i] = 1;
                        ++ans;
                    } else if (surprising[v[i]][p]) {
                        for (int j = 0; j < i; ++j) {
                            if (mask[j] == 2 && plain[v[j]][p]) {
                                mask[j] = 1;
                                mask[i] = 2;
                                ++ans;
                                break;
                            }
                        }
                    }
                }
            }
            if (s > 0) {
                for (int i = 0; i < n && s > 0; ++i) {
                    if (mask[i] == 0 && v[i] >= 2 && v[i] <= 28) {
                        --s;
                    }
                }
            }
            if (s > 0) {
                System.out.println("bad");
            }
            println("Case #" + cs + ": " + ans);
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
        new B().solve();
    }
}
