// {{{ Header
// vim:filetype=java:foldmethod=marker:foldmarker={{{,}}}

import java.io.*;
import java.util.*;

// }}}

class A {

  public static void main(String[] args) {
    MyScanner sc = new MyScanner();
    PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    int T = sc.nextInt();
    Solver s = new Solver();
    for(int t = 1; t <= T; t++)
      out.format("Case #%d: %d\n", t, s.solve(t, sc, out));
    out.close();
  }

}

class Solver {

  int R, C, W;

  public int solve(int tno, MyScanner sc, PrintWriter out) {
    R = sc.nextInt();
    C = sc.nextInt();
    W = sc.nextInt();

    if(C % W == 0)
      return C/W + W - 1;
    else
      return C/W + W;
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
