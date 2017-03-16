package round1.p1;

import java.io.File;
import java.util.Scanner;

public class Main
{

  public static void main(final String[] args) throws Exception
  {
    Scanner s = new Scanner(new File("D:\\unsorted\\in"));
    int N = s.nextInt();

    for (int n = 0; n < N; n++)
    {
      int A = s.nextInt();
      int B = s.nextInt();
      double[] p = new double[A];
      for (int i = 0; i < A; i++)
        p[i] = s.nextDouble();
      double[] probMatrix = new double[A+1];
      double prob = 1.0;
      probMatrix[0] = prob;
      for (int i = 1; i < A+1; i++) {
         prob *= p[i-1];
         probMatrix[i] = prob;
      }
      double best = 2.0 + B;
      double[] backSpaces = new double[A+1];
      for (int i = 0; i < A+1; i++) {
        int index = A-i;
        int ks = B - A + i*2 + 1;
        int kf = B + ks + 1;
        double e = probMatrix[index] * ks + (1 - probMatrix[index]) * kf;
        best = Math.min(best, e);
      }
      System.out.println("Case #"+(n+1)+": "+best);
    }
  }
}