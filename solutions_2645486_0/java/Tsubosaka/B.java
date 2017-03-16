package r1a;

import java.util.Scanner;

public class B {
  static long solveSmall(int E , int R , int V[]){
    int dp[] = new int[E + 1];
    for(int i = 0 ; i < V.length ; ++i){
      int next[] = new int[E + 1];
      for(int ns = 0 ; ns <= E ; ++ns){
        int max = 0;
        for(int cs = 0 ; cs <= E ; ++cs){
          int cval = Math.min(cs + R, E);
          if(cval < ns){
            continue;
          }
          max = Math.max(max, dp[cs] + (cval - ns) * V[i]);
        }
        next[ns] = max;
      }
      dp = next;
    }
    int max = 0;
    for(int d : dp)
      max = Math.max(max, d);
    return max;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      int E = sc.nextInt();
      int R = sc.nextInt();
      int N = sc.nextInt();
      int V[] = new int[N];
      for(int i = 0 ; i < N ; ++i){
        V[i] = sc.nextInt();
      }
      System.out.printf("Case #%d: %d\n", cn , solveSmall(E, R , V));
    }
  }
}
