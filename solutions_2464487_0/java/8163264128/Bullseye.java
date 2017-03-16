import java.util.*;

public class Bullseye
{
  public static void main(String []args)
  {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for(int i = 1; i <= T; i++)
    {
      long r = in.nextLong();
      long t = in.nextLong();
      System.out.print("Case #" + i + ": ");
      
      if(2 * r + 1 > t) { System.out.println(0); continue; }

      long lo = 1;
      long hi = 1000000000000000000L;
      while(lo <= hi)
      {
        long mid = (lo + hi) / 2;
        boolean qqq = p(mid, r, t);
        if(qqq) lo = mid + 1;
        else hi = mid - 1;
      }
      System.out.println(hi);
    }
  }
  
  public static boolean p(long k, long r, long t)
  {
    return (2 * r - 1 + 2 * k) <= (t / k);
  }
}