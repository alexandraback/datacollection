/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package rounda;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;

/**
 *
 * @author Rizal ZAF
 */
public class RoundA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = null;        
                    
        br = new BufferedReader(new FileReader("A-large (1).in"));
        FileWriter writer = new FileWriter("A.txt");
        
        int num = Integer.parseInt(br.readLine().trim());
        
        for (int i=0;i<num;i++){
            
            String[] vals = br.readLine().split(" ");
            
            BigInteger r = new BigInteger(vals[0]);
            BigInteger t = new BigInteger(vals[1]);
            
            r = r.add(BigInteger.ONE);      
            
            BigInteger four = new BigInteger("4");
            BigInteger twelve = new BigInteger("12");
            BigInteger eight = new BigInteger("8");
            BigInteger nine = new BigInteger("9");
            BigInteger two = new BigInteger("2");
            BigInteger minus = new BigInteger("-1");
            
            BigInteger a = r.pow(2).multiply(four);
            BigInteger b = r.multiply(twelve);
            BigInteger c = t.multiply(eight);
            BigInteger aa = a.subtract(b).add(c).add(nine);
            BigInteger ac = r.multiply(two).add(BigInteger.ONE);
            BigInteger bb = bigIntSqRootFloor(aa).subtract(ac);
            BigInteger cc = bb.divide(four);
            BigInteger ans = cc.add(BigInteger.ONE);
            
            writer.write("Case #" + (i+1) + ": " + ans.toString()  + "\r\n");
            
        }
        
        writer.close();
    }
    
    public static BigInteger bigIntSqRootFloor(BigInteger x) {
    if (x == BigInteger.ZERO || x == BigInteger.ONE) {
        return x;
    } 
    BigInteger two = BigInteger.valueOf(2L);
    BigInteger y;    
    for (y = x.divide(two);
            y.compareTo(x.divide(y)) > 0;
            y = ((x.divide(y)).add(y)).divide(two));
    return y;
}
    
}
