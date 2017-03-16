/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package zad1;

import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Formatter;
import java.util.Scanner;

/**
 *
 * @author Milen
 */
public class Zad1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        Formatter out = new Formatter(new File("output.txt"));
        
        int tests = in.nextInt();
        for(int test = 0 ; test < tests ; test ++){
            long r = in.nextLong();
            long t = in.nextLong();
             
            BigInteger counter = binarySearch(new BigInteger("0"), new BigInteger(String.format("%d",t/r)), new BigInteger(String.format("%d",t)), new BigInteger(String.format("%d",r)));
            out.format("Case #%d: %d\n", test+1,counter);
        }
        
        
        
        out.close();
    }
    public static final BigInteger TWO = new BigInteger("2");
    public static final BigInteger ONE = new BigInteger("1");
    public static BigInteger f(BigInteger n, BigInteger r){
        return n.multiply(n).multiply(TWO).subtract(n).add(TWO.multiply(n).multiply(r));//(2*r+1)*n + 2*(n-1)*n;
    }
    public static BigInteger binarySearch(BigInteger start, BigInteger end,BigInteger searchValue,BigInteger r){
        if(f(start.add(ONE),r).compareTo(searchValue)>0){
            return start;
        }
        if(f(end,r).compareTo(searchValue) <=0){
            return end;
        }
        BigInteger mid = end.add(start).divide(TWO);
        if(f(mid,r).compareTo(searchValue)<=0){
            return binarySearch(mid, end, searchValue, r);
        }else{
            return binarySearch(start, mid.subtract(ONE), searchValue, r);
        }
    }
    
}
