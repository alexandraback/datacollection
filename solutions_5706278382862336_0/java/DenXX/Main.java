//package denxx;

import java.util.*;

public class Main {

    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static int highestBitPos(long a) {
        int res = 0;
        while (a != 0) {
            ++res;
            a >>= 1;
        }
        return res;
    }

    public static void main(String[] args) {
	    Scanner stdin = new Scanner(System.in);
        int T = stdin.nextInt();
        for (int t = 1; t <= T; ++t) {
            String fr = stdin.next();
            int pos = fr.indexOf('/');
            long p = Long.parseLong(fr.substring(0, pos));
            long q = Long.parseLong(fr.substring(pos + 1));
            long g = gcd(p, q);
            if (g != 1) {
                p /= g;
                q /= g;
            }
            if ((q & (q - 1)) != 0) {
                System.out.println("Case #" + t + ": impossible");
            } else {
                System.out.println("Case #" + t + ": " + (highestBitPos(q) - highestBitPos(p)));
            }
        }
    }
}
