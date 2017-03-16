import java.util.*;

public class pa {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int tc = 1; tc <= T; tc++) {
      int A = in.nextInt(), B = in.nextInt();
      double[] prob = new double[A];
      for (int i = 0; i < A; i++) {
        prob[i] = in.nextDouble();
      }
      
      double right = 1;
      double best = Double.POSITIVE_INFINITY;
      for(int i = 0; i <= A; i++) {
        double curr = right * (A - i + (B - i) + 1) + (1 - right) * (A - i + B - i + B + 2);
        best = Math.min(best, curr);
        if (i < A) right *= prob[i];
      }
      best = Math.min(best, B + 2);
      System.out.printf("Case #%d: %.6f\n", tc, best);
    }
  }
}