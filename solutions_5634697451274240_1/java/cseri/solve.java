// Compile with: javac solve.java

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

class Solve
{

  static int solve(String line)
  {
    int sol = 0;
    int n = line.length();

    for (int i = 1; i < n; ++i) {
      if (line.charAt(i) != line.charAt(i - 1)) {
        // invert(line, i);
        ++sol;
      }
    }
    return sol;
  }


  public static void main(String[] args) throws IOException {
    Scanner s = new Scanner(new File("input.txt"));

    String tn_str = s.nextLine();
    int tn = Integer.parseInt(tn_str);

    for (int ti = 0; ti < tn; ti++) {
      String line = s.nextLine() + "+";

      int sol = solve(line);

      System.out.println("Case #" + (ti + 1) + ": " + sol);
    }
  }

}
