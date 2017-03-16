import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class CFairAndSquareMid {
  Scanner in;

  public static void main(String[] args) throws Exception {
    new CFairAndSquareMid().run();
  }

  private void run() throws Exception{
    System.setIn(new FileInputStream("C-small-attempt0.in"));
    //System.setIn(new FileInputStream("C-large.in"));
    System.setOut(new PrintStream("C-small-attempt0.out"));
    in = new Scanner(System.in);
    int cases = in.nextInt();
    for (int C = 1; C <=cases; ++C)
      System.out.println(String.format("Case #%d: %d", C, count(in.nextLong(), in.nextLong())));

  }

  long count(long A, long B) {
    long res = 0;
    for(long b = 1; b*b<=B; b++) {
      if(b*b < A) continue;
      if(isPal(b) && isPal(b*b)) res ++;
    }
    return res;
  }

  long reverse(long n) {
    long res = 0;
    while(n>0) {
      res *=10;
      res += n%10;
      n/=10;
    }
    return res;
  }
  boolean isPal(long n) {
    return n == reverse(n);
  }
}
