import java.util.Scanner;

public class Solution
{

  private static final double INIT_RATE = 2.0;

  private double C, F, X;

  public Solution (Scanner sc)
  {
    C = sc.nextDouble();
    F = sc.nextDouble();
    X = sc.nextDouble();
  }

  public double solve ()
  {
    if (X <= C)
      return X / INIT_RATE;
    double rate = INIT_RATE;
    double time = 0.0;
    while (true)
    {
      time += C / rate;
      if (C / F * (rate + F) < X)
        rate += F;
      else
      {
        time += (X - C) / rate;
        break;
      }
    }
    return time;
  }

  public static void main (String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for (int t = 1; t <= T; ++t)
    {
      Solution sol = new Solution(sc);
      System.out.format("Case #%d: %.7f\n", t, sol.solve());
    }
    sc.close();
  }

}
