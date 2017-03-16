import java.util.*;

public class ihop {

  public static int splits(int x, int h) {
    int piles = x / h;
    if(x % h > 0) piles++;
    return piles - 1;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int ii=1;ii<=T;ii++) {
      int D = sc.nextInt();
      int[] P = new int[D];
      int max = -1;
      for(int i=0;i<D;i++) {
        P[i] = sc.nextInt();
        if(P[i] > max) max = P[i];
      }

      int ans = max;
      for(int i=1;i<max;i++) {
        int temp = i;
        for(int j=0;j<D;j++) {
          temp += splits(P[j], i);
        }
        if(temp < ans) ans = temp;
      }

      System.out.printf("Case #%d: %d\n", ii, ans);
    }


  }

}
