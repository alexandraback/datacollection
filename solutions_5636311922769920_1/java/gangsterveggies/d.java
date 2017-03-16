import java.util.ArrayList;
import java.util.Scanner;

public class d {
  public static void main (String[] args) {
    Scanner s = new Scanner(System.in);
    int T, t;
    T = s.nextInt();

    for (t = 1; t <= T; t++) {
      int K, C, S;
      K = s.nextInt();
      C = s.nextInt();
      C = Math.min(C, K);
      S = s.nextInt();

      ArrayList<Long> ls = new ArrayList<>();

      int mn = (int)Math.ceil(K / ((double) C));

      for (int i = 0; i < K;)
      {
        long vl = 1;
        for (int j = C - 1; j >= 0 && i < K; j--, i++)
          vl += Math.pow(K, j) * i;

        ls.add(vl);
      }

      if (ls.size() != mn)
      {
        System.out.println("ERROR on " + t);
        System.out.println(ls.size() + " " + mn);
      }
      
      if (S < mn)
        System.out.println("Case #" + t + ": IMPOSSIBLE");
      else
      {
        System.out.print("Case #" + t + ":");
        for (int i = 0; i < ls.size(); i++)
          System.out.print(" " + ls.get(i));
        System.out.println();
      }
    }
  }
}
