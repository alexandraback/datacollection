//package Qualification;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.File;
import java.util.*;
import java.math.*;
import java.util.regex.*;

/**
 *
 * @author Jurek
 */
public class C {

    public static boolean isPalindrome(BigInteger in) {
        char[] line = in.toString().toCharArray();
        int len = line.length;
        for (int i = 0; i < len / 2; i++) {
            if (line[i] != line[len - 1 - i]) {
                return false;
            }
        }

        return true;
    }
    public static ArrayList<BigInteger> fairAndSquare;

    public static int lower_bound(BigInteger test) {
        int it, step;
        int first = 0;
        int last = fairAndSquare.size();

        int count = last - first;

        while (count > 0) {
            it = first;
            step = count / 2;
            it += step;
            if (fairAndSquare.get(it).compareTo(test) <= 0) {
                first = ++it;
                count -= step + 1;
            } else {
                count = step;
            }
        }
        return first;
    }

    public static int upper_bound(BigInteger test) {
        int it, step;
        int first = 0;
        int last = fairAndSquare.size();

        int count = last - first;

        while (count > 0) {
            it = first;
            step = count / 2;
            it += step;
            if (!(fairAndSquare.get(it).compareTo(test) >= 0)) {
                first = ++it;
                count -= step + 1;
            } else {
                count = step;
            }
        }
        return first;
    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();

        // =====================================================================
        // Operation
        // =====================================================================       
       
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        in.nextLine();
        String line;
        String[] split;
        BigInteger A;
        BigInteger B;
        BigInteger count;

        BigInteger lowerLimit = new BigInteger("1");
        BigInteger upperLimit = new BigInteger("10");
        upperLimit = upperLimit.pow(14);

        fairAndSquare = new ArrayList<BigInteger>(1000);
        for (BigInteger i = lowerLimit, square; i.compareTo(upperLimit) < 0; i = i.add(BigInteger.ONE)) {
            square = i.multiply(i);
            if (square.compareTo(upperLimit) > 0) {
                break;
            }
            if (isPalindrome(i) && isPalindrome(square)) {
                fairAndSquare.add(new BigInteger(square.toString()));
            }
        }
        //BigInteger[] fAS = fairAndSquare.toArray(new BigInteger[fairAndSquare.size()]);
        //pl(fairAndSquare);

        for (int kase = 1; kase <= T; kase++) {
            count = BigInteger.ZERO;

            // Read in
            line = in.nextLine();
            split = line.split("[\\s]+");
            A = new BigInteger(split[0]);
            B = new BigInteger(split[1]);

            // Calculate number
            int low  = upper_bound(A);
            int high = lower_bound(B);
            //if(high > fairAndSquare.size() - 1) {
            high--;
            //}
            //pl("low:  " + low );
            //pl("high: " + high);
            //pl("low:  " + low + " (" + fairAndSquare.get(low).toString()  + ")");
            //pl("high: " + high+ " (" + fairAndSquare.get(high).toString() + ")");
            
            if(low > high) {
                count = BigInteger.ZERO;
            } else if(fairAndSquare.get(low).compareTo(B) > 0) {
                count = BigInteger.ZERO;
            } else if(fairAndSquare.get(high).compareTo(A) < 0) {
                count = BigInteger.ZERO;
            } else {
                count = new BigInteger("" + high).subtract(new BigInteger("" + low)).add(BigInteger.ONE);
            }
            
            // Print
            //pr(A);
            //pr(" ");
            //pl(B);
            pr("Case #" + kase + ": ");
            pl(count);
            //pl();
        }

        // =====================================================================
        // Output
        // =====================================================================
        long end = System.currentTimeMillis();

        //pl("============" + (end - start) + " ms");
        //pl("");
    }

    public static void pf(String s, Object... o) {
        System.out.printf(s, o);
    }

    public static void pl() {
        System.out.println("");
    }

    public static void pl(ArrayList<Object> i) {
        System.out.println(Arrays.toString(i.toArray()));
    }

    public static void pl(Object o) {
        System.out.println(o);
    }

    public static void pr(Object o) {
        System.out.print(o);
    }
}
