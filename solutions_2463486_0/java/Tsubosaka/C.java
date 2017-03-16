package qual;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {
  static boolean isPalindrome(long val){
    String s = String.valueOf(val);
    int j = s.length() - 1;
    for(int i = 0 ; i < j ; ++i , --j){
      if(s.charAt(i) != s.charAt(j)){
        return false;
      }
    }
    return true;
  }
  
  static long count(long val , List<Long> valids){
    long ret = 0;
    for(long l : valids){
      if(l <= val){
        ++ret;
      }
    }
    return ret;
  }
  
  public static void main(String[] args) {
    List<Long> valids = new ArrayList<Long>();
    for(long i = 1 ; i <= 10000000 ; ++i){
      if(isPalindrome(i) && isPalindrome(i * i)){
        valids.add(i * i);
      }
    }
//    System.out.println(valids);
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      long A = sc.nextLong();
      long B = sc.nextLong();
      long x = count(B , valids) - count(A - 1 , valids);
      System.out.printf("Case #%d: %d\n", cn , x);
    }
  }
}
