import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class ProblemC {

    private static long div = 0;

    private static long getNext(long n) {
        long bin = Long.valueOf(n + "", 2) + 6;
        while (Long.toBinaryString(bin).endsWith("0")) { bin += 6;}
        return Long.parseLong(Long.toBinaryString(bin));
    }
      private static boolean isPrime(long n) {
            if (n % 2 == 0) { div = 2; return false; }
            if (n % 3 == 0) { div = 3; return false; }
            long i = 5;
            while ( i*i <= n) {
                if (n % i == 0) { div = i; return false; }
                if (n % (i + 2) == 0) {
                    div = i + 2;
                    return false;
                }
                i += 6;
            }
            return true;
      }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt() + 1;
        for (int i = 1 ; i < n ; i++) {
    			   int N = in.nextInt();
             int J = in.nextInt();

             long num = (long) Math.pow(10, N-1) + 1;
             long[][] ar = new long[J][10];
             boolean flag = false;
             int count = 0;
             while (count < J) {
               flag = true;
               num = getNext(num);
               //System.out.println("next num " + num);
               ar[count][0] = num;
               for (int j = 2; flag && j < 11; j++) {
                 flag = !isPrime(Long.valueOf(num + "", j));
                 ar[count][j-1] = div;
                 //System.out.println(num + " : " + Long.valueOf(num + "", j) + " : " + !flag);
               }
               if (flag) {
                 //System.out.println(new Date());
                 //System.out.println(Arrays.toString(ar[count]));
                 count++;
               }
             }

    			   System.out.println("Case #" + i + ":");
             for (int j = 0 ; j < J ; j++) {
               String str = "";
               for (int k = 0 ; k < 10 ; k++)
                str += " " + ar[j][k];
               System.out.println(str.trim());
             }
        }
		    in.close();
    }
}
