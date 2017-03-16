import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class probAlarge {
    public static long cool = 2000000000000000000L;
    
    public static double func(long r, long k) {
        double temp = 2*r;
        temp*=k;
        double t2 = 2*k-1;
        t2*=k;
        return temp+t2;
    }

    public static int check(int r, int t) {
        long k = 1;
        while(func((long)r,k)<=t) {
            k++;
        }
        return (int)(k-1);
    }

    public static long binarySearch(long r, long t) {
        //System.out.println("searching "+r+" "+t);
        long low = 1;
        long high = cool;
        double comp = t;
        while( low <= high) {
            long mid = (low+high)/2;
            double key = func(r,mid);
         //   System.out.println("step: "+low+" "+high+" "+key);
            if(key == comp) {
                return mid;
            }
            else if (key < comp) {
                low = mid+1;
            }
            else {
                high = mid - 1;
            }
        }
        while(func(r,low)<=comp) {
            low++;
        }
        return low-1;
    }
    public static void main(String ... args) throws IOException {
        System.out.println(cool);
        Scanner input = new Scanner(System.in);
        PrintWriter out = new PrintWriter("probAlarge.out");
        int t = Integer.parseInt(input.nextLine());
        for(int i=1;i<=t;i++) {
            long r = input.nextLong();
            long m = input.nextLong();

            long answer = binarySearch(r,m);
//            System.out.println("Case #"+i+":"+answer);
            out.println("Case #"+i+": "+answer);
        }
        out.close();
        

    }
}
