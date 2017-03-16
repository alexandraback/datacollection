import java.math.BigInteger;
public class Lottery {

   public static void main(String[] args) {
      int T = StdIn.readInt();
      for (int t = 0; t < T; t++) {
         long a = StdIn.readLong();
         long b = StdIn.readLong();
         long k = StdIn.readLong();
         long max = Math.max(a, b);
         long min = Math.min(a, b);
         long kmin = Math.min(min, k);
         BigInteger count = BigInteger.valueOf(max).multiply((BigInteger.valueOf(kmin)));
         for (long i = kmin; i < min; i++) {
            for (long j = 0; j < max; j++) {
               long c = i & j;
               if (c < k) count = count.add(BigInteger.ONE); 
            }
         }
         System.out.println("Case #" + (t + 1) + ": " + count);
      }
      
   }

}
