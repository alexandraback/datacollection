import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new File("D-small-attempt0.in"));
//    PrintWriter out = new PrintWriter(System.out);
     PrintWriter out = new PrintWriter(new File("D-small-attempt0.out"));

    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int X = in.nextInt();
      int R = in.nextInt();
      int C = in.nextInt();
      out.println("Case #" + t + ": " + solve(X, R, C));
    }

    out.close();
  }

  public static String solve(int X, int R, int C) {
    if (X >= 7)  // island
      return "RICHARD";
    if (R * C % X != 0) // invalid number of pieces
      return "RICHARD";
    if (X > Math.max(R, C))
      return "RICHARD"; // one LONG piece
    
    int square = Math.min(R, C) + 1;
    if (square*square - square + 1 <= X) { // create a square
      return "RICHARD";
    }
    
    
    return "GABRIEL";
  }

}
