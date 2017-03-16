import java.util.*;
public class A {
    static Scanner s;
    public static void main(String[] args) {
        s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.printf("Case #%d: %s\n", i, solve());
        }
    }

    public static String solve() {
        String tmp = s.next();
        String[] lol = tmp.split("/");
        long P = Long.parseLong(lol[0]);
        long Q = Long.parseLong(lol[1]);
        long gcd = GCD(P,Q);
        P /= gcd;
        Q /= gcd;
        if (!powerOf2(Q)) {
            return "impossible";
        } else {
            long temp = Q / 2;
            int count = 1;
            while (P < temp) {
                temp /= 2;
                count++;
            }
            return "" + count;
        }

    }

    public static long GCD(long a, long b) {
        if (b==0) return a;
        return GCD(b,a%b);
    }

    public static boolean powerOf2 (long a) {
        while (a > 0) {
            if (a % 2 == 0) {
                a /= 2;
            } else {
                if (a == 1) return true;
                else return false;
            }
        }
        return true;
    }
}
