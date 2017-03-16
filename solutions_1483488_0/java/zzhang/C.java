import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class C {

  public static int gao(int a, int b) {
    int r = 0;
    int n = ("" + a).length();
    int m = 1;
    for (int i = 1; i < n; ++i) m*= 10;
    
    for (int i = a; i <=b; ++i) {
      Set<Integer> s = new HashSet<Integer>();
      
      int x = i;
      for (int j = 0; j < n; ++j) {
        int y = x % 10 * m + x / 10;
        if (y > i && y <=b && !s.contains(y)) {
          r ++;
          s.add(y);
        }
        x = y;
        
      }

    }
    return r;
  }
  
  public static void main(String[] args) throws Exception {
    
    
    //InputStream in = System.in;
    InputStream in = new FileInputStream("c:\\C-small-attempt0.in");
    
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
      int a = scanner.nextInt();
      int b = scanner.nextInt();
      
      System.out.println("Case #" + i + ": " + gao(a,b));
    }
    
    
    
  }

}
