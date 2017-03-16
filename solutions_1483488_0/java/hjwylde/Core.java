package qualification.c;

import java.awt.Point;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Core {
  
  public static void main(String[] args) {
    int t, a, b;
    try {
      Scanner scan = new Scanner(new File(args[0]));
      
      t = scan.nextInt();
      for (int i = 1; i <= t; i++) {
        a = scan.nextInt();
        b = scan.nextInt();
        
        System.out.println(solve(i, a, b));
      }
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
  }
  
  public static String solve(int caseNumber, int a, int b) {
    a = Math.max(10, a);
    
    if ((b < 12) || (b <= a))
      return "Case #" + caseNumber + ": 0";
    
    int rev;
    String s;
    Set<Point> set = new TreeSet<Point>(new Comparator<Point>() {
      
      @Override
      public int compare(Point p1, Point p2) {
        if (p1.x != p2.x)
          return p1.x - p2.x;
        
        return p1.y - p2.y;
      }
      
    });
    for (int i = a; i <= b; i++) {
      s = String.valueOf(i);
      for (int j = 0; j < s.length(); j++) {
        rev = Integer.valueOf(s.substring(j) + s.substring(0, j));
        if ((rev > b) || (rev <= i)
            || (String.valueOf(rev).length() != s.length()))
          continue;
        
        set.add(new Point(i, rev));
      }
    }
    
    return "Case #" + caseNumber + ": " + set.size();
  }
  
  /*
   * public static String solve(int caseNumber, int a, int b) {
   * if (b < 12)
   * return "Case #" + caseNumber + ": 0";
   * 
   * a = Math.max(10, a);
   * 
   * int n = 0;
   * String s, bStr;
   * bStr = String.valueOf(b);
   * char f;
   * int check;
   * for (int i = a; i <= b; i++) {
   * s = String.valueOf(i);
   * System.out.println("STR: " + s);
   * f = s.charAt(0);
   * for (int j = 1; j < s.length(); j++) {
   * if ((s.charAt(j) < f) || (s.charAt(j) > bStr.charAt(0)))
   * continue;
   * 
   * check = 0;
   * if (s.charAt(j) == f) {
   * while (((j + check) < s.length()) && (s.charAt(j + check) == f))
   * check++;
   * if ((j + check) == s.length()) {
   * if (i == 449)
   * System.out.println(j + " : " + check + " : " + s.length());
   * continue;
   * }
   * }
   * 
   * check = 0;
   * if (Integer.valueOf("" + s.charAt(j)) <= Integer.valueOf(""
   * + bStr.charAt(0))) {
   * while (((j + check) < s.length())
   * && (Integer.valueOf("" + s.charAt(j + check)) <= Integer
   * .valueOf("" + bStr.charAt(check))))
   * check++;
   * 
   * if ((j + check) != (s.length()))
   * continue;
   * }
   * 
   * System.out.println(s + " : " + s.substring(j) + s.substring(0, j));
   * n++;
   * }
   * }
   * 
   * return "Case #" + caseNumber + ": " + n;
   * }
   */
}