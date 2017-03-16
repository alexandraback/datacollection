import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
import java.util.Vector;

/*
 * Google Code Jam 2013
 * Qualification Round 2013
 * raguenets@gmail.com
 * Usage : java FairAndSquare inputFileName outputFileName
 */
public class FairAndSquare {
  public static int[] SMALL_PALINDROMES = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, 212, 222, 232, 242, 252,
      262, 272, 282, 292, 303, 313, 323, 333, 343, 353, 363, 373, 383, 393, 404, 414, 424, 434, 444, 454, 464, 474, 484, 494, 505, 515, 525, 535, 545, 555, 565, 575, 585, 595, 606, 616, 626, 636,
      646, 656, 666, 676, 686, 696, 707, 717, 727, 737, 747, 757, 767, 777, 787, 797, 808, 818, 828, 838, 848, 858, 868, 878, 888, 898, 909, 919, 929, 939, 949, 959, 969, 979, 989, 999 };

  public static long[] SMALL_SQUARE_AND_FAIR;

  /**
   * @param args
   */
  public static void main(String[] args) {
    int T = 0;
    long A = 0;
    long B = 0;
    initFairAndSquare();
    if (args.length == 2) {
      String inputFilename = args[0];
      File finput = new File(inputFilename);
      String outputFilename = args[1];
      File foutput = new File(outputFilename);
      Scanner scanner = null;
      BufferedWriter bw = null;
      try {
        bw = new BufferedWriter(new FileWriter(foutput));
      }
      catch (IOException e1) {
        e1.printStackTrace();
      }
      if (finput.exists()) {
        try {
          scanner = new Scanner(finput);
          // Reads first line : number of Tests
          if (scanner.hasNextInt()) {
            T = scanner.nextInt();
          }
          for (int k = 0; k < T; k++) {
            if (scanner.hasNextLong()) {
              A = scanner.nextLong();
            }
            if (scanner.hasNextLong()) {
              B = scanner.nextLong();
            }
            String result = countFairAndSquare(A, B);
            bw.write("Case #" + (k + 1) + ": " + result + "\n");
          }
        }
        catch (FileNotFoundException e) {
          // TODO Auto-generated catch block
          e.printStackTrace();
        }
        catch (IOException e) {
          // TODO Auto-generated catch block
          e.printStackTrace();
        }
        finally {
          try {
            bw.close();
            if (scanner != null) {
              scanner.close();
            }
          }
          catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
          }
        }
      }
    }

  }

  private static boolean isPalindrome(long p) {
    String display = Long.toString(p);
    int length = display.length();
    for (int i = 0; i < length / 2; i++) {
      if (display.charAt(i) != display.charAt(length - i - 1)) { return false; }
    }
    return true;
  }

  public static Set<Long> allPalindromic(long limit) {

    Set<Long> result = new HashSet<Long>();

    for (long i = 1; i <= 9 && i <= limit; i++)
      result.add(i);

    boolean cont = true;
    for (int i = 1; cont; i++) {
      StringBuffer rev = new StringBuffer("" + i).reverse();
      cont = false;
      for (String d : "0123456789".split("")) {
        long n = Long.parseLong("" + i + d + rev);
        if (n <= limit) {
          cont = true;
          result.add(n);
        }
      }
    }

    return result;
  }

  private static void initFairAndSquare() {
    Set<Long> set = allPalindromic(100000000);
    List<Long> liste = new ArrayList<Long>(new TreeSet<Long>(set));
    Vector<Long> v = new Vector<Long>();
    for (int i = 0; i < liste.size(); i++) {
      long d = liste.get(i) * liste.get(i);
      if (isPalindrome(d)) {
        v.add(d);
        System.out.println(d);
      }
    }

    SMALL_SQUARE_AND_FAIR = new long[v.size()];
    int index = 0;
    for (Long i : v) {
      SMALL_SQUARE_AND_FAIR[index++] = i;
    }
  }

  private static String countFairAndSquare(long A, long B) {
    long count = 0;
    for (int i = 0; i < SMALL_SQUARE_AND_FAIR.length; i++) {
      if (SMALL_SQUARE_AND_FAIR[i] >= A && SMALL_SQUARE_AND_FAIR[i] <= B) {
        count++;
      }
    }
    return Long.toString(count);
  }

}
