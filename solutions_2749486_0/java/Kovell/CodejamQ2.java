
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;


public class CodejamQ2 {

  private static String inputFilename = "B-small-attempt1.in";
  private static String outputFilename = "";
  private static Map<Integer, Integer> dt = new HashMap<Integer, Integer>();
  private static ArrayList<Integer> nums;

  /**
   * Forgive me for my sins. I haven't woken up yet.
   * @param args
   */
  public static void main(String[] args) {
    Scanner sc = null, line = null;
    BufferedWriter out = null;
    outputFilename = inputFilename.substring(0, inputFilename.length() - 2)
        + "out";
    try {
      sc = new Scanner(new File(inputFilename));
      out = new BufferedWriter(new FileWriter(new File(outputFilename)));
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }
    line = new Scanner(sc.nextLine());
    int runs = line.nextInt();

    try {
      for (int i = 1; i <= runs; ++i) {
        int x = sc.nextInt();
        int y = sc.nextInt();
        out.write("Case #" + i + ": ");
        String result = attempt(x, y); 
        System.out.println("Case #" + i + ": " + result);
        out.write(result);
        out.newLine();
        if (sc.hasNextLine()) {
          sc.nextLine();
        }
      }
      out.close();

    } catch (IOException e) {
      e.printStackTrace();
    }
  }
  
  private static String attempt(int x, int y) {
    int count = 0;
    StringBuilder sb = new StringBuilder();
    while (x != 0 || y != 0) {
      System.out.println(count + ":" + x + ":" + y);
      if (count > 100) {
        System.exit(0);
      }
      if (x > 0) {
        if (x == 1 && count != 0) {
          sb.append("WE");
          x = 0;
          count += 2;
        } else if (x < count) {
          sb.append('W');
          ++count;
          x += count;
        } else {
          sb.append('E');
          ++count;
          x -= count;
        }
      } else if (x < 0) {
        if (x == -1 && count != 0) {
          sb.append("EW");
          x = 0;
          count += 2;
        } else if (x > count) {
          sb.append('E');
          ++count;
          x -= count;
        } else {
          sb.append('W');
          ++count;
          x += count;
        }
      } else if (y > 0) {
        if (y == 1 && count != 0) {
          sb.append("SN");
          y = 0;
          count += 2;
        } else if (y < count) {
          sb.append('S');
          ++count;
          y += count;
        } else {
          sb.append('N');
          ++count;
          y -= count;
        }
      } else if (y < 0) {
        if (y == -1 && count != 0) {
          sb.append("NS");
          y = 0;
          count += 2;
        } else if (y > count) {
          sb.append('N');
          ++count;
          y -= count;
        } else {
          sb.append('S');
          ++count;
          y += count;
        }
      }
    }
    return sb.toString();
  }
  
}
