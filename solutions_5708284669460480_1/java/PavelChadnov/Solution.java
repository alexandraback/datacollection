import java.io.*;
import java.util.*;


public class Solution {
  BufferedReader reader;

  int nextInt() throws IOException {
    tokenizer.nextToken();
    return (int) tokenizer.nval;
  }

  String next() throws IOException {
    tokenizer.nextToken();
    return tokenizer.sval;
  }

  StreamTokenizer tokenizer;
  Scanner in;

  void run() throws Exception {
//    in = new Scanner(System.in);
//    PrintWriter out = new PrintWriter(System.out);
    in = new Scanner(new File("input.txt"));
    PrintWriter out = new PrintWriter(new File("output.txt"));
    reader = new BufferedReader(new InputStreamReader(System.in));
    tokenizer = new StreamTokenizer(reader);
    solve();


    in.close();
    reader.close();
    out.close();
  }

  int k, l, s;
  char[] keyboard;
  String target;
  int cnt;
  int occ;
  int max;

  void rec(String w) {
    if (w.length() == s) {
      int cur = 0;
      for (int i = 0; i + l - 1 < w.length(); i++) {
        if (w.substring(i, i + l).equals(target)) {
          cur++;
        }
      }
      if (cur > max) max = cur;
      occ += cur;
      cnt++;
      return;
    }
    for (char c : keyboard) rec(w + c);
  }

  double solve1() {
    k = in.nextInt();
    l = in.nextInt();
    s = in.nextInt();
    keyboard = in.next().toCharArray();
    target = in.next();
    cnt = 0;
    occ = 0;
    max = 0;
    rec("");
    return (occ * 1. / cnt);
  }

  int[] prefixFunction(String s) {
    int[] p = new int[s.length()];
    int k = 0;
    for (int i = 1; i < s.length(); i++) {
      while (k > 0 && s.charAt(k) != s.charAt(i))
        k = p[k - 1];
      if (s.charAt(k) == s.charAt(i))
        ++k;
      p[i] = k;
    }
    return p;
  }

  double solve2() {
    k = in.nextInt();
    l = in.nextInt();
    s = in.nextInt();
    keyboard = in.next().toCharArray();
    target = in.next();


    double[][][] dp = new double[s + 1][s + 1][l];
    double[] letProb = new double[26];
    for (char c : keyboard) {
      letProb[c - 'A'] += 1. / keyboard.length;
    }
    int[] targetPF = prefixFunction(target);
    dp[0][0][0] = 1;
    int[][] pref = new int[target.length()][26];
    for (int i = 0; i < target.length(); i++) {
      for (int c = 0; c < 26; c++) {
        String s = target.substring(0, i) + ('A' + c);
        String t = target + "+" + s;
        pref[i][c] = prefixFunction(t)[t.length() - 1];
      }
    }

    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        for (int k = 0; k < l; k++) {
          for (int c = 'A'; c <= 'Z'; c++) {
            if (target.charAt(k) == c) {
              if (k == l - 1) {
                dp[i + 1][j + 1][prefixFunction(target)[targetPF.length - 1]] += dp[i][j][k] * letProb[c-'A'];
              } else {
                dp[i + 1][j][k + 1] += dp[i][j][k] * letProb[c-'A'];
              }
            } else {
              dp[i + 1][j][pref[k][c-'A']] += dp[i][j][k] * letProb[c-'A'];
            }
          }
        }
      }
    }

    double res = 0;
    for(int i=0;i<=s;i++) {
      for(int j=0;j<l;j++) {
        res += dp[s][i][j]*i;
      }
    }

    double max = 0;
    for(int i=0;i<=s;i++)for(int j=0;j<=s;j++)for(int k=0;k<l;k++) {
      if (dp[i][j][k]>0) {
        max = Math.max(j, max);
      }
    }
    return max-res;
  }

  void solve() throws IOException, Exception {
    int tcs = in.nextInt();
    for (int tc = 1; tc <= tcs; tc++) {
      double x = solve2();
      System.out.println("Case #" + tc + ": " + String.format("%.10f", x));
    }
  }

  public static void main(String[] args) throws Exception {
    new Solution().run();
  }
}

