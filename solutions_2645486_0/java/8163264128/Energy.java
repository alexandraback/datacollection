import java.util.*;

public class Energy
{
  public static void main(String []args)
  {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for(int i = 1; i <= T; i++)
    {
      int E = in.nextInt();
      int R = in.nextInt();
      int N = in.nextInt();
      int []v = new int[N];
      for(int j = 0; j < v.length; j++) v[j] = in.nextInt();
      
      long []s0 = new long[E + 1];
      long []s = new long[E + 1];
      for(int j = v.length - 1; j >= 0; j--)
      {
        for(int k = 0; k < s.length; k++)
        {
          s[k] = -1;
          for(int e = 0; e <= k; e++)
          {
            int r = Math.min(E, k - e + R);
            long cur = s0[r] + e * v[j];
            if(cur > s[k]) s[k] = cur;
          }
        }
        long []tmp = s;
        s = s0;
        s0 = tmp;
      }
      System.out.println("Case #" + i + ": " + s0[E]);
    }
  }
}