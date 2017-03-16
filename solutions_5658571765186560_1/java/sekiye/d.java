import java.util.*;

public class d {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int t = 1; t <= T; ++t) {
      int X = in.nextInt();
      int R = in.nextInt();
      int C = in.nextInt();
      System.out.println("Case #" + t + ": " + solve(X, R, C));
    }
  }
	
  static String solve(int X, int R, int C) {
    if (R > C) {
      int tmp = R;
      R = C;
      C = tmp;
    }
    if (X > 6) {
      return "RICHARD";
    }
    if (R >= X - 1 && C >= X && (R * C) % X == 0) {
      return "GABRIEL";
    } else {
      return "RICHARD";
    }
  }
}
