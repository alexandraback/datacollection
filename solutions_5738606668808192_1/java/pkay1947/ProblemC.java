import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class ProblemC {

    private static BigInteger div = BigInteger.ONE;
    private static BigInteger two = new BigInteger("2");
    private static BigInteger three = new BigInteger("3");
    private static BigInteger six = new BigInteger("6");

    private static BigInteger getNext(BigInteger n) {
        BigInteger bin = new BigInteger(n.toString(), 2).add(six) ;
        while (bin.toString(2).endsWith("0")) { bin = bin.add(six);}
        return new BigInteger(bin.toString(2));
    }
      private static boolean isPrime(BigInteger n) {
            if (n.mod(two).equals(BigInteger.ZERO)) { div = two; return false; }
            if (n.mod(three).equals(BigInteger.ZERO)) { div = three; return false; }
            BigInteger i = new BigInteger("5");
            int count = 25; // max tries
            while ( i.multiply(i).compareTo(n) != 1 && count-- > 0) {
                if (n.mod(i).equals(BigInteger.ZERO)) { div = i; return false; }
                if (n.mod(i.add(two)).equals(BigInteger.ZERO)) {
                    div = i.add(two);
                    return false;
                }
                i = i.add(six);
            }
            return true;
      }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt() + 1;
        for (int i = 1 ; i < n ; i++) {
    			   int N = in.nextInt();
             int J = in.nextInt();

             String str = "1";
             while (str.length() < N - 1) str += "0";
             BigInteger num = new BigInteger(str + "1", 10);
             String[][] ar = new String[J][10];
             boolean flag = false;
             int count = 0;
             while (count < J) {
               flag = true;
               num = getNext(num);
               //System.out.println(" nextNum -> " + num);
               ar[count][0] = num.toString();
               for (int j = 2; flag && j < 11; j++) {
                 flag = !isPrime(new BigInteger(num.toString(),j));
                 ar[count][j-1] = div.toString();
                 //System.out.println(num + " : " + num.toString(j) + " : " + !flag);
               }
               if (flag) {
                 //System.out.println(new Date());
                 //System.out.println(Arrays.toString(ar[count]));
                 count++;
               }
             }

    			   System.out.println("Case #" + i + ":");
             for (int j = 0 ; j < J ; j++) {
               String str1 = "";
               for (int k = 0 ; k < 10 ; k++)
                str1 += " " + ar[j][k];
               System.out.println(str1.trim());
             }
        }
		    in.close();
    }
}
