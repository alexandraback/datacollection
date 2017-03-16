package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Scanner;

public class Problem4 {

  public static void main(String[] args) throws FileNotFoundException {
    Problem4 problem2 = new Problem4();
    problem2.solve();
  }

  private void solve() throws FileNotFoundException {
    String fileName = Problem1.class.getResource("/input4.txt").getPath();

    File problemFile = new File(fileName);

    Scanner scanner = new Scanner(problemFile);
    int cases = scanner.nextInt();
    scanner.nextLine();

    for (int i = 0; i < cases; i++) {
      scanner.nextLine();
      String[] naomi = scanner.nextLine().split(" ");
      Arrays.sort(naomi);
      String[] ken = scanner.nextLine().split(" ");
      Arrays.sort(ken);

      int deceit = countDeceit(naomi.clone(), ken.clone());
      int normal = countNormal(naomi.clone(), ken.clone());

      System.out.println("Case #"+(i+1) + ": " + deceit + " " + normal);
    }
  }

  private int countNormal(String[] naomi, String[] ken) {
    int normal = 0;
    for(int k = 0; k < ken.length; k++) {
      for(int n = 0; n < naomi.length; n++) {
        if(Double.parseDouble(naomi[n]) != -1 && Double.parseDouble(ken[k]) > Double.parseDouble(naomi[n])) {
          naomi[n] = "-1";
          normal++;
          break;
        }
      }
    }

    return ken.length - normal;
  }


  private int countDeceit(String[] naomi, String[] ken) {
    int deceit = 0;

    for(int n = 0; n < naomi.length; n++) {
      for(int k = 0; k < ken.length; k++) {
        if(Double.parseDouble(ken[k]) != -1 && Double.parseDouble(ken[k]) < Double.parseDouble(naomi[n])) {
          ken[k] = "-1";
          deceit++;
          break;
        }
      }
    }
    return deceit;
  }

}
