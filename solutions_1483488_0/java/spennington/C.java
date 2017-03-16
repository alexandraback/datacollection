import java.util.Scanner;

public class C {
  
  public static void output(int T, int recycles) {
    System.out.print(String.format("Case #%d: ", T));
    System.out.print(recycles);
    System.out.println();
  }
  
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    in.nextLine();
  
    for (int i=0; i<T; i++) {
      int A = in.nextInt();
      int B = in.nextInt();
      int recycles = 0;
      
      for (int n=A; n<B; n++) {
        String a = Integer.toString(n);
        for (int k=0; k<a.length(); k++) {
          int m = Integer.parseInt(a);
          if (m > n && m <= B) {
            recycles++;
          }
          a = a.substring(1) + a.substring(0, 1);
          m = Integer.parseInt(a);
          if (m == n) {
            break;
          }
        }
      }
      
      output(i + 1, recycles);
    }
  }
}
