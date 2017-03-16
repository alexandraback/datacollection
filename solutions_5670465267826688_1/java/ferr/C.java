import java.io.PrintWriter;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class C {

    private static class Q {
        public int a, b, c, d;

        public Q(int a, int b, int c, int d) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
        }

        Q mul(Q other) {
            return new Q(
                    a * other.a - b * other.b - c * other.c - d * other.d,
                    a * other.b + b * other.a + c * other.d - d * other.c,
                    a * other.c - b * other.d + c * other.a + d * other.b,
                    a * other.d + b * other.c - c * other.b + d * other.a
            );
        }

        @Override
        public boolean equals(Object o) {
            Q q = (Q) o;

            return a == q.a && b == q.b && c == q.c && d == q.d;
        }

        @Override
        public int hashCode() {
            int result = a;
            result = 31 * result + b;
            result = 31 * result + c;
            result = 31 * result + d;
            return result;
        }

        @Override
        public String toString() {
            return "Q{" +
                    "a=" + a +
                    ", b=" + b +
                    ", c=" + c +
                    ", d=" + d +
                    '}';
        }

        public static final Q X = new Q(1, 0, 0, 0);
        public static final Q I = new Q(0, 1, 0, 0);
        public static final Q J = new Q(0, 0, 1, 0);
        public static final Q K = new Q(0, 0, 0, 1);
    }


    private static Scanner sc;
    private static PrintWriter pw;

    boolean ttry(String s) {
        Map<Character, Q> by = new HashMap<>();
        by.put('i', Q.I);
        by.put('j', Q.J);
        by.put('k', Q.K);

        Q cur = Q.X;

        for (int i = 0; i < s.length(); ++i) {
            cur = cur.mul(by.get(s.charAt(i)));
            if (cur.equals(Q.I)) {
                cur = Q.X;
                for (int j = i + 1; j < s.length(); ++j) {
                    cur = cur.mul(by.get(s.charAt(j)));
                    if (cur.equals(Q.J)) {
                        cur = Q.X;
                        for (int k = j + 1; k < s.length(); ++k) {
                            cur = cur.mul(by.get(s.charAt(k)));
                        }
                        return cur.equals(Q.K);
                    }
                }
                return false;
            }
        }
        return false;
    }

    private String run_case() {
        long L = sc.nextLong(), X = sc.nextLong();
        String s = sc.next();
        int qty;
        if (X > 16) {
            qty = 16 + (int)((X - 16) % 4);
        } else {
            qty = (int) X;
        }
        StringBuilder ss = new StringBuilder();
        for (int i = 0; i < qty; ++i) {
            ss.append(s);
        }
        return ttry(ss.toString()) ? "YES" : "NO";
    }


    private void run() {
        int n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            System.err.println(i);
            System.err.flush();
            String res = run_case();
            pw.println("Case #" + (i + 1) + ": " + res);
            pw.flush();
        }
    }

    public static void main(String[] args) throws Exception {
        if (args.length == 2) {
            sc = new Scanner(Paths.get(args[0]));
            pw = new PrintWriter(args[1]);
        } else {
            sc = new Scanner(System.in);
            pw = new PrintWriter(System.out);
        }
        new C().run();
    }
}
