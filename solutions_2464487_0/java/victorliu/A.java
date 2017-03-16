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
import java.util.Scanner;

public class A {

    public static final String INPUT_FILE = "C:\\Users\\Victor\\Downloads\\A-small.in";
    public static final String OUTPUT_FILE = "C:\\Users\\Victor\\Desktop\\A-small.out";

    public static void main(String[] args) throws FileNotFoundException {

        Scanner sc = new Scanner(new File(INPUT_FILE));
        PrintWriter pw = new PrintWriter(OUTPUT_FILE);

        int T = Integer.parseInt(sc.nextLine());
        for (int n = 1; n <= T; n++) {
            String[] in = sc.nextLine().split(" ");
            String r = in[0];
            String t = in[1];
            pw.printf("Case #%d: %d\n", n, solve(r, t));
        }
        
        pw.close();

    }
    
    static BigDecimal PI = BigDecimal.valueOf(3.141592653);
    static BigDecimal TWO = BigDecimal.valueOf(2);
    
    public static long solve(String r, String t) {

        long y = 0;
        BigDecimal R = new BigDecimal(r);
        BigDecimal T = new BigDecimal(t);

        while (T.compareTo(BigDecimal.ZERO) > 0) {
            BigDecimal A = TWO.multiply(R).add(BigDecimal.ONE);
            T = T.subtract(A);
            if (T.compareTo(BigDecimal.ZERO) < 0) y--;
            y++;
            R = R.add(TWO);
        }

        return y;
        
    }
}