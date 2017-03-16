import java.util.*;

class prog1{
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for(int i=1;i<=n;i++){
      String fraction = in.next();
      long P = new Long(fraction.substring(0,fraction.indexOf('/')));
      long Q = new Long(fraction.substring(fraction.indexOf('/')+1, fraction.length()));
      System.out.println("Case #"+i+": "+q1(P, Q));
    }
  }
  public static String q1(long P, long Q){
    long g = gcd(P,Q);
    P /= g;
    Q /= g;
    if(powof2(Q)){
      int dist = 1;
      while(P*2 < Q){
        P = 2*P;
        dist ++;
      }
      return dist+"";
    }
    return "impossible";
  }

  //source: http://introcs.cs.princeton.edu/java/23recursion/Euclid.java.html
  public static long gcd(long p, long q) {
        if (q == 0) return p;
        else return gcd(q, p % q);
  }
  public static boolean powof2(long q){
    while(q > 1){
      if(q % 2 != 0)
        return false;
      q /= 2;
    }
    return true;
  }
}
