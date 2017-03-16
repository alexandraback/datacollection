import java.io.*;
import java.util.*;

public class GoodLuck {
  public BufferedReader br;
  public boolean flag, ok1, ok2;
  public int t, r, n, m, k;
  public int[] a, p;
  public void go() throws Throwable {
    br = new BufferedReader(new InputStreamReader(System.in));
    t = Integer.parseInt(br.readLine());
    String[] ss = br.readLine().split(" +");
    r = Integer.parseInt(ss[0]);
    n = Integer.parseInt(ss[1]);
    m = Integer.parseInt(ss[2]);
    k = Integer.parseInt(ss[3]);
    a = new int[8];
    System.out.println("Case #1:");
    for (int loop = 0; loop < r; loop++) {
      ss = br.readLine().split(" +");
      p = new int[k];
      for (int i = 0; i < k; i++)
        p[i] = Integer.parseInt(ss[i]);
      flag = false;
      for (int i = 2; i <= m && !flag; i++)
        for (int j = 2; j <= m && !flag; j++)
          for (int kk = 2; kk <= m && !flag; kk++) {
            a[0] = 1;
            a[1] = i;
            a[2] = j;
            a[3] = kk;
            a[4] = i * j;
            a[5] = i * kk;
            a[6] = j * kk;
            a[7] = i * j * kk;
            ok1 = true;
            for (int x = 0; x < k && ok1; x++) {
              ok2 = false;
              for (int y = 0; y <= 7 && !ok2; y++)
                if (a[y] == p[x])
                  ok2 = true;
              if (!ok2)
                ok1 = false;
            }
            if (ok1) {
              System.out.println(i + "" + j + "" + kk);
              flag = true;
            }
          }
    }
  }
  public static void main(String[] args) throws Throwable {
    new GoodLuck().go();
  }
}
