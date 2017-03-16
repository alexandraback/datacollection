import java.io.File;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.*;

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

  boolean g(String s) {
    int cur = 0;
    Set<Character> u = new HashSet<Character>();
    while (cur < s.length()) {
      char c = s.charAt(cur);
      if (u.contains(c)) return false;
      u.add(c);
      while (cur < s.length() && s.charAt(cur) == c) {
        cur++;
      }
    }
    return true;
  }

  long[] fact = new long[110];

  long mul(long a, long b) {
    return (a * b) % MOD;
  }

  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File(NAME + ".in"));
      //BufferedReader in = new BufferedReader(new FileReader(new File(NAME + "in")));
      //StreamTokenizer in = new StreamTokenizer(new BufferedReader(new FileReader(new File(NAME + "in"))));

      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = in.nextInt();

      fact[0] = 1;
      for (int i = 1; i < fact.length; i++) {
        fact[i] = mul(fact[i - 1], i);
      }

      for (int test = 1; test <= tests; test++) {
        System.out.println(test);
        int n = in.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
          s[i] = in.next();
          System.out.print(s[i] + " ");
        }
        System.out.println();

        boolean good = true;
        List<String> s1 = new ArrayList<String>();
        List<String> s2 = new ArrayList<String>();
        for (int i = 0; i < n; i++) {
          String ss = s[i];
          if (!g(ss)) {
            good = false;
            break;
          }
          int l = 0;
          char c = ss.charAt(0);
          while (l < ss.length() && ss.charAt(l) == c) l++;
          int r = ss.length() - 1;
          c = ss.charAt(ss.length() - 1);
          while (r >= 0 && ss.charAt(r) == c) r--;
          for (int k = l; k <= r; k++) {
            for (int j = 0; j < n; j++) if (i != j) {
              if (s[j].contains("" + s[i].charAt(k))) {
                good = false;
                break;
              }
            }
          }
          if (l == ss.length()) {
            s1.add(ss);
          } else {
            s2.add(ss);
          }
        }
        for (int i = 0; i < s2.size(); i++) {
          for (int j = i + 1; j < s2.size(); j++) {
            String si = s2.get(i);
            String sj = s2.get(j);
            if (si.charAt(0) == sj.charAt(0) || si.charAt(si.length() - 1) == sj.charAt(sj.length() - 1)) {
              good = false;
            }
          }
        }

        long res = 0;

        Map<Character, Integer> f = new HashMap<Character, Integer>();
        for (int i = 0; i < s1.size(); i++) {
          char c = s1.get(i).charAt(0);
          if (!f.containsKey(c)) f.put(c, 1);
          else f.put(c, f.get(c) + 1);
        }

        if (good) {
          res = 1;
          boolean[] u = new boolean[s2.size()];
          int numG = 0;
          for (int i = 0; i < s2.size(); i++) if (!u[i]) {
            u[i] = true;
            numG++;
            char l = s2.get(i).charAt(0);
            char r = s2.get(i).charAt(s2.get(i).length() - 1);
            Set<Character> uc = new HashSet<Character>();
            uc.add(l); uc.add(r);
            boolean lf = false;
            boolean rf = false;
            while (!lf || !rf) {
              if (!lf) {
                int nl = -1;
                for (int j = 0; j < s2.size(); j++) if (!u[j]) {
                  if (s2.get(j).charAt(s2.get(j).length() - 1) == l) {
                    nl = j;
                  }
                }
                if (nl == -1) {
                  lf = true;
                } else {
                  u[nl] = true;
                  l = s2.get(nl).charAt(0);
                  uc.add(l);
                }
              }

              if (!rf) {
                int nr = -1;
                for (int j = 0; j < s2.size(); j++) if (!u[j]) {
                  if (s2.get(j).charAt(0) == r) {
                    nr = j;
                  }
                }
                if (nr == -1) {
                  rf = true;
                } else {
                  u[nr] = true;
                  r = s2.get(nr).charAt(s2.get(nr).length() - 1);
                  uc.add(r);
                }
              }
            }

            long curR = 1;
            for (char c: uc) if (f.containsKey(c)) {
              curR = mul(curR, fact[f.get(c)]);
            }
            if (l == r) {
              good = false;
              break;
            }
            res = mul(res, curR);
            for (char c: uc) f.remove(c);
          }

          for (char c: f.keySet()) {
            numG++;
            res = mul(res, fact[f.get(c)]);
          }
          res = mul(res, fact[numG]);
        }

        if (!good) res = 0;
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
