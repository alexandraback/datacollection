
import java.util.*;


public class B
{
   public static void main(String[] args)
   {
      new B(new Scanner(System.in));
   }

	// Note: all values must be distinct
	int[] nextperm(int[] vals) {
   if (vals.length == 1)
      return vals;
   int i =  vals.length-1;
   while (true) {
	  int ii =  i;
	  i--;
	  if (vals[i] < vals[ii]) {
		 int j = vals.length;
		 while (vals[i] >= vals[--j]);
			int temp = vals[i];  //Swap
			vals[i] = vals[j]; 
			vals[j] = temp;
		 int begin = ii, end = vals.length-1;
		 while (end>begin) {
			   int stemp = vals[end];   //Swap
			   vals[end] = vals[begin]; 
			   vals[begin] = stemp;
			end--; begin++;
		 }   
		 return vals;
	  } else if (vals[i] == vals[0]) {
		 int begin = 0, end = vals.length-1;
		 while (end>begin) {
			   int stemp = vals[end];   //Swap
			   vals[end] = vals[begin]; 
			   vals[begin] = stemp;
			end--; begin++;
		 }   
		 return vals;
	  }
   }
	}

   int go(Scanner in)
   {
      int oo = 987654321;
      int res = oo;
      int N = in.nextInt();
      int[][] vs = new int[N][2];
      for (int i=0; i<N; i++)
         for (int j=0; j<2; j++)
            vs[i][j] = in.nextInt();
      
      int[] p = new int[N];
      for (int i=0; i<N; i++)
         p[i] = i;
      int nPerms = 1;
      for (int i=2; i<=N; i++)
         nPerms *= i;
      while (nPerms-->0)
      {
         //System.out.println(Arrays.toString(p));
         int[] stars = new int[N];
         int nStars = 0;
         boolean changed = true;
         int rr = 0;
         while (changed)
         {
            changed = false;
            for (int j=0; j<N; j++)
            {
               int i = p[j];
               if (vs[i][1] <= nStars && stars[i] < 2)
               {
                  rr++;
                  nStars += 2-stars[i];
                  stars[i] = 2;
                  changed = true;
                  break;
               }

               if (vs[i][0] <= nStars && stars[i] < 1)
               {
                  rr++;
                  nStars += 1-stars[i];
                  stars[i] = 1;
                  changed = true;
                  break;
               }
            }
         }
         boolean passed = true;
         for (int s : stars)
            if (s != 2)
               passed = false;
         if (passed)
            res = Math.min(res, rr);
         p = nextperm(p);
      }

      if (res < oo)
         return res;
      return -1;
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
