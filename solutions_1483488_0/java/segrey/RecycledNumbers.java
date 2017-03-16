import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class RecycledNumbers {

  BufferedReader br;
  StringTokenizer st = new StringTokenizer("");

  private void solve() throws IOException {
//    final String IO_FILE = null;
    final String IO_FILE = "./C/C-small-attempt0";
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
      int a = nextInt();
      int b = nextInt();
      int ans = find(a, b);
      pw.println("Case #" + ti + ": " + ans);
    }
    br.close();
    pw.close();
  }

  private int find(int a, int b) {
    int ans = 0;
    for (int n = a; n <= b; n++) {
      ans += check(n, b);
    }
    return ans;
  }

  private int check(final int n, final int b) {
    int length = 0, copy = n, pow10 = 1;
    while (copy > 0) {
      length++;
      copy /= 10;
      pow10 *= 10;
    }
    int firstDigitPow10 = pow10 / 10;
    int x = n;
    Set<Integer> set = new HashSet<Integer>();
    for (int i = 0; i < length - 1; i++) {
      int lastDigit = x % 10;
      x /= 10;
      int m = lastDigit * firstDigitPow10 + x;
      if (lastDigit != 0 && n < m && m <= b) {
        set.add(m);
      }
      x = m;
    }
    return set.size();
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
    new RecycledNumbers().solve();
  }
}
