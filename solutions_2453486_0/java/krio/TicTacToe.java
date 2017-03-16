import java.io.*;
import java.util.*;

public class TicTacToe {
  private static final int SIZE = 4;

  public static void main(String[] args){
    FastScanner sc = new FastScanner();
    int tests = sc.nextInt();

    for(int i = 1; i <= tests; i++) {
      String[] rows = new String[SIZE];
      for(int j = 0; j < SIZE; j++) {
        rows[j] = sc.nextToken();
      }
      solve(rows, i);
    }
  }

  private static void solve(String[] rows, int testNum) {
    Set<Result> results = new HashSet<Result>();

    // columns
    for(int i = 0; i < SIZE; i++) {
      char[] seq = new char[SIZE];
      for(int j = 0; j < SIZE; j++) {
        seq[j] = rows[j].charAt(i);
      }
      results.add(result(seq));
    }

    // rows
    for(int i = 0; i < SIZE; i++) {
      results.add(result(rows[i].toCharArray()));
    }

    // diagonals
    char[] seq = new char[SIZE];
    for(int i = 0, j = 0; i < SIZE; i++, j++) {
      seq[i] = rows[i].charAt(j);
    }
    results.add(result(seq));

    for(int i = 0, j = SIZE - 1; i < SIZE; i++, j--) {
      seq[i] = rows[i].charAt(j);
    }
    results.add(result(seq));

    if (results.contains(Result.X)) {
      printCase("X won", testNum);
    } else if (results.contains(Result.O)) {
      printCase("O won", testNum);
    } else if(results.contains(Result.NOT_COMPLETED)) {
      printCase("Game has not completed", testNum);
    } else {
      printCase("Draw", testNum);
    }
  }

  private static void printCase(String result, int testNum) {
    System.out.println("Case #" + testNum + ": " + result);
  }

  private static Result result(char[] chars) {
    int num = 0, numX = 0, numO = 0;
    for(char c : chars) {
      if(c != '.') {
        num++;
        if(c == 'X') {
          numX++;
        }

        if(c == 'O') {
          numO++;
        }
      }
    }

    if(num == SIZE) {
      if(numX == 0) {
        return Result.O;
      } else if(numO == 0) {
        return Result.X;
      } else {
        return Result.DRAW;
      }
    } else {
      return Result.NOT_COMPLETED;
    }
  }

  private static enum Result {
    X, O, NOT_COMPLETED, DRAW;
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
      while (st == null || !st.hasMoreElements()) try {
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
