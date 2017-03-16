import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;


public class BLawnmower {
  Scanner in;

  public static void main(String[] args) throws Exception{
    new BLawnmower().run();
  }

  void run() throws Exception {
    //System.setIn(new FileInputStream("B-test.in"));
    System.setIn(new FileInputStream("B-small-attempt0.in"));
    System.setOut(new PrintStream("B-small-attempt0.out"));
    in = new Scanner(System.in);
    int cases = in.nextInt();
    for (int C = 1; C <=cases; ++C) {
      int N = in.nextInt(), M = in.nextInt();
      int Y[][] = new int [N][M];
      for(int r = 0; r <N; ++r)
        for (int c = 0; c < M; ++c)
          Y[r][c] = in.nextInt();

      ArrayList<Integer>[] L = new ArrayList[101];
      for(int i = 0; i < L.length; ++i)
        L[i] = new ArrayList<Integer>();
      for(int r = 0; r <N; ++r)
        for (int c = 0; c < M; ++c) {
          int v= r*M + c;
          L[Y[r][c]].add(v);
        }
      String valid = "YES";

      main: for(int i = 0; i < L.length; ++i)
        for (int v: L[i]){
          int r=v/M, c = v%M;
          boolean col = true, row = true;
          int ref = Y[r][c];
          for(int j = 0; j < N; ++j)
            if(Y[j][c] > ref) col = false;
          for(int j = 0; j < M; ++j)
            if(Y[r][j] > ref) row = false;
          if(!row && !col) {
            valid = "NO";
            break main;
          }
        }

      System.out.println(String.format("Case #%d: %s", C, valid));
    }

  }
}
