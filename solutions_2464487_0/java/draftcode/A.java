import java.math.BigInteger;
import java.util.*;

public class A {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for (int cs = 1; cs <= T; cs++) {
      int r = sc.nextInt();
      int t = sc.nextInt();
      int ans = 0;

      while (true) {
        int req = (r+1)*(r+1)-r*r;
        if (req > t) break;
        t -= req;
        ans++;
        r += 2;
      }
      System.out.printf("Case #%d: %d\n", cs, ans);
    }
  }
}

