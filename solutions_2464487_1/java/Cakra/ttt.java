import java.util.*;
import java.io.*;
import java.math.*;
 
public class ttt {
        static BigInteger area(BigInteger r, BigInteger i) {
//              BigInteger a = i*r*r + 2*i*i*r + i*(4*i*i-1)/3, b = (i*r*r + 2*(i-1)*((i-1)+1)*r + 2*(i-1)*((i-1)+1)*(2*(i-1)+1)/3);
                BigInteger ii = i.subtract(BigInteger.valueOf(1));
                BigInteger a, b;
                a = i.multiply(r).multiply(r);
                a = a.add(i.multiply(i).multiply(r).multiply(BigInteger.valueOf(2)));
                a = a.add( i.multiply( i.multiply(i).multiply(BigInteger.valueOf(4)).subtract(BigInteger.valueOf(1)) ).divide(BigInteger.valueOf(3)) );
                
                b = i.multiply(r).multiply(r);
                b = b.add( ii.multiply( ii.add(BigInteger.valueOf(1)) ).multiply(r).multiply(BigInteger.valueOf(2)) );
                b = b.add( ii.multiply( ii.add(BigInteger.valueOf(1)) ).multiply( ii.multiply(BigInteger.valueOf(2)).add(BigInteger.valueOf(1)) ).multiply(BigInteger.valueOf(2)).divide(BigInteger.valueOf(3)) );
                
                return a.subtract(b);
        }
        
        public static void main(String args[]) {
                Scanner in = new Scanner(System.in);
                
                int T = in.nextInt();
                for(int tc = 0; tc < T; tc++) {
                        BigInteger r = in.nextBigInteger(), t = in.nextBigInteger(); 
//                      System.out.println(area(r, t));
                        
                        BigInteger le = BigInteger.valueOf(1), ri =  BigInteger.valueOf(1000000000), mid;
                        while(le.compareTo(ri) < 0) {
                                mid = le.add(ri).add(BigInteger.valueOf(1));
                                mid = mid.divide(BigInteger.valueOf(2));
                                
//                              System.out.println("le="+le+",ri="+ri+",mid="+mid);
                                
                                // YYNN
                                if(area(r, mid).compareTo(t) <= 0)      le = mid;
                                else                                                            ri = mid.subtract(BigInteger.valueOf(1));
                        }
                        System.out.println("Case #"+(tc+1)+": "+ri);
                }
        }
}