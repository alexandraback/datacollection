import java.io.*;
import java.util.*;

public class A {
  Scanner sc;
  
  public A() {
    sc = new Scanner(System.in);
  }

  public void solveAll() {
    int T = sc.nextInt();
    for(int tc = 1; tc <= T; ++tc) {
      System.out.println("Case #" + tc + ": " + solve());
    }
  }

  public int solve() {
    int N;
    long A;

    A = sc.nextLong();
    N = sc.nextInt();
    int[] motes = new int[N];


    for(int i = 0; i < N; ++i)
      motes[i] = sc.nextInt();

    Arrays.sort(motes);

    int start;
    for(start = 0; start < N && motes[start] < A; ++start)
      A += motes[start];

    int best = N - start;

    if(A > 1) {
      int addc = 0;

      for(int thr = start; thr < N; ++thr) {
        int cand = N - (thr + 1);

        while(A <= motes[thr]) {
          A = A + A - 1;
          addc ++;
        }

        A += motes[thr];

        cand += addc;

        if(cand < best)
          best = cand;
      }
    }

    return best;
  }

  public static void main(String[] args) {
    A solver = new A(); 
    solver.solveAll();
  }
}
