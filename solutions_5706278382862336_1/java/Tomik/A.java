package round1c;

import java.util.Scanner;

/**
 * Created by tomas on 11.05.14.
 */
public class A {

    public static void main(String[] argv) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.useDelimiter("[\\s/]");
        for (int i = 1; i <= T; i++) {
            long P = sc.nextLong();
            long Q = sc.nextLong();

            long g = gcd(P, Q);
            P /= g;
            Q /= g;

            int k = gk(Q);
            if (k == -1) {
                System.out.println("Case #" + i + ": impossible");
                continue;
            }

            int tk = tk(P, k);
            System.out.println("Case #" + i + ": " + (k-tk));
        }
    }

    public static long gcd(long a, long b) {
        if (b > a) {
            return gcd(b, a);
        }
        if (b == 0) {
            return a;
        }
        return gcd(b, a%b);
    }

    public static int gk(long a) {
        int k = 0;
        while (a % 2 == 0) {
            ++k;
            a /= 2;
        }
        if (a % 2 == 1 && a / 2 > 0) {
            return -1;
        }
        return k;
    }

    public static int tk(long a, int k) {
        long t = 1;
        int mk = 0;
        int ck = 0;
        while (a >= t && ck <= k) {
            mk = ck;
            t *= 2;
            ++ck;
        }
        return mk;
    }
}
