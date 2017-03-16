import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new File("A-large.in"));
    PrintWriter out = new PrintWriter(new File("A-large.out"));

    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
   
      r = in.nextInt();
      c = in.nextInt();
      w = in.nextInt();
      
      out.println("Case #" + t + ": " + solve());
    }

    out.close();
  }
  static int r;
  static int c;
  static int w;
  
  private static int solve() {
    int badRows = (r-1) * (c/w);
    if (c % w == 0) {
      return badRows + (c/w) + w - 1;
    } else {
      return badRows + (c/w) + w - 1 + 1;
    }
    
  }


}
