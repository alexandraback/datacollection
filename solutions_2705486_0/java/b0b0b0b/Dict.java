package r1b.c;

import java.io.*;
import java.util.*;

public class Dict {
  static PrintStream out;
  public static final void main(String[]args)throws Exception{
    Scanner s = new Scanner(new File(args[0]));
    out = new PrintStream(new FileOutputStream(args[0]+".out"));
    List<String> dict = new ArrayList<>();
    int b = 0;
    int maxlen = 0;
    try (BufferedReader r = new BufferedReader(new InputStreamReader(Dict.class.getClassLoader().getResourceAsStream("r1b/c/garbled_email_dictionary.txt")))) {
      String line;
      while (null != (line = r.readLine())) {
        b += line.length() + 1;
        dict.add(line);
        if (line.length() > maxlen) maxlen = line.length();
      }
    }

    FatTrie head = new FatTrie(null);
    head.head = head;
    for (String str : dict) {
      head.add(str);
    }

//    System.out.println(dict.size() + " " + b);
    int T = s.nextInt();
    for (int t=0; t<T; t++) {
      String S = s.next();
      println("Case #" + (t+1)+": " + foo(S, head));
    }
    s.close();
    out.close();
  }

  static class FatTrie {
    FatTrie head;
    FatTrie[] next = new FatTrie[26];
    boolean end;
    public FatTrie(FatTrie head) {
      this.head = head;
    }
    void add(String str) {
      if (str.length() == 0) {
        end =true;
        return;
      }
      char ch = str.charAt(0);
      int idx = ch - 'a';
      if (next[idx] == null) next[idx] = new FatTrie(head);
      next[idx].add(str.substring(1));
    }

    public boolean accept(String mangled, Set<String> fail) {
      if (mangled.length() == 0) return end;
      char ch = mangled.charAt(0);
      if (end) {
        if (head != this) {
          if (!fail.contains(mangled)) {
            if (head.accept(mangled, fail)) return true;
            //fail.add(mangled);
          }
        }
      }
      if (ch == '.') {
        for (int idx=0;idx<26;idx++) {
          if (next[idx] != null && next[idx].accept(mangled.substring(1), fail)) return true;
        }
        return false;
      }
      int idx = ch - 'a';
      if (next[idx] == null) return false;
      return next[idx].accept(mangled.substring(1), fail);
    }
  }

  private static int foo(String orig, FatTrie dict) {
    for (int edits = 0; edits < orig.length(); edits++) {
      Set<String> edited = edit(edits, orig);
      if (edited.size() == 0) break;
//      System.out.println(edits+" " + edited.size());
      for (String mangled : edited) {
//        System.out.println(mangled);
        if (dict.accept(mangled, new HashSet<String>())) return edits;
      }
    }
    return -1;//throw new Error();
  }

  private static Set<String> edit(int edits, String orig) {
    Set<String> list = new HashSet<>();
    derp(edits, orig, list, 0);
    return list;
  }


  private static void derp(int edits, String word, Set<String> list, int begin) {
    if (edits == 0) {
      list.add(word);
      return;
    }
    if(begin >= word.length()) return;

    for (int i = begin; i < word.length(); i++) {
      derp(edits - 1, twiddle(word, i), list, i + 5);
    }
  }


  private static String twiddle(String word, int i) {
    if (i == 0) {
      return "." + word.substring(i+1);
    }
    return word.substring(0, i) + "." + word.substring(i+1);
  }


  public static void println(String s) throws Exception {
    System.out.println(s);
    out.println(s);
  }

}
