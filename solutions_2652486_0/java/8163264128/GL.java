import java.util.*;

public class GL
{
  public static void main(String []args)
  {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for(int i = 1; i <= T; i++)
    {
      int R = in.nextInt();
      int N = in.nextInt();
      int M = in.nextInt();
      int K = in.nextInt();
      System.out.println("Case #" + i + ":");

      for(int ii = 0; ii < R; ii++)
      {
        int [][]p = new int[K][6];
        int []max = new int[6];
        for(int j = 0; j < p.length; j++)
        {
          factor(in.nextInt(), p[j]);
          if(p[j][2] > max[2]) max[2] = p[j][2];
          if(p[j][3] > max[3]) max[3] = p[j][3];
          if(p[j][5] > max[5]) max[5] = p[j][5];
        }
        for(int j = 0; j < max[3]; j++) System.out.print(3);
        for(int j = 0; j < max[5]; j++) System.out.print(5);
        int rem = N - max[3] - max[5];
        for(int j = 0; j < max[2] - rem; j++) System.out.print(4);
        for(int j = max[2] > rem? 2 * rem - max[2]: rem; j > 0; j--) System.out.print(2);
        System.out.println();
      }
    }
  }
  
  public static void factor(int i, int []a)
  {
    while(i % 2 == 0) { a[2]++; i /= 2; }
    while(i % 3 == 0) { a[3]++; i /= 3; }
    while(i % 5 == 0) { a[5]++; i /= 5; }
  }
}