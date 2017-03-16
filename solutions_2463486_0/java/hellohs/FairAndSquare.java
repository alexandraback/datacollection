package codejam;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

public class FairAndSquare {
  private static String getResultString(int caseNo, int result) {
    return "Case #" + caseNo + ": " + result;
  }

  private static boolean isPalindrome(int val) {
    String x = "" + val;
    char[] c = x.toCharArray();
    for (int i = 0; i < c.length / 2; i++) {
      if (c[i] != c[c.length - i - 1]) return false;
    }
    return true;
  }

  private static boolean isSquareOfPalindrome(int val) {
    int intsqrt = (int) (Math.sqrt(val) + 0.5);
    if (intsqrt * intsqrt == val) return isPalindrome(intsqrt);
    else return false;
  }

  private static int cal(int start, int end) {
    int count = 0;
    for (int val = start; val <= end; val++) {
      if (isPalindrome(val) && isSquareOfPalindrome(val)) count++;
    }
    return count;
  }

  public static void main(String[] args) throws Exception {
    String file = "D:\\C-small-attempt0.in";
    Scanner cin = new Scanner(new File(file));
    Writer writer = new FileWriter(new File("D:\\t2-out.dat"));
    int n = Integer.parseInt(cin.nextLine());
    for (int caseNum = 1; caseNum <= n; caseNum++) {
      int start = cin.nextInt(), end = cin.nextInt();
      int result = cal(start, end);
      writer.append(getResultString(caseNum, result) + "\n");
    }
    writer.close();
    cin.close();
    System.out.println("Finished.");
  }
}
