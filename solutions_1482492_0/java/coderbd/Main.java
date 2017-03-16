import java.util.*;

public class Main {
  Scanner in;
  int tt, n, aa;
  double d;
  double[] t, x, a;
  
  public void go() throws Exception {
    in = new Scanner(System.in);
    tt = in.nextInt();
    
    for (int caseNo = 1; caseNo <= tt; caseNo++) {
      d = in.nextDouble();
      n = in.nextInt();
      aa = in.nextInt();
      
      t = new double[n];
      x = new double[n];
      a = new double[aa];
      for (int i = 0; i < n; i++) {
        t[i] = in.nextDouble();
        x[i] = in.nextDouble();
      }
      for (int i = 0; i < aa; i++)
        a[i] = in.nextDouble();
      
      System.out.println("Case #" + caseNo + ":");
      for (int i = 0; i < aa; i++) {
        if (n == 1)
          System.out.println(Math.sqrt(2.0f * d / a[i]));
        else if (n == 2) {
          double v = (x[1] - x[0]) / (t[1] - t[0]);
          double ttt = (d - x[0]) / v;
          double tmp = (x[0] * 2.0f - x[1] * 2.0f) / t[1];
          double tttt = (-tmp + Math.sqrt(tmp * tmp + 8.0f * a[i] * x[0])) / (2.0f * a[i]);
          double ttttt = Math.sqrt(2.0f * d / a[i]);
          
          if (tttt < ttttt)
            System.out.println(ttt);
          else
            System.out.println(Math.sqrt(2.0f * d / a[i]));
        }
        else {
          throw new Exception("I dunno how to solve!");
        }
      }
    }
  }
  
  public static void main(String[] args) {
    try {
      new Main().go();
    }
    catch (Exception e) {
    }
  }
  
}
