import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import com.google.common.base.Charsets;
import com.google.common.base.Predicate;
import com.google.common.collect.ArrayListMultimap;
import com.google.common.collect.Collections2;
import com.google.common.collect.HashMultimap;
import com.google.common.collect.Multimap;
import com.google.common.io.Files;

public class Main {
  
  public static void main(String[] args) throws IOException {

//    File f = new File("C-small-attempt0.in");
    File f = new File("C-small-attempt1.in");
//    File f = new File("C-small-attempt2.in");
//    File f = new File("C-large.in");
//    File f = new File("B-large.in");
//    File f = new File("A-large-practice.in");
//    File f = new File("example.in");
//    File f = new File("test.in");
    List<String> lines = Files.readLines(f, Charsets.UTF_8);

    int cases = Integer.valueOf(lines.get(0));
    int c = 0;
    while (c < cases) {
      int result = 0;
      c++;
      String[] tokens = lines.get(c).split(" ");
      int a = Integer.valueOf(tokens[0]);
      int b = Integer.valueOf(tokens[1]);
      
      Set<Integer> set = new HashSet<Integer>();
      for(int n = a; n < b; n++) {
        set.clear();
        String s = "" + n;
//        System.out.println(" >> " + s);
        int sl = s.length();
        for (int i = 0; i < sl; i++) {
          Integer shifted = shift(s, i);
          if (shifted != null && shifted <= b && shifted > n) {
//            System.out.println(shifted);
            set.add(shifted);
          }
        }
        result += set.size();
      }
      
      System.out.println("Case #" + c + ": " + result);
    }
  }

  private static Integer shift(String n, int i) {
    i++;
    int l = n.length();
    String s = n.substring(l - i, l) + n.substring(0,l - i);
    if (s.compareTo(n) <= 0) {
      return null;
    } else {
      return Integer.valueOf(s);
    }
  }

}