//package FairAndSquare;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class FairAndSquare {
    private static boolean isPalindrom(String s) {
        int i=0, j=s.length()-1;
        while (i<j) {
            if (s.charAt(i) != s.charAt(j))
                return false;
            ++i; --j;
        }
        
        return true;
    }
    
    public static void main(String[] args) throws IOException {
        List<BigInteger> l = new ArrayList<>();
        BigInteger MAX = new BigInteger("1000000000000000");
        BigInteger i = new BigInteger("1"), pow=i.pow(2);
        while (pow.compareTo(MAX) == -1) {
            pow = i.pow(2);
            if (isPalindrom(pow.toString()) && isPalindrom(i.toString())) {
                l.add(pow);
            }
            i = i.add(BigInteger.ONE);
        }
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String st = br.readLine();
        Integer t = new Integer(st);
        for (int it=0; it<t; ++it) {
            String in = br.readLine();
            String[] ins = in.split(" ");
            String as = ins[0];
            String bs = ins[1];
            
            BigInteger a = new BigInteger(as);
            BigInteger b = new BigInteger(bs);
            int count=0;
            for (BigInteger bi : l){
                if (a.compareTo(bi) <= 0 && b.compareTo(bi) >= 0 ) count++;
            }
            
            System.out.println("Case #" + (it+1) + ": " + count);
        }
    }
}
