import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.util.Scanner;


public class B {

  public static int gao() {

    int s = 0;
    for (int ret = 1; ;ret++) {
      
      int ss = 0;
      for (int i = 0; i < m; ++i) {
        if (b[i] >= 0 && a[i] >= 0 && s >= b[i]) {
          ss = 2;
          b[i] = -1;
          a[i] = -1;
          break;
        }
      }
      if (ss == 0) {
        for (int i = 0; i < m; ++i) {
          if (b[i] >= 0 && s >= b[i]) {
            ss = 1;
            b[i] = -1;
            break;
          }
        }
      }
      if (ss == 0) {
        int k = -1;
        for (int i = 0; i < m; ++i) {
          if (a[i] >= 0 && s >= a[i]) {
            if (k < 0) {
              k = i;
            } else {
              if (b[i] > b[k]) {
                k = i;
              }
            }
          }
        }
        
        if (k >= 0) {
          ss = 1;
          a[k] = -1;
        }
      }
      if (ss == 0) {
        return -1;
      }
      s += ss;
      if (s == m * 2) return ret;
    }
   
  }
  
  static int m;
  static int[] a;
  static int[] b;
  
  public static void main(String[] args) throws Exception {
    
    
    //InputStream in = System.in;
    InputStream in = new FileInputStream("B-small-attempt1.in");
    
    Scanner scanner = new Scanner(in);
    
    
    
    int n = scanner.nextInt();
    for (int i = 1; i <= n; ++i) {
      m = scanner.nextInt();
      a = new int[m];
      b = new int[m];
      for (int j = 0; j < m; ++j) {
        a[j] = scanner.nextInt();
        b[j] = scanner.nextInt();
      }
      int ret = gao();
      String xx = ret > 0 ? ret + "" : "Too Bad";
      System.out.println("Case #" + i + ": " + xx);

    }
    
    
  }

}
