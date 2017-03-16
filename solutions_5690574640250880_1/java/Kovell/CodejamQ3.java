package qualifying;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class CodejamQ3 {
  private static String baseName = "C-large";
  private static String inputFilename = baseName + ".in";
  private static String outputFilename = baseName + ".out";

  /**
   * Forgive me for my sins. I haven't woken up yet.
   * 
   * @param args
   */
  public static void main(String[] args) {
    Scanner sc = null, line = null;
    BufferedWriter out = null;
    try {
      sc = new Scanner(new File(inputFilename));
      out = new BufferedWriter(new FileWriter(new File(outputFilename)));
    } catch (FileNotFoundException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    } catch (IOException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }
    line = new Scanner(sc.nextLine());
    int runs = line.nextInt();

    try {
      for (int i = 1; i <= runs; ++i) {
        System.out.println("Case #" + i + ": ");
        out.write("Case #" + i + ": ");
        out.newLine();
        String result = attempt(sc.nextInt(), sc.nextInt(), sc.nextInt());
        out.write(result);
        System.out.print(result);
      }
      out.close();

    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private static String attempt(int r, int c, int m) {
    int spaces = r * c - m;
    if (spaces == 0) {
      return "Impossible\n";
    } else if (r > 2 && c > 2) {
      if (spaces == 2
          || spaces == 3
          || spaces == 5
          || spaces == 7) {
        return "Impossible\n";
      }
    } else if ((r == 2 || c == 2) && spaces > 1 && r > 1 && c > 1) {
      if (spaces % 2 == 1
          || spaces < 3) {
        return "Impossible\n";
      }
    }
    return makeGrid(r, c, m);
    
  }
  
  private static String makeGrid(int r, int c, int m) {
    int mOrig = m;
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (m == 0) {
          if (i == r - 1 && j == c - 1) {
            sb.append("c");
          } else {
            sb.append(".");
          }
        } else {
          if (r * c == mOrig + 1 ||
              (j == 0 || sb.charAt(sb.length() - 1) == '*')
              && !(j > 0 && j >= c - 2 && c - 1 == m + j)
              && !(m % 2 == 0 && r - 3 == i && j == c - 3)
              && !(r - 2 == i && j + 1 > m)
              && (m > 1 && r - i > 2 || c - j > 2 || c == 1 || i == r - 1
              || c - j == m && sb.charAt(sb.length() - 1) == '*')) {
            sb.append("*");
            --m;
          } else {
            sb.append(".");
          }
        }
      }
      sb.append("\n");
    }
    if (m != 0) {
      System.err.println("ARGH!");
      System.exit(1);
    }
    return sb.toString();
  }

}
