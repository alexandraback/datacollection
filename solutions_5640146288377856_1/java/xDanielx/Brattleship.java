package brattleship;

import java.util.Scanner;

public class Brattleship {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int numTestCases = sc.nextInt();
    for (int testCase = 1; testCase <= numTestCases; ++testCase) {
      int rows = sc.nextInt(), cols = sc.nextInt(), shipWidth = sc.nextInt();
      System.out.printf("Case #%d: %d\n", testCase, getTurnsRequired(rows, cols, shipWidth));
    }
  }

  private static int getTurnsRequired(int rows, int cols, int shipWidth) {
    return (rows - 1) * getTurnsRequiredToEliminateRow(cols, shipWidth)
        + getTurnsRequiredForLastRow(cols, shipWidth);
  }

  private static int getTurnsRequiredToEliminateRow(int cols, int shipWidth) {
    int turns = 0;
    while (cols >= shipWidth) {
      cols -= shipWidth;
      ++turns;
    }
    return turns;
  }

  private static int getTurnsRequiredForLastRow(int cols, int shipWidth) {
    int turns = getTurnsRequiredToEliminateRow(cols, shipWidth);
    if (cols % shipWidth == 0)
      turns += shipWidth - 1;
    else
      turns += shipWidth;
    return turns;
  }
}
