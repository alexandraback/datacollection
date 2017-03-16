
import java.util.*;

public class A
{
   public static void main(String[] args)
   {
      new A(new Scanner(System.in));
   }

   int[] convert(String s)
   {
      int[] res = new int[s.length()];
      int ptr = 0;
      for (char c : s.toCharArray())
         res[ptr++] = c-'0';
      return res;
   }

   public A(Scanner in)
   {
      int T = in.nextInt();
      for (int tc=1; tc<=T; tc++)
      {
         int N = in.nextInt();
         int[] vs = convert(in.next());
         int res = 0, count = 0;
         for (int i=0; i<=N; i++)
         {
            if (vs[i] > 0 && count < i)
            {
               res += (i-count);
               count = i;
            }
            count += vs[i];
         }
         System.out.printf("Case #%d: %d%n", tc, res);
      }
   }
}
