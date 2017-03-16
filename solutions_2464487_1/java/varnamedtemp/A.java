/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj;

/**
 *
 * @author Microsoft
 */
import java.util.*;
import java.math.BigInteger;
import java.io.*;
public class A {
    public static BigInteger S(BigInteger n, BigInteger r) {
        BigInteger first = new BigInteger("2").multiply(r).multiply(n);
        BigInteger second = new BigInteger("-3").multiply(n);
        BigInteger third = new BigInteger("2").multiply(n).multiply(n.add(BigInteger.ONE));
        return first.add(second.add(third));
    }
    
    public static void main(String []args) throws IOException {
        String largeNumber = "";
        for(int i = 0;i<30;i++)
            largeNumber += "9";
        
        
        Scanner sc = new Scanner(new File("A-large.in")) ;
        PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
        int T = sc.nextInt();
        for(int c = 1;c<=T;c++) {
            BigInteger r = new BigInteger(sc.next());
            BigInteger t = new BigInteger(sc.next());
            BigInteger l = BigInteger.ONE;
            BigInteger h = new BigInteger(largeNumber);
            BigInteger res = new BigInteger("0");

            while(l.compareTo(h) <= 0) {
                BigInteger m = (l.add(h)).divide(new BigInteger("2"));
                if(S(m, r).compareTo(t) > 0) {
                    h = m.subtract(BigInteger.ONE);
                }
                else {
                    l = m.add(BigInteger.ONE);
                    res = m;
                }
            }
            out.println("Case #" + c + ": " + res);
        }
    }
}
