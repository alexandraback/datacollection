
import java.util.*;

public class B
{
   public static void main(String[] args)
   {
      new B(new Scanner(System.in));
   }

   public B(Scanner in)
   {
      int T = in.nextInt();
      for (int tc=1; tc<=T; tc++)
      {
         int N = in.nextInt();
         int[] vs = new int[N];
         int res = 0;
         for (int i=0; i<N; i++)
            res = Math.max(res, vs[i] = in.nextInt());
         for (int max=1; max<=1000; max++)
         {
            int numSpecial = 0;
            for (int i=0; i<N; i++)
               numSpecial += (vs[i]-1)/max;
            res = Math.min(res, numSpecial+max);
         }
         System.out.printf("Case #%d: %d%n", tc, res);
      }
   }
}
