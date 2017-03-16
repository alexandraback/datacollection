package exoA;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jean
 */
public class ExoA {

    public static void main(String[] args) {


        String base = "/home/jean/gcj2014/1c/ExoA/";
        String input = base + "b1.in";
        String output = base + "b1.out";

        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);

            int n = sc.nextInt();
            sc.nextLine();
            for (int c = 0; c < n; c++) {
                System.out.println("Test case " + (c + 1) + "...");
                pw.print("Case #" + (c + 1) + ": ");
                test(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(ExoA.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    private static void test(Scanner sc, PrintWriter pw) {
        String l[] = sc.nextLine().split("/");
        long P = Long.valueOf(l[0]);
        long Q = Long.valueOf(l[1]);
        
        BigInteger p = BigInteger.valueOf(P);
        BigInteger q = BigInteger.valueOf(Q);
        BigInteger g = p.gcd(q);
        
        BigInteger pp = p.divide(g);
        BigInteger qq = q.divide(g);
        
        //System.out.println("pp is " + pp + " of size  " + pp.bitLength());
        //System.out.println("qq is " + qq + " of size  " + qq.bitLength());
        
        if( qq.bitCount() > 1) {
            pw.print("impossible");
        } else {
            int c = qq.bitLength() - pp.bitLength();
            pw.print(c);
        }
        
        
    }


}
