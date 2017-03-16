import static java.util.stream.Collectors.*;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.stream.Stream;

public class StandingOvation {

  public static void main(String[] args) throws IOException {

    try (Stream<String> lines = Files.lines(Paths.get("CodeJam/in/A-large.in"))) {
      List<String> inputs = lines.collect(toList());
      int count = Integer.parseInt(inputs.get(0));
      for (int i = 0; i < count; i++) {
        solve(i, inputs.get(i + 1));
      }
    }
  }

  private static void solve(int num, String s) {
    String[] split = s.split("\\s");
    String aus = split[1];
    int[] result = aus.chars().map(Character::getNumericValue).toArray();

    int sum = result[0];
    int need = 0;
    for (int i = 1; i < result.length; i++) {
      int now = result[i];
      if (sum < i) {
        int plus = i - sum;
        need += plus;
        sum += plus;
      }
      sum += now;
    }
    System.out.println("Case #" + (num + 1) + ": " + need);
  }
}
