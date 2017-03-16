package gcj16.qualification.d;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Fractiles {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    for(int i = 1; i <= n ; i++) {
      int k = scanner.nextInt();
      int c = scanner.nextInt();
      int s = scanner.nextInt();
      processTestCase(i, k, c, s);
    }

  }

  private static void processTestCase(int testCaseNumber, int tileSize, int complexity, int attempts) {
    if(tileSize > complexity * attempts) {
      System.out.println("Case #" + testCaseNumber + ": IMPOSSIBLE");
      return;
    }
    if(tileSize == 1) {
      System.out.println("Case #" + testCaseNumber + ": 1");
      return;
    }
    System.out.print("Case #" + testCaseNumber + ":");
    Integer serialNumber = 0;
    for(int a = 0; a < (tileSize+complexity-1)/complexity ; a++) {
      List<Integer> seq = new ArrayList<>();
      for(int b = 0; b < complexity; b++) {
        seq.add(serialNumber);
        serialNumber = (serialNumber + 1) % tileSize;
      }
      System.out.print(" " + (parse(seq, tileSize) + 1));
    }
    System.out.println();
  }

  public static long parse(List<Integer> digits, int radix) {
    long result = 0;
    long multiplier = 1;
    for(int i = digits.size() - 1; i >= 0; i-- ) {
      result += digits.get(i) * multiplier;
      multiplier *= radix;
    }
    return result;
  }
}
