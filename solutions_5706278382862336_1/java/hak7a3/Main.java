import java.io.*;
import java.util.*;
import java.util.regex.*;

class Main {
  public static void main(String[] args) {
    Scanner read = new Scanner(System.in);
    int cases = read.nextInt();
    read.nextLine();
    Pattern p = Pattern.compile("(.*)/(.*)");
    MAIN:for(int i=1; i<=cases; i++) {
      System.out.printf("Case #%d: ", i);
      Matcher m = p.matcher(read.nextLine());
      m.matches();
      long P = Long.parseLong(m.group(1));
      long Q = Long.parseLong(m.group(2));
      long D = gcd(Q, P);
      P /= D;
      Q /= D;
      long Qd = Q;
      long Pd =P;
      /* Q -> 2^n */
      while((Qd & (Qd-1)) != 0) {
        Qd += Q;
        Pd += P;
        if(Qd <= 0) {
          System.out.println("impossible");
          continue MAIN;   
        }
      }
      for(int j=1; j<=40; j++) {
        if(Pd >= (Qd >> j)) {
          System.out.println(j);
          continue MAIN;
        }
      }
      System.out.println("impossible");
    }  
  }
  public static long gcd(long n, long m) {
    while(m != 0) {
      long t = n % m; n = m; m = t;
    }
    return n;
  }
}