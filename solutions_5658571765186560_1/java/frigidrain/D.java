import java.io.*;
import java.util.*;

public class D
{

  public static String solve(int X, int R, int C) {
    if(R * C % X != 0)
      return "RICHARD";

    if(R > C) {
      int tmp = R;
      R = C;
      C = tmp;
    }

    if( X == 1 ||
        X == 2 ||
        X == 3 && R >= 2 ||
        X == 4 && R >= 3 ||
        X == 5 && R >= 3 ||
        X == 6 && R >= 4)
      return "GABRIEL";
    else
      return "RICHARD";
  }
    
	public static void main(String[] args)
	{
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    sc.nextLine();
    for(int i = 1; i <= T; i++) {
      int X = sc.nextInt();
      int R = sc.nextInt();
      int C = sc.nextInt();
      String winner = solve(X, R, C);
      System.out.format("Case #%d: %s\n", i, winner);
      sc.nextLine();
    }
	}
}
