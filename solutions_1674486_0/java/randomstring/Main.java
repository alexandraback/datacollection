import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main {

  public static void main (String[] args) throws IOException {
    Writer writer = new FileWriter("output.txt");
    // Writer writer = new PrintWriter(System.out);
    Scanner scanner = new Scanner(new File("input.txt"));
    int n_cases = scanner.nextInt();
    scanner.nextLine();
    for (int i = 0; i < n_cases; ++i) {
      int n = scanner.nextInt();
      Map < Integer, Set < Integer > > inherits = new TreeMap < Integer, Set < Integer > >();
      for (int j = 0; j < n; ++j) {
        inherits.put(j, new TreeSet < Integer >());
        int m = scanner.nextInt();
        for (int k = 0; k < m; ++k) {
          inherits.get(j).add(Integer.valueOf(scanner.nextInt() - 1));
        }
      }
      Main main = new Main(writer, inherits);
      writer.write("Case #" + (i + 1) + ": " + main.solve() + "\n");
    }
    writer.close();
  }

  Writer writer;
  Map < Integer, Set < Integer > > inherits;

  public Main (Writer writer, Map < Integer, Set < Integer > > inherits) {
    this.writer = writer;
    this.inherits = inherits;
  }
  
  public String solve () {
    for (int i = 0; i < inherits.size(); ++i) {
      Set < Integer > closure_i = new TreeSet < Integer >();
      for (Integer parent : inherits.get(Integer.valueOf(i))) {
        try {
          close(parent, closure_i);
        } catch (Yes e) {
          return "Yes";
        }
      }
    }
    return "No";
  }
  
  public void close (Integer node, Set < Integer > closure) throws Yes {
    if (closure.contains(node)) {
      throw new Yes();
    }
    closure.add(node);
    for (Integer parent : inherits.get(node)) {
      close(parent, closure);
    }
  }

  public static class Yes extends Exception {
    private static final long serialVersionUID = 1L;
  }

}
