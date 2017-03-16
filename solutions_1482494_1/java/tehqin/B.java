
import java.util.*;


public class B
{
   public static void main(String[] args)
   {
      new B(new Scanner(System.in));
   }

   int go(Scanner in)
   {
      int N = in.nextInt();
      int[][] vs = new int[N][2];
      for (int i=0; i<N; i++)
         for (int j=0; j<2; j++)
            vs[i][j] = in.nextInt();

      Arrays.sort(vs, new Comparator<int[]>(){
            public int compare(int[] a, int[] b)
            {
               return b[1]-a[1];
            }
         });
      int[] stars = new int[N];
      boolean changed = true;
      int nStars = 0, res = 0;
      while (changed && nStars < 2*N)
      {
         changed = false;
         for (int i=0; i<N; i++)
         {
            if (vs[i][1] <= nStars && stars[i] == 0)
            {
               res++;
               nStars += 2;
               changed = true;
               stars[i] = 2;
               break;
            }
         }
         if (changed)
            continue;
         for (int i=0; i<N; i++)
         {
            if (vs[i][1] <= nStars && stars[i] == 1)
            {
               res++;
               nStars++;
               changed = true;
               stars[i] = 2;
               break;
            }
         }
         if (changed)
            continue;
         for (int i=0; i<N; i++)
         {
            if (vs[i][0] <= nStars && stars[i] == 0)
            {
               res++;
               nStars++;
               changed = true;
               stars[i] = 1;
               break;
            }
         }
      }

      for (int i=0; i<N; i++)
         if (stars[i] != 2)
            return -1;
      return res;
   }

   public B(Scanner in)
   {
      int tc=1, T = in.nextInt();
      while (T-->0)
      {
         int rr = go(in);
         String res = "Too Bad";
         if (rr >= 0)
            res = String.format("%d", rr);
         System.out.printf("Case #%d: %s%n", tc++, res);
      }
   }
}
