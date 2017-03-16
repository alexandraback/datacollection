import java.util.Scanner;

class Password
{
  public static void main(String... args)
  {
    Scanner sc = new Scanner(System.in);
    int tests = sc.nextInt();
    for (int test = 1; test <= tests; test++)
    {
      int a = sc.nextInt();
      int b = sc.nextInt();
      double[] ps = new double[a];
      for (int i = 0; i < ps.length; i++)
      {
        ps[i] = sc.nextDouble();
      }
      System.out.println("Case #" + test + ": " + solve(a, b, ps));
    }
  }

  public static double solve(int a, int b, double[] ps)
  {
    double[] probs = new double[ps.length];
    double acc = ps[0];
    for (int i = 1; i < ps.length; i++)
    {
      probs[ps.length - i] = acc * (1 - ps[i]);
      acc *= ps[i];
    }
    probs[0] = acc;
    double sum = 0;
    int rem = (b - a) + 1;
    int len = b + 1;
    double minExpected = 1 + len;
    for (int i = 0; i < ps.length; i++)
    {
      sum += probs[i];
      double expected = sum * (rem + 2*i) + (1 - sum) * ((rem + 2*i) + len);
      minExpected = Math.min(minExpected, expected);
    }
    return minExpected;
  }
}

