// Yen-Ming Lee <leeym@leeym.com>
// http://code.google.com/codejam/contest/dashboard?c=2437488#s=p0

import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class A
{
  public static void main(String[] args) throws Exception
  {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    sc.nextLine();
    for (int t = 1; t <= T; t++) {
      System.err.printf("Case #%d/%d\n", t, T);
      String L = sc.next();
      int N = sc.nextInt();
      sc.nextLine();
      int n = 0;
      for (int i = 0; i <= L.length(); i++) {
        for (int j = i + N; j <= L.length(); j++) {
          String l = L.substring(i, j);
          String p = "";
          for (int k = 0; k < N; k++)
            p += "[^aeiou]";
          Pattern P = Pattern.compile("(" + p + ")");
          Matcher m = P.matcher(l);
          if (m.find())
            n++;
        }
      }
      System.out.println("Case #" + t + ": " + n);
    }
    sc.close();
  }
}
