import java.util.Scanner;

class B {
  static double C,F,X;

  static double answer(int k) {
    double sum = 0;
    for (int i = 0; i < k; i++) {
      sum += 1.0/(2 + i*F);
    }
    return C*sum + X / (2 + k*F);
  }

  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();
    for (int caseNo = 1; caseNo <= T; caseNo++) {
      C = cin.nextDouble();
      F = cin.nextDouble();
      X = cin.nextDouble();
      int k = (int)Math.ceil(X/C - 2/F - 1);
      if (k < 0) k = 0;
      /*
      for (int i = 0; i < 10; i++)
        System.out.format("%d %f\n", i, answer(i));
        */
      System.out.format("Case #%d: %.7f\n", caseNo, answer(k));
    }
  }
}
