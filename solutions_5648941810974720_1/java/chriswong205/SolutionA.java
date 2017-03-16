package _2016_round1b;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.HashMap;
import java.util.Map;


@SuppressWarnings("unused")
public class SolutionA {

  // NOTE: Download input files to TOP-LEVEL directory of project.
  // Example: "A-small-attempt0", "A-large"
  private static final String FILENAME = "A-large";

  /*
   * API for output:
   * - void sout(Object): output to console
   * - void fout(Object): output to output file
   * - void out(Object): output to console and output file
   * - void outCase(int, Object): outputs "Case #[i]: " + obj.toString()
   *
   * API for file reading:
   * - String[] getStrings(): read and parse one line of Strings from input file
   * - String getString(): read and parse one line of one String from input file
   * - int[] getInts(): read and parse one line of ints from input file
   * - int getInt(): read and parse one line of one int from input file
   * - double[] getDoubles(): read and parse one line of doubles from input file
   * - double getDouble(): read and parse one line of one double from input file
   */
  private void solveCase(int caseNumber) throws Exception {
    //"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"

    // Zero
    // tWo
    // foUr
    // siX
    // eiGht
    // One
    // Seven
    // Nine
    // fiVe
    // three
    String s = getString();
    int[] numDigit = new int[10];
    Map<Character, Integer> seenCounts = new HashMap<>();
    for(int i = 0; i < s.length(); ++i) {
      char ch = s.charAt(i);
      ch = Character.toLowerCase(ch);
      seenCounts.put(ch, seenCounts.containsKey(ch) ? seenCounts.get(ch) + 1 : 1);
    }

    int n = !seenCounts.containsKey('z') ? 0 : seenCounts.get('z');
    numDigit[0] = n;
    d(seenCounts, "zero", n);

    n = !seenCounts.containsKey('w') ? 0 : seenCounts.get('w');
    numDigit[2] = n;
    d(seenCounts, "two", n);

    n = !seenCounts.containsKey('u') ? 0 : seenCounts.get('u');
    numDigit[4] = n;
    d(seenCounts, "four", n);

    // siX
    // eiGht
    // One
    // Seven
    // Nine
    // fiVe
    // three
    n = !seenCounts.containsKey('x') ? 0 : seenCounts.get('x');
    numDigit[6] = n;
    d(seenCounts, "six", n);

    n = !seenCounts.containsKey('g') ? 0 : seenCounts.get('g');
    numDigit[8] = n;
    d(seenCounts, "eight", n);

    n = !seenCounts.containsKey('o') ? 0 : seenCounts.get('o');
    numDigit[1] = n;
    d(seenCounts, "one", n);

    // Seven
    // Nine
    // fiVe
    // three
    n = !seenCounts.containsKey('s') ? 0 :  seenCounts.get('s');
    numDigit[7] = n;
    d(seenCounts, "seven", n);

    n = !seenCounts.containsKey('n') ? 0 : seenCounts.get('n') / 2;
    numDigit[9] = n;
    d(seenCounts, "nine", n);

    n = !seenCounts.containsKey('v') ? 0 : seenCounts.get('v');
    numDigit[5] = n;
    d(seenCounts, "five", n);

    n = !seenCounts.containsKey('t') ? 0 : seenCounts.get('t');
    numDigit[3] = n;
    d(seenCounts, "three", n);

    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < numDigit[i]; ++j) {
        sb.append(i);
      }
    }

    outCase(caseNumber, sb.toString());
  }

  private void d(Map<Character, Integer> seenCounts, String s, int n) {
    if (n == 0) return;
    for (int i = 0; i < s.length(); ++i) {
      char ch = s.charAt(i);
      seenCounts.put(ch, seenCounts.get(ch) - n);
    }
  }


  /* ----- Code run from main() ----- */

  private SolutionA() {
    try {
      rd = new BufferedReader(new FileReader(FILENAME + ".in"));
      wr = new PrintWriter(new FileWriter(FILENAME + ".out"));
      numCases = getInt();
      isInitialized = true;
    } catch (Exception e) {
      sout("Error reading file:");
      e.printStackTrace();
    }
  }

  private void solveCases() {
    if (!isInitialized) {
      return;
    }

    for(int i = 1; i <= numCases; ++i) {
      try {
        solveCase(i);
      } catch (Exception e) {
        sout("Exception in Case " + i + ".");
        e.printStackTrace();
        break;
      }
    }
  }

  private void tearDown() {
    try {
      if (wr != null) {
        wr.close();
      }
    } catch (Exception e) {
      sout("Error closing writer.");
      e.printStackTrace();
    }

    try {
      if (rd != null) {
        rd.close();
      }
    } catch (Exception e) {
      sout("Error closing reader.");
      e.printStackTrace();
    }
  }

  /* ----- Utility fields ----- */

  private BufferedReader rd = null;
  private PrintWriter wr = null;
  private boolean isInitialized = false;
  private int numCases = -1;

  /* ----- Output utilities ----- */

  private void sout(Object s) {
    System.out.println(s);
  }

  private void fout(Object s) {
    if (wr == null) {
      throw new RuntimeException("Writer has not been initialized.");
    }
    wr.println(s);
  }

  private void out(Object s) {
    sout(s);
    fout(s);
  }

  private void outCase(int c, Object s) {
    String out = "Case #" + c + ": " + s.toString();
    sout(out);
    fout(out);
  }

  /* ----- Input utilities ----- */

  private String[] getStrings() throws Exception {
    if (rd == null) {
      throw new RuntimeException("Reader has not been initialized.");
    }
    return rd.readLine().split(" ");
  }

  private int[] getInts() throws Exception {
    String[] strData = getStrings();
    int length = strData.length;
    int[] arr = new int[length];
    for(int i = 0; i < length; ++i) {
      arr[i] = Integer.parseInt(strData[i], 10);
    }
    return arr;
  }

  private double[] getDoubles() throws Exception {
    String[] strData = getStrings();
    int length = strData.length;
    double[] arr = new double[length];
    for (int i = 0; i < length; ++i) {
      arr[i] = Double.parseDouble(strData[i]);
    }
    return arr;
  }

  private String getString() throws Exception {
    String[] strData = getStrings();
    if (strData.length != 1) {
      throw new RuntimeException("Misinterpreted the file in getString().");
    }
    return strData[0];
  }

  private int getInt() throws Exception {
    int[] intData = getInts();
    if (intData.length != 1) {
      throw new RuntimeException("Misinterpreted the file in getInt().");
    }
    return intData[0];
  }

  private double getDouble() throws Exception {
    double[] doubleData = getDoubles();
    if (doubleData.length != 1) {
      throw new RuntimeException("Misinterpreted the file in getDouble().");
    }
    return doubleData[0];
  }


  /* Start program via code in constructor */
  public static void main(String[] args) {
    SolutionA solution = new SolutionA();
    solution.solveCases();
    solution.tearDown();
  }
}
