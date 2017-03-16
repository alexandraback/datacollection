import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  long solve(long R, long V) {

    long ret = 0;

    long min = 1;
    long max = V;

    for(int i=0; i<200; ++i) {
      long mid = (min + max) / 2;
      if( (R * 2 + mid * 2 - 1) <= V / mid ) {
        min = mid;
      }
      else { max = mid; }
    }

    return min;

  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      long R = cin.nextLong();
      long V = cin.nextLong();

      System.out.println("Case #" + C + ": " + solve(R, V));

    }

  }

}
