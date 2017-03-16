import java.io.*;
import java.util.*;

public class Main{
  static final String ANSWER = "Case #%d: %d\n";
  
  public static void main(String args[]) throws Exception {
    BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    String line;
    String[] prms;
    int T = Integer.parseInt(stdin.readLine());
    for (int t = 1; t <= T; t++) {
      line = stdin.readLine();
      prms = line.split(" ");
      int A = Integer.parseInt(prms[0]);
      int B = Integer.parseInt(prms[1]);
      int K = Integer.parseInt(prms[2]);
      int cnt = 0;
      for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
          if ((i&j) < K) cnt++;
        }
      }
      System.out.printf(ANSWER, t, cnt);
    }
  }
}
