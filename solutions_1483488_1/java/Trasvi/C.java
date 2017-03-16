import java.util.*;

public class C {

  public static void main(String[] args) {
    new C();
  }
  
  private Set<Integer> NUMSET;
  
  public C() {
    Scanner scan = new Scanner(System.in);
    
    int NCASES = scan.nextInt();
    for (int ZZ = 1; ZZ <= NCASES; ZZ++) {
      int A = scan.nextInt();
      int B = scan.nextInt();
      NUMSET = new TreeSet<Integer>();
      int nDigits = String.valueOf(A).length();
      long count = 0;
      for (int i = A; i <= B; i++) {
        count += rot(i, A, B, nDigits);
      }
      System.out.println("Case #"+ZZ+": "+count);
    }
  }
  
  private int rot(int num, int min, int max, int len) {
    NUMSET.clear();
    for (int i = 1; i < len; i++) {
      int divisor = (int) (Math.pow(10, i));
      int mult = (int) (Math.pow(10, len-i));
      int one = num / divisor;
      int two = (num % divisor)*mult;
      int next = two+one;
      if (next > num && next <= max) {
        NUMSET.add(next);
      }
    }
    return NUMSET.size();
  }

}