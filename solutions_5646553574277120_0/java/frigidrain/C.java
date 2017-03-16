// {{{ Header
// vim:filetype=java:foldmethod=marker:foldmarker={{{,}}}

import java.io.*;
import java.util.*;

// }}}

class C {

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

  int C, D, V;
  int[] coins;
  boolean[] yes;

  public void make(int i) {
    
    if(i == D)
      return;

    boolean[] tmp = new boolean[V + 1];

    for(int j = 0; j <= V; j++)
      if(yes[j] && j + coins[i] <= V) {
        tmp[j + coins[i]] = true;
      }

    for(int j = 0; j <= V; j++)
      yes[j] = tmp[j] | yes[j];

    make(i + 1);
  }

  public int solve(int tno, MyScanner sc, PrintWriter out) {
    C = sc.nextInt();
    D = sc.nextInt();
    V = sc.nextInt();
    coins = new int[D];
    for(int i = 0; i < D; i++)
      coins[i] = sc.nextInt();

    yes = new boolean[V + 1];
    yes[0] = true;

    make(0);

    int res = 0;
    for(int i = 0; i <= V; i++) {
      // very ugly solution
      if(!yes[i]) {
        res++;

        boolean[] tmp = new boolean[V + 1];
        for(int j = 0; j <= V; j++)
          if(yes[j] && j + i <= V) {
            tmp[j + i] = true;
          }

        for(int j = 0; j <= V; j++)
          yes[j] = tmp[j] | yes[j];

      }
    }

    return res;
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
