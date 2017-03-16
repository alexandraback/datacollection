import java.io.*;
import java.util.*;

public class B{
  static String keyboard;
  static String target;
  static int s;
  
  public static int repeats(String current, String next){
    int num = 0;
    current = current + next;
    if (current.length() >= s){
      return current.endsWith (target)?1:0;
    }
   // if (target.equals ("AAA"))
    //System.out.println (current + " "  + num);
    if (current.endsWith (target))
      num+=keyboard.length()*(s-current.length());


    for (int i = 0; i < keyboard.length();i++){
      num += repeats (current, keyboard.substring (i, i+1));
      //if (target.equals ("AAA"))
    //System.out.println (current + " "  + num);
    }
   if (target.equals ("M"))
    System.out.println (current + " "  + num);
    return num;
  }
  
  public static void main (String[] args) throws Exception{
    Scanner in = new Scanner (new FileReader("B-small-attempt1.in"));
    PrintWriter out = new PrintWriter ("B.out");
    int cases = in.nextInt();
    for (int casenum = 1; casenum <= cases; casenum++){
      int k = in.nextInt();
      int l = in.nextInt();
      s = in.nextInt();
      keyboard = in.next();
      target = in.next();
      int num = 0;
      for (int i = 0; i < keyboard.length();i++){
        num += repeats ("", keyboard.substring (i, i+1));
      }
      
      int overlaps = 0;
      for (int i = target.length() - 1; i > 0; i--){
        if (target.lastIndexOf (target.substring(0,i)) != 0){
          overlaps = i;
          break;
        }
      }

      
      int realLength = target.length()-overlaps;
      double maxbananas = Math.floor((s-target.length())/realLength) + 1;
      
      //System.out.println (maxbananas + " " + num +" " + Math.pow (k, s));
      
      if (num == 0)
        out.println ("Case #" + casenum + ": 0.0");
      else if (k > 1)
      out.println ("Case #" + casenum + ": " + (maxbananas - (double)num/Math.pow (k, s)));
      else
        out.println ("Case #" + casenum + ": 0.0");
    }
    out.close();
    in.close();
  }
}