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

public class TypeWriterMonkey {
  private static final String OUTPUT_FILE = "task.out";

  public static void main(String[] args) throws IOException {
    FileWriter writer = new FileWriter(OUTPUT_FILE);
    try {
      FastScanner sc = new FastScanner();
      int T = sc.nextInt();
      for(int t = 1; t <= T; t++) {
        int K = sc.nextInt();
        int L = sc.nextInt();
        int S = sc.nextInt();
        String keyboard = sc.nextToken();
        String target = sc.nextToken();
        printResult(writer, t, solve(S, keyboard, target));
      }
    } finally {
      writer.close();
    }
  }

  private static double solve(int S, String keyboard, String target) {
    List<String> all = generateAll(S, keyboard);
    double count = 0;
    double max = 0;
    for(String s : all) {
      double thisTurn = countSubstr(s, target);
      max = Math.max(thisTurn, max);
      count += thisTurn;
    }
    return max - count/all.size();
  }

  private static List<String> generateAll(int S, String keyboard) {
    ArrayList<String> list = new ArrayList<String>();
    for(int i = 0; i < keyboard.length(); i++) {
      list.add(Character.toString(keyboard.charAt(i)));
    }
    for(int i = 1; i < S; i++) {
      ArrayList<String> newList = new ArrayList<String>();
      for(int j = 0; j < keyboard.length(); j++) {
        for(String s : list) {
          newList.add(s + keyboard.charAt(j));
        }
      }
      list = newList;
    }
    return list;
  }

  public static int countSubstr(final String string, final String substring) {
     int count = 0;
     int idx = 0;

     while ((idx = string.indexOf(substring, idx)) != -1)
     {
        idx++;
        count++;
     }

     return count;
  }

  private static void printResult(Writer writer, int t, double result) throws IOException {
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
