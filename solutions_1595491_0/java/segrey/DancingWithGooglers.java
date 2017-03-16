import java.io.*;
import java.util.StringTokenizer;

public class DancingWithGooglers {

  BufferedReader br;
  StringTokenizer st = new StringTokenizer("");

  private void solve() throws IOException {
//    final String IO_FILE = null;

    final String IO_FILE = "./B/B-small-attempt0";
    final PrintWriter pw;
    if (IO_FILE == null) {
      br = new BufferedReader(new InputStreamReader(System.in));
      pw = new PrintWriter(System.out);
    } else {
      br = new BufferedReader(new FileReader(IO_FILE + ".in"));
      pw = new PrintWriter(IO_FILE + ".out");
    }
    int testCases = nextInt();
    for (int ti = 1; ti <= testCases; ti++) {
      int n = nextInt();
      int s = nextInt();
      int p = nextInt();
      int[] pointSums = new int[n];
      for (int i = 0; i < n; i++) {
        pointSums[i] = nextInt();
      }
      int ans = find(n, s, p, pointSums);
      pw.println("Case #" + ti + ": " + ans);
    }
    br.close();
    pw.close();
  }

  private int find(int n, int s, int p, int[] pointSums) {
    int[][] d = new int[n + 1][s + 1];
    d[0][0] = 0;
    for (int i = 0; i < n; i++) {
      final int sum = pointSums[i];
      for (int j = 0; j <= s; j++) {
        int maxRegularPoint = calcMaxRegularPoint(sum);
        if (p <= maxRegularPoint) {
          d[i + 1][j] = Math.max(d[i + 1][j], d[i][j] + 1);
        }
        else {
          d[i + 1][j] = Math.max(d[i + 1][j], d[i][j]);
          int maxSurprisingPoint = calcMaxSurprisingPoint(sum);
          if (sum >= 2 && p <= maxSurprisingPoint && j != s) {
            d[i + 1][j + 1] = Math.max(d[i + 1][j + 1], d[i][j] + 1);
          }
        }
      }
    }
    int ans = 0;
    for (int j = 0; j <= s; j++) {
      ans = Math.max(ans, d[n][j]);
    }
    return ans;
  }

  private int calcMaxRegularPoint(int sum) {
    return (sum + 2) / 3;
  }

  int calcMaxSurprisingPoint(int sum) {
    return (sum + 4) / 3;
  }

  String nextString() throws IOException {
    while (!st.hasMoreTokens()) {
      st = new StringTokenizer(br.readLine());
    }
    return st.nextToken();
  }

  int nextInt() throws IOException {
    return Integer.parseInt(nextString());
  }

  public static void main(String[] args) throws IOException {
    new DancingWithGooglers().solve();
  }
}
