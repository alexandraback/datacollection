import java.util.*;

public class DancingWithTheGooglers
{
  public static void main(String []args)
  {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for(int i = 1; i <= T; i++)
    {
      System.out.print("Case #" + i + ": ");
      int N = in.nextInt();
      int S = in.nextInt();
      int p = in.nextInt();
      int count = 0;
      for(int j = 0; j < N; j++)
      {
        int t = in.nextInt();
        if(t >= 2 * Math.max(p - 1, 0) + p) count++;
        else if(t >= 2 * Math.max(p - 2, 0) + p && S > 0) { count++; S--; }
      }
      System.out.print(count);
      if(i < T) System.out.println();
    }
  }
}