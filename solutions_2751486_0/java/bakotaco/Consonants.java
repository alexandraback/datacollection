package global2013.round1c;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Consonants {

  static final String INPUT_FILENAME = "A-small-attempt0.in";
  static final boolean OUTPUT_TO_FILE = true;

  private void solve(Scanner sc, PrintWriter pw) {
    String name = sc.next();
    int n = sc.nextInt();
    int len = name.length();
    int prev = - 1;
    int score = 0;
    System.err.println(name);
    for (int i = 0; i < len - n + 1; i++) {
      System.err.println(name.substring(i, i+n));
      if (name.substring(i, i+n).matches("[^aeiou]*")) {
        System.err.println("MATCHES!");
        int before = i - prev;
        int after = len - (i+n) + 1;
        System.err.println("+ " + before + " * " + after + " = " + before * after);
        score += before * after;
        prev = i;
      }
    }
    System.err.println("**** " + score);
    pw.println(score);
  }

  public static void main(String[] args) throws FileNotFoundException {
    String inputFilename = System.getProperty("user.home") + "/Downloads/" + INPUT_FILENAME;
    Scanner sc = new Scanner(new FileReader(inputFilename));
    PrintWriter pw;
    if (OUTPUT_TO_FILE) {
      pw = new PrintWriter(inputFilename.replaceFirst("\\.in$", ".out"));
    } else {
      pw = new PrintWriter(System.out);
    }
    int caseCnt = sc.nextInt();
    sc.nextLine();
    for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
      //System.err.println("Solving test case " + (caseNum + 1));
      pw.print("Case #" + (caseNum + 1) + ": ");
      new Consonants().solve(sc, pw);
    }
    pw.flush();
    pw.close();
    sc.close();
  }

}
