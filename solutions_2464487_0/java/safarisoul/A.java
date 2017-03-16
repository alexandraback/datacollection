package gcj2013r1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A {
    private static BigInteger t;
    private static BigInteger two = new BigInteger("2");
    private static BigInteger three = new BigInteger("3");

    public static void main(String[] args) throws IOException,
            FileNotFoundException {
        String input = "A-small-attempt0.in";
        String output = "A-small-attempt0.out";
        // String input = "A-large.in";
        // String output = "A-large.out";

        Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(
                output)));

        int T = Integer.parseInt(scan.nextLine());
        for (int c = 1; c <= T; c++) {
            String[] info = scan.nextLine().split(" ");
            long r = Long.parseLong(info[0]);
            t = new BigInteger(info[1]);
            if (Long.parseLong(info[0]) % 2 == 1) {
                BigInteger exclude = new BigInteger(String.valueOf(r / 2));
                BigInteger save = sumOdd(exclude);

                BigInteger left = BigInteger.ONE;
                BigInteger right = t;
                while (right.subtract(left).compareTo(BigInteger.ONE) > 0) {
                    BigInteger mid = left.add(right).divide(two);
                    if (sumOdd(mid).subtract(save).compareTo(t) <= 0)
                        left = mid;
                    else
                        right = mid;
                }

                pw.println("Case #" + c + ": "
                        + left.subtract(exclude).toString());
                System.out.println("Case #" + c + ": "
                        + left.subtract(exclude).toString());
            }
            else {
                BigInteger exclude = new BigInteger(String.valueOf((r - 1) / 2));
                BigInteger save = sumEven(exclude);

                BigInteger left = BigInteger.ONE;
                BigInteger right = t;
                while (right.subtract(left).compareTo(BigInteger.ONE) > 0) {
                    BigInteger mid = left.add(right).divide(two);
                    if (sumEven(mid).subtract(save).compareTo(t) <= 0)
                        left = mid;
                    else
                        right = mid;
                }

                pw.println("Case #" + c + ": "
                        + left.subtract(exclude).toString());
                System.out.println("Case #" + c + ": "
                        + left.subtract(exclude).toString());
            }
        }

        scan.close();
        pw.close();
    }

    private static BigInteger sumOdd(BigInteger n) {
        return n.multiply(n).multiply(two).add(n);
    }

    private static BigInteger sumEven(BigInteger n) {
        return n.multiply(n).multiply(two).add(n.multiply(three));
    }
}
