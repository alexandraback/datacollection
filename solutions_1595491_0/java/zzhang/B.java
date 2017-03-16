import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;


public class B {

  public static int gao(int s, int p , int[] ss) {
    int p1 = p + Math.max(0,p-1) * 2;
    int p2 = p + Math.max(0,p-2) * 2;
    
    Arrays.sort(ss);
    int ret = 0;
    for (int i = ss.length - 1; i >=0; --i) {
      int n = ss[i];
      if (n >= p1) {
        ret ++;
      } else  if (n >= p2 && s > 0) {
        ret ++;
        s--;
      }
    }
    
    
    return ret;
    
  
  }
  
  public static void main(String[] args) throws Exception {
    
    
    //InputStream in = System.in;
    InputStream in = new FileInputStream("c:\\B-small-attempt0.in");
    
    Scanner scanner = new Scanner(in);
    //BufferedReader r = new BufferedReader(new InputStreamReader(in));
    /*
    for (;;) {
      String l = r.readLine();
      if (l == null) {
        break;
      }
    }
    */
    
    int n;
    n = scanner.nextInt();
    for (int i = 1; i <= n; ++i) {
      int m = scanner.nextInt();
      int s = scanner.nextInt();
      int p = scanner.nextInt();
      int[] ss = new int[m];
      for (int j = 0; j < m; ++j) {
        ss[j] = scanner.nextInt();
      }
      System.out.println("Case #" + i + ": " + gao(s, p, ss));
    }
    
    
    
  }

}
