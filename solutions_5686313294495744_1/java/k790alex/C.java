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
    BufferedReader br = new BufferedReader( new FileReader(name) );
    int[] pass = new int[3000];
    int last = 0;
    String s;
    while ( (s=br.readLine() != null) ) {
      StringTokenizer st = new StringTokenizer(s);
      st.nextToken();
      st.nextToken()
      int x = Integer.parseInt( st.nextToken() );
    }

    int cases = Integer.parseInt( next() );
    for (int k = 0; k < cases; k++) {
      readInput();
      int ans = solveCaseFast();
      out.println("Case #" + (k+1) + ": " + ans);
    }
    //
    out.flush();
    System.exit(0);
  }

  void readInput() {
    N = Integer.parseInt( next() );
    topics = new String[N][2];
    for (int k = 0; k < N; k++) {
      topics[k][0] = next();
      topics[k][1] = next();
    }
  }

  final Random RNG = new Random();
  void shuffle(String[][] v)  {
    for (int k = 1; k < v.length; k++)  {
      int m = RNG.nextInt(k);

      // swap
      String[] aux = v[k];
      v[k] = v[m];
      v[m] = aux;
    }
  }
  int solveCaseFast() {
    int ans = 0;
    int tries = 50000;
    while (tries-- != 0) {
      int cur = 0;
      Set<String> first = new HashSet<>();
      Set<String> second = new HashSet<>();
      for (int k = 0; k < N; k++) {
        if (first.contains(topics[k][0]) && second.contains(topics[k][1])) {
          cur++;
        }
        first.add(topics[k][0]);
        second.add(topics[k][1]);
      }
      shuffle(topics);
      ans = Math.max(cur, ans);
    }
    return ans;
  }

  int solveCaseSlow()  {
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
    String first = topics[id][0];
    String second = topics[id][1];
    for (int a = 0; a < N; a++) if ( ((1<<a)&used) != 0) for (int b = 0; b < N; b++) if (a != b && ((1<<b)&used) != 0 ) {
      if ( topics[a][0].equals(first) && topics[b][1].equals(second) )
        return true;
    }
    return false;
  }
  int N;
  String[][] topics;
}
