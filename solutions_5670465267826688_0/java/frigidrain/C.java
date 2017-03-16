import java.io.*;
import java.util.*;

public class C
{
  static final int I = 2;
  static final int J = 3;
  static final int K = 4;
  static int[][] table;
  long curj, curk;

  String s;
  int reps;
  long len; 

  public C(String s, int reps) {
    this.s = s;
    this.reps = reps;
    this.len = s.length() * (long)reps;
  }

  public int getc(long i) {
    char c = s.charAt((int)(i % s.length()));
    return c - 'i' + 2;
  }

  public static int getc(String s, int i) {
    return s.charAt(i) - 'i' + 2;
  }

  public static int op(int a, int b) {
    int res = table[Math.abs(a)][Math.abs(b)];
    //System.out.format("%d %d %d\n", a, b, res);
    if(a * b < 0)
      return -res;
    else
      return res;
  }

  public static int eval(String s) {
    int res = 1;
    for(int i = 0; i < s.length(); i++) {
      res = op(res, getc(s, i));
    }
    return res;
  }

  public boolean solve(long start, int target) {
    int res = 1;
    long p = start;

    while(p < len) {
      res = op(res, getc(p));
      if(target == I && res == I) {
        curj = p + 1;
        // System.out.format("I found ending at %d\n", p);
        //if(solve(p + 1, J)) return true;
        return solve(p + 1, J);
      } else if(target == J && res == J) {
        // System.out.format("J found ending at %d\n", p);
        curk = p + 1;
        // if(solve(p + 1, K)) return true; 
        return solve(p + 1, K);
      }
      p++;
    }

    if(target == K && res == K) {
      // System.out.format("%d %d\n", curj, curk);
      return true;
    } else
      return false;
  }

	public static void main(String[] args)
  {  
    int[][] init = {
      {0, 0, 0, 0, 0},
      {0, 1, I, J, K},
      {0, I, -1, K, -J},
      {0, J, -K, -1, I},
      {0, K, J, -I, -1}
    };
    table = init;

    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    sc.nextLine();
    for(int t = 1; t <= T; t++) {
      int L = sc.nextInt();
      int X = sc.nextInt();
      sc.nextLine();
      String s = sc.nextLine();
      C problem = new C(s, X);
      //System.out.format("%s = %d\n", s, eval(s));
      System.out.format("Case #%d: %s\n", t, problem.solve(0, I) ? "YES" : "NO");
    }
    sc.close();
	}
}
