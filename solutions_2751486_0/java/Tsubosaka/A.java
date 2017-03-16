package r1c;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;

public class A {
  static long solve(boolean[] arr , int n){
    int N = arr.length;
    int cnt[] = new int[N + 1];
    int count = 0;
    TreeSet<Integer> set = new TreeSet<Integer>();
    for(int i = N - 1 ; i >= 0 ; --i){
      if(arr[i]){
        ++count;
        cnt[i] = count;
        if(count >= n){
          set.add(i);
        }
      }else{
        count = 0;
      }
    }
//    System.out.println(set);
//    System.out.println(Arrays.toString(cnt));
    long result = 0;
    for(int i = 0 ; i <= arr.length - n ; ++i){
      Integer sub = set.higher(i - 1);
      if(sub == null){
        continue;
      }
      long add = N - n - sub + 1;
      result += add;
//      System.out.println(i+" "+sub+" "+N+" "+add);
    }
    return result;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      String str = sc.next();
      int N = str.length();
      boolean arr[] = new boolean[N];
      for(int i = 0 ; i < N ; ++i){
        char c = str.charAt(i);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
          arr[i] = false;
        }else{
          arr[i] = true;
        }
      }
//      System.out.println(Arrays.toString(arr));
      int n = sc.nextInt();
      System.out.printf("Case #%d: %d\n", cn, solve(arr , n));
    }
  }  
}
