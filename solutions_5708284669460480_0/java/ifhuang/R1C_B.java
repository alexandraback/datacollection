package codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class R1C_B {

  static BufferedReader in;
  static PrintWriter out;
  static StringTokenizer tok;

  static void solve() throws Exception {
    int T = nextInt();
    for (int i = 1; i <= T; i++) {
      int K = nextInt();
      int L = nextInt();
      int S = nextInt();
      char[] key = next().toCharArray();
      char[] target = next().toCharArray();
      out.print(String.format("Case #%d: ", i));
      char[][] gen = new char[(int) Math.pow(K, S)][S];
      for (int k = 0; k < S; k++)
        for (int j = 0; j < gen.length; j++) {
          gen[j][k] = key[(int) (j / Math.pow(K, S - k - 1)) % K];
        }
      int[] count = new int[gen.length];
      int max = 0;
      for (int j = 0; j < gen.length; j++) {
        int t = 0;
        int k1 = 0;
        while (k1 < S) {
          int k2 = 0;
          while (k2 < L)
            if (gen[j][k1 + k2] == target[k2])
              k2++;
            else
              break;
          if (k2 == L)
            t++;
          k1++;
          if (k1 + L > S)
            break;
        }
        count[j] = t;
        max = Math.max(max, count[j]);
      }
      double ans = 0;
      for (int j = 0; j < gen.length; j++)
        ans += (double) 1 / gen.length * (max - count[j]);
      out.println(ans);
    }
  }

  public static void main(String args[]) {
    try {
      in = new BufferedReader(new InputStreamReader(System.in));
      out = new PrintWriter(new OutputStreamWriter(System.out));
      solve();
      in.close();
      out.close();
    } catch (Throwable e) {
      e.printStackTrace();
      System.exit(1);
    }
  }

  static int nextInt() throws IOException {
    return Integer.parseInt(next());
  }

  static int[] nextIntArray(int len, int start) throws IOException {
    int[] a = new int[len];
    for (int i = start; i < len; i++)
      a[i] = nextInt();
    return a;
  }

  static long nextLong() throws IOException {
    return Long.parseLong(next());
  }

  static long[] nextLongArray(int len, int start) throws IOException {
    long[] a = new long[len];
    for (int i = start; i < len; i++)
      a[i] = nextLong();
    return a;
  }

  static String next() throws IOException {
    while (tok == null || !tok.hasMoreTokens()) {
      tok = new StringTokenizer(in.readLine());
    }
    return tok.nextToken();
  }

}
