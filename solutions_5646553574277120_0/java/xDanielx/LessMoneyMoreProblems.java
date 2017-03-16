package money;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class LessMoneyMoreProblems {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int numTestCases = sc.nextInt();
    for (int testCase = 1; testCase <= numTestCases; ++testCase) {
      int maxCoins = sc.nextInt();
      int numExistingDenominations = sc.nextInt();
      long maxPrice = sc.nextInt();
      List<Long> existingDenominations = new ArrayList<>();
      for (int i = 0; i < numExistingDenominations; ++i)
        existingDenominations.add(sc.nextLong());
      Collections.sort(existingDenominations);
      System.out.printf("Case #%d: %d\n", testCase,
          getMinAddedDenominations(maxCoins, existingDenominations, maxPrice));
    }
  }

  private static int getMinAddedDenominations(int maxCoins, List<Long> denominations,
      long maxPrice) {
    int added = 0;
    if (!denominations.contains(1L)) {
      denominations.add(0, 1L);
      ++added;
    }

    for (int i = 1; i < denominations.size(); ++i) {
      long target = denominations.get(i) - 1;
      long max = maxWeCanMake(denominations.subList(0, i), maxCoins);
      if (max < target) {
        denominations.add(max + 1);
        Collections.sort(denominations);
        ++added;
      }
    }

    for (;;) {
      long max = maxWeCanMake(denominations, maxCoins);
      if (max >= maxPrice)
        return added;

      denominations.add(max + 1);
      Collections.sort(denominations);
      ++added;
    }
  }

  private static long maxWeCanMake(List<Long> denominations, int maxCoins) {
    long sum = 0;
    for (long d : denominations)
      sum += d * maxCoins;
    return sum;
  }

  private static boolean canMake(long amount, List<Long> denominations, int maxCoins) {
    if (amount == 0)
      return true;
    long highest = denominations.get(denominations.size() - 1);
    return canMake(
        highest * maxCoins > amount
            ? amount % highest
            : amount - highest * maxCoins,
        denominations.subList(0, denominations.size() - 1),
        maxCoins);
  }
}
