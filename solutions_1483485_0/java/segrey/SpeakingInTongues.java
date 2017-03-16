import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class SpeakingInTongues {

  BufferedReader br;
  StringTokenizer st = new StringTokenizer("");

  private void solve() throws IOException {
//    final String IO_FILE = null;
    final String IO_FILE = "./A/A-small-attempt0";
    final PrintWriter pw;
    if (IO_FILE == null) {
      br = new BufferedReader(new InputStreamReader(System.in));
      pw = new PrintWriter(System.out);
    } else {
      br = new BufferedReader(new FileReader(IO_FILE + ".in"));
      pw = new PrintWriter(IO_FILE + ".out");
    }
    Map<Character, Character> mapping = buildMapping();
    int testCases = nextInt();
    for (int ti = 1; ti <= testCases; ti++) {
      String line = br.readLine();
      String ans = translate(mapping, line);
      pw.println("Case #" + ti + ": " + ans);
    }
    br.close();
    pw.close();
  }

  private String translate(Map<Character, Character> mapping, String line) {
    StringBuilder out = new StringBuilder();
    for (int i = 0; i < line.length(); i++) {
      char ch = line.charAt(i);
      if (ch == ' ') {
        out.append(' ');
      } else {
        out.append(mapping.get(ch));
      }
    }
    return out.toString();
  }

  private Map<Character, Character> buildMapping() {
    Map<Character, Character> mapping = new HashMap<Character, Character>();
    String[][] pairs = {
        {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand"},
        {"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities"},
        {"de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up"},
        {"y qee", "a zoo"}
    };
    for (String[] pair : pairs) {
      if (pair[0].length() != pair[1].length()) {
        throw new RuntimeException();
      }
      for (int i = 0; i < pair[0].length(); i++) {
        char from = pair[0].charAt(i);
        char to = pair[1].charAt(i);
        if (from == ' ') {
          if (to != ' ') {
            throw new RuntimeException();
          }
          continue;
        }
        if (mapping.containsKey(from)) {
          char was = mapping.get(from);
          if (was != to) {
            throw new RuntimeException();
          }
        } else {
          mapping.put(from, to);
        }
      }
    }

    if (mapping.size() == 'z' - 'a') {
      int keySum = 0;
      int valueSum = 0;
      for (Map.Entry<Character, Character> entry : mapping.entrySet()) {
        keySum += entry.getKey();
        valueSum += entry.getValue();
      }
      int fullSum = 0;
      for (char ch = 'a'; ch <= 'z'; ch++) {
        fullSum += ch;
      }
      mapping.put((char) (fullSum - keySum), (char) (fullSum - valueSum));
    }
    for (char ch = 'a'; ch <= 'z';ch++) {
      if (!mapping.containsKey(ch)) {
        throw new RuntimeException("Mapping misses " + ch);
      }
    }
    return mapping;
  }

  String nextString() throws IOException {
    while (!st.hasMoreTokens()) {
      st = new StringTokenizer(br.readLine());
    }
    return st.nextToken();
  }

  int nextInt() throws IOException {
    return Integer.parseInt(nextString());
  }

  public static void main(String[] args) throws IOException {
    new SpeakingInTongues().solve();
  }
}
