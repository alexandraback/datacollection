import java.io.File;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class cj4 {
  public static void main(String[] args) throws Exception {
    final Scanner scanner = new Scanner(new File("D:\\unsorted\\in.txt"));
    final int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      long radius = scanner.nextLong();
      long paint = scanner.nextLong();
      long paintUsed = 0l;

      for (int ring = 1;; ring++) {
        long ringRadius = radius + (ring * 2 - 1);
        long paintForRing = ringRadius * 2 - 1;
        paintUsed = paintUsed + paintForRing;

        if (paintUsed > paint) {
          System.out.println("Case #" + t + ": " + (ring - 1));
          break;
        }
      }
    }
  }
}
