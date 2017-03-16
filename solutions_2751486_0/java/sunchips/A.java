package round1c;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
  public static void main(String[] args) throws Exception, IOException {
    String round = "round1c";
    String question = "A";
    String type = "small";
    String attempt = "0";
    boolean practice = false;

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    if (practice) {
      out = new PrintWriter(new FileWriter(round + "/" + question + "-" + type + "-practice.out"));
      br = new BufferedReader(new FileReader(round + "/" + question + "-" + type + "-practice.in"));
    } else {
      if (type.equals("small")) {
        out = new PrintWriter(new FileWriter(round + "/" + question + "-" + type + "-attempt" + attempt + ".out"));
        br = new BufferedReader(new FileReader(round + "/" + question + "-" + type + "-attempt" + attempt + ".in"));
      } else {
        out = new PrintWriter(new FileWriter(round + "/" + question + "-" + type + ".out"));
        br = new BufferedReader(new FileReader(round + "/" + question + "-" + type + ".in"));
      }
    }

    int cases = Integer.parseInt(br.readLine());
    for (int zz = 1; zz <= cases; zz++) {
      st = new StringTokenizer(br.readLine().trim().toLowerCase());
      char[] word = st.nextToken().toCharArray();
      int n = Integer.parseInt(st.nextToken());

      long ans = 0;
      for (int i = 0; i <= word.length; i++) {
        for (int j = i + 1; j <= word.length; j++) {
          //System.out.print(i+ " " + j + " ");
          if (performTest(word, i, j, n)) {
            ans++;
            //System.out.print("T");
          }
          //System.out.println();
        }
      }

      out.println("Case #" + zz + ": " + ans);
      //System.out.println();
    }
    out.close();
    br.close();
  }

  private static boolean performTest(char[] word, int i, int j, int n) {
    if (j - i < n)
      return false;

    for (int zz = i; zz < j; zz++) {
      boolean found = true;
      if (zz + n - 1 > word.length - 1 || j - zz < n)
        continue;
      for (int xx = zz; xx < zz + n && found; xx++) {
        found &= isConsonant(word[xx]);
      }
      if (found)
        return true;
    }
    return false;
  }

  private static boolean isConsonant(char c) {
    return !isVowel(c);
  }

  private static boolean isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
}
