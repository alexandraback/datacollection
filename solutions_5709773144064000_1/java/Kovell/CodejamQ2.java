package qualifying;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class CodejamQ2 {
  private static String baseName = "B-large";
  private static String inputFilename = baseName + ".in";
  private static String outputFilename = baseName + ".out";
  private static double baseRate = 2.0;

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
        String result = attempt(sc.nextDouble(), sc.nextDouble(), sc.nextDouble(), baseRate);
        out.write(result);
        System.out.println(result);
        out.newLine();
      }
      out.close();

    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private static String attempt(double c, double f, double x, double rate) {
    return String.valueOf(subAttempt(c, f, x, rate));
  }

  private static double subAttempt(double c, double f, double x, double rate) {
    double timeToFarm = c/rate;
    double timeToWin = x/rate;
    double timeToFarmWin = timeToFarm + x/(rate + f);
    double time = 0;
    while (timeToWin > timeToFarmWin) {
      time += timeToFarm;
      rate += f;
      timeToFarm = c/rate;
      timeToWin = x/rate;
      timeToFarmWin = timeToFarm + x/(rate + f);
    }
    return time + timeToWin;
  }

}
