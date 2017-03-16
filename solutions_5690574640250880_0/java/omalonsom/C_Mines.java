package gcj2014;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class C_Mines {
  public static void main2(String[] args) throws Exception {

    for (int n = 0; n < 16; ++n) {
      print(generate(4, 4, n));
      System.out.println();
    }
    // print(generate(10, 10, 82));

  }

  public static void main(String[] args) throws Exception {

     Scanner in = new Scanner(new File("/Users/omalonsom/Tmp/C-small-attempt0.in"));
    //Scanner in = new Scanner(new File("/Users/omalonsom/Tmp/C-test.txt"));
     System.setOut(new PrintStream("/Users/omalonsom/Tmp/C-small.out"));

    int T = in.nextInt();
    for (int t = 1; t <= T; ++t) {

      System.out.printf("Case #%s:\n", t);
      solve(in.nextInt(), in.nextInt(), in.nextInt());

    }
  }

  private static void solve(int R, int C, int M) {
    print(generate(R, C, M));
  }

  static char[][] generate(int R, int C, int M) {
    char[][] A = new char[R][C];
    for (int r = 0; r < R; ++r)
      for (int c = 0; c < C; ++c)
        A[r][c] = '.';

    int m = 0;
    for (int r = 0; r < R - 2; ++r)
      for (int c = 0; c < C - 2 && m < M && m < (C - 2) * (R - 2) - 1; ++c) {
        A[r][c] = '*';
        m++;
      }

    for (int r = 0; r < R - 3 && m < M - 1 && C > 1; ++r) {
      A[r][C - 2] = A[r][C - 1] = '*';
      m += 2;
    }

    for (int c = 0; c < C - 3 && m < M - 1 && R > 1; ++c) {
      A[R - 2][c] = A[R - 1][c] = '*';
      m += 2;
    }

    boolean top = R < 3, left = C < 3, corner = top || left;

    if (!top && !left && M > m) {
      A[R - 3][C - 3] = '*';
      ++m;
      corner = true;
    }

    if (corner && !left && M - m >= 2 && R > 1 && C > 1) {
      A[R - 2][C - 3] = A[R - 1][C - 3] = '*';
      m += 2;
      left = true;
    }

    if (corner && !top && M - m >= 2 && R > 1 && C > 1) {
      A[R - 3][C - 2] = A[R - 3][C - 1] = '*';
      m += 2;
      top = true;
    }

    if (R > 1 && C > 1 && M - m == 3 && left && top && corner && R > 1 && C > 1) {
      A[R - 2][C - 2] = A[R - 1][C - 2] = A[R - 2][C - 1] = '*';
      m += 3;
    }

    if (R == 1) for (int c = 0; c < M; ++c) {
      A[0][c] = '*';
      m++;
    }
    if (C == 1) for (int r = 0; r < M; ++r) {
      A[r][0] = '*';
      m++;
    }

    if (M != m) return null;

    A[R - 1][C - 1] = 'c';
    return A;
  }

  static void print(char[][] A) {
    if (A == null) System.out.println("Impossible");
    else for (int r = 0; r < A.length; ++r)
      System.out.println(new String(A[r]));
  }
}
