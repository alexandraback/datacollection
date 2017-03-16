import java.util.*;
import java.io.*;

public class A {

  public static void main(String[] args) throws Exception {
    //Scanner in = new Scanner(System.in);
    Scanner in = new Scanner(new File("A-small-attempt0.in"));
    PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
    int tests = in.nextInt();
    for (int t = 1; t <= tests; t++) {
      String take = in.next();
      int len = take.length();
      String build = take.charAt(0)+"";
      for (int i = 1; i < len; i++) {
        if (take.charAt(i) >= build.charAt(0)) {
          build = take.charAt(i) + build;
        } else {
          build = build + take.charAt(i);
        }
      }
      
      String answer = build;
      out.println("Case #" + t + ": " + answer);
    }
    in.close();
    out.close();
  }
}