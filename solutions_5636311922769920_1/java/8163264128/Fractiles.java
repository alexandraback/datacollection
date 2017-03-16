import java.util.*;

public class Fractiles {
  public static void main(String []args) {
    Scanner in = new Scanner(System.in);
    final int T = in.nextInt();
    for (int i = 1; i <= T; i++) {
      final int K = in.nextInt();
      final int C = in.nextInt();
      final int S = in.nextInt();
      if (K > C * S)
        System.out.println("Case #" + i + ": IMPOSSIBLE");
      else {
        System.out.print("Case #" + i + ":");
        for (int j = 0; j < (K + C - 1) / C; j++) {
          long pos = 0;
          for (int k = j * C; k < (j + 1) * C; k++) {
            pos *= K;
            if (k < K)
              pos += k;
          }
          System.out.print(" " + ++pos);
        }
        System.out.println();
      }
    }
  }
}