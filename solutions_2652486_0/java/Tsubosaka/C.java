package r1a;

import java.util.Arrays;
import java.util.Scanner;

public class C {
  static boolean next(int[] state , int M){
    state[0]++;
    if(state[0] < M){
      return true;
    }
    state[0] = 0;
    for(int i = 1 ; i < state.length ; ++i){
      state[i]++;
      if(state[i] < M){
        return true;
      }
      state[i] = 0;
    }
    return false;
  }
  
  static double prob(int N[] , int K[]){
    int prod = 1;
    for(int n : N){
      prod *= n;
    }
    double dp[] = new double[prod + 1];
    dp[1] = 1.0;
    for(int n : N){
      double next[] = new double[prod + 1];
      for(int i = 1 ; i < dp.length ; ++i){
        next[i] = 0.5 * dp[i];
        if(i % n == 0){
          next[i] += 0.5 * dp[i / n];
        }
      }
      dp = next;
    }
    double p = 1.0;
    for(int k : K){
      if(k >= dp.length){
        return 0.0;
      }
      p *= dp[k];
    }
//    if(prod == 36){
//      System.out.println(Arrays.toString(dp)+" "+p);      
//    }
    return p;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    int R = sc.nextInt();
    int N = sc.nextInt();
    int M = sc.nextInt();
    int K = sc.nextInt();
    System.out.println("Case #1:");
    for(int r = 0 ; r < R ; ++r){
      int ks[] = new int[K];
      for(int i = 0 ; i < ks.length ; ++i){
        ks[i] = sc.nextInt();
      }
      int state[] = new int[N];
      double maxProb = 0.0;
      int best[] = new int[N];
      do{
        int nums[] = new int[N];
        for(int i = 0 ; i < nums.length ; ++i){
          nums[i] = state[i] + 2;
        }
        double prob = prob(nums , ks);
        if(prob > maxProb){
          best = nums.clone();
          maxProb = prob;
//          System.out.println(Arrays.toString(nums)+" "+prob);
        }
      }while(next(state , M - 1));
      
      for(int i : best){
        System.out.print(i);
      }
      System.out.println();
    }
  }
}
