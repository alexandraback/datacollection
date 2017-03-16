import java.util.*;

public class B {

  public static void main(String[] args) {
    new B();
  }
  
  public B() {
    Scanner scan = new Scanner(System.in);
    int NCASES = scan.nextInt();
    for (int ZZ = 1; ZZ <= NCASES; ZZ++) {
      System.out.print("Case #"+ZZ+": ");
      int N = scan.nextInt();
      int S = scan.nextInt();
      int p = scan.nextInt();
      int count = 0;
      for (int i = 0; i < N; i++) {
        int t = scan.nextInt();
        if (t < p) continue;
        if (t > (p-1)*3) {
          count++;
        } else if (t >= p*3-4 && S > 0) {
          count++;
          S--;
        }
      }
      System.out.println(count);
    }
  }
  
}
