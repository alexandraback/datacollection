
package codejam2016_1c;


import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class FashionPolice {
  public static void main(String[] args) {
    try {
      FashionPolice fashionPolice = new FashionPolice();
//      fashionPolice.executeBatch("src/codejam2016_1c/FashionPoliceExample.txt");
//      fashionPolice.executeBatch("src/codejam2016_1c/C-small-attempt0.in");
//      fashionPolice.executeBatch("src/codejam2016_1c/C-small-attempt1.in");
//      fashionPolice.executeBatch("src/codejam2016_1c/C-small-attempt2.in");
      fashionPolice.executeBatch("src/codejam2016_1c/C-small-attempt3.in");
//      fashionPolice.executeBatch("src/codejam2016_1c/C-large.in");
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
    int j = scanner.nextInt();
    int p = scanner.nextInt();
    int s = scanner.nextInt();
    int k = scanner.nextInt();

    List<int[]> values = new ArrayList<>();
    int v0 = 0;
    int v1 = 0;
    int v2 = 0;
    int v0n = -1;
    int v1n = -1;
    int v2n = -1;
    for (int i0 = 0; i0 < j; ++i0) {
      for (int i1 = 0; i1 < p; ++i1) {
        for (int i2 = 0; i2 < s; ++i2) {
          int f0 = (v0 + i0) % j;
          int f1 = (v1 + i1) % p;
          int f2 = (v2 + i2) % s;
//          System.out.println(f0 + ":" + f1 + ":" + f2);
          int k0 = 0;
          int k1 = 0;
          int k2 = 0;
          for (int[] value : values) {
            if ((value[0] == f0) && (value[1] == f1))
              ++k0;
            if ((value[0] == f0) && (value[2] == f2))
              ++k1;
            if ((value[1] == f1) && (value[2] == f2))
              ++k2;
            if ((k0 >= k) || (k1 >= k) || (k2 >= k))
              break;
          }
          if ((k0 < k) && (k1 < k) && (k2 < k)) {
//            System.out.println(f0 + "*" + f1 + "*" + f2);
            values.add(new int[] {f0, f1, f2});
            if (v0n == -1)
              v0n = f0;
            if (v1n == -1)
              v1n = f1;
            if (v2n == -1)
              v2n = f2;
          }
        }
        if (v2n != -1) {
          v2 = v2n;
          v2n = -1;
        }
      }
      if (v1n != -1) {
        v1 = v1n;
        v1n = -1;
      }
    }

    System.out.printf("Case #%d: %d\n", testCase, values.size());
    for (int[] value : values)
      System.out.printf(
          "%d %d %d\n", 1 + value[0], 1 + value[1], 1 + value[2]);
  }
}
