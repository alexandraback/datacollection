import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * Created by kojilin on 2014/05/11.
 */
public class ReorderingTrainCars {

  public static void main(String[] args) throws IOException {
    Path path = FileSystems.getDefault().getPath("GCJ", "rtc.txt");
    List<String> lines = Files.lines(path).collect(Collectors.toList());
    int testCases = Integer.parseInt(lines.get(0));

    for (int i = 0; i < testCases; ++i) {
      int s = Integer.parseInt(lines.get(i * 2 + 1));
      String[] blocks = lines.get(i * 2 + 2).split("\\s");

      System.out.println("Case #" + (i + 1) + ": " + solve(new ArrayList<>(), blocks));
    }
  }

  private static class StringW {

    String content;

    public StringW(final String block) {
      content = block;
    }

    boolean isSame() {
      for (int i = 0; i < content.length(); ++i) {
        if (content.charAt(i) != content.charAt(0)) {
          return false;
        }
      }
      return true;
    }

    boolean isSame(String s) {
      for (int i = 0; i < content.length(); ++i) {
        if (content.charAt(i) != s.charAt(0)) {
          return false;
        }
      }
      return true;
    }
  }

  private static String solve(final List<Integer> used, final String[] blocks) {

    //    List<StringW> strings = new ArrayList<>();
    //    for (int i = 0; i < blocks.length; i++) {
    //      strings.add(new StringW(blocks[i]));
    //    }
    //    int count = 1;
    //    List<StringW> remain = new ArrayList<>();
    //    List<StringW> filtered = new ArrayList<>();
    //    for (int i = 0; i < strings.size(); i++) {
    //      final StringW string = strings.get(i);
    //      if(filtered.contains(string)){
    //        continue;
    //      }
    //      List<StringW> all = new ArrayList<>();
    //      if (string.isSame()) {
    //        filtered.add(string);
    //        all.add(string);
    //        for (int j = i + 1; j < strings.size(); j++) {
    //          final StringW target = strings.get(j);
    //          if (target.isSame(string.content)) {
    //            all.add(target);
    //            filtered.add(target);
    //          }
    //        }
    //      }
    //    }

    //    for (int i = 0; i < blocks.length; ++i) {
    //      if (!used.contains(i)) {
    //        ArrayList<Integer> used1 = new ArrayList<>(used);
    //        used.add(i);
    //        dosolve(used1, blocks);
    //      }
    //    }

    return "" + dosolve(used, blocks);
  }

  private static int dosolve(final List<Integer> used, final String[] blocks) {
    if (used.size() == blocks.length) {
      return isOk(used, blocks) ? 1 : 0;
    }
    int count = 0;
    for (int i = 0; i < blocks.length; ++i) {
      if (!used.contains(i)) {
        ArrayList<Integer> used1 = new ArrayList<>(used);
        used1.add(i);
        count += dosolve(used1, blocks);
      }
    }
    return count;
  }

  private static boolean isOk(final List<Integer> used, final String[] blocks) {
    String result = "";
    for (Integer integer : used) {
      result += blocks[integer];
    }

    Set<Character> chars = new HashSet<>();
    Character last = null;
    for (int i = 0; i < result.length(); ++i) {
      char c = result.charAt(i);

      if (chars.contains(c)) {
        return false;
      }

      if (last == null) {
        last = c;
        continue;
      }
      if (last.charValue() != c) {
        chars.add(last);
        last = c;
      }
    }
    return true;
  }
}
