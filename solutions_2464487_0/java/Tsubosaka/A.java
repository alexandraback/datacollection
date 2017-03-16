package r1a;

import java.util.Scanner;

public class A {
  static long solveSmall(long r , long t){
    long ret = 0;
    while(t > 0){      
      long need = 2 * r + 1;
      if(need > t){
        break;
      }
      ++ret;
      t -= need;
      r += 2;
    }
    return ret;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      long r = sc.nextLong();
      long t = sc.nextLong();
      System.out.printf("Case #%d: %d\n" , cn , solveSmall(r,t));
    }
  }
}
