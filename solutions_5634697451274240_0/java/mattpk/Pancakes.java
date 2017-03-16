import java.util.*;
import java.io.*;

public class Pancakes {
  public static void main(String[] args) throws Exception {
    //Scanner in = new Scanner(System.in);
    Scanner in = new Scanner(new File("B-small-attempt0.in"));
    PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
    int tests = in.nextInt();
    for (int t = 1; t <= tests; t++) {
      String take = in.next();
      int count = 1;
      int takeLen = take.length();
      char last = take.charAt(0);
      for (int x = 1; x < takeLen; x++) {
        char now = take.charAt(x);
        if (now != last) {
          count++;
        }
        last = now;
      }
      if (last == '+') {
        count--;
      }
      
      String answer = count + "";
      out.println("Case #" + t + ": " + answer);
    }
    in.close();
    out.close();
  }
}