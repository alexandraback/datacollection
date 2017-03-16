import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class C {

  static final String FILENAME = "C-small";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;

  private void printNum(boolean[] num) throws IOException {
    for(int i = 7; i >= 0; i--) {
      out.write(num[i] ? "1" : "0");
    }
    for(int i = 7; i >= 0; i--) {
      out.write(num[i] ? "1" : "0");
    }
  }
  
  private void increase(boolean[] num) {
    for(int i = 1; i < 7; i++) {
      if(num[i]) {
        num[i] = false;
      } else {
        num[i] = true;
        break;
      }
    }
  }
  
  private int pow(int a, int n) {
    int ans = 1;
    for(int i = 0; i < n; i++) {
      ans *= a;
    }
    return ans;
  }
  
  private void solve() throws IOException {
    int J = 50;
    boolean[] num = new boolean[8];
    num[0] = num[7] = true;
    for(int i = 0; i < J; i++) {
      printNum(num);
      for(int b = 2; b <= 10; b++) {
        out.write(" ");
        out.write(Integer.toString(pow(b, 8) + 1));
      }
      out.newLine();
      increase(num);
    }
  }

  private void run() throws IOException {
    sc = new Scanner(new File(IN));
    out = new BufferedWriter(new FileWriter(OUT));
    int t = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      out.write("Case #" + i + ": ");
      out.newLine();
      solve();
    }
    sc.close();
    out.close();
  }

  public static void main(String args[]) throws Exception {
    new C().run();
  }
}
