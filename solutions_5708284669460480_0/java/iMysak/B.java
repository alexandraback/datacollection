import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;

public class B {

    double minTime = Double.MAX_VALUE;
    private String keyboard;
    private String target;
    private int max;

    private B() {
    }

    public static void main(final String[] args) throws Exception {
        final B a = new B();
        a.solve();
    }

    public void solve() throws Exception {
        final BufferedReader in = new BufferedReader(new FileReader(new File("f.in")));
        System.setOut(new PrintStream(this.getClass().getSimpleName() + ".out"));
        // StringTokenizer st;
        final String line = in.readLine();
        final int test = Integer.parseInt(line);
        start: for (int q = 1; q <= test; q++) {
            final String sq = in.readLine();
            final String[] ss = sq.split(" ");
            final int k = Integer.parseInt(ss[0]);
            final int l = Integer.parseInt(ss[1]);
            final int s = Integer.parseInt(ss[2]);
            keyboard = in.readLine();
            target = in.readLine();

            max = 0;
            final int[] num = new int[40];
            for (int i = 0; i < k; i++) {
                num[(keyboard.charAt(i)) - ('A')]++;
            }


            boolean ok = true;
            for (int i = 0; i < l; i++) {
                final int _ = (target.charAt(i) - 'A');
                if (num[_] == 0) {
                    ok = false;
                }
            }

            if (!ok)
                System.out.println("Case #" + q + ": " + (0.0));
            else {
                final int x = count(k, l, s, "", s);

                double z = (max - x / (Math.pow(k, s)));
                z = Math.round(z * 10000000.0) / 10000000.0;

                System.out.println("Case #" + q + ": " + z);
            }
        }

    }

    private int count(final int k, final int l, final int s, final String z, final int q) {
        if (q == 0) {
            int lastIndex = 0;
            int count = 0;

            while (lastIndex != -1) {

                lastIndex = z.indexOf(target, lastIndex);

                if (lastIndex != -1) {
                    count++;
                    lastIndex++;
                }
            }
            max = Math.max(count, max);
            // if (count > 0)
            // System.err.println("" + z + " in " + target + " :" + count);
            return count;
        }
        int x = 0;
        for (int i = 0; i < k; i++) {
            x += count(k, l, s, z + keyboard.charAt(i), q - 1);
        }
        return x;
    }

}

/*
 *     final int[] num = new int[40];
            for (int i = 0; i < k; i++) {
                num[(keyboard.charAt(i)) - ('A')]++;

            }
            boolean ok = true;
            double x = 1;
            for (int i = 0; i < l; i++) {
                final int _ = (target.charAt(i) - 'A');
                if (num[_] == 0) {
                    ok = false;
                    break;
                }

                x = x * num[_] / k;

            }

            if (!ok)
                System.out.println("Case #" + q + ": " + (0.0));
            else {

                final int vo = (s - l + 1);
                final int v = (s + 1) / l;

                double z = (v - x * vo);
                z = Math.round(z * 10000000.0) / 10000000.0;

                System.out.println("Case #" + q + ": " + z);
            }
 */
