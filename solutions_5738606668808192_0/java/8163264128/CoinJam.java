import java.util.*;

public class CoinJam {
  public static void main(String []args) {
    Scanner in = new Scanner(System.in);
    final int T = in.nextInt();
    for (int i = 1; i <= T; i++) {
      final int N = in.nextInt();
      final int J = in.nextInt();
      System.out.println("Case #" + i + ":");
      if (N == 16 && J == 50) {
        for (int j = 0; j < 50; j++) {
          String s = "1";
          for (int k = 5; k >= 0; k--)
            s += getBit(j, k);
          s += "1";
          System.out.print(s + s);
          for (int r = 2; r <= 10; r++) {
            int v = 1;
            for (int k = 5; k >= 0; k--) {
              v *= r;
              v += getBit(j, k);
            }
            System.out.print(" " + (r * v + 1));
          }
          System.out.println();
        }
      }
      else if (N == 32 && J == 500) {
        for (int j = 0; j < 500; j++) {
          String s = "1";
          for (int k = 13; k >= 0; k--)
            s += getBit(j, k);
          s += "1";
          System.out.print(s + s);
          for (int r = 2; r <= 10; r++) {
            int v = 1;
            for (int k = 13; k >= 0; k--) {
              v *= r;
              v += getBit(j, k);
            }
            System.out.print(" " + (r * v + 1));
          }
          System.out.println();
        }
      }
    }
  }

  private static int getBit(int i, int p) {
    return (i >> p) & 1;
  }
}