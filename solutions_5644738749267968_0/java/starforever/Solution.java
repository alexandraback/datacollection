import java.util.Scanner;
import java.util.Arrays;

public class Solution
{

  private int N;
  private double[] A;
  private double[] B;

  public Solution (Scanner sc)
  {
    N = sc.nextInt();
    A = new double[N];
    B = new double[N];
    for (int i = 0; i < N; ++i)
      A[i] = sc.nextDouble();
    for (int i = 0; i < N; ++i)
      B[i] = sc.nextDouble();
    Arrays.sort(A);
    Arrays.sort(B);
    for (int i = 0; i < N; ++i)
      System.err.format(" %.5f", A[i]);
    System.err.println();
    for (int i = 0; i < N; ++i)
      System.err.format(" %.5f", B[i]);
    System.err.println();
  }

  public int normalWin ()
  {
    int j = N - 1;
    int win = 0;
    for (int i = N - 1; i >= 0; --i)
      if (B[j] > A[i])
        --j;
      else
        ++win;
    return win;
  }

  public int deceitfulWin ()
  {
    int j = 0;
    int win = 0;
    for (int i = 0; i < N; ++i)
      if (A[i] > B[j])
      {
        ++j;
        ++win;
      }
    return win;
  }

  public static void main (String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for (int t = 1; t <= T; ++t)
    {
      Solution sol = new Solution(sc);
      System.out.format("Case #%d: %d %d\n", t, sol.deceitfulWin(), sol.normalWin());
    }
    sc.close();
  }

}
