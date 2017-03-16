import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by kojilin on 2014/05/04.
 */
public class Lottery {

  public static void main(String[] args) throws IOException {
    Path path = FileSystems.getDefault().getPath("GCJ", "l1.txt");
    List<String> lines = Files.lines(path).collect(Collectors.toList());
    int testCases = Integer.parseInt(lines.get(0));

    for (int i = 0; i < testCases; ++i) {
      String[] s = lines.get(i + 1).split("\\s");
      int a = Integer.parseInt(s[0]);
      int b = Integer.parseInt(s[1]);
      int k = Integer.parseInt(s[2]);

      System.out.println("Case #" + (i + 1) + ": " + solve(a, b, k));
    }
  }

  private static String solve(final int a, final int b, final int k) {
    int count = 0;
    for (int l = 0; l < k; l++) {
      for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; j++) {
          if(l == (i & j)){
            count++;
          }
        }
      }
    }
    return count+"";
  }
}
