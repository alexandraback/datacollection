import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Set;

public class A {

    private A() {
    }

    public static void main(final String[] args) throws Exception {
        final A a = new A();
        a.solve();
    }

    long[] mas = new long[41];
    final Set<Long> qq = new HashSet<Long>();

    public void solve() throws Exception {
        final BufferedReader in = new BufferedReader(new FileReader(new File("f.in")));
        System.setOut(new PrintStream(this.getClass().getSimpleName() + ".out"));
        final String line = in.readLine();
        final int test = Integer.parseInt(line);

        mas[0] = 1;
        qq.add(mas[0]);
        for (int i = 1; i < 41; i++) {
            mas[i] = mas[i - 1] * 2;
            qq.add(mas[i]);
        }

        start: for (int w = 1; w <= test; w++) {

            final String s = in.readLine();
            final String[] ss = s.split("/");
            long p = Long.parseLong(ss[0]);
            long q = Long.parseLong(ss[1]);

            long x = q;
            while (x % 2 == 0) {
                x /= 2;
            }
            if (p % x == 0) {
                p /= x;
                q /= x;
            }
            final long[] cc = simplify(p, q);
            p = cc[0];
            q = cc[1];

            if (!qq.contains(q)) {
                System.out.println("Case #" + w + ": impossible");
                continue;
            }

            if (p == q) {
                System.out.println("Case #" + w + ": 0");
                continue;
            }
            if ((p == 1 && q == 2) || (p == 3 && q == 4)) {
                System.out.println("Case #" + w + ": 1");
                continue;
            }

            final int d = deep(p, q);




            System.out.println("Case #" + w + ": " + d);
        }
    }


    private long[] simplify(long a, long b) {
        while (a % 2 == 0 && b % 2 == 0) {
            a = a / 2;
            b = b / 2;
        }
        return new long[] { a, b };
    }

    private int deep(long p, long q) {
        final long[] cc = simplify(p, q);
        p = cc[0];
        q = cc[1];

        if (p == q) {
            return 0;
        }
        if ((p == 1 && q == 2) || (p == 3 && q == 4)) {
            return 1;
        }
        if (p == 1 && qq.contains(q)) {
            return log(q, 2);
        }

        // find max
        long k = 1;
        for (int i = 40; i >= 0; i--) {
            if (mas[i] >= q)
                continue;

            if (p > mas[i]) {
                k = mas[i];
                break;
            }
        }

        final long x = p - k;

        return 1 + Math.min(deep(k, q / 2), deep(x, q / 2));
    }

    static int log(final long x, final long base)
    {
        return (int) (Math.log(x) / Math.log(base));
    }
}
