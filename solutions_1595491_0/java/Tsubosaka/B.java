package qual;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class B {
  static int rec(int[][] memo , List<Integer> tlist , int supprize , int pos , int point){
    int N = tlist.size();
    if(pos == N){
      return 0;
    }
    if(memo[pos][supprize] >= 0){
      return memo[pos][supprize];
    }
    int left = tlist.size() - pos;
    int ti = tlist.get(pos);
    int tave = ti / 3;
    int smax = ti % 3 == 2 ? tave + 2 : tave + 1;
    int nmax = ti % 3 == 0 ? tave     : tave + 1;
    if(supprize == left){
      int ret = rec(memo , tlist , supprize - 1 , pos + 1, point) + (smax >= point ? 1 : 0);
      return ret;
    }else if(supprize == 0){
      int ret = rec(memo , tlist , supprize, pos + 1, point) + (nmax >= point ? 1 : 0);
      return ret;
    }else{
      int ret = rec(memo , tlist , supprize - 1 , pos + 1, point) + (smax >= point ? 1 : 0);
      ret = Math.max(ret, rec(memo , tlist , supprize, pos + 1, point) + (nmax >= point ? 1 : 0));
      return ret;
    }
  }
  
  static int solve(int ts[] , int S , int p){
    List<Integer> tlist = new ArrayList<Integer>();
    int offset = 0;
    for(int t : ts){
      if(t == 0){
        if(p == 0)++offset;
      }else if(t == 1){
        if(p <= 1)++offset;
      }else if(t >= 29){
        ++offset;
      }else{
        tlist.add(t);
      }
    }
    int N = tlist.size();
    int dp[][] = new int[N][S + 1];
    for(int i = 0 ; i < N ; ++i){
      Arrays.fill(dp[i], -1);
    }
    return offset + rec(dp, tlist, S, 0 , p);
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      int N = sc.nextInt();
      int S = sc.nextInt();
      int p = sc.nextInt();
      int ts[] = new int[N];
      for(int i = 0 ; i < N ; ++i){
        ts[i] = sc.nextInt();
      }
      System.out.printf("Case #%d: %d\n", cn , solve(ts , S , p));
    }
  }
}
