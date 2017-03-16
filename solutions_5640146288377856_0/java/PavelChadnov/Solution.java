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

  int solve1() {
    int n = in.nextInt();
    int m = in.nextInt();
    int len = in.nextInt();
    return m / len * n + len - 1 + ((m%len!=0)?1:0);
  }

  void solve() throws IOException, Exception {
    int tcs = in.nextInt();
    for (int tc = 1; tc <= tcs; tc++) {
      int x = solve1();
      System.out.println("Case #" + tc + ": " + x);
    }
  }

  public static void main(String[] args) throws Exception {
    new Solution().run();
  }
}

