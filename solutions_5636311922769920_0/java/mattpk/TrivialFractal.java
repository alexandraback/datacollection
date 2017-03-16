import java.util.*;
import java.io.*;

public class TrivialFractal {

  public static void main(String[] args) throws Exception {
    //Scanner in = new Scanner(System.in);
    Scanner in = new Scanner(new File("D-small-attempt0.in"));
    PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
    int tests = in.nextInt();
    for (int t = 1; t <= tests; t++) {
      in.nextInt();
      in.nextInt();
      int lol = in.nextInt();
      out.print("Case #" + t + ":");
      for (int i = 1; i <= lol; i++) out.print(" " + i);
      out.println();
    }
    in.close();
    out.close();
  }
}