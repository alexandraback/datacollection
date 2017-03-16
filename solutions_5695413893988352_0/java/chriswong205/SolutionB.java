package _2016_round1b;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


@SuppressWarnings("unused")
public class SolutionB {

  // NOTE: Download input files to TOP-LEVEL directory of project.
  // Example: "A-small-attempt0", "A-large"
  private static final String FILENAME = "B-small-attempt1";

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
    String[] data = getStrings();
    String c = data[0];
    String j = data[1];

    int index = getFirstNeqIndex(c, j);
    if (index == -1) {
      String s = outputEasy(c, j);
      outCase(caseNumber, s + " " + s);
      return;
    }

    if (caseNumber == 13) {
      System.out.println("OOH");
    }

    String[] nums1 = new String[2];
    boolean success1 = cGreaterThanJ(c, j, index, nums1);
    String[] nums2 = new String[2];
    boolean success2 = cGreaterThanJ(j, c, index, nums2);
    String c2 = nums2[1];
    String j2 = nums2[0];
    nums2[0] = c2;
    nums2[1] = j2;

    if (!success1) {
      outCase(caseNumber, nums2[0] + " " + nums2[1]);
    } else if (!success2) {
      outCase(caseNumber, nums1[0] + " " + nums1[1]);
    } else {
      int diff1 = Math.abs(Integer.parseInt(nums1[0]) - Integer.parseInt(nums1[1]));
      int diff2 = Math.abs(Integer.parseInt(nums2[0]) - Integer.parseInt(nums2[1]));
      if (diff1 < diff2) {
        outCase(caseNumber, nums1[0] + " " + nums1[1]);

      } else if (diff2 < diff1) {
        outCase(caseNumber, nums2[0] + " " + nums2[1]);
      } else {
        if (Integer.parseInt(nums2[1]) < Integer.parseInt(nums1[1])) {
          outCase(caseNumber, nums2[0] + " " + nums2[1]);

        } else {
          outCase(caseNumber, nums1[0] + " " + nums1[1]);

        }
      }
    }

    //outCase(caseNumber, "");
  }

  private int getFirstNeqIndex(String c, String j) {
    for (int i = 0; i < c.length(); ++i) {
      char ci = c.charAt(i);
      char ji = j.charAt(i);
      if (ci != '?' && ji != '?' && ci != ji) {
        return i;
      }
    }
    return -1;
  }

  private boolean cGreaterThanJ(String c, String j, int index, String[] nums) {
    char n1 = c.charAt(index);
    char n2 = j.charAt(index);
    StringBuilder cb = new StringBuilder();
    StringBuilder jb = new StringBuilder();
    if (n1 > n2) {
      for (int i = 0; i < index; ++i) {
        if (c.charAt(i) == '?' && j.charAt(i) == '?') {
          cb.append('0');
          jb.append('0');
        } else if (c.charAt(i) == '?') {
          cb.append(j.charAt(i));
          jb.append(j.charAt(i));
        } else {
          cb.append(c.charAt(i));
          jb.append(c.charAt(i));
        }
      }
      cb.append(n1);
      jb.append(n2);
      for (int i = index + 1; i < c.length(); ++i) {
        if (c.charAt(i) == '?') {
          cb.append('0');
        } else {
          cb.append(c.charAt(i));
        }
        if (j.charAt(i) == '?') {
          jb.append('9');
        } else {
          jb.append(j.charAt(i));
        }
      }
      nums[0] = cb.toString();
      nums[1] = jb.toString();
      return true;
    } else {
      if (index == 0) {
        return false;
      }
      int firstIndex = -1;
      for (int i = index - 1; i >= 0; --i) {
        if (j.charAt(i) != '9') {
          firstIndex = i;
          break;
        }
      }
      if (firstIndex == -1) return false;
      for (int i = 0; i < index; ++i) {
        if (i < firstIndex) {
          if (c.charAt(i) == '?' && j.charAt(i) == '?') {
            cb.append('0');
            jb.append('0');
          } else if (c.charAt(i) == '?') {
            cb.append(j.charAt(i));
            jb.append(j.charAt(i));
          } else {
            cb.append(c.charAt(i));
            jb.append(c.charAt(i));
          }
        } else if (i == firstIndex) {
          char ji = j.charAt(i);
          if (ji == '?') {
            cb.append('1');
            jb.append('0');
          } else {
            cb.append(ji + 1);
            jb.append(ji);
          }
        } else {
          cb.append('0');
          jb.append('9');
        }
      }

      cb.append(n1);
      jb.append(n2);
      for (int i = index + 1; i < c.length(); ++i) {
        if (c.charAt(i) == '?') {
          cb.append('0');
        } else {
          cb.append(c.charAt(i));
        }
        if (j.charAt(i) == '?') {
          jb.append('9');
        } else {
          jb.append(j.charAt(i));
        }
      }
      nums[0] = cb.toString();
      nums[1] =jb.toString();
      return true;
    }
  }

  private String outputEasy(String c, String j) {
    StringBuilder sb = new StringBuilder(c.length());
    for (int i = 0; i < c.length(); ++i) {
      if (c.charAt(i) == '?' && j.charAt(i) == '?') {
        sb.append('0');
      } else if (c.charAt(i) == '?') {
        sb.append(j.charAt(i));
      } else {
        sb.append(c.charAt(i));
      }
    }
    return sb.toString();
  }


  /* ----- Code run from main() ----- */

  private SolutionB() {
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
    SolutionB solution = new SolutionB();
    solution.solveCases();
    solution.tearDown();
  }
}
