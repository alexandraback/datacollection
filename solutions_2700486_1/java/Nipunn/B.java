import java.util.*;
import java.io.*;
import java.math.*;

public class B {
   static Scanner sc;

   public static void go() {
      int N = sc.nextInt();
      int X = sc.nextInt();
      int Y = sc.nextInt();
      int XPY = Math.abs(X) + Y;

      int k; // num layers definitely falling
      for (k=1; 4*k - 3 <= N; k++)
         N -= 4*k - 3;
      k--;
      //System.out.format("k=%d\n", k);

      if (XPY <= 2*(k-1)) {
         // definitely falling
         System.out.println("1.0");
         return;
      } else if (XPY > 2*k) {
         // on a layer not falling
         System.out.println("0.0");
         return;
      } else if (Y == 2*k) {
         // on the top of the partial layer
         System.out.println("0.0");
         return;
      }

      assert(XPY == 2*k);

      int NMAX = 4*(k+1) - 3;
      int numLeft = Y + 1;

      // at least numLeft have to fall left out of N
      //System.out.format("%d out of %d. On layer %d which has %d\n", numLeft, N,
            //k+1, NMAX);
      BigDecimal totprob = BigDecimal.ONE;
      // calc prob you DON'T make it
      for (int nl=0; nl < numLeft; nl++) {
         BigDecimal prob = getProb(N, nl, k);
         totprob = totprob.subtract(prob);
      }

      System.out.println(totprob.toPlainString());
   }

   public static BigDecimal getProb(int N, int nl, int k) {
      int nr = N - nl;
      //System.out.format("getProb(%d %d %d) called\n", N, nl, k);
      int h = 2*k;

      if (nl > h || nr > h) {
         return BigDecimal.ZERO; // impossible!
      } else if (nl == h && nr == h) {
         return BigDecimal.ONE;
      } else if (nl == h || nr == h) {
         nl = Math.min(nl, nr);
         nr = N - nl;

         BigDecimal half = new BigDecimal(0.5);
         if (nl == 0)
            return half.pow(nr);

         BigDecimal sum = BigDecimal.ZERO;
         for (int kk = nr-1; kk<N; kk++) {
            BigDecimal pp = getProb(kk, nr-1, k);
            //System.out.println("yo: " +pp.multiply(half));
            sum = sum.add(pp.multiply(half));
         }

         //System.out.format("getProb(%d %d %d) return %s\n", N, nl, k,
               //sum.toString());
         return sum;
      }

      BigInteger comb = BigInteger.ONE;
      // (N choose nl)
      for (int q=0; q<nl; q++) {
         comb = comb.multiply(BigInteger.valueOf(N-q))
            .divide(BigInteger.valueOf(q+1));
      }

      BigDecimal p = (new BigDecimal(comb)).multiply(
            (new BigDecimal(0.5)).pow(N));
      //System.out.format("getProb_comb(%d %d %d) return %s\n", N, nl, k,
            //p.toString());
      return p;
   }

   public static void main(String[] args) {
      sc = new Scanner(System.in);
      int T = sc.nextInt();
      for (int i=1; i<=T; i++) {
         System.out.format("Case #%d: ", i);
         go();
      }
   }
}
