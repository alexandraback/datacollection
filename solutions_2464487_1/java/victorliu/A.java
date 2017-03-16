/**
 * Google Code Jam | Round 1A | Problem A
 * 
 * @author Victor Liu
 * @contact victor.liu@rochester.edu
 */
package GCJ2013.Round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class A {

    public static final String INPUT_FILE = "C:\\Users\\Victor\\Downloads\\A-large.in";
    public static final String OUTPUT_FILE = "C:\\Users\\Victor\\Desktop\\A-large2.out";

    public static void main(String[] args) throws FileNotFoundException {

        Scanner sc = new Scanner(new File(INPUT_FILE));
        PrintWriter pw = new PrintWriter(OUTPUT_FILE);

        int T = Integer.parseInt(sc.nextLine());
        for (int n = 1; n <= T; n++) {
            String[] in = sc.nextLine().split(" ");
            String r = in[0];
            String t = in[1];
            pw.printf("Case #%d: %s\n", n, solve(r, t));
        }
        
        pw.close();

    }
    
    public static String solve(String r, String t) {

        BigDecimal R = new BigDecimal(r);
        BigDecimal T = new BigDecimal(t);
        
        BigDecimal a = BigDecimal.valueOf(2);
        BigDecimal b = R.multiply(a).subtract(BigDecimal.ONE);
        BigDecimal c = T.negate();
        
        BigDecimal result = b.negate().add(sqrt(b.pow(2).subtract(BigDecimal.valueOf(4).multiply(a).multiply(c)), 10000)).divide(BigDecimal.valueOf(4));
        return result.toBigInteger().toString();
        
        /*
        double R = Double.valueOf(r);
        double T = Double.valueOf(t);
        
        double a = 2;
        double b = 2*R-1;
        double c = -T;

        double result = (-b + Math.sqrt(b*b - 4*a*c)) / (2.0 * a);
        System.out.println(result);
        return (long) result;
        */
        
    }
    
    /*** Gratefully from http://www.java-forums.org/advanced-java/44345-square-rooting-bigdecimal.html ***/
    public static BigDecimal sqrt(BigDecimal x, int scale)
    {
        // Check that x >= 0.
        if (x.signum() < 0) {
            throw new IllegalArgumentException("x < 0");
        }
 
        // n = x*(10^(2*scale))
        BigInteger n = x.movePointRight(scale << 1).toBigInteger();
 
        // The first approximation is the upper half of n.
        int bits = (n.bitLength() + 1) >> 1;
        BigInteger ix = n.shiftRight(bits);
        BigInteger ixPrev;
 
        // Loop until the approximations converge
        // (two successive approximations are equal after rounding).
        do {
            ixPrev = ix;
 
            // x = (x + n/x)/2
            ix = ix.add(n.divide(ix)).shiftRight(1);
 
            Thread.yield();
        } while (ix.compareTo(ixPrev) != 0);
 
        return new BigDecimal(ix, scale);
    }
}