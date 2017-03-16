import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {
  public static List<BigInteger> pals = new ArrayList<BigInteger>();

  public static void fairAndSquare(int n, int total, String pal) {
    if (total >= 10) return;

    if (n <= 0) {
      StringBuilder sb = new StringBuilder();
      sb = sb.append(pal).reverse();
      if (n == -1) sb = sb.deleteCharAt(0);
      sb = sb.insert(0, pal);
      pals.add(new BigInteger(sb.toString()).pow(2));
    } else {
      int k = (n == 1) ? 1 : 2;
      for (int i = 0; i < 3; i++) {
        if (total == 0 && i == 0) continue;
        String c = Character.toString((char) ('0' + i));
        fairAndSquare(n-2, total + k * i * i, pal + c);
      }
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    pals.add(new BigInteger("9"));
    for (int i = 1; i < 52; i++)
      fairAndSquare(i, 0, "");

    int T;
    T = scanner.nextInt();
    for (int k = 1; k <= T; k++) {
      BigInteger a = scanner.nextBigInteger();
      BigInteger b = scanner.nextBigInteger();
      int cnt = 0;
      for (int i = 0; i < pals.size(); i++)
        if (pals.get(i).compareTo(a) >= 0 && pals.get(i).compareTo(b) <= 0)
          cnt += 1;

      System.out.format("Case #%d: %d%n", k, cnt);
    }
  }
}
