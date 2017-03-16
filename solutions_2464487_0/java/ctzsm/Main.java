
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    static long r, t;
    static BigInteger calc(long x) {
        BigInteger n = BigInteger.valueOf(x);
        return n.multiply(BigInteger.valueOf(r * 2 + 1)).add(n.multiply(n.subtract(BigInteger.ONE)).multiply(BigInteger.valueOf(2)));
    }
    static long solve() {
        long l = 0, h = t, mid = 0;
        while (l < h) {
            mid = (l + h) >> 1;
            if (calc(mid).compareTo(BigInteger.valueOf(t)) > 0) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l - 1;
    }

    public static void main(String[] args) throws java.io.IOException {
        Scanner in = new Scanner(new FileInputStream("A-small-attempt0.in"));
        PrintWriter out = new PrintWriter("A-small-attempt0.out");
        int T = in.nextInt(), nCase = 0;
        while (++nCase <= T) {
            r = in.nextLong();
            t = in.nextLong();
            System.out.println("Case #" + nCase + ": " + solve());
            out.println("Case #" + nCase + ": " + solve());
        }
        in.close();
        out.close();
    }
}
