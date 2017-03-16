import java.util.*;

public class CloseMatch {
  public static void main(String []args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int i = 1; i <= T; i++) {
      int []letters = new int[26];
      String C = in.next();
      String J = in.next();
      String large = C;
      String small = J;
      char []lb = new char[C.length()];
      char []sb = new char[C.length()];
      boolean swapped = false;
      
      int j = 0;
      for (; j < C.length(); j++) {
        if (C.charAt(j) == J.charAt(j)) {
          if (C.charAt(j) == '?') {
            lb[j] = '0';
            sb[j] = '0';
          }
          else {
            lb[j] = C.charAt(j);
            sb[j] = C.charAt(j);
          }
        }
        else if (C.charAt(j) == '?') {
          lb[j] = J.charAt(j);
          sb[j] = J.charAt(j);
        }
        else if (J.charAt(j) == '?') {
          lb[j] = C.charAt(j);
          sb[j] = C.charAt(j);
        }
        else {
          if (J.charAt(j) > C.charAt(j)) {
            swapped = true;
            String s = large;
            large = small;
            small = s;
            char []b = lb;
            lb = sb;
            sb = b;
          }
          break;
        }
      }
      int jj = j;
      
      for (; j < large.length(); j++) {
        if (large.charAt(j) == '?') lb[j] = '0';
        else lb[j] = large.charAt(j);
        if (small.charAt(j) == '?') sb[j] = '9';
        else sb[j] = small.charAt(j);
      }
      
      String nl = new String(lb);
      String ns = new String(sb);
      long nat = Long.parseLong(nl) - Long.parseLong(ns);
      String nc;
      String nj;
      
      if (swapped) {
        nc = ns;
        nj = nl;
      }
      else {
        nc = nl;
        nj = ns;
      }
      
      if (jj < C.length()) {
        {
          swapped ^= true;
          String s = large;
          large = small;
          small = s;
          char []b = lb;
          lb = sb;
          sb = b;
        }
        for (; jj >= 0; jj--) {
          if (large.charAt(jj) == '?') {
            if (small.charAt(jj) == '?') {
              lb[jj] = '1';
              sb[jj] = '0';
              break;
            }
            else {
              if (small.charAt(jj) != '9') {
                lb[jj] = (char)(sb[jj] + 1);
                break;
              }
            }
          }
          else {
            if (small.charAt(jj) == '?') {
              if (large.charAt(jj) != '0') {
                sb[jj] = (char)(lb[jj] - 1);
                break;
              }
            }
          }
        }
        if (jj >= 0) {
          for (j = jj + 1; j < large.length(); j++) {
            if (large.charAt(j) == '?') lb[j] = '0';
            else lb[j] = large.charAt(j);
            if (small.charAt(j) == '?') sb[j] = '9';
            else sb[j] = small.charAt(j);
          }
          String fl = new String(lb);
          String fs = new String(sb);
          long f = Long.parseLong(fl) - Long.parseLong(fs);
          String fc;
          String fj;
          if (swapped) {
            fc = fs;
            fj = fl;
          }
          else {
            fc = fl;
            fj = fs;
          }
          
          //System.out.println(fc + " " + fj + " " + nc + " " + nj);
          if (f < nat
                || (f == nat && Long.parseLong(fc) < Long.parseLong(nc))
                || (f == nat && Long.parseLong(fc) == Long.parseLong(nc) && Long.parseLong(fj) < Long.parseLong(nj))) {
            //System.out.println("Case #" + i + ": " + fc + " " + fj);
            //continue;
            nc = null;
          }
        }
      }
      //if (nc != null)
      //System.out.println("Case #" + i + ": " + nc + " " + nj);
      
      int min = 10000;
      String ans = null;
      for (int a = 1000; a < 2000; a++)
        for (int b = 1000; b < 2000; b++) {
          String ssa = ("" + a).substring(4 - C.length());
          String ssb = ("" + b).substring(4 - C.length());
          if (match(ssa, C) && match(ssb, J)) {
            if (Math.abs(a - b) < min) {
              min = Math.abs(a - b);
              ans = ssa + " " + ssb;
            }
          }
      }
      System.out.println("Case #" + i + ": " + ans);
      
    }
  }
  
  public static boolean match(String s1, String s2) {
    for (int i = 0; i < s1.length(); i++) {
      if (s1.charAt(i) != '?' && s2.charAt(i) != '?' && s1.charAt(i) != s2.charAt(i))
        return false;
    }
    return true;
  }
}