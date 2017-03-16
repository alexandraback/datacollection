package gjam_1_a;

import java.math.BigDecimal;
import java.util.Scanner;

/**
 * @author  Josef Malík (malikjo1(at)fit.cvut.cz)
 * @version 0.1
 * @since   27-Apr-2013
 */

public class GJAM_1_A {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    int cases = Integer.parseInt(sc.nextLine());
    for (int i = 1; i <= cases; i++) {
      String [] tok = sc.nextLine().split(" ");
      BigDecimal r = new BigDecimal(tok[0]);
      BigDecimal t = new BigDecimal(tok[1]);
      
      BigDecimal c = new BigDecimal(0);
      BigDecimal p = r.add(r).add(BigDecimal.ONE);
      
      p.add(BigDecimal.valueOf(1));
      while (t.compareTo(BigDecimal.valueOf(0)) > 0) {
        t = t.subtract(p);
        if (t.compareTo(BigDecimal.valueOf(0)) >= 0) {
          c = c.add(BigDecimal.valueOf(1));
        }
        p = p.add(BigDecimal.valueOf(4));
      }
      System.out.println("Case #" + i + ": " + c.toString());
    }
  }

}