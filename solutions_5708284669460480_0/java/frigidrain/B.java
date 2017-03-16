// {{{ Header
// vim:filetype=java:foldmethod=marker:foldmarker={{{,}}}

import java.io.*;
import java.util.*;

// }}}

class B {

  public static void main(String[] args) {
    MyScanner sc = new MyScanner();
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    int T = sc.nextInt();
    for(int t = 1; t <= T; t++) {
      Solver s = new Solver();
      out.format("Case #%d: %f\n", t, s.solve(t, sc, out));
    }
    out.close();
  }

}

class Solver {

  int K, L, S;
  char[] keys;
  String target;
  int bananas = 0;

  public double generate(String cur) {
    if(cur.length() == S) {
      int c = 0;
      // count bananas to pay
      for(int i = 0; i <= cur.length() - L; i++) {
        if(cur.substring(i, i + L).equals(target))
          c++;
      }
      bananas = Math.max(bananas, c);
      return c;
    }

    double ev = 0.0;
    for(char c : keys) {
     ev += generate(cur + c)/K;
    }
    return ev;
  }

  public double solve(int tno, MyScanner sc, PrintWriter out) {
    bananas = 0;
    K = sc.nextInt();
    L = sc.nextInt();
    S = sc.nextInt();
    String keyString = sc.nextLine();
    keys = keyString.toCharArray();
    target = sc.nextLine();

    //quick check to see if possible
    for(int i = 0; i < L; i++) {
      if(keyString.indexOf(target.charAt(i)) == -1)
        return 0.0;
    }

    double ev = generate("");
    return bananas - ev;
  }

}

// {{{ MyScanner
class MyScanner {
  BufferedReader br;
  StringTokenizer st;

  public MyScanner() {
     br = new BufferedReader(new InputStreamReader(System.in));
  }

  String next() {
    while (st == null || !st.hasMoreElements()) {
      try {
        st = new StringTokenizer(br.readLine());
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    return st.nextToken();
  }

  int nextInt() {
    return Integer.parseInt(next());
  }

  long nextLong() {
    return Long.parseLong(next());
  }

  double nextDouble() {
    return Double.parseDouble(next());
  }

  String nextLine(){
    String str = "";
    try {
       str = br.readLine();
    } catch (IOException e) {
       e.printStackTrace();
    }
    return str;
  }

}
// }}}
