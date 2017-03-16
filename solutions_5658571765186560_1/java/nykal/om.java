import java.util.*;
import java.lang.Math;

public class om {

  //Can we win with this piece
  public static boolean tester(int r, int c, int x, int k) {
    for(int i=0;i<r;i++) {
      int temp = c*i + k;
      if(c*i + 2*x > c*r) break;
      if(temp % x == 0) return false;
    }
    return true;
  }

  public static boolean evaluate(int X, int R, int C) {
      int r = Math.max(R, C);
      int c = Math.min(R, C);
      
      if(X > Math.max(R, C) || X >= 7) return true;
      if(X == 1) return false;
      if(R*C % X != 0) return true;
      if(X == 2) return false;
      if(X <= Math.min(R,C)) return false;
      if(Math.sqrt(X) > Math.min(R, C)) return true;
      if(X == 3) return false;
      if(X == 4 && c == 2) return true;
      if(X == 4 && c >= 3) return false;
      if(X == 5 && c >= 4) return false;
      if(X == 5 && c == 3) return tester(r, c, X, 1); // try stair piece
      if(X == 6 && c >= 4) return false;

      return tester(r, c, X, 1) || tester(r, c, X, 2) || tester(r, c, X, 3);
  }


  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int ii=1;ii<=T;ii++) {
      int X = sc.nextInt();
      int R = sc.nextInt();
      int C = sc.nextInt();
      boolean win = evaluate(X, R, C); //Richard wins if true

      System.out.printf("Case #%d: ", ii);
      if(win) System.out.printf("RICHARD\n");
      else System.out.printf("GABRIEL\n");
    }


  }

}
