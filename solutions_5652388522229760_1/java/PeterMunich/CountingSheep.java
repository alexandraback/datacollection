
package codejam2016;


import java.io.File;
import java.util.Scanner;


public class CountingSheep {
  public static void main(String[] args) {
    try {
      CountingSheep countingSheep = new CountingSheep();
//      countingSheep.executeBatch("src/codejam2016/CountingSheepExample.txt");
//      countingSheep.executeBatch("src/codejam2016/A-small-attempt0.in");
      countingSheep.executeBatch("src/codejam2016/A-large.in");
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
    int number = scanner.nextInt();

    if (number == 0) {
      System.out.printf("Case #%d: INSOMNIA\n", testCase);
      return;
    }

    boolean[] digits = new boolean[10];
    int accounted = 0;
    int current = number;
    for (;; current += number) {
      int check = current;
      do {
        int digit = check % 10;
        if (!digits[digit]) {
          ++accounted;
          digits[digit] = true;
        }
        check /= 10;
      } while (check != 0);

      if (accounted == 10)
        break;
    }

    System.out.printf("Case #%d: %d\n", testCase, current);
  }
}
