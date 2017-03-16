
package codejam2016;


import java.io.File;
import java.math.BigInteger;
import java.util.Scanner;


public class CoinJam {
  public static void main(String[] args) {
    try {
      CoinJam coinJam = new CoinJam();
//      coinJam.executeBatch("src/codejam2016/CoinJamExample.txt");
//      coinJam.executeBatch("src/codejam2016/C-small-attempt0.in");
      coinJam.executeBatch("src/codejam2016/C-large.in");
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
    int n = scanner.nextInt();
    int solutions = scanner.nextInt();

    System.out.printf("Case #%d:\n", testCase);

    long check = (1L << (n - 1)) + 1L;

    for (int solution = 0; solution < solutions; check += 2) {
      BigInteger[] factors = new BigInteger[11];
      int factorCount = 0;

      for (int base = 2; base <= 10; ++base) {
        long current = check;
        BigInteger value = BigInteger.ZERO;
        BigInteger position = BigInteger.ONE;
        BigInteger bigBase = BigInteger.valueOf(base);
        do {
          if ((current & 1L) != 0)
            value = value.add(position);
          current >>= 1;
          position = position.multiply(bigBase);
        } while (current != 0);

        for (int i = 3; i < 100; i += 2) {
          if (value.remainder(BigInteger.valueOf(i)).equals(BigInteger.ZERO)) {
            factors[base] = BigInteger.valueOf(i);
            ++factorCount;
            break;
          }
        }

        if (factors[base] == null)
          break;
      }

      if (factorCount != 9)
        continue;

      System.out.print(dual(check));
      for (int i = 2; i <= 10; ++i)
        System.out.print(" " + factors[i]);
      System.out.println();
      ++solution;
    }
  }

  private String dual(long value) {
    String dual = "";
    do {
      dual = (((value & 1) == 0) ? '0' : '1') + dual;
      value >>= 1;
    } while (value != 0);
    return dual;
  }
}
