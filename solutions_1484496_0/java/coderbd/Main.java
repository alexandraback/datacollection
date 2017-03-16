import java.io.*;
import java.util.*;

public class Main {
  BufferedReader br;
  int[] a;
  boolean[] ex, b;
  boolean ok;
  int t, n, tar;
  
  public void bf2(int id, int sum) {
    if (id == n) {
      if (sum == tar) {
        output();
        tar = -1;
      }
      return;
    }
    
    b[id] = false;
    bf2(id + 1, sum);
    b[id] = true;
    bf2(id + 1, sum + a[id]);
  }
  
  public void bf(int id, int sum) {
    if (id == n) {
      if (tar == -1 && ex[sum]) {
        output();
        tar = sum;
      }
      ex[sum] = true;
      return;
    }
    
    b[id] = false;
    bf(id + 1, sum);
    b[id] = true;
    bf(id + 1, sum + a[id]);
  }
  
  public void output() {
    boolean flag = false;
    ok = true;
    for (int i = 0; i < n; i++)
      if (b[i])
        if (flag)
          System.out.print(" " + a[i]);
        else {
          flag = true;
          System.out.print(a[i]);
        }
    System.out.println();
  }
  
  public void go() throws Exception {
    br = new BufferedReader(new InputStreamReader(System.in));
    
    t = Integer.parseInt(br.readLine());
    for (int caseNo = 1; caseNo <= t; caseNo++) {
      String[] ss = br.readLine().split(" ");
      n = Integer.parseInt(ss[0]);
      
      ex = new boolean[3000000];
      b = new boolean[n];
      a = new int[n];
      Arrays.fill(ex, false);
      for (int i = 0; i < n; i++)
        a[i] = Integer.parseInt(ss[i+1]);
      
      System.out.println("Case #" + caseNo + ":");
      tar = -1;
      ok = false;
      bf(0, 0);
      if (ok)
        bf2(0, 0);
      else
        System.out.println("Impossible");
    }
  }
  
  public static void main(String[] args) throws Exception {
    new Main().go();
  }
}
