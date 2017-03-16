package qualifying;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class CodejamQ4 {
  private static String baseName = "D-small-attempt1";
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
        System.out.print("Case #" + i + ": ");
        out.write("Case #" + i + ": ");
        int blocks = sc.nextInt();
        TreeSet<Double> n = new TreeSet<Double>();
        TreeSet<Double> k = new TreeSet<Double>();
        for (int j = 0; j < blocks; ++j) {
          n.add(sc.nextDouble());
        }
        for (int j = 0; j < blocks; ++j) {
          k.add(sc.nextDouble());
        }
        String result = attempt(n, k);
        out.write(result);
        out.newLine();
        System.out.println(result);
      }
      out.close();

    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private static String attempt(TreeSet<Double> n, TreeSet<Double> k) {
    String result = "";
    TreeSet<Double> n1 = new TreeSet<Double>(n);
    TreeSet<Double> k1 = new TreeSet<Double>(k);
    int score = 0;
    while (n1.size() > 0) {
      if (n1.first() < k1.first()) {
        n1.pollFirst();
        k1.pollLast();
      } else {
        n1.pollFirst();
        k1.pollFirst();
        ++score;
      }
    }
    result += String.valueOf(score) + " ";
    while (n.size() > 0 && n.first() < k.last()) {
      Double block = n.pollFirst();
      k.remove(k.ceiling(block));
    }
    result += String.valueOf(n.size());
    
    return result;
  }
 

}
