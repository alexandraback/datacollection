import java.math.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    System.out.println("Case #1:");
    int N = sc.nextInt();
    int J = sc.nextInt();

    Set<String> used = new HashSet<String>();
    Random rnd = new Random();
    int numComposites = 0;
    while (numComposites < J) {
      StringBuilder sb = new StringBuilder();
      sb.append('1');
      for (int i = 0; i + 2 < N; i++) {
        sb.append((char) ('0' + rnd.nextInt(2)));
      }
      sb.append('1');

      String str = sb.toString();
      if (used.contains(str)) {
        continue;
      }

      used.add(str);
      boolean isPrime = false;
      for (int base = 2; base <= 10; ++base) {
        BigInteger bi = new BigInteger(str, base);
        isPrime |= bi.isProbablePrime(100);
      }

      if (isPrime) {
        continue;
      }

      boolean found_divs = true;
      List<BigInteger> divs = new ArrayList<BigInteger>();
      for (int base = 2; base <= 10; ++base) {
        boolean found_div = false;
        BigInteger bi = new BigInteger(str, base);

        BigInteger div = BigInteger.valueOf(3);
        while (div.compareTo(BigInteger.valueOf(1000)) != 1) {
          if (bi.mod(div).equals(BigInteger.ZERO)) {
            divs.add(div);
            found_div = true;
            break;
          }

          div = div.add(BigInteger.valueOf(2));
        }

        if (!found_div) {
          found_divs = false;
          break;
        }
      }

      if (!found_divs) {
        continue;
      }

      System.err.println(++numComposites);
      System.out.print(str);

      for (int i = 0; i < divs.size(); i++) {
        BigInteger div = divs.get(i);
        System.out.print(" " + div);
        BigInteger bi = new BigInteger(str, i + 2);
        System.err.printf("Base %d: %s = %s * %s\n", i + 2, bi, div, bi.divide(div));
      }

      System.out.println("");
    }
  }
}
