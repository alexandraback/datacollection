package r1a;


import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class B {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      int N = sc.nextInt();
      int A[] = new int[N];
      int B[] = new int[N];
      for(int i = 0 ; i < N ; ++i){
        A[i] = sc.nextInt();
        B[i] = sc.nextInt();
      }
      int move = solve1(N, A, B);
//      int m2 = solveSmall(N, A, B);
//      if(move != m2){
//        System.out.println("case " + cn);
//        System.out.println(move+" "+m2);
//      }
//      move = m2;
      if(move < 0){
        System.out.printf("Case #%d: Too Bad\n", cn);
      }else{
        System.out.printf("Case #%d: %d\n", cn , move);        
      }
    }
  }

  static int solveSmall(int N, int[] A, int[] B) {
    Queue<Integer> q = new LinkedList<Integer>();
    int used[] = new int[1024 * 1024];
    Arrays.fill(used, -1);
    used[0] = 0;
    q.add(0);
    while(!q.isEmpty()){
      int cp = q.poll();
      int turn = used[cp];
      int astat = cp % 1024;
      int bstat = (cp / 1024);
      if(bstat == ((1 << N) -1)){
        return turn;
      }
      int curStar = Integer.bitCount(bstat) * 2 + Integer.bitCount((astat | bstat) - bstat);
      for(int i = 0 ; i < N ; ++i){
        if(B[i] <= curStar){
          int ns = (astat) + (bstat | (1 << i)) * 1024;
          if(used[ns] >= 0)continue;
          used[ns] = turn + 1;
          q.add(ns);
        }
        if(A[i] <= curStar){
          int ns = (astat | (1 << i)) + (bstat) * 1024;
          if(used[ns] >= 0)continue;
          used[ns] = turn + 1;
          q.add(ns);
        }
      }
    }
    return -1;
  }
  private static int solve1(int N, int[] A, int[] B) {
    int curStar = 0;
    boolean cleared[][] = new boolean[N][2];
    int l2Clear = 0;
    int move = 0;
    while(l2Clear < N){
      boolean f = false;
      for(int i = 0 ; i < N ; ++i){
        if(cleared[i][1])continue;
        if(B[i] <= curStar){
          cleared[i][1] = true;
          f = true;
          if(cleared[i][0]){
            curStar += 1;
          }else{
            curStar += 2;              
          }
          ++l2Clear;
          ++move;
          break;
        }
      }
      if(f)continue;
      int maxi = -1;
      for(int i = 0 ; i < N ; ++i){
        if(cleared[i][0])continue;
        if(A[i] <= curStar && !cleared[i][1]){
          if(maxi < 0){
            maxi = i;
          }else if(B[maxi] < B[i]){            
            maxi = i;
          }
          f = true;
        }
      }
      if(f){
        cleared[maxi][0] = true;
        ++move; ++curStar;
      }else{
        return -1;        
      }
    }
    return move;
  }
}