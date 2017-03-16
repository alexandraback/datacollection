import java.io.*;
import java.util.*;

public class C {

    void solve() throws IOException {
        in("C-large.in"); out("C-large.out");

        long tm = System.currentTimeMillis();
        boolean[] mask = new boolean[2000000];
        int[] r = new int[10];
        int t = readInt();
        for (int cs = 1; cs <= t; ++cs) {
            int a = readInt();
            int b = readInt();
            int ans = 0;
            for (int m = a + 1; m <= b; ++m) {
                char[] d = String.valueOf(m).toCharArray();
                int c = 0;
                for (int i = 1; i < d.length; ++i) {
                    if (d[i] != '0' && d[i] <= d[0]) {
                        int n = 0;
                        for (int j = 0; j < d.length; ++j) {
                            int jj = i + j;
                            if (jj >= d.length) jj -= d.length;
                            n = n * 10 + (d[jj] - '0');
                        }
                        if (n >= a && n < m && !mask[n]) {
                            ++ans;
                            mask[n] = true;
                            r[c++] = n;
                        }
                    }
                }
                for (int i = 0; i < c; ++i) {
                    mask[r[i]] = false;
                }
            }
            println("Case #" + cs + ": " + ans);
            //System.out.println(cs);
        }
        System.out.println("time: " + (System.currentTimeMillis() - tm));
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
