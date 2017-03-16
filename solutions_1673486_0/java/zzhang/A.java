import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.util.Scanner;


public class A {

  public static double gao() {
    
    double best = Math.min(a + b + 1, 2 + b);
    double q = 1;
    for (int i = 0; i < a; ++i) {
      q *= p[i];
      best = Math.min(best, q * (a - i - 1 + b - i - 1 + 1) + (1-q) * (a - i - 1 + b - i - 1 + 1 + b + 1));  
    }
    
    return best;
   
  }
  
  static int a;
  static int b;
  static double[] p;
  
  public static void main(String[] args) throws Exception {
    
    
    //InputStream in = System.in;
    InputStream in = new FileInputStream("A-small-attempt0 (1).in");
    
    Scanner scanner = new Scanner(in);
    
    
    
    int n = scanner.nextInt();
    for (int i = 1; i <= n; ++i) {
      a = scanner.nextInt();
      b = scanner.nextInt();
      p = new double[a];
      for (int j = 0; j < a; ++j) {
        p[j] = scanner.nextDouble();
      }
      System.out.println("Case #" + i + ": " + gao());

    }
    
    
  }

}
