import java.io.*;
import java.util.*;

public class C {

    void solve() throws IOException {
        in("C-small-attempt2.in"); out("C-small-attempt2.out");

        int T = readInt();
        for (int t = 1; t <= T; ++t) {
            int n = readInt();
            int[] c = new int[n];
            int[] s = new int[n];
            double[] p = new double[n];
            for (int i = 0; i < n; ++i) {
                c[i] = readToken().charAt(0) == 'L' ? 1 : 0;
                s[i] = readInt();
                p[i] = readInt();

            }
            double ans = 0;
            boolean flag = true;
            int a = 10000;
            while (flag && a-- > 0) {
                double min = 1e23;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (c[i] == c[j] && ((p[i] < p[j] && s[i] > s[j]) || (p[j] < p[i] && s[j] > s[i]))) {
                            double r;
                            if (p[i] < p[j]) {
                                r = (p[j] - p[i] - 5) / (s[i] - s[j]);
                            } else {
                                r = (p[i] - p[j] - 5) / (s[j] - s[i]);
                            }


                            if (r < 0) {
                                r = 0;
                            }


                            if (r < min) min = r;
                       }
                    }
                }


                if (min < 0) {
                    min = 0;
                }


                if (min > 1e22) {
                    break;
                }
                for (int i = 0; i < n; ++i) {
                    p[i] += min * s[i];
                }
                for (int i = 0; i < n && flag; ++i) {
                    for (int j = 0; j < n && flag; ++j) {
                        if (c[i] == c[j] && s[i] > s[j] && (p[i] < p[j]) && Math.abs(p[j] - p[i] - 5) < 1e-10) {
                            for (int k = 0; k < n && flag; ++k) {
                                if (c[k] != c[i]) {
                                    if ((p[i] + 1e-10 >= p[k] && p[i] + 1e-10 <= p[k] + 5) ||
                                            (p[i] + 5 - 1e-10 >= p[k] && p[i] + 5 - 1e-10 <= p[k] + 5)) {
                                        flag = false;
                                    }
                                }
                            }
                            if (flag) {
                                c[i] = 1 - c[i];
                            }
                        }
                    }
                }
                ans += min;
            }
            if (flag) {
                println("Case #%d: Possible", t);
            } else {
                println("Case #%d: %.6f", t, ans);
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
        new C().solve();
    }
}
