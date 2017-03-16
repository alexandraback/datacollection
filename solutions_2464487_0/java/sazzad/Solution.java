import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {
        
    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(new File("input.in"));
        PrintWriter writer = new PrintWriter("output.txt");
        
        int kases = scn.nextInt();
        BigInteger r, t, s, n, m, lo, hi, x, y;
        
        for(int kase = 1;kase <= kases; kase++) {
            r = scn.nextBigInteger();
            t = scn.nextBigInteger();
            
            n = new BigInteger("1");
            lo = new BigInteger("1");
            hi = t;
            
            while(lo.compareTo(hi)<=0) {
                m = lo.add(hi).divide(new BigInteger("2"));
                x = m.multiply(r);
                y = m.multiply(m);
                s = x.add(x).add(y).add(y).subtract(m);
                
                //System.out.println(m+" "+s);
                if(s.compareTo(t)<=0) {
                    if(n.compareTo(m)<0) {
                        n = m;
                    }
                    lo = m.add(BigInteger.ONE);
                } else {
                    hi = m.subtract(BigInteger.ONE);
                }
            }
            
            writer.write("Case #"+kase+": "+n+"\n");
        }
        
        writer.close();
    }
}
