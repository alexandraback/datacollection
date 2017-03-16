import java.io.File;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Train implements Runnable {
  private static final String NAME = "car";
  private static final int MOD = 1000000007;

  int nextInt(StreamTokenizer in) throws Exception {
    in.nextToken();
    return (int) in.nval;
  }

  long nextLong(StreamTokenizer in) throws Exception {
    in.nextToken();
    return (long) in.nval;
  }

  int n;
  String[] s;
  int[] p;
  boolean[] u;

  int res;

  void check() {
    String ss = "";
    for (int i = 1; i <= n; i++) ss += s[p[i] - 1];
    int cur = 0;
    Set<Character> used = new HashSet<Character>();
    boolean good = true;
    while (cur < ss.length()) {
      char c = ss.charAt(cur);
      if (used.contains(c)) {
        good = false;
        break;
      }
      used.add(c);
      while (cur < ss.length() && ss.charAt(cur) == c) cur++;
    }
    if (good) res++;
  }

  void go(int v, int num) {
    p[num] = v;
    u[v] = true;
    if (num == n) {
      check();
    }
    for (int i = 0; i < n; i++) if (!u[i + 1]) {
      go(i + 1, num + 1);
    }
    u[v] = false;
  }

  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File(NAME + ".in"));
      //BufferedReader in = new BufferedReader(new FileReader(new File(NAME + "in")));
      //StreamTokenizer in = new StreamTokenizer(new BufferedReader(new FileReader(new File(NAME + "in"))));

      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = in.nextInt();

      for (int test = 1; test <= tests; test++) {
        System.out.println(test);
        n = in.nextInt();
        s = new String[n];
        for (int i = 0; i < n; i++) s[i] = in.next();
        p = new int[n + 1];
        u = new boolean[n + 1];
        res = 0;
        go(0, 0);
        out.println("Case #" + test + ": " + res);
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Train()).start();
  }
}
