import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {

  static final String FILENAME = "A-small-attempt0";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;

  private void cancel(int[] cnt, int t, String word) {
    for(int i = 0; i < word.length(); i++) {
      cnt[(int)word.charAt(i) - (int)'A'] -= t;
    }
  }
  
  private void solve() throws IOException {
    String str = sc.next();
    int[] cnt = new int[26];
    for(int i = 0; i < str.length(); i++) {
      cnt[(int)str.charAt(i) - (int)'A']++;
    }
    int[] num = new int[10];
    num[0] = cnt[(int)'Z' - (int)'A'];
    cancel(cnt, num[0], "ZERO");
    num[2] = cnt[(int)'W' - (int)'A'];
    cancel(cnt, num[2], "TWO");
    num[4] = cnt[(int)'U' - (int)'A'];
    cancel(cnt, num[4], "FOUR");
    num[6] = cnt[(int)'X' - (int)'A'];
    cancel(cnt, num[6], "SIX");
    num[5] = cnt[(int)'F' - (int)'A'];
    cancel(cnt, num[5], "FIVE");
    num[7] = cnt[(int)'V' - (int)'A'];
    cancel(cnt, num[7], "SEVEN");
    num[1] = cnt[(int)'O' - (int)'A'];
    cancel(cnt, num[1], "ONE");
    num[8] = cnt[(int)'G' - (int)'A'];
    cancel(cnt, num[8], "EIGHT");
    num[3] = cnt[(int)'T' - (int)'A'];
    cancel(cnt, num[3], "THREE");
    num[9] = cnt[(int)'I' - (int)'A'];
    cancel(cnt, num[9], "NINE");
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < num[i]; j++) {
        out.write(Integer.toString(i));
      }
    }
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
    new A().run();
  }
}
