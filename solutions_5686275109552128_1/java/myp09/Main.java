import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    InputStreamReader isr = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(isr);
    int T = Integer.parseInt(br.readLine());
    for (int t = 1; t <= T; t++) {
      int D = Integer.parseInt(br.readLine());
      int[] count = new int[MAX + 1]; 
      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 0; i < D; i++) {
        int p = Integer.parseInt(st.nextToken());
        count[p]++;
      }
      int ans = MAX;
      for (int k = 1; k <= MAX; k++) {
        int cut = 0;
        for (int i = k + 1; i <= MAX; i++) {
          int cost = i / k - 1;
          if (i % k != 0) {
            cost++;
          }
          cut += cost * count[i];
        }
        if (ans > k + cut) {
          ans = k + cut;
        }
      }
      System.out.println(String.format("Case #%d: %d", t, ans));
    }
  }

  private static final int MAX = 1000;
}