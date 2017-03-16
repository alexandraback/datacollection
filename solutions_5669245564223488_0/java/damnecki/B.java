import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

/**
 * @author damnecki
 */
public class B {

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new File("b/data/B-small-attempt0.in"));
    PrintWriter pw = new PrintWriter("b/data/B-small-attempt0.out");
//    Scanner sc = new Scanner(new File("b/data/B-local.in"));
//    PrintWriter pw = new PrintWriter("b/data/B-local.out");
    int T = sc.nextInt();
    int N;
    List<String> cars;
    for (int i = 0; i < T; i++) {
      N = sc.nextInt();
      cars = new ArrayList<String>();
      for (int j = 0; j < N; j++) {
        cars.add(sc.next());
      }
      String result = "Case #" + (i + 1) + ": " + test(cars) + "\n";
      pw.write(result);
      System.out.print(result);
    }
    sc.close();
    pw.close();
  }

  private static String test(List<String> cars) {
    BigInteger bi = BigInteger.ONE;
    BigInteger two = new BigInteger("2");
    int groups = 0;
    for (char c = 'a'; c < 'z'; c++) {
      String cStr = String.valueOf(c);
      int same = 0;
      int start = 0;
      int end = 0;
      int enclosed = 0;
      for (String car : cars) {
        if (car.matches("^[" + cStr + "]+$")) {
          same++;
        } else if (car.startsWith(cStr) && car.endsWith(cStr)) {
          return "0";
        } else if (car.contains(cStr)) {
          char[] cArr = car.toCharArray();
          for (int i = 0; i < cArr.length; i++) {
            char cc = cArr[i];
            if (cc == c) {
              boolean encLeft = false;
              boolean encRight = false;
              for (int j = 0; j < i; j++) {
                if (cArr[j] != c) {
                  encLeft = true;
                  break;
                }
              }
              for (int j = i + 1; j < cArr.length; j++) {
                if (cArr[j] != c) {
                  encRight = true;
                  break;
                }
              }
              if (encLeft && encRight) {
                enclosed++;
              }
            }
          }
          if (car.startsWith(cStr)) {
            start++;
          } else if (car.endsWith(cStr)) {
            end++;
          }
        }
      }
      if (start > 1 || end > 1 || (enclosed > 0 && (same > 0 || start > 0 || end > 0))) {
        return "0";
      }
      if (start == 0 && end == 0 && same > 0) {
        groups++;
      }
      int cnt = 1;
      for (int i = 1; i <= same; i++) {
        cnt *= i;
      }
      bi = bi.multiply(new BigInteger(String.valueOf(cnt)));
    }
    for (int i = 0; i < groups; i++) {
      bi = bi.multiply(two);
    }
    return bi.toString();
  }
}
