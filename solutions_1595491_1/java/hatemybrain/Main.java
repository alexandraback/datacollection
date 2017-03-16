import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;

import com.google.common.base.Charsets;
import com.google.common.base.Predicate;
import com.google.common.collect.Collections2;
import com.google.common.io.Files;

public class Main {
  
  static String[] ins = new String[] {
      "yeqz",
      "ejp mysljylc kd kxveddknmc re jsicpdrysi",
      "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
      "de kr kd eoya kw aej tysr re ujdr lkgc jv"
  };

  static String[] outs = new String[] {
      "aozq",
      "our language is impossible to understand",
      "there are twenty six factorial possibilities",
      "so it is okay if you want to just give up"
  };
  
  public static void main(String[] args) throws IOException {

//    File f = new File("B-small-attempt0.in");
//    File f = new File("B-small-attempt2.in");
    File f = new File("B-large.in");
//    File f = new File("A-large-practice.in");
//    File f = new File("example.in");
//    File f = new File("test.in");
    List<String> lines = Files.readLines(f, Charsets.UTF_8);

    int cases = Integer.valueOf(lines.get(0));
    int c = 0;
    while (c < cases) {
      c++;
      String[] tokens = lines.get(c).split(" ");
      int n = Integer.valueOf(tokens[0]);
      int s = Integer.valueOf(tokens[1]);
      int p = Integer.valueOf(tokens[2]);
//      System.out.println(lines.get(c));
//      System.out.printf("%d %d\n", s, p);
      
      int[] g = new int[n];
      int result = 0;
      for (int i = 0; i < n; i++) {
        int score = Integer.valueOf(tokens[3 + i]);
        int mod = mod(score, 3); 
        int a = 0;
        int b = 0;
        switch (score) {
          case 0: a = 0; b = 0; break;
          case 1: a = 1; b = 0; break;
          case 2: a = 1; b = 2;
            break;
          default:
            switch (score % 3) {
              case 0: a = mod + 0; b = mod + 1;  break;
              case 1: a = mod + 1; b = mod + 1;  break;
              case 2: a = mod + 1; b = mod + 2;  break;
            }
        }
        if (a > 10) a = 10;
        if (b > 10) b = 10;
//        System.out.printf("%d (%d, %d) ", score, a, b);
        if (a >= p) {
          result++;
          continue;
        }
        if (s > 0 && b >= p) {
          result++;
          --s;
        }
      }
      
//      System.out.println();
      System.out.println("Case #" + c + ": " + result);
      
    }
  }
  
  static int mod(int a, int b) {
    return ((a - (a % b)) / b);
  }
}