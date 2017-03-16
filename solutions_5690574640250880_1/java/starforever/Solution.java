import java.util.Scanner;

public class Solution
{

  private int R, C, M, S;
  private char[][] board;

  public Solution (Scanner sc)
  {
    R = sc.nextInt();
    C = sc.nextInt();
    M = sc.nextInt();
    S = R * C - M;
    board = new char[R][C];
  }

  public void solve ()
  {
    if (paint())
      print();
    else
      System.out.println("Impossible");
  }

  private boolean paint ()
  {
    if (R == 1)
    {
      paintRect(1, S);
      return true;
    }
    if (C == 1)
    {
      paintRect(S, 1);
      return true;
    }
    if (S == 1)
    {
      paintRect(1, 1);
      return true;
    }
    for (int r = 2; r <= R && r * 2 <= S; ++r)
    {
      int c = Math.min((S - r * 2) / 2 + 2, C);
      if (S - (r * 2 + (c - 2) * 2) <= (r - 2) * (c - 2))
      {
        paint(r, c);
        return true;
      }
    }
    return false;
  }

  private void paintRect (int r, int c)
  {
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        board[i][j] = '*';
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        board[i][j] = '.';
    board[0][0] = 'c';
  }

  private void paint (int r, int c)
  {
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        board[i][j] = '*';
    for (int i = 0; i < r; ++i)
      board[i][0] = board[i][1] = '.';
    for (int j = 2; j < c; ++j)
      board[0][j] = board[1][j] = '.';
    int rem = S - (r * 2 + (c - 2) * 2);
    for (int i = 2; i < r && rem > 0; ++i)
      for (int j = 2; j < c && rem > 0; ++j)
      {
        board[i][j] = '.';
        --rem;
      }
    board[0][0] = 'c';
  }

  private void print ()
  {
    for (int i = 0; i < R; ++i)
      System.out.println(board[i]);
  }

  public static void main (String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for (int t = 1; t <= T; ++t)
    {
      Solution sol = new Solution(sc);
      System.out.format("Case #%d:\n", t);
      sol.solve();
    }
    sc.close();
  }

}
