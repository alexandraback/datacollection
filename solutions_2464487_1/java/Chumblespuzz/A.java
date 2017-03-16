package round.one.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class A
{

   public static void main(String[] args) throws FileNotFoundException
   {
      System.setOut(new PrintStream(new File("small.out")));
      Scanner scan = new Scanner(new File("small.in"));

      
      int numCases = scan.nextInt();
      for (int z = 1; z <= numCases; z++)
      {
         BigInteger two = new  BigInteger("2");
         
         BigInteger r = new BigInteger(scan.next());
         BigInteger t = new BigInteger(scan.next());
         
         BigInteger count = BigInteger.ZERO;
         BigInteger lo = BigInteger.ZERO, hi = new BigInteger("707106780");
         while (lo.compareTo(hi) <= 0)
         {
            BigInteger mid = hi.add(lo).divide(two);

            BigInteger total = mid.multiply(mid.subtract(BigInteger.ONE)).multiply(two)
                  .add(two.multiply(r).multiply(mid)).add(mid);
            
            if (total.compareTo(t) <= 0)
            {
               count = count.compareTo(mid) > 0 ? count : mid;
               lo = mid.add(BigInteger.ONE);
            }
            else
            {
               hi = mid.subtract(BigInteger.ONE);
            }
            
         }
//         while (t > 0)
//         {
//            t -= 4L * count + 2L * r + 1L;
//            if (t >= 0)
//            {
//               count++;
//            }
//         }
//         
         System.out.println("Case #" + z + ": " + count);
      }
      
      scan.close();
   }

}

