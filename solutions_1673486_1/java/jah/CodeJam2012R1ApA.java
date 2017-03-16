package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CodeJam2012R1ApA {

  static final String fileIn = "/Users/jhorwitz/Documents/workspace/test/src/codejam/data/2012/R1A/A-large.in";
  static final String fileOut = "/Users/jhorwitz/Documents/workspace/test/src/codejam/data/2012/R1A/2012-1A-A-out.txt";

  public static void main(String[] args) throws Exception {
    BufferedReader r = new BufferedReader(new FileReader(fileIn));
    BufferedWriter w = new BufferedWriter(new FileWriter(fileOut));
    String line = r.readLine();
    int T = Integer.parseInt(line);
    for (int caseNum = 1; caseNum <= T; caseNum++) {
      String str = "Case #" + caseNum + ": " + solve(r);
      w.write(str + "\n");
      System.out.println(str);
    }
    w.close();
    r.close();
  }

  private static String solve(BufferedReader r) throws IOException {
    String line = r.readLine();
    String[] AB = line.split(" ");
    int A = Integer.valueOf(AB[0]);
    int B = Integer.valueOf(AB[1]);
    line = r.readLine();
    String[] pAsAString = line.split(" ");
    double[] p = new double[A];
    for (int i=0; i<A; ++i) {
      p[i] = Double.valueOf(pAsAString[i]);
    }

    double minE = 1+B+1; // "Keystrokes if I press enter right away" case ... we'll try to beat that

    for (int timesToBackspace=0; timesToBackspace<=A; ++timesToBackspace) {
      double pProd = 1;
      for (int i=0; i<=(A-1)-timesToBackspace; ++i) {
        pProd *= p[i];
      }
      double curE = (2*timesToBackspace + 1 + B-A) + (B+1)*(1-pProd); // (timesToBackspace+(B-A)+timesToBackspace+1)*pProd + (timesToBackspace+(B-A)+timesToBackspace+1+B+1)*(1-pProd);
      if (curE < minE) {
        minE = curE;
      }
    }

    return Double.toString(minE);
  }
}