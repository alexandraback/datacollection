/*
 ID: timtimp1
 LANG: JAVA
 TASK: pprime
 */

import java.io.*;
import java.util.*;
import java.math.*;

public class Bullseye {

    static Scanner in;
    static BufferedWriter out;

    public static void main(String[] args) throws IOException {
        
        in = new Scanner(new File("Bullseye.in"));
        out = new BufferedWriter(new FileWriter("Bullseye.out"));


        int length = in.nextInt();

        BigInteger TWO = new BigInteger("2");
        BigInteger ONE = new BigInteger("1");
        BigInteger EIGHT = new BigInteger("8");
        BigInteger FOUR = new BigInteger("4");

        for (int test = 0; test < length; test++) {

            BigInteger r = new BigInteger("" + in.next());
            BigInteger t = new BigInteger("" + in.next());

            BigInteger TWOR = TWO.multiply(r);
            BigInteger n = ONE.subtract(TWOR).add(sqrt(TWOR.subtract(ONE).pow(2).add(EIGHT.multiply(t)))).divide(FOUR);

            out.write("Case #" + (test + 1) + ": " + n + "\n");
        }

        in.close();
        out.close();
    }
    public static BigInteger sqrt(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while(b.compareTo(a) >= 0) {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
            else a = mid.add(BigInteger.ONE);
        }
        return a.subtract(BigInteger.ONE);
    }

}    