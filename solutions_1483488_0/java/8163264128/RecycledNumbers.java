import java.util.*;

public class RecycledNumbers
{
  public static void main(String []args)
  {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for(int i = 1; i <= T; i++)
    {
      System.out.print("Case #" + i + ": ");
      int A = in.nextInt();
      int B = in.nextInt();
      int count = 0;
      int n = 0;
      int t = A;
      while(t > 0) { t /= 10; n++; }
      boolean []b = new boolean[B + 1];
      for(int j = A; j <= B; j++)
      {
        int cycle = 0;
        for(int k = 0; k < n; k++)
        {
          t = rotate(j, n, k);
          if(A > t || t > B) continue;
          if(!b[t]) { b[t] = true; cycle++; }
        }
        count += cycle * (cycle - 1) / 2;
      }
      System.out.print(count);
      if(i < T) System.out.println();
    }
  }
  
  public static int rotate(int n, int size, int r)
  {
    int p = 1;
    for(int i = 0; i < r; i++) p *= 10;
    int cp = 1;
    for(int i = 0; i < size - r; i++) cp *= 10;
    return n % p * cp + n / p;
  }
}