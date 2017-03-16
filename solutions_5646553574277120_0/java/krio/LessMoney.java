package codejam;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class LessMoney {
  private static final String OUTPUT_FILE = "task.out";

  public static void main(String[] args) throws IOException {
    FileWriter writer = new FileWriter(OUTPUT_FILE);
    try {
      FastScanner sc = new FastScanner();
      int T = sc.nextInt();
      for(int t = 1; t <= T; t++) {
        int C = sc.nextInt();
        int D = sc.nextInt();
        int V = sc.nextInt();
        List<Integer> existing = new ArrayList<Integer>();
        for(int i = 0; i < D; i++) {
          existing.add(sc.nextInt());
        }
        printResult(writer, t, solve(V, existing));
      }
    } finally {
      writer.close();
    }
  }

  private static int solve(int V, List<Integer> dims) {
    int initialSize = dims.size();
    for(int i = 1; i <= V; i++) {
      int[] array = new int[dims.size()];
      for(int j = 0; j < dims.size(); j++) {
        array[j] = dims.get(j);
      }
      if(!hasSubsetSum(array, array.length, i)) {
        dims.add(i);
      }
    }

    return dims.size() - initialSize;
  }

  private static boolean hasSubsetSum(int set[], int n, int sum) {
      // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
      //  with sum equal to i
      boolean[][] subset = new boolean[sum+1][n+1];

      // If sum is 0, then answer is true
      for (int i = 0; i <= n; i++)
        subset[0][i] = true;

      // If sum is not 0 and set is empty, then answer is false
      for (int i = 1; i <= sum; i++)
        subset[i][0] = false;

       // Fill the subset table in botton up manner
       for (int i = 1; i <= sum; i++)
       {
         for (int j = 1; j <= n; j++)
         {
           subset[i][j] = subset[i][j-1];
           if (i >= set[j-1])
             subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
         }
       }


       return subset[sum][n];
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
