import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class QA {

  static long sqr(long a){
    return a*a;
  }

  public static void main(String[] args) {
    final String PREFIX = "/home/saul/IdeaProjects/CodeJam1A/src/";

    try {
      Scanner sc = new Scanner(new File(PREFIX + "A-small-attempt0.in"));
      PrintWriter out = new PrintWriter(new File(PREFIX + "QA.out"));
      //PrintWriter out = new PrintWriter(System.out);
      int n = sc.nextInt();
      for (int iCases = 0; iCases < n; iCases++) {
        int ans = 0;
        long r = sc.nextLong() , t = sc.nextLong();
        long used = 0;
        long last = 1;
        while ( true ){
          used += sqr( r + last );
          used -= sqr( r + (last-1) );
          if ( used > t ){
            break;
          }
          last+=2;
          ++ans;
        }
        System.err.println("CASE " + iCases);
        out.println("Case #" + (iCases+1) + ": " + ans);
      }
      out.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

}
