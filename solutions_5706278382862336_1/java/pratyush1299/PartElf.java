import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: pratyush.verma
 * Date: 11/05/14
 * Time: 2:37 PM
 * To change this template use File | Settings | File Templates.
 */
public class PartElf {
    public static void main(String[] args) {
        int T;
        int index = 1;
        Scanner cin = new Scanner(System.in);
        T = cin.nextInt();
        while (T-- != 0) {
            String input = cin.next();
            String ip[] = input.split("/");
            System.out.print("Case #" + index++ + ": ");

            long numerator = Long.parseLong(ip[0]);
            long denominator = Long.parseLong(ip[1]);
            long[] simple = simple(numerator, denominator);
            numerator = simple[0];
            denominator = simple[1];
            long tempD = denominator;
            long tempN = numerator;
            long generation = generation(tempN, tempD);
            if (generation == -1) {
                System.out.println("impossible");
            }
            else {
                System.out.println(generation);
            }
        }
    }

    private static long generation(long tempN, long tempD) {
        if (tempD % 2 == 1 && tempD != 1)
            return -1;
        long generation = 0;
        if (!((tempN == 0 && tempD == 1) || (tempN == 1 && tempD == 1))) {
            if (tempN > tempD) {
                tempN -= tempD;
                return generation(tempN, tempD) == -1 ? -1 : 0;
            }
            long x = 0;
            return (x = generation(tempN, tempD >> 1)) == -1 ? x :  x + 1;
        }
        return generation;
    }

    private static long[] simple(long numerator, long denominator) {
        long[] res = new long[2];
        long gcd = gcd(numerator, denominator);
        res[0] = numerator / gcd;
        res[1] = denominator / gcd;
        return res;
    }

    public static long gcd(long p, long q) {
        if (q == 0) {
            return p;
        }
        return gcd(q, p % q);
    }
}
