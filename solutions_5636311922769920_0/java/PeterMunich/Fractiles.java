
package codejam2016;


import java.io.File;
import java.util.Scanner;


public class Fractiles {
  public static void main(String[] args) {
    try {
      Fractiles fractiles = new Fractiles();
//      fractiles.executeBatch("src/codejam2016/FractilesExample.txt");
      fractiles.executeBatch("src/codejam2016/D-small-attempt0.in");
//      fractiles.executeBatch("src/codejam2016/D-large.in");
    }
    catch (Exception exception) {
      System.out.println(exception.getMessage());
      exception.printStackTrace();
    }
  }

  private void executeBatch(String filename) throws Exception {
    Scanner scanner = new Scanner(new File(filename));
    int testCases = scanner.nextInt();
    for (int testCase = 1; testCase <= testCases; ++testCase)
      execute(testCase, scanner);
  }

  private void execute(int testCase, Scanner scanner) {
    int k = scanner.nextInt();
    int c = scanner.nextInt();
    int s = scanner.nextInt();

    if (s < (k + c - 1) / c) {
      System.out.printf("Case #%d: IMPOSSIBLE\n", testCase);
      return;
    }

    System.out.printf("Case #%d:", testCase);
    for (int i = 0; i < (k + c - 1) / c; ++i) {
//      System.out.println("i=" + i);
      long start = 0L;
      for (int j = i * c; j < i * c + c; ++j) {
        int jMax = j < k - 1 ? j : k - 1;
//        System.out.println("j=" + j + ", jMax=" + jMax);
        start = start * k + jMax;
//        System.out.println(start);
      }
      System.out.printf(" %d", start + 1);
    }
    System.out.println();

//    long start = 0L;
//    long delta = 0L;
//    for (int i = 0; i < c; ++i) {
//      start = start * k + i;
//      delta = delta * k + c;
//      System.out.println(start + ":" + delta);
//    }
//
//    System.out.printf("Case #%d:", testCase);
//    for (int i = 0; i < (k + c - 1) / c; ++i) {
//      System.out.printf(" %d", start + 1);
//      start += delta;
//    }
//    System.out.println();
  }
}
