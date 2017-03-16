/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj2013;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author vieta_000
 */

public class C_2 {
    
    static boolean palin(BigInteger a) {
        String s = a.toString();
        //System.out.println(s);
        for (int i = 0; i < s.length()/2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) 
                return false;
        }
        return true;
    }
    static int sum;
    static BigInteger[] result = new BigInteger[100000];    
    static int get(BigInteger A) {
        int l = 1, r = sum, res = 0;
        while (l <= r) {
            int m = (l + r)/2;
            if (result[m].compareTo(A) <= 0) {
                res = m;
                l = m + 1;
            } else r = m - 1;
        }
        //System.out.println(A.toString() + " " + res);
        return res;
    }
    
    public static void main(String[] args) {
        BigInteger[][] res = new BigInteger[52][10000];
        int[] d = new int[52];
        
        //1
        res[1][0] = BigInteger.valueOf(1);
        res[1][1] = BigInteger.valueOf(2);
        res[1][2] = BigInteger.valueOf(3);
        d[1] = 3;
        //2
        res[2][0] = BigInteger.valueOf(11);
        res[2][1] = BigInteger.valueOf(22);
        d[2] = 2;
        
        //3..50
        for (int i = 3; i <= 50; i++) {
            if (i % 2 == 1) {
                for (int j = 0; j < d[i - 1]; j++) {
                    StringBuffer s = new StringBuffer();
                    s.append(res[i - 1][j]);
                    for (int k = 0; k <= 2; k++) {
                        s.insert(i/2, k);          
                        BigInteger tmp = new BigInteger(s.toString());
                        BigInteger tmp2 = tmp.multiply(tmp);
                        if (palin(tmp2)) {
                            res[i][d[i]] = tmp;
                            d[i]++;
                        }
                        s.delete(i/2, i/2 + 1);
                    }
                }
            } else {
                for (int j = 0; j < d[i - 2]; j++) {
                    StringBuffer s = new StringBuffer();
                    s.append(res[i - 2][j]);
                    for (int k = 0; k <= 2; k++) {
                        s.insert(i/2 - 1, k + "" + k);
                        BigInteger tmp = new BigInteger(s.toString());
                        BigInteger tmp2 = tmp.multiply(tmp);
                        if (palin(tmp2)) {
                            res[i][d[i]] = tmp;
                            d[i]++;
                        }
                        s.delete(i/2 - 1, i/2 + 1);                        
                    }
                }                
            }
        }
        
        sum = 0;
        for (int i = 1; i <= 50; i++) {
            for(int j = 0; j < d[i]; j++) result[++sum] = res[i][j].multiply(res[i][j]);
        }
        
        try {
            Scanner in = new Scanner(new File("C-small-attempt0.in"));
            PrintWriter out = new PrintWriter(new File("C.out"));
            int ntest = in.nextInt();
            for (int test = 1; test <= ntest; test++) {
                String a = in.next();
                BigInteger A = new BigInteger(a);
                String b = in.next();
                BigInteger B = new BigInteger(b);
                out.write("Case #" + test + ": " + (get(B) - get(A.subtract(BigInteger.ONE))) + "\n");   
            }
            out.close();            
        } catch(IOException e) {
        }
        
        System.out.println(sum);
    }
}
