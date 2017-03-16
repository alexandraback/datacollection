import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by kojilin on 2014/05/11.
 */
public class PartElf {

  static long gcd(long m, long n) {
    if (n == 0) {
      return m;
    } else {
      return gcd(n, m % n);
    }
  }

  public static void main(String[] args) throws IOException {
    Path path = FileSystems.getDefault().getPath("GCJ", "pe1.txt");
    List<String> lines = Files.lines(path).collect(Collectors.toList());
    int testCases = Integer.parseInt(lines.get(0));

    for (int i = 0; i < testCases; ++i) {
      String[] s = lines.get(i + 1).split("\\/");
      long a = Long.parseLong(s[0]);
      long b = Long.parseLong(s[1]);

      System.out.println("Case #" + (i + 1) + ": " + solve(a, b));
    }
  }

  private static boolean isBPossbile(long B) {
    return Long.toBinaryString(B).chars().filter(i -> i == '1').count() == 1;
  }

  private static String solve(final long a, final long b) {
    long gcd = gcd(a, b);
    long A = a / gcd;
    long B = b / gcd;
    if (!isBPossbile(B)) {
      return "impossible";
    }
    double result = (double) A / (double) B;
    int generation = 1;
    while (result < (1 / Math.pow(2, generation))) {
      generation++;
    }

    return "" + (generation);
  }
}
