package Round1A;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A {
    public static String filename = "A-large (3)";
    public static Scanner scanner;
    public static PrintWriter writer;
    public static void main(String[] args) throws Exception {
        scanner = new Scanner(new File(filename + ".in"));
        writer = new PrintWriter(filename + ".out");
        int iterations = scanner.nextInt();
        scanner.nextLine();
        for (int iter = 1; iter <= iterations; iter++) {
            print("Case #" + iter + ": ");
            solve();
            flush();
        }
    }
    
    public static void solve() {
        BigInteger TWO = new BigInteger("2");
        BigInteger r = new BigInteger(scanner.next());
        BigInteger t = new BigInteger(scanner.next());
        BigInteger c = new BigInteger("2").multiply(r).add(BigInteger.ONE).subtract(t);
        BigInteger b = TWO.multiply(r).add(new BigInteger("3"));
        
        BigInteger circles = b.negate().add(bigIntSqRootFloor(b.multiply(b).subtract(new BigInteger("8").multiply(c))));
        circles = circles.divide(new BigInteger("4"));
        
        circles = circles.subtract(BigInteger.ONE);
        
        while(t.compareTo(TWO.multiply(circles).multiply(circles).add(b.multiply(circles)).add(new BigInteger("2").multiply(r).add(BigInteger.ONE))) >= 0 ) {
            circles = circles.add(BigInteger.ONE);
        }
        
        println(""+circles);
    }
    
    public static BigInteger bigIntSqRootFloor(BigInteger x)
            throws IllegalArgumentException {
        if (x.compareTo(BigInteger.ZERO) < 0) {
            throw new IllegalArgumentException("Negative argument.");
        }
        // square roots of 0 and 1 are trivial and
        // y == 0 will cause a divide-by-zero exception
        if (x == BigInteger.ZERO || x == BigInteger.ONE) {
            return x;
        } // end if
        BigInteger two = BigInteger.valueOf(2L);
        BigInteger y;
        // starting with y = x / 2 avoids magnitude issues with x squared
        for (y = x.divide(two);
                y.compareTo(x.divide(y)) > 0;
                y = ((x.divide(y)).add(y)).divide(two));
        return y;
    } // end bigIntSqRootFloor
    
    public static void print(String string) {
        System.out.print(string);
        writer.print(string);
    }
    
    public static void println(String string) {
        System.out.println(string);
        writer.println(string);
    }
    
    public static void flush() {
        System.out.flush();
        writer.flush();
    }
}
