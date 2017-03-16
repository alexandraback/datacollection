import java.util.Scanner;

public class B {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    outer:
    for (int k = 1; k <= T; k++) {
      double C = in.nextDouble();
      double F = in.nextDouble();
      double X = in.nextDouble();
      double t = 0, rate = 2;
      if (X <= C) {
        System.out.printf("Case #%d: %f\n", k, X / 2);
        continue outer;
      }
      while (true) {
        t += C / rate;
        if ((X - C) / rate > X / (rate + F)) {
          rate += F;
        } else {
          System.out.printf("Case #%d: %f\n", k, t + (X - C) / rate);
          continue outer;
        }
      }
    }
    in.close();
  }
}
