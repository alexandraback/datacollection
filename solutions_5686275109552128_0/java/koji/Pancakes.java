import static java.util.stream.Collectors.*;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

public class Pancakes {
  public static void main(String[] args) throws IOException {

    //    try (Stream<String> lines = Files.lines(Paths.get("CodeJam/in/B.in"))) {

    try (Stream<String> lines = Files.lines(Paths.get("CodeJam/in/B-small-attempt5.in"))) {
      List<String> inputs = lines.collect(toList());
      int count = Integer.parseInt(inputs.get(0));
      for (int i = 0; i < count; i++) {
        int s1 = solve3(inputs.get(i * 2 + 2));
        System.out.println("Case #" + (i + 1) + ": " + s1);
      }
    }
  }

  private static int solve3(String plates) {
    List<String> input = Arrays.asList(plates.split("\\s"));
    int[] cakeOnPlates = input
        .stream()
        .mapToInt(Integer::parseInt)
        .toArray();
    int max = input.stream().mapToInt(Integer::parseInt).max().getAsInt();
    int result = Integer.MAX_VALUE;
    for (int unit = 1; unit <= max; ++unit) {
      int count = 0;
      for (int i = 0; i < cakeOnPlates.length; ++i) {
        int divides = (cakeOnPlates[i] / unit) - (cakeOnPlates[i] % unit == 0 ? 1 : 0);
        count += divides;
      }
      count += unit;
      result = Math.min(result, count);
    }
    return result;
  }

}
