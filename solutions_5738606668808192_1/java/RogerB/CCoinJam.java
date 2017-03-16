package Qualifier;

import java.math.BigInteger;

public class CCoinJam {
    public static void main (String[] args) {
        int jamLength = 32;
        int jamCount = 500;
        
        BigInteger begin = BigInteger.ONE.shiftLeft(jamLength - 1).add(BigInteger.ONE);
        BigInteger end = BigInteger.ONE.shiftLeft(jamLength).subtract(BigInteger.ONE);
        
        System.out.println("Case #1:");
        
        int foundCount = 0;
        
        for (BigInteger x = begin; x.compareTo(end) <= 0; x = x.add(new BigInteger("2"))) {
            String[] divisorList = coinJam(x);
            if (divisorList.length > 0) {
                System.out.printf(x.toString(2));
                for (int i = 0; i < divisorList.length; i++)
                    System.out.printf(" %s", divisorList[i]);
                System.out.println();
                if (++foundCount >= jamCount) break;
            }
        }
    }
    
    static String[] coinJam(BigInteger testVal) {
        String[] divisorList = new String[9];
        for (int x = 2; x <= 10; x++) {
            String smallestDivisor = smallestDivisor(testVal, x);
            if (smallestDivisor.length() == 0) {
                return new String[0];
            } else {
                divisorList[x - 2] = smallestDivisor;
            }
        }
        return divisorList;
    }
    
    static String smallestDivisor(BigInteger testVal, int base) {
        BigInteger val = new BigInteger(testVal.toString(2), base);
        BigInteger cap = new BigInteger("100000"); //cut off primality testing early and move on if no small factor is found
        if (cap.compareTo(val) >= 0) cap = val.subtract(BigInteger.ONE);
        for (BigInteger test = new BigInteger("3"); test.compareTo(cap) <= 0; test = test.add(new BigInteger("2"))) {
            if (val.mod(test).equals(BigInteger.ZERO)) return test.toString();
        }
        return "";
    }
}
