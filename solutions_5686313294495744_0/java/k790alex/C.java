import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out), true);
  static StringTokenizer st = new StringTokenizer("");

  public static String next() {
    try {
    while (!st.hasMoreTokens()) {
      String s = br.readLine();
      if (s == null)
        return null;
      st = new StringTokenizer(s);
    }
    return st.nextToken();
    } catch(Exception e)  {
      return  null;
    }
  }

  public static void main(String[] asda) throws Exception {
    new Thread(null, new C(), "C", 1<<26).start();
  }

  public void run() {
    int cases = Integer.parseInt( next() );
    for (int k = 0; k < cases; k++) {
      int ans = solveCaseSlow();
      out.println("Case #" + (k+1) + ": " + ans);
    }
    //
    out.flush();
    System.exit(0);
  }

  int solveCaseSlow()  {
    N = Integer.parseInt( next() );
    topics = new String[2][N];
    for (int k = 0; k < N; k++) {
      topics[0][k] = next();
      topics[1][k] = next();
    }

    mem = new int[1<<N];
    Arrays.fill(mem, -1);

    int ans = solve(0);
    return ans;
  }

  int[] mem;
  int solve(int used) {
    if (Integer.bitCount(used) == N) {
      return 0;
    }

    if (mem[used] != -1) {
      return mem[used];
    }

    int ans = 0;
    for (int item = 0; item < N; item++) if ( ((1<<item)&used) == 0) {
      int count = isRepeated(item, used) ? 1 : 0;
      count += solve(used | (1<<item));
      ans = Math.max(ans, count);
    }
    return mem[used] = ans;
  }

  boolean isRepeated(int id, int used)  {
    String first = topics[0][id];
    String second = topics[1][id];
    for (int a = 0; a < N; a++) if ( ((1<<a)&used) != 0) for (int b = 0; b < N; b++) if (a != b && ((1<<b)&used) != 0 ) {
      if ( topics[0][a].equals(first) && topics[1][b].equals(second) )
        return true;
    }
    return false;
  }
  int N;
  String[][] topics;
}
