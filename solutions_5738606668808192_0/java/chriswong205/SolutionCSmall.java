package _2016_qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;


@SuppressWarnings("unused")
public class SolutionCSmall {

  // For example, "B-small". Download input/output files to TOP-LEVEL directory of project.
  private static final String FILENAME = "C-small-attempt0";

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
    out("Case #1:");

    int numJamCoins = 0;

    double max = Math.pow(2, 16);
    int start = (int)Math.pow(2, 15);
    for (int i = start; i < max; ++i) {
      if (i % 2 == 0) {
        continue;
      }
      String binaryString = Integer.toBinaryString(i);

      int[] divisors = new int[9];

      boolean isJamCoin = true;
      for (int radix = 2; radix <= 10; ++radix) {
        long n = Long.parseLong(binaryString, radix);
        if (n % 2 == 0) {
          divisors[radix - 2] = 2;
        } else if (n % 10 == 5) {
          divisors[radix - 2] = 5;
        } else if (getSumOfDigits(n) % 3 == 0) {
          divisors[radix - 2] = 3;
        } else if (n % 7 == 0) {
          divisors[radix - 2] = 7;
        } else {
          isJamCoin = false;
          break;
        }
      }

      if (isJamCoin) {
        out(getJamCoinOutputString(binaryString, divisors));
        ++numJamCoins;
        if (numJamCoins == 50) {
          break;
        }
      }
    }

    sout(numJamCoins);
    //outC(caseNumber, "");
  }

  private boolean hasEvenNumberOfOnes(String s) {
    int numOnes = 0;
    int length = s.length();
    for (int i = 0; i < length; ++i) {
      if (s.charAt(i) == '1') {
        ++numOnes;
      }
    }
    return numOnes % 2 == 0;
  }

  private int getSumOfDigits(long n) {
    int sum = 0;
    for ( ; n > 0; n /= 10) {
      sum += n % 10;
    }
    return sum;
  }

  private String getJamCoinOutputString(String jamCoin, int[] divisors) {
    StringBuilder sb = new StringBuilder(40);
    sb.append(jamCoin);
    for (int d : divisors) {
      sb.append(' ');
      sb.append(d);
    }
    return sb.toString();
  }


  /* Code run from main() */
  private SolutionCSmall() {
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
  private void sout(Object s) { System.out.println(s); }
  private void fout(Object s) { wr.println(s); }
  private void out(Object s) { sout(s); fout(s); }
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
    new SolutionCSmall();
  }
}
