package codejam2014;

import java.util.Scanner;

/**
 * Created by kong
 * Time: 5/11/2014 12:13 PM
 */
public class Elfs {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int tests = s.nextInt();
        s.nextLine();
        for (int t = 1; t <= tests; t++) {
            String line = s.nextLine();
            String[] parts = line.split("/");
            int k = Integer.parseInt(parts[0]);
            int n = Integer.parseInt(parts[1]);

            int rez = getGen(k, n);
            if (rez < 0)
                System.out.printf("Case #%d: impossible\n", t);
            else
                System.out.printf("Case #%d: %d\n", t, rez);
        }
    }

    private static int getGen(int k, int n) {
        long gcd = gcd(k, n);
        k /= gcd;
        n /= gcd;
        if (!isPowerOf2(n))
            return -1;

        return (31 - Integer.numberOfLeadingZeros(n)) - (31 - Integer.numberOfLeadingZeros(k));
    }

    private static boolean isPowerOf2(int n) {
        return (n & n-1) == 0;
    }

    public static long gcd (long a, long b) {
        while (b != 0) {
            long tmp = b;
            b = a % b;
            a = tmp;
        }

        return a;
    }

}

