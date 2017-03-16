import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class B
{
  public static void main(String[] args) throws Exception
  {
    Scanner in = new Scanner(new File("problem.in"));
    PrintStream out = new PrintStream("problem.out");

    int T = in.nextInt();

    for(int test = 1; test <= T; test++)
    {
      int e = in.nextInt();
      int r = in.nextInt();
      int n = in.nextInt();
      
      if (r > e) {
        r = e;
      }

      long[] v = new long[n];

      for(int i = 0; i < n; i++)
        v[i] = in.nextLong();

      long[][] res = new long[n][e - r + 1];
      for(int j = 0; j <= e - r; j++)
      {
        res[0][j] = (e - j) * v[0];
      }

      for(int i = 1; i < n; i++)
      {
        for(int j = 0; j <= e - r; j++)
        {
          for(int j1 = 0; j1 <= Math.min(j + r, e - r); j1++)
          {
            res[i][j1] = Math.max(res[i][j1], res[i - 1][j] + (long) (j + r - j1) * v[i]);
          }
        }
      }

      out.println("Case #" + test + ": " + res[n - 1][0]);
    }
  }
}
