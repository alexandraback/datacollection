import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Digits implements Runnable {
  private static final String NAME = "digits";

  private static String[] d = new String[] {
      "ZERO",
      "ONE",
      "TWO",
      "THREE",
      "FOUR",
      "FIVE",
      "SIX",
      "SEVEN",
      "EIGHT",
      "NINE"
  };

  void dec(String s, int num, int[] c) {
    for (int i = 0; i < s.length(); i++) {
      c[s.charAt(i) - 'A'] -= num;
    }
  }

  void unique(char ch, String s, int d, int[] c, int[] r) {
    r[d] = c[ch - 'A'];
    dec(s, r[d], c);
  }

  String solve(String s) {
    int[] r = new int[10];
    int[] c = new int[26];
    for (int i = 0; i < s.length(); i++) {
      c[s.charAt(i) - 'A']++;
    }
    unique('Z', "ZERO", 0, c, r);
    unique('W', "TWO", 2, c, r);
    unique('U', "FOUR", 4, c, r);
    unique('F', "FIVE", 5, c, r);
    unique('X', "SIX", 6, c, r);
    unique('V', "SEVEN", 7, c, r);
    unique('G', "EIGHT", 8, c, r);
    unique('I', "NINE", 9, c, r);
    unique('O', "ONE", 1, c, r);
    unique('T', "THREE", 3, c, r);

    String res = "";
    for (int i = 0; i < r.length; i++) {
      for (int j = 0; j < r[i]; j++) {
        res += i;
      }
    }
    return res;
  }

  @Override
  public void run() {
    try {
      BufferedReader in = new BufferedReader(new FileReader(new File(NAME + ".in")));

      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = Integer.parseInt(in.readLine());

      for (int test = 1; test <= tests; test++) {
        //put solution here
        out.println("Case #" + test + ": " + solve(in.readLine()));
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
//    Set<String> get = new HashSet<String>();
//    while (true) {
//      for (String s : d) {
//        if (get.contains(s)) {
//          continue;
//        }
//        for (int i = 0; i < s.length(); i++) {
//          char c = s.charAt(i);
//          boolean u = true;
//          for (String ss : d) {
//            if (ss != s && !get.contains(ss) && ss.contains("" + c)) {
//              u = false;
//            }
//          }
//          if (u) {
//            get.add(s);
//            System.out.println(s + " unique " + c);
//          }
//        }
//      }
//    }
    new Thread(new Digits()).start();
  }
}
