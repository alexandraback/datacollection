import java.util.*;

public class C {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int t = in.nextInt();
    for (int testnum = 1; testnum <= t; ++testnum) {
      System.out.printf("Case #%d: ", testnum);
      int n = in.nextInt();
      int m = in.nextInt();
      int k = in.nextInt();
      
      int min = 0;
      int max = n*m;
      while (min < max-1) {
        int stoneguess = (min + max)/2;
        int eval = getcover(n, m, stoneguess);
        if (eval >= k)
          max = stoneguess;
        else
          min = stoneguess;
      }
      System.out.printf("%d\n", max);
    }
  }
  
  public static int getcover(int n, int m, int stones) {
    if (n > m)
      return getcover(m, n, stones);
    // n <= m
    if (n <= 2)
      return stones; // can't enclose anything extra
    if (stones >= 2*n + 2*m - 8) // can almost cover the whole grid
      return n*m - Math.max(0, (2*n + 2*m - 4 - stones));
    if (n == 3) {
      return (stones/2) - 1 + stones + (stones == 1 ? 1 : 0);
    }
    switch (stones) {
      case 0:
        return 0;
      case 1:
        return 1;
      case 2:
        return 2;
      case 3:
        return 3;
      case 4:
        return 5;
      case 5:
        return 6;
      default:
        return stones*2 - 4;
    }
  }
}