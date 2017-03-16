package _2016_qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


@SuppressWarnings("unused")
public class SolutionD {

  // For example, "B-small". Download input/output files to TOP-LEVEL directory of project.
  private static final String FILENAME = "D-small-attempt0";

  /*
   * API for output:
   * - void sout(String): output to console
   * - void fout(String): output to output file
   * - void out(String): output to console and output file
   * - void outC(int, Object): outputs "Case #X: " + obj.toString()
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
    int[] data = getInts();
    int K = data[0];
    int C = data[1];
    int S = data[2];

    StringBuilder sb = new StringBuilder();
    for (int i = 1; i <= K; ++i) {
      sb.append(i);
      if (i != K) {
        sb.append(' ');
      }
    }

    outC(caseNumber, sb.toString());
  }


  /* Code run from main() */
  private SolutionD() {
    int numCases;
    try {
      rd = new BufferedReader(new FileReader(FILENAME + ".in"));
      wr = new PrintWriter(new FileWriter(FILENAME + ".out"));
      numCases = getInt();
    } catch (Exception e) {
      sout("Error reading file:");
      e.printStackTrace();
      return;
    }

    for(int i = 1; i <= numCases; i++) {
      try {
        solveCase(i);
      } catch (Exception e) {
        sout("Exception in Case " + i + ". Stack trace:");
        e.printStackTrace();
        break;
      }
    }

    try {
      rd.close();
      wr.close();
    } catch (Exception e) {
      sout("Error closing file:");
      e.printStackTrace();
    }
  }

  /* ----- Utility fields ----- */

  private BufferedReader rd = null;
  private PrintWriter wr = null;

  // Output helper methods
  private void sout(String s) { System.out.println(s); }
  private void fout(String s) { wr.println(s); }
  private void out(String s) { sout(s); fout(s); }
  private void outC(int c, Object s) { String out = "Case #" + c + ": " + s.toString(); sout(out); fout(out); }

  // File reading helper methods
  private String[] getStrings() throws Exception {
    return rd.readLine().split(" ");
  }
  private int[] getInts() throws Exception {
    String[] strData = getStrings();
    int[] arr = new int[strData.length];
    for(int i = 0; i < strData.length; i++) arr[i] = Integer.parseInt(strData[i], 10);
    return arr;
  }
  private double[] getDoubles() throws Exception {
    String[] strData = getStrings();
    double[] arr = new double[strData.length];
    for(int i = 0; i < strData.length; i++) arr[i] = Double.parseDouble(strData[i]);
    return arr;
  }
  private String getString() throws Exception {
    String[] strData = getStrings();
    if (strData.length != 1) throw new RuntimeException("Misinterpreting the file in getString().");
    return strData[0];
  }
  private int getInt() throws Exception {
    int[] intData = getInts();
    if (intData.length != 1) throw new RuntimeException("Misinterpreting the file in getInt().");
    return intData[0];
  }
  private double getDouble() throws Exception {
    double[] doubleData = getDoubles();
    if (doubleData.length != 1) throw new RuntimeException("Misinterpreting the file in getDouble().");
    return doubleData[0];
  }

  /* Start program via code in constructor */
  public static void main(String[] args) {
    new SolutionD();
  }
}
