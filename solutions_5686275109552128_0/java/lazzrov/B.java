import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

  public static void main(String[] args) throws FileNotFoundException {
    
    Scanner in = new Scanner(new File("B-small-attempt0.in"));
//    PrintWriter out = new PrintWriter(System.out);
     PrintWriter out = new PrintWriter(new File("B-small-attempt0.out"));

    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int D = in.nextInt();
      int P[] = new int[D];
      for (int i = 0; i < P.length; i++) {
        P[i] = in.nextInt();
      }
      int best = Integer.MAX_VALUE;
      for (int eatingMinutes = 1; eatingMinutes < 3000; eatingMinutes++) {
        int current = eatingMinutes;
        for (int i = 0; i < P.length; i++) {
          if (P[i] > eatingMinutes) {
            current += (P[i] + eatingMinutes - 1)/eatingMinutes - 1;
          }
        }
        best = Math.min(best, current);
      }
      
      
      out.println("Case #" + t + ": " + best);
    }

    out.close();
  }


}
