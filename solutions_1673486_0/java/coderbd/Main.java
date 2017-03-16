import java.io.*;
import java.util.*;

public class Main {
  int a, b, t;
  double[] c, p, e;
  double[][] d;
  final String[] s = {"000", "001", "010", "011", "100", "101", "110", "111"};
  final int MAX = 250;
  
  public void go() throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(br.readLine());
    
    c = new double[MAX];
    p = new double[MAX];
    e = new double[MAX];
    d = new double[MAX][MAX];
    for (int caseNo = 1; caseNo <= t; caseNo++) {
      String[] ss = br.readLine().split(" ");
      a = Integer.parseInt(ss[0]);
      b = Integer.parseInt(ss[1]);
      ss = br.readLine().split(" ");
      for (int i = 0; i < a; i++)
        p[i] = Double.parseDouble(ss[i]);
      
      Arrays.fill(c, 0.0f);
      Arrays.fill(e, 0.0f);
      for (int i = 0; i < MAX; i++)
        Arrays.fill(d[i], 0);
      
      double exp = 2.0f + b;
      for (int i = 0; i < 8; i++) {
        double prob = 1;
        for (int j = 0; j < 3; j++)
          prob *= (s[i].charAt(j) == '1'? p[j] : (1.0f - p[j]));
        c[i] = prob;
      }
      
      for (int i = 0; i < 8; i++)
        for (int j = 0; j <= 3; j++) {
          int min = 10;
          for (int k = 0; k < 3; k++)
            if (s[i].charAt(k) == '0')
              min = Math.min(min, k);
          
          if (a - min <= j)
            d[i][j] += (2 * j + 1 + b - a);
          else
            d[i][j] += (2 * j + 2 * b - a + 2);
        }

      for (int i = 0; i < 8; i++)
        if (c[i] != 0) {
          double texp = 0.0f;
          for (int j = 0; j < 3; j++)
            e[j] += c[i] * d[i][j];
        }

      for (int i = 0; i < a; i++)
        exp = Math.min(exp, e[i]);
      
      System.out.format("Case #%d: %.6f%n", caseNo, exp);
    }
  }
  
  public static void main(String[] args) throws Exception {
    new Main().go();
  }
}
