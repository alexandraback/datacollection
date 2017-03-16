import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Eugene
 * Date: 27.04.13
 * Time: 4:22
 * To change this template use File | Settings | File Templates.
 */
public class Solution {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        int n = in.nextInt();
        for (int t=0; t<n; ++t) {
            pw.print("Case #" + (t+1) + ": ");
            long r1 = in.nextLong();
            long r2 = in.nextLong();
            BigInteger r = BigInteger.valueOf(r1);
            BigInteger q = BigInteger.valueOf(r2);
            BigInteger BAD = BigInteger.ZERO;
            BigInteger GOOD = BigInteger.valueOf(2200000000000000000L);
            while (GOOD.subtract(BAD).compareTo(BigInteger.ONE) > 0) {
                BigInteger med = GOOD.add(BAD).divide(BigInteger.valueOf(2));
                BigInteger need = (BigInteger.valueOf(2).multiply(r.add(med)).subtract(BigInteger.ONE)).multiply(med);
                if (need.compareTo(q) > 0) {
                    GOOD = med;
                } else {
                    BAD = med;
                }
            }
            BigInteger need = (BigInteger.valueOf(2).multiply(r.add(GOOD)).subtract(BigInteger.ONE)).multiply(GOOD);
            if (need.compareTo(q) > 0)
                GOOD = BAD;
            pw.println(GOOD.toString());
        }
        pw.flush();
    }
}
