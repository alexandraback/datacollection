package codejam;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.util.StringTokenizer;

public class Battleship {
  private static final String OUTPUT_FILE = "task.out";

  public static void main(String[] args) throws IOException {
    FileWriter writer = new FileWriter(OUTPUT_FILE);
    try {
      FastScanner sc = new FastScanner();
      int T = sc.nextInt();
      for(int t = 1; t <= T; t++) {
        int R = sc.nextInt();
        int C = sc.nextInt();
        int W = sc.nextInt();
        printResult(writer, t, solve(R, C, W));
      }
    } finally {
      writer.close();
    }
  }

  private static int solve(int R, int C, int W) {
    int firstHit = R * (C / W);
    int result = firstHit + (C % W == 0 ? 0 : 1);
    result +=  W - 1;
    return result;
  }


  private static void printResult(Writer writer, int t, long result) throws IOException {
    //writer.append("Case #" + t + ": " + num + "\n");
    StringBuilder sb = new StringBuilder();
    sb.append("Case #" + t + ": ");
    sb.append(result).append("\n");
    System.out.print(sb);
    writer.append(sb);
  }

  private static class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    public FastScanner(String s) {
      try {
        br = new BufferedReader(new FileReader(s));
      } catch (FileNotFoundException e) {
        e.printStackTrace();
      }
    }

    public FastScanner() {
      br = new BufferedReader(new InputStreamReader(System.in));
    }

    String nextToken() {
      while (st == null || !st.hasMoreElements())
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      return st.nextToken();
    }

    int nextInt() {
      return Integer.parseInt(nextToken());
    }

    long nextLong() {
      return Long.parseLong(nextToken());
    }

    double nextDouble() {
      return Double.parseDouble(nextToken());
    }
  }
}
