
package codejam2016;


import java.io.File;
import java.util.Scanner;


public class PancakesRevenge {
  public static void main(String[] args) {
    try {
      PancakesRevenge pancakesRevenge = new PancakesRevenge();
      //pancakesRevenge.executeBatch("src/codejam2016/PancakesRevengeExample.txt");
      //pancakesRevenge.executeBatch("src/codejam2016/B-small-attempt0.in");
      pancakesRevenge.executeBatch("src/codejam2016/B-large.in");
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
    String stack = scanner.next();
    int swaps = 0;

    for (;;) {
//      System.out.println(stack);
      int bottomOk = stack.lastIndexOf('-');
      if (bottomOk == -1)
        break;

      if (stack.charAt(0) == '-')
        stack = swap(stack, bottomOk + 1);
      else
        stack = swap(stack, stack.indexOf('-'));
      ++swaps;
    }

    System.out.printf("Case #%d: %d\n", testCase, swaps);
  }

  private String swap(String stack, int count) {
    String newStack = "";
    for (int i = 0; i < count; ++i)
      newStack += stack.charAt(count - 1 - i) == '+' ? '-' : '+';
    return newStack + stack.substring(count);
  }
}
