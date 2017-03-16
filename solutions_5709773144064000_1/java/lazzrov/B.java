import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {

  static String inputFile = "B-large.in";
  static String outputFile = "B-large.out";
  
  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new File(inputFile));
    PrintWriter out = new PrintWriter(new File(outputFile));
    
    
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      double C = in.nextDouble();
      double F = in.nextDouble();
      double X = in.nextDouble();
      
      out.println("Case #" + t + ": " + solve(C, F, X));
    }
    out.close();
  }

  private static double solve(double c, double f, double x) {
    double best = x/2;
    
    double rate = 2;
    double currentTime = 0;
    
    for (int it = 0; it <= 1000000; it++) {
      best = Math.min(best, currentTime + x/rate);
      currentTime += c/rate;
      rate += f;
    }
    
    return best;
  }

  
}
