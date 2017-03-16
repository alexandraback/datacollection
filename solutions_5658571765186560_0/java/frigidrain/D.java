import java.io.*;
import java.util.*;

public class D
{

  // table = 1 if Gabriel wins
  static int[][][] table = new int[5][5][5];

  public static String solve(int X, int R, int C) {
    if(R * C % X != 0)
      return "RICHARD";

    if(X <= 2) {
      if(R * C % X != 0)
        return "RICHARD";
      else
        return "GABRIEL";
    }

    int tmp = Math.min(R, C);
    if(tmp == C) {
      C = R;
      R = tmp;
    }

    if(table[X][R][C] == 1)
      return "GABRIEL";
    else
      return "RICHARD";
  }
    
	public static void main(String[] args)
	{

    table[3][2][3] = 1;
    table[3][3][3] = 1;
    table[3][3][4] = 1;
    table[4][3][4] = 1;
    table[4][4][4] = 1; 

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
