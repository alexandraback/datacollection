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
      double t = 0, cookie = 0, rate = 2;
      if (X <= C) {
        System.out.printf("Case #%d: %f\n", k, X / 2);
        continue outer;
      }
      while (cookie < X) {
        if (cookie < C) {
          t += (C - cookie) / rate;
          cookie = C;
        }
        if ((X - C) / rate > X / (rate + F)) {
          //System.out.println("buy! " + cookie + " " + t);
          cookie -= C;
          rate += F;
        } else {
          System.out.printf("Case #%d: %f\n", k, t + (X - cookie) / rate);
          continue outer;
        }
      }
      //System.out.printf("Case #%d: %f\n", k, t);
    }
    in.close();
  }
}
