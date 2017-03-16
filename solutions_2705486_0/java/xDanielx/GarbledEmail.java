import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.AbstractMap;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class GarbledEmail {
  private static final int INFINITY = 10000;
  private static final Set<String> dictionarySet = readDictionary();
  private static final Trie dictionaryTrie = buildTrie(dictionarySet);

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt(); sc.nextLine();
    for (int t = 1; t <= T; ++t) {
      String s = sc.nextLine();
      System.out.printf("Case #%d: %d\n", t, minChanges(s, ""));
    }
    int x = 0;
  }

  private static Map<Map.Entry<String, String>, Integer> mem =
      new HashMap<Map.Entry<String, String>, Integer>();

  private static int minChanges(String s, String prefix) {
    Map.Entry<String, String> key = new AbstractMap.SimpleEntry<String, String>(s, prefix);
    if (mem.containsKey(key))
      return mem.get(key);

    int min = INFINITY;
    for (int l = 1; l <= prefix.length(); ++l) {
      String word = prefix.substring(0, l);
      if (dictionarySet.contains(word)) {
        String newPrefix = prefix.substring(word.length());
        min = Math.min(min, minChanges(s, newPrefix));
      }
    }

    if (s.isEmpty()) {
      if (prefix.isEmpty())
        min = 0;
    } else {
      Trie child = dictionaryTrie.getChild(prefix);
      if (child != null) {
        for (char c : dictionaryTrie.children.keySet()) {
          boolean isReplacement = c != s.charAt(0);
          if (isReplacement) {
            int toMove = Math.min(5, s.length());
            String newPrefix = prefix + c + s.substring(1, toMove);
            //if (dictionaryTrie.getChild(newPrefix) != null)
              min = Math.min(min, 1 + minChanges(s.substring(toMove), newPrefix));
          } else {
            min = Math.min(min, minChanges(s.substring(1), prefix + c));
          }
        }
      }
    }

    mem.put(key, min);
    return min;
  }

  private static abstract class Trie {
    final Map<Character, Trie> children = new HashMap<Character, Trie>();

    void add(String word) {
      char c = word.charAt(0);
      if (!children.containsKey(c))
        children.put(c, new NonRootTrie(c));
      if (word.length() > 1)
        children.get(c).add(word.substring(1));
    }

    Trie getChild(String prefix) {
      if (prefix.isEmpty())
        return this;
      if (!children.containsKey(prefix.charAt(0)))
        return null;
      return children.get(prefix.charAt(0)).getChild(prefix.substring(1));
    }
  }

  static class RootTrie extends Trie {
  }

  static class NonRootTrie extends Trie {
    final char character;

    NonRootTrie(char character) {
      this.character = character;
    }
  }

  private static Set<String> readDictionary() {
    Set<String> dictionary = new HashSet<String>(521196);
    try {
      BufferedReader reader = new BufferedReader(new InputStreamReader(
          new FileInputStream("garbled_email_dictionary.txt")));
      String word;
      while ((word = reader.readLine()) != null)
        dictionary.add(word);
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
    return dictionary;
  }

  private static Trie buildTrie(Set<String> dictionary) {
    Trie trie = new RootTrie();
    for (String word : dictionary)
      trie.add(word);
    return trie;
  }
}
