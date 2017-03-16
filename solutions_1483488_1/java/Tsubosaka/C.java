package qual;

import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class C {
  static long count(int n , int B){
    String s = String.valueOf(n);
    Set<Integer> set = new TreeSet<Integer>();
    for(int i = 1 ; i < s.length()  ; ++i){
      String rot = s.substring(i) + s.substring(0, i);
      if(rot.charAt(0) == '0')continue;
      int v = Integer.parseInt(rot);
      if(n < v && v <= B){
        set.add(v);
      }
    }
    return set.size();
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();    
    for(int cn = 1 ; cn <= T ; ++cn){
      int A = sc.nextInt();
      int B = sc.nextInt();
      long ret = 0;
      for(int n = A ; n <= B ; ++n){
        ret += count(n , B);
      }
      System.out.printf("Case #%d: %d\n", cn , ret);
    }
  }
}
