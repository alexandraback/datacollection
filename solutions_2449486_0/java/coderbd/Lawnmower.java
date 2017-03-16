import java.io.*;

public class Lawnmower {

  public BufferedReader br;
  public int[][] a;
  public int m, n, t;
  public boolean flag;

  public boolean goHorizontal(int x, int y) {
    for (int i = 0; i < m; i++)
      if (a[x][i] > a[x][y])
        return false;
    return true;
  }

  public boolean goVertical(int x, int y) {
    for (int i = 0; i < n; i++)
      if (a[i][y] > a[x][y])
        return false;
    return true;
  }

  public void go() throws Throwable {
    br = new BufferedReader(new InputStreamReader(System.in));
    t = Integer.parseInt(br.readLine());
    for (int caseNo = 1; caseNo <= t; caseNo++) {
      String[] ss = br.readLine().split(" +");
      n = Integer.parseInt(ss[0]);
      m = Integer.parseInt(ss[1]);
      a = new int[n][m];
      for (int i = 0; i < n; i++) {
        ss = br.readLine().split(" +");
        for (int j = 0; j < m; j++)
          a[i][j] = Integer.parseInt(ss[j]);
      }
      flag = true;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (!goHorizontal(i, j) && !goVertical(i, j)) {
            flag = false;
            i = j = 1000;
          }
      System.out.println("Case #" + caseNo + ": " + (flag ? "YES" : "NO"));
    }
  }

  public static void main(String[] args) throws Throwable {
    new Lawnmower().go();
  }

}
