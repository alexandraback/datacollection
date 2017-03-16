import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

  static String inputFile = "B-small-attempt0.in";
  static String outputFile = "B-small-attempt0.out";
  static PrintWriter out;
  
  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new File(inputFile));
    out = new PrintWriter(new File(outputFile));
//    Scanner in = new Scanner(System.in);
    
    
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int a = in.nextInt();
      int b = in.nextInt();
      int k = in.nextInt();
      
      int count = 0;
      for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
          int v = i & j;
          if(v < k) {
            count++;
          }
        }
      }
      System.out.println(count);
      out.println("Case #" + t + ": " + count);
    }
    
    out.close();
    
  }

  
}
