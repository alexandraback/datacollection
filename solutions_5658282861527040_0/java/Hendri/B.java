import java.util.*;

class B {

  static long A, B, K;

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int T = input.nextInt();
    for (int t = 1; t <= T; t++) {
      System.out.print("Case #" + t + ": ");
      A = input.nextLong();
      B = input.nextLong();
      K = input.nextLong();
      long sol = 0;
      for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
          long temp = (i&j);
          if (temp < K) sol++;
        }
      }
      System.out.println(sol);
    }
  }
}
