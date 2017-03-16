package codejam.y2013.r1a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Cronos
 */
public class Task1 {

    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new File("D:/Programming/Projects/CodeJam/input.txt"));
        output = new BufferedWriter(new FileWriter("D:/Programming/Projects/CodeJam/output.txt"));
        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            String result = getResult();
            System.out.println("Case #" + i + ": " + result);
            output.write("Case #" + i + ": " + result);
            output.newLine();
        }
        output.close();
    }

    public static String getResult() {
        BigInteger r = input.nextBigInteger();
        BigInteger t = input.nextBigInteger();
        BigInteger s0 = r.multiply(BigInteger.valueOf(2));
        BigInteger d = t.divide(BigInteger.valueOf(100));
        Set<BigInteger> td = new HashSet<BigInteger>();
        BigInteger lc = t.divide(BigInteger.valueOf(100));
        while (true) {
            if ((s0.multiply(d.add(BigInteger.ONE))).add((d.multiply(BigInteger.valueOf(2)).add(BigInteger.ONE)).multiply(d.add(BigInteger.ONE))).compareTo(t) > 0
                    && (s0.multiply(d).add((d.subtract(BigInteger.ONE).multiply(BigInteger.valueOf(2))).multiply(d)).compareTo(t) <= 0)) return d.toString();
            if (s0.multiply(d).add((d.subtract(BigInteger.ONE).multiply(BigInteger.valueOf(2))).multiply(d)).compareTo(t) > 0) {
                lc = lc.divide(BigInteger.valueOf(2));
                d = d.subtract(lc);
                while (td.contains(d)) d = d.subtract(BigInteger.ONE);
                td.add(d);
            } else {
                lc = lc.divide(BigInteger.valueOf(2));
                d = d.add(lc);
                while (td.contains(d)) d = d.add(BigInteger.ONE);
                td.add(d);
            }
        }
    }
}
