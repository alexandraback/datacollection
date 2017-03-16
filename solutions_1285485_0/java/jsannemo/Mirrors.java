
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author juice
 */
public class Mirrors {

    public static long sign(long x) {
        if (x == 0) {
            return 0;
        }
        if (x < 0) {
            return -1;
        }
        return 1;

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        for (long i = 1; i <= t; i++) {
            long h = sc.nextLong(), w = sc.nextLong(), d = sc.nextLong();
            long myx = 0, myy = 0;
            for (long j = 0; j < h; ++j) {
                String row = sc.next();
                for (int k = 0; k < w; k++) {
                    if (row.charAt(k) == 'X') {
                        myx = k;
                        myy = j;
                    }
                }
            }
            assert myx != 0 && myy != 0;
            myx--;
            myy--;
            w -= 2;
            h -= 2;
            long ans = 0;
            List<Pair> polongs = new ArrayList<Pair>();
            for (long j = -d * d; j <= d * d; j++) {
                for (long k = -d * d; k <= d * d; k++) {
                    if (j == 0 && k == 0) {
                        continue;
                    }
                    long tx = myx;
                    long ty = myy;
                    if (Math.abs(j % 2) == 1) {
                        tx = w - tx - 1;
                    }
                    if (Math.abs(k % 2) == 1) {
                        ty = h - ty - 1;
                    }
                    tx += w * j;
                    ty += h * k;
                    long dx = Math.abs(tx - myx);
                    long dy = Math.abs(ty - myy);
                    if (dx * dx + dy * dy <= d * d) {
                        //System.out.println("Room " + j + "," + k + " gives coords " + new Pair(tx, ty).toString());

                        //System.out.println("... which is OK!");
                        polongs.add(new Pair(tx, ty));
                    }
                }
            }
            for (int j = 0; j < polongs.size(); j++) {
                boolean ok = true;
                Pair a = polongs.get(j);
                for (int k = 0; k < j; k++) {
                    Pair b = polongs.get(k);
                    if ((a.a - myx) * (b.b - myy) == (a.b - myy) * (b.a - myx) && sign(a.a - myx) == sign(b.a - myx) && sign(a.b - myy) == sign(b.b - myy)) {
                        ok = false;
                    }
                }
                //System.out.println("Ok: " + a);
                if (ok) {
                    ans++;
                }
            }
            System.out.println("Case #" + i + ": " + ans);
        }
    }

    public static class Pair {

        long a, b;

        public Pair(long a, long b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int hashCode() {
            return (int) (37 * a + b);
        }

        @Override
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }
            if (getClass() != obj.getClass()) {
                return false;
            }
            final Pair other = (Pair) obj;
            if (this.a != other.a) {
                return false;
            }
            if (this.b != other.b) {
                return false;
            }
            return true;
        }

        @Override
        public String toString() {
            return "Pair{" + "a=" + a + "b=" + b + '}';
        }
    }
}
