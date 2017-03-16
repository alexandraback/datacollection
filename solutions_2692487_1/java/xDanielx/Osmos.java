import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Osmos {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for (int t = 1; t <= T; ++t) {
      int initialSize = sc.nextInt(), n = sc.nextInt();
      List<Integer> motes = new ArrayList<Integer>(n);
      for (int i = 0; i < n; ++i)
        motes.add(sc.nextInt());
      Collections.sort(motes);
      System.out.printf("Case #%d: %d\n", t, minOperations(motes, initialSize));
    }
  }

  private static int minOperations(List<Integer> motes, int initialSize) {
    int min = Integer.MAX_VALUE;
    for (int numRemovals = 0; numRemovals <= motes.size(); ++numRemovals) {
      Integer operations = numOperations(motes, initialSize, numRemovals);
      if (operations != null)
        min = Math.min(min, operations);
    }
    return min;
  }

  private static Integer numOperations(List<Integer> motes, int size, int numRemovals) {
    int count = numRemovals;
    for (int mote : motes.subList(0, motes.size() - numRemovals)) {
      while (mote >= size) {
        if (size <= 1) return null;
        size += size - 1;
        ++count;
      }
      size += mote;
    }
    return count;
  }
}
