import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class BSmall {

  static final String FILENAME = "B-small-attempt2";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;
  
  int best;
  char[] bc;
  char[] bj;
  
  private void work(char[] a, char[] b) {
    int mark = -1;
    for(int i = 0; i < a.length; i++) {
      if(a[i] == '?') {
        mark = i;
        break;
      }
    }
    if(mark != -1) {
      for(int x = 0; x < 10; x++) {
        a[mark] = (char)((int)'0' + x);
        work(a, b);
      }
      a[mark] = '?';
    } else {
      for(int i = 0; i < a.length; i++) {
        if(b[i] == '?') {
          mark = i;
          break;
        }
      }
      if(mark != -1) {
        for(int x = 0; x < 10; x++) {
          b[mark] = (char)((int)'0' + x);
          work(a, b);
        }
        b[mark] = '?';
      } else {
        int d = Math.abs(Integer.parseInt(new String(a)) - Integer.parseInt(new String(b)));
        if(d < best) {
          best = d;
          for(int i = 0; i < a.length; i++) {
            bc[i] = a[i];
            bj[i] = b[i];
          }
        }
      }
    }
  }
  
  private void solve() throws IOException {
    char[] c = sc.next().toCharArray();
    char[] j = sc.next().toCharArray();
    best = 1000;
    bc = new char[c.length];
    bj = new char[c.length];
    work(c, j);
    out.write(new String(bc));
    out.write(" ");
    out.write(new String(bj));
    out.newLine();
  }

  private void run() throws IOException {
    sc = new Scanner(new File(IN));
    out = new BufferedWriter(new FileWriter(OUT));
    int t = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      out.write("Case #" + i + ": ");
      solve();
    }
    sc.close();
    out.close();
  }

  public static void main(String args[]) throws Exception {
    new BSmall().run();
  }
}
