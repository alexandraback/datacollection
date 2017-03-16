import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Problem1 {
  public static void main(String[] args) throws Exception {
    final Scanner scanner = new Scanner(new File("Google/input.txt"));
    final BufferedWriter writer = new BufferedWriter(new FileWriter("Google/output.txt"));
    final int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      final int N = scanner.nextInt();
      results.clear();
      final String result = "Case #" + t + ": " + count(N, 1);
      System.out.println(result);
      writer.write(result + '\n');
    }
    writer.close();
    scanner.close();
  }

  private static Map<Integer, Integer> results = new HashMap<>();
  private static int count(int N, int current) {
    if (current == N) {
      return 1;
    } else if (results.containsKey(current)) {
      return results.get(current);
    }
    int up = count(N, current+1) + 1;
    int reversed = reverse(current);
    if (reversed <= current || reversed > N) {
      results.put(current, up);
      return up;
    }

    int flip = count(N, reversed) + 1;
    results.put(current, Math.min(up, flip));
    return Math.min(up, flip);
  }

  private static int reverse(int n) {
    String digits = "" + n;
    String reversedDigits = "";
    for (int i = digits.length() - 1; i >= 0; i--) {
      reversedDigits += digits.substring(i, i+1);
    }
    return Integer.parseInt(reversedDigits);
  }
}
