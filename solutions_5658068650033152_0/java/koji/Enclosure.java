import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by kojilin on 2014/05/11.
 */
public class Enclosure {

  static long gcd(long m, long n) {
    if (n == 0) {
      return m;
    } else {
      return gcd(n, m % n);
    }
  }

  public static void main(String[] args) throws IOException {
    Path path = FileSystems.getDefault().getPath("GCJ", "enc1.txt");
    List<String> lines = Files.lines(path).collect(Collectors.toList());
    int testCases = Integer.parseInt(lines.get(0));

    for (int i = 0; i < testCases; ++i) {
      String[] s = lines.get(i + 1).split("\\s");
      long a = Long.parseLong(s[0]);
      long b = Long.parseLong(s[1]);
      long c = Long.parseLong(s[2]);

      System.out.println("Case #" + (i + 1) + ": " + solve(a, b, c));
    }
  }

  private static String solve(final long a, final long b, final long c) {
    if (a <= 2 || b <= 2 || c < 5) {
      return c + "";
    }
    long sm = Math.min(a, b);
    long lm = sm == a ? b : a;

    long result = Long.MAX_VALUE;

    for (long i = lm; i >= 3; --i) {
      for (long j = sm; j >= 3; --j) {

        long block = i * j - 4;
        if (block == c) {
          result = Math.min((i - 2) * 2 + (j - 2) * 2, result);
        }
        if (block < c) {
          block = c - block;
          result = Math.min((i - 2) * 2 + (j - 2) * 2 + block, result);
        }
      }
    }
    return result + "";
  }
}
