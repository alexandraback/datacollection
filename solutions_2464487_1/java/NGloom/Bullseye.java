import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;


public class Bullseye {
    
    static boolean greater(long r, long t, long n) {
        BigInteger rtn = new BigInteger("" + (2*r+1));
        rtn = rtn.multiply(new BigInteger(""+n));
        BigInteger tmp  = new BigInteger("" + n);
        tmp = tmp.multiply(tmp.subtract(new BigInteger("1")));
        tmp = tmp.multiply(new BigInteger(""+2));
        rtn = rtn.add(tmp);
        
        BigInteger max = new BigInteger(""+t);
        return rtn.compareTo(max) == 1;
    }
    
    
    public static long count(long t, long r) {
        long l = 1;
        long h = (long)(Math.sqrt(t)+100);
        while(l + 1 < h) {
            long mid = l+(h-l)/2;
            
            if(greater(r, t, mid)) {
                h = mid;
            } else {
                l = mid;
            }
        }
        return l;
    }
    
    static long gcd(long a,long b) {
        if(b== 0) {
            return a;
        }
        return gcd(b,a%b);
    }
    
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("bulls_eye.txt"));
            int num = in.nextInt();
            for(int n = 1; n <= num; n++) {
                long r = in.nextLong();
                long t = in.nextLong();
                long cnt = 0;

                cnt = count(t,r);
                
                System.out.println(String.format("Case #%d: %d",n,cnt));
                
            }
            
            
            
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
