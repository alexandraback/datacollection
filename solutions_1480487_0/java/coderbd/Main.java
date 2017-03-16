import java.io.*;
import java.util.*;

public class Main {
  BufferedReader br;
  int[] s;
  double[] p;
  int t, n, x, cnt;
  double tar, sum;
  
  public void go() throws Exception {
    br = new BufferedReader(new InputStreamReader(System.in));
    
    t = Integer.parseInt(br.readLine());
    for (int caseNo = 1; caseNo <= t; caseNo++) {
      String[] ss = br.readLine().split(" ");
      n = Integer.parseInt(ss[0]);

      s = new int[n];
      p = new double[n];

      x = 0;
      for (int i = 0; i < n; i++)
        x += s[i] = Integer.parseInt(ss[i+1]);
      
      tar = x * 2.0f / n;
      sum = 0.0f;
      cnt = 0;
      for (int i = 0; i < n; i++) {
        p[i] = (tar - s[i]) / x * 100.f;
        if (p[i] <= 0.0f) {
          cnt++;
          sum += Math.abs(p[i]);
          p[i] = 0.0f;
        }
      }
      
      for (int i = 0; i < n; i++)
        if (p[i] > 0.0f)
          p[i] -= sum / (n - cnt);
      
      System.out.print("Case #" + caseNo + ":");
      for (int i = 0; i < n; i++)
        System.out.print(" " + p[i]);
      System.out.println();
    }
  }
  
  public static void main(String[] args) throws Exception {
    new Main().go();
  }
}
