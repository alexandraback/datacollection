import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class SpeakingInTongues {
  private static char[] letters = new char[26];
  private static char EmptyChar = Character.UNASSIGNED;
  static {
    char a = 'a';
    char z = 'z';
    int j = 0;
    for (char i = a; i <= z; ++i) {
      letters[j++] = i;
    }
  }

  private Map<Character, Character> dic;

  public SpeakingInTongues(Map<Character, Character> dic) {
    this.dic = dic;
  }

  public String solve(String googlerese) {
    StringBuffer strBuffer = new StringBuffer();
    char[] gCs = googlerese.toCharArray();
    for (char c : gCs) {
      Character e = dic.get(c);
      if (e == null) {
        strBuffer.append("?");
      } else {
        strBuffer.append(e);
      }
    }
    return strBuffer.toString();
  }

  public static void train(Map<Character, Character> dic, String googlerese, String english) {
    char[] gCs = googlerese.toCharArray();
    char[] eCs = english.toCharArray();
    for (int i=0; i < gCs.length; ++i) {
      dic.put(gCs[i], eCs[i]);
    }
  }
  

  public static void main(String[] args) throws IOException {
    Map<Character, Character> dic = new HashMap<Character, Character>();
    train(dic, "ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
    train(dic, "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
    train(dic, "de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
//    Set<Character> missingGr = new HashSet<Character>();
//    Set<Character> missingEg = new HashSet<Character>();
//    for (char c : letters) {
//      if (!dic.keySet().contains(c)) {
//        missingGr.add(c);
//      }
//      if (!dic.values().contains(c)) {
//        missingEg.add(c);
//      }
//    }
//    System.out.println(missingGr);
//    System.out.println(missingEg);
    //[q -> z, z -> q]
    dic.put('q', 'z');
    dic.put('z', 'q');

    SpeakingInTongues solver = new SpeakingInTongues(dic);

    BufferedReader reader = new BufferedReader(new FileReader("A-small-attempt2.in"));
    String str;
    int lineNum = 0, caseNum = 1;
    BufferedWriter writer = new BufferedWriter(new FileWriter("A-small-attempt2.out"));
    lineNum = Integer.valueOf(reader.readLine());
    while ((str = reader.readLine()) != null) {
      writer.write(String.format("Case #%d: %s\n", caseNum++, solver.solve(str)));
    }
    writer.flush();
    writer.close();
  }
}
