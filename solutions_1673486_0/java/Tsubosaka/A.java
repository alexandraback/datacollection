package r1a;

import java.util.Scanner;

public class A {
  static double solve(int A , int B , double[] P){
    double minExp = B + 2;
    double correct = 1.0;
    for(int i = 0 ; i < P.length ; ++i){
      correct *= P[i];
      double move = (A - i - 1) + (B - i - 1) + 1;
      double exp = correct * (move) + (1 - correct) * (move + B + 1);
      minExp = Math.min(minExp, exp);
    }
    return minExp;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      int A = sc.nextInt();
      int B = sc.nextInt();
      double P[] = new double[A];
      for(int i = 0 ; i < P.length ; ++i){
        P[i] = sc.nextDouble();
      }
      System.out.printf("Case #%d: %f\n", cn , solve(A , B , P));
    }
  }
}