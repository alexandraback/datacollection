package gjam_0_c;

import java.math.BigInteger;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

/**
 * @author  Josef Malík (malikjo1(at)fit.cvut.cz)
 * @version 0.1
 * @since   13-Apr-2013
 */

public class GJAM_0_C {

  public static Set<BigInteger> l = new TreeSet<>();

  public static boolean isP (BigInteger bi) {
    String str = bi.toString();
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
      if (str.charAt(i) != str.charAt(len - 1 - i)) {
        return false; 
      }
    }
    return true;
  }
  
  public static void tryAdd (String s) {
    BigInteger sq = new BigInteger(s);
    sq = sq.multiply(sq);
    if (isP(sq)) {
      l.add(sq);
    }
  }
  
  public static void main(String[] args) {
    for (int i = 1; i < 10; i++) {
      tryAdd("" + i);
    }
    for (int i = 1; i < 1000000; i++) {
      String num = "" + i;
      String rnum = new StringBuffer(num).reverse().toString();
      tryAdd(num + rnum);
      for (int j = 0; j < 10; j++) {
        tryAdd(num + j + rnum); 
      }
    }
    
    Scanner sc = new Scanner(System.in);
    int cases = sc.nextInt();
    sc.nextLine();
    for (int i = 1; i <= cases; i++) {
      String [] tok = sc.nextLine().split(" ");
      
      BigInteger a, b;
      a = new BigInteger(tok[0]);
      b = new BigInteger(tok[1]);
      
      int res = 0;
      for (BigInteger bi : l) {
        if (bi.compareTo(a) < 0) {
          continue;
        }
        if (bi.compareTo(b) > 0) {
          break; 
        }
        ++res;
      }
      System.out.println("Case #" + i + ": " + res);
    }
  }

}