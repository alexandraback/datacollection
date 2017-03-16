import java.io.*;
import java.util.*;

public class A {

    void solve() throws IOException {
        in("A-small-attempt0.in"); out("A-small-attempt0.out");

        final String a =
                "ejp mysljylc kd kxveddknmc re jsicpdrysi\n" +
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\n" +
                "de kr kd eoya kw aej tysr re ujdr lkgc jv";

        final String b =
                "our language is impossible to understand\n" +
                "there are twenty six factorial possibilities\n" +
                "so it is okay if you want to just give up";

        final char[] f = new char['z' - 'a' + 1];
        for (int i = 0; i < a.length(); ++i) {
            char ch = a.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                int index = ch - 'a';
                if (f[index] == 0) {
                    f[index] = b.charAt(i);
                } else if (f[index] != b.charAt(i)) {
                    System.out.println("bad in " + i + " pos");
                }

            }
        }

        if (f['q' - 'a'] == 0) {
           f['q' - 'a'] = 'z';
        }

        if (f['z' - 'a'] == 0) {
            f['z' - 'a'] = 'q';
        }

        for (int i = 0; i < 'z' - 'a' + 1; ++i) {
            if (f[i] == 0) {
                System.out.println("empty char in " + i + " pos");
            }
        }

        System.out.println("done");

        int t = readInt();
        for (int cs = 1; cs <= t; ++cs) {
            char[] s = readLine().toCharArray();
            print("Case #" + cs + ": ");
            for (int i = 0; i < s.length; ++i) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    print(f[s[i] - 'a']);
                } else {
                    print(s[i]);
                }
            }
            println();
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
