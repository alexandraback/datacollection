import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class bullseye {
  
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("bullseye.in"));
    PrintWriter out = new PrintWriter(new File("bullseye.out"));
    int cases = in.nextInt();
    int caseOn = 1;
    while (cases-- != 0) {
      int r = in.nextInt();
      int t = in.nextInt();
      int cnt = 0;
      while (true) {
        long area = area(r);
        if (t >= area) {
          t -= area;
          cnt++;
        } else {
          break;
        }
        r += 2;
      }
      
      out.printf("Case #%d: %d\n", caseOn++, cnt);
    }
    
    out.close();
  }
  
  public static long area(int r) {
    return ((r + 1) * (r + 1) - r * r);
  }
}
