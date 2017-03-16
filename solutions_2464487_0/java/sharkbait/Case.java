/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package test;

import java.io.IOException;
import java.io.LineNumberReader;
import java.math.BigInteger;

public class Case {

    private BigInteger _r;
    private BigInteger _t;
    
    public static Case readCase(LineNumberReader lnr) throws IOException {
        String line = lnr.readLine();
        String[] parts = line.split(" ");
        BigInteger r = new BigInteger(parts[0]);
        BigInteger t = new BigInteger(parts[1]);
        return new Case(r, t);
    }

    private Case(BigInteger r, BigInteger t) {
        _r = r;
        _t = t;
    }
    
    public String solve() {
//        BigInteger TWO = BigInteger.valueOf(2);
//        BigInteger a = BigInteger.ZERO;
//        BigInteger ap = a;
//        BigInteger k;
//        
//        BigInteger r2p1 = _r.multiply(TWO).add(BigInteger.ONE);
//        BigInteger k = BigInteger.ZERO
//        while(true) {
//            
//        }
        long r = _r.longValue();
        long t = _t.longValue();
        long k;
        long a = 0;
        long ap = a;
        
        for(k = 0; true; k++) {
            ap = 2 * k * (k + 1) + (k + 1) * ( 2 * r + 1);
            if(ap <= t) {
                a = ap;
            } else {
                if(k < 0) {
                    k--;
                }
                break;
            }
        }
        return Long.toString(k);
    }
    
}
