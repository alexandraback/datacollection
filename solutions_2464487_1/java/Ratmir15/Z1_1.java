package c2013_r1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class Z1_1 {

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
    
    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\tests\\zz1.txt";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-small-attempt0.in";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\A-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            BigInteger r = scanner.nextBigInteger();
            BigInteger t = scanner.nextBigInteger();
            System.out.println(r+" "+t);
            BigInteger x = t;
            BigInteger prev = r;
            BigInteger r21 = r.multiply(new BigInteger("2")).subtract(new BigInteger("1"));
            BigInteger r212 = r21.multiply(r21);
            BigInteger t8 = t.multiply(new BigInteger("8"));
            r212 = r212.add(t8);
            BigInteger sq = bigIntSqRootFloor(r212);
            BigInteger ress = sq.subtract(r21).divide(new BigInteger("4"));
            //double xz = Math.sqrt((2*r-1)*(2*r-1)+8*t);
            //double xz = Math.sqrt((2*r-1)*(2*r-1)+8*t);
            //double result1 = (1-2*r+xz)/4;
            //double result2 = (2*r-1+xz)/4;
            //System.out.println(ress);
            //double ress = Math.floor(result1);
            //System.out.println(ress);
            String s = "Case #" + ti + ": "+ress;
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

}
