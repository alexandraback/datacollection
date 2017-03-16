package net.purevirtual.googlejam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Hello world!
 *
 */
public class App {
    private static class Lawn {
        int[][] lawn;
        int rows;
        int cols;
        public Lawn(Scanner scanner) {
            rows = scanner.nextInt();
            cols = scanner.nextInt();
            scanner.nextLine();
            lawn = new int[rows][cols];
            System.out.println("new lawn "+rows+" "+cols);
            for (int i = 0; i < rows; i++) {
                lawn[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    lawn[i][j] = scanner.nextInt();
                }
                scanner.nextLine();    
            }
            //scanner.nextLine();
        }
        
        
        private int getRowMaximum(int row) {
            int maximum = lawn[row][0];
            for (int j = 1; j < cols; j++) {
                    if(lawn[row][j] > maximum) {
                        maximum = lawn[row][j];
                    }
            }
            return maximum;
        }
        
        private int getColMaximum(int col) {
            int maximum = lawn[0][col];
            for (int i = 1; i < rows; i++) {
                    if(lawn[i][col] > maximum) {
                        maximum = lawn[i][col];
                    }
            }
            return maximum;
        }
        
        public boolean isValid() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    int val = lawn[i][j];
                    if (val >= getColMaximum(j) || val >= getRowMaximum(i)) {
                        //ok
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    
    
    
        
    public static void main(String[] args) throws FileNotFoundException, IOException {
        PrintWriter writer = new PrintWriter(new FileWriter("output"));
        Scanner scanner = new Scanner(new FileReader("input"));
        int tests = scanner.nextInt();
        scanner.nextLine();
        for(int t=0;t<tests;t++) {
            BigInteger a = scanner.nextBigInteger();
            BigInteger b = scanner.nextBigInteger();
            //System.out.println("a"+a);
            a = bigIntSqRootCeil(a);
            //System.out.println("a"+a);
            //System.out.println("b"+b);
            b = bigIntSqRootFloor(b);
            //System.out.println("b"+b);
            scanner.nextLine();
            BigInteger count = BigInteger.ZERO;
            for(BigInteger i=a;i.compareTo(b)<=0;i=i.add(BigInteger.ONE)) {
            //    System.out.println("i"+i);
                if (isPalindrome(i) && isPalindrome(i.multiply(i))) {
                    count = count.add(BigInteger.ONE);
                }
            }
            
            String msg = "Case #"+(t+1)+": "+count;
            System.out.println(msg);
            writer.println(msg);
        }
        writer.close();
    }
    
    public static boolean isPalindrome(BigInteger num) {
        char[] word = num.toString().toCharArray();
        int i1 = 0;
        int i2 = word.length - 1;
        while (i2 > i1) {
            if (word[i1] != word[i2]) {
                return false;
            }
            ++i1;
            --i2;
        }
        return true;
    }
    
    //http://stackoverflow.com/a/11962756/158037
    public static BigInteger bigIntSqRootFloor(BigInteger x)
            throws IllegalArgumentException {
        if (x.compareTo(BigInteger.ZERO) < 0) {
            throw new IllegalArgumentException("Negative argument.");
        }
        // square roots of 0 and 1 are trivial and
        // y == 0 will cause a divide-by-zero exception
        if (x.equals( BigInteger.ZERO) || x.equals( BigInteger.ONE)) {
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

    public static BigInteger bigIntSqRootCeil(BigInteger x)
            throws IllegalArgumentException {
        if (x.compareTo(BigInteger.ZERO) < 0) {
            throw new IllegalArgumentException("Negative argument.");
        }
        // square roots of 0 and 1 are trivial and
        // y == 0 will cause a divide-by-zero exception
        if (x.equals( BigInteger.ZERO) || x.equals( BigInteger.ONE)) {
            return x;
        } // end if
        BigInteger two = BigInteger.valueOf(2L);
        BigInteger y;
        // starting with y = x / 2 avoids magnitude issues with x squared
        for (y = x.divide(two);
                y.compareTo(x.divide(y)) > 0;
                y = ((x.divide(y)).add(y)).divide(two));
        if (x.compareTo(y.multiply(y)) == 0) {
            return y;
        } else {
            return y.add(BigInteger.ONE);
        }
    } // end bigIntSqRootCeil
}
