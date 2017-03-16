import java.io.*;
import java.util.*;
import java.math.*;

public class Dlarge{
    public static void main( String[] args ) throws IOException {
        Scanner in = new Scanner( System.in );
        PrintWriter out = new PrintWriter( System.out );
        
        int T = in.nextInt();

        for (int i = 0; i < T; i++){
            int k,c,s;
            k = in.nextInt();
            c = in.nextInt();
            s = in.nextInt();

            BigInteger[] ret = new BigInteger[s];
            
            ret = solve(k,c,s);
            
            if (ret[0].compareTo(BigInteger.ZERO) == 0){
                out.print("Case #");
                out.print(i + 1);
                out.println(": IMPOSSIBLE"); 
                out.flush();
            }else{
                out.print("Case #");
                out.print(i + 1);
                out.print(":");  
                for (int j = 0; j < s; j++){
                    if (ret[j].compareTo(BigInteger.ZERO) == 1){
                        out.print(" ");
                        out.print(ret[j]);
                    }
                }
                out.println();
                out.flush();
            }
        }
            
    }
    
    public static BigInteger[] solve(int k, int c, int s){

        BigInteger bk = BigInteger.valueOf(k);
        BigInteger bc = BigInteger.valueOf(c);
        BigInteger[] ret = new BigInteger[s];
        int b = 0;
        for (int i = 0; i < s; i++){
            ret[i] = BigInteger.ZERO;
        }
        
        if (k > c * s){
            return ret;
        }
        
        BigInteger a = BigInteger.ZERO;
        
        while(bk.compareTo(a.add(bc)) != -1){
            BigInteger sum = BigInteger.ZERO;
            BigInteger bbk = BigInteger.ONE;
            for (int i = 0; i < c; i++){
                sum = sum.add(bbk.multiply(a));
                bbk = bbk.multiply(bk);
                a = a.add(BigInteger.ONE);
            }
            ret[b] = sum.add(BigInteger.ONE);
            b++;
        }
        
        if (a.compareTo(bk) == -1){
            BigInteger sum = BigInteger.ZERO;
            BigInteger bbk = BigInteger.ONE;
            for (int i = 0; a.compareTo(bk) == -1; i++){
                sum = sum.add(bbk.multiply(a));
                bbk = bbk.multiply(bk);
                a = a.add(BigInteger.ONE);
            }
            ret[b] = sum.add(BigInteger.ONE);
            b++;
        }
        return ret;
    }
}