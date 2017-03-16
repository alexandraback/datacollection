import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class QC {

  public static void main(String[] args) {
    final String PREFIX = "/home/saul/IdeaProjects/CodeJam1A/src/";

    try {
      Scanner sc = new Scanner(new File(PREFIX + "C-small-1-attempt0.in"));
      PrintWriter out = new PrintWriter(new File(PREFIX + "QC.out"));
      //PrintWriter out = new PrintWriter(System.out);
      sc.nextInt();
      //for (int iCases = 0; iCases < n; iCases++) {
        int r = sc.nextInt();
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        out.println("Case #1:");
        for (int rCases = 0; rCases < r; rCases++) {
          HashSet<Integer> kSet = new HashSet<Integer>();
          for (int i = 0; i < k; i++) {
            kSet.add(sc.nextInt());
          }
          for (int tryNumber = 100; tryNumber < 1000; tryNumber++) {
            if ( isValid(tryNumber, m) ){
              HashSet<Integer> curSet = new HashSet<Integer>();
              String number = String.format("%03d",tryNumber);
              for (int iMask = 0; iMask < 1 << 3; iMask++) {
                int curProduct = 1;
                for (int i = 0; i < 3; i++) {
                  if ( (iMask & 1 << i) != 0 ){
                    curProduct *= number.charAt(i) - '0';
                  }
                }
                curSet.add(curProduct);
              }
              boolean isOk = true;
              for ( Integer kk : kSet ){
                isOk &= curSet.contains(kk);
              }
              if ( isOk ){
                out.println(tryNumber);
                break;
              }
            }
          }
        }
      //}
      out.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  private static boolean isValid(int tryNumber, int m) {
    boolean isOk = true;
    while ( tryNumber > 0 ){
      isOk &= tryNumber % 10 >= 2 && tryNumber % 10 <= m;
      tryNumber /= 10;
    }
    return isOk;
  }

}
