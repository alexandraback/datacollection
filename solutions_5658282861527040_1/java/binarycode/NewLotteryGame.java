import java.util.*;
import java.io.*;

public class NewLotteryGame {
  private Scanner in;

  public NewLotteryGame() {
    in = new Scanner(System.in);

    int T = in.nextInt();

    for (int t = 1; t <= T; t++) {
      long A = in.nextLong();
      long B = in.nextLong();
      long K = in.nextLong();

      if (A > B) {
        long tmp = A;
        A = B;
        B = tmp;
      }

      if (K > A) {
        K = A;
      }

      long x = A * B - (A - K) * (B - K);

      for (long i = K; i < A; i++) {
        for (long j = K; j < B; j++) {
          if ((i & j) < K) {
            x++;
          }
        }
      }

      System.out.println("Case #" + t + ": " + x);
    }
  }

  public static void main(String[] args) {
    new NewLotteryGame();
  }
}
