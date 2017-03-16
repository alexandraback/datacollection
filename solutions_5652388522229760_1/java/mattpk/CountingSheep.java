import java.util.*;
import java.io.*;

public class CountingSheep {
  private static boolean done(boolean[] visited) {
    for (int i = 0; i <= 9; i++) {
      if (!visited[i]) return false;
    }
    return true;
  }
  
  public static void main(String[] args) throws Exception {
    //Scanner in = new Scanner(System.in);
    Scanner in = new Scanner(new File("A-large.in"));
    PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
    int tests = in.nextInt();
    for (int t = 1; t <= tests; t++) {
      boolean[] visited = new boolean[10];
      int base = in.nextInt();
      int as = base;
      String answer = "INSOMNIA";
      if (as != 0) {
        while(!done(visited)) {
          String cast = "" + as;
          int len = cast.length();
          for (int i = 0; i < len; i++) {
            char c = cast.charAt(i);
            if (c >= '0' && c <= '9') visited[c - '0'] = true;
          }
          as = as + base;
        }
        answer = (as - base) + "";
      }
      System.out.println("Case #" + t + ": " + answer);
      out.println("Case #" + t + ": " + answer);
    }
    in.close();
    out.close();
  }
}