package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Problem2 {

  public static void main(String[] args) throws FileNotFoundException {
    Problem2 problem2 = new Problem2();
    problem2.solve();
  }

  private void solve() throws FileNotFoundException {
    String fileName = Problem1.class.getResource("/input2.txt").getPath();

    File problemFile = new File(fileName);

    Scanner scanner = new Scanner(problemFile);
    int cases = scanner.nextInt();

    for (int i = 0; i < cases; i++) {
      double c = scanner.nextDouble();
      double f = scanner.nextDouble();
      double x = scanner.nextDouble();

      double currF = 0;
      double tToEnd = x / (currF + 2.0);
      double currX = x < c ? x : c;
      double t = c > x ? tToEnd : c / (currF + 2.0);
      while (true) {
        double remIfNotBuy = (x - currX) / (currF+2.0);
        double remIfBuy = (x - (currX - c)) / (f + currF + 2.0);

        if( remIfBuy < remIfNotBuy) {
          currX -= c;
          currF += f;
        }

        if( (x - currX) / (currF + 2.0) < c / (currF + 2.0)) {
          t += (x - currX) / (currF + 2.0);
          currX = x;
        }

        if(currX >= x) {
          break;
        }

        double nextT = c / (currF + 2.0) > (x - currX) / (currF + 2.0) ? (x - currX) / (currF + 2.0) : c / (currF + 2.0);

        currX += nextT * (currF + 2);
        t += nextT;
      }

      DecimalFormat df = new DecimalFormat("0.000000");
      System.out.println("Case #"+(i+1) + ": " + df.format(t));
    }
  }

}
