import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;

public class B {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int numCases = scanner.nextInt();
    for (int i = 1; i <= numCases; ++i) {
      int n = scanner.nextInt();
      Collection<List<Integer>> lists = new ArrayList<>();
      for (int j = 0; j < 2 * n - 1; ++j) {
        List<Integer> list = new ArrayList<>();
        for (int k = 0; k < n; ++k)
          list.add(scanner.nextInt());
        lists.add(list);
      }
      System.out.printf("Case #%d: %s\n", i, getResult(lists));
    }
  }

  private static String getResult(Collection<List<Integer>> lists) {
    Collection<Integer> flattened = lists.stream()
        .flatMap(Collection::stream)
        .collect(Collectors.toList());
    Set<Integer> unique = new HashSet<>(flattened);
    List<Integer> missingHeights = new ArrayList<>();
    for (Integer height : unique) {
      long count = flattened.stream().filter(h -> h.equals(height)).count();
      if (count % 2 != 0)
        missingHeights.add(height);
    }
    Collections.sort(missingHeights);
    return String.join(" ", missingHeights.stream().map(Long::toString).collect(Collectors.toList()));
  }
}
