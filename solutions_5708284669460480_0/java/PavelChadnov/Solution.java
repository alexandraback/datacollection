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

  void solve() throws IOException, Exception {
    int tcs = in.nextInt();
    for (int tc = 1; tc <= tcs; tc++) {
      double x = solve1();
      System.out.println("Case #"+tc+": "+(max-x));
    }
  }

  public static void main(String[] args) throws Exception {
    new Solution().run();
  }
}

