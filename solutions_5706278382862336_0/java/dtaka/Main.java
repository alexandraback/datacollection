import java.io.*;
import java.util.*;

public class Main{
  static final String ANSWER = "Case #%d: %d\n";
  static final String IMPOSSIBLE = "Case #%d: impossible\n";
  
  public static void main(String args[]) throws Exception {
    BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    String line;
    String[] prms;
    int T = Integer.parseInt(stdin.readLine());
    for (int t = 1; t <= T; t++) {
      line = stdin.readLine();
      prms = line.split("/");
      long P = Long.parseLong(prms[0]);
      long Q = Long.parseLong(prms[1]);
      int cnt = 0;
      
      while (Q%2 == 0) {
        if (Q > P) cnt++;
        Q /= 2;
      }
      if (Q != 1) {
        System.out.printf(IMPOSSIBLE, t);
      } else{
        System.out.printf(ANSWER, t, cnt);
      }
    }
  }
}
