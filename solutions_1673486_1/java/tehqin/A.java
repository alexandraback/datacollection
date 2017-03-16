
import java.util.*;


public class A
{
   public static void main(String[] args)
   {
      new A(new Scanner(System.in));
   }

   public A(Scanner in)
   {
      int T = in.nextInt();
      for (int tc=1; tc<=T; tc++)
      {
         int A = in.nextInt();
         int B = in.nextInt();
         int nLeft = B-A;
         double[] prob = new double[A];
         double[] invp = new double[A];
         for (int i=0; i<A; i++)
         {
            prob[i] = in.nextDouble();
            invp[i] = 1-prob[i];
         }

         double res = 2+B;
         double probOfNoMistake = 1.0;
         for (int i=0; i<=A; i++)
         {
            int k = A-i;
            double probOfMistake = 1.0-probOfNoMistake;
            double left = probOfMistake*(B+2+nLeft+2*k);
            double right = probOfNoMistake*(1+nLeft+2*k);
            double exp = left+right;
            res = Math.min(res, exp);
            if (i < A)
               probOfNoMistake *= prob[i];
         }
         System.out.printf("Case #%d: %.10f%n", tc, res);

      }
   }
}
