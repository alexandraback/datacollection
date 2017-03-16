import static java.util.stream.Collectors.*;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Stream;

public class Dijkstra {
  public static void main(String[] args) throws IOException {
    try (Stream<String> lines = Files.lines(Paths.get("CodeJam/in/C-small-attempt2.in"))) {
      List<String> inputs = lines.collect(toList());
      int count = Integer.parseInt(inputs.get(0));
      for (int i = 0; i < count; i++) {
        long repeat = Long.parseLong(inputs.get(i * 2 + 1).split("\\s")[1]);

        boolean result = solve(inputs.get(i * 2 + 2), repeat);
        System.out.println("Case #" + (i + 1) + ": " + (result ? "YES" : "NO"));
      }
    }
  }

  static class Pair {
    int positive;
    String value;

    public Pair(int positive, String value) {
      this.positive = positive;
      this.value = value;
    }
  }

  static Map<String, Pair> data = new HashMap<>();

  static {
    data.put("11", new Pair(1, "1"));
    data.put("1i", new Pair(1, "i"));
    data.put("1j", new Pair(1, "j"));
    data.put("1k", new Pair(1, "k"));

    data.put("i1", new Pair(1, "i"));
    data.put("ii", new Pair(-1, "1"));
    data.put("ij", new Pair(1, "k"));
    data.put("ik", new Pair(-1, "j"));

    data.put("j1", new Pair(1, "j"));
    data.put("ji", new Pair(-1, "k"));
    data.put("jj", new Pair(-1, "1"));
    data.put("jk", new Pair(1, "i"));

    data.put("k1", new Pair(1, "k"));
    data.put("ki", new Pair(1, "j"));
    data.put("kj", new Pair(-1, "i"));
    data.put("kk", new Pair(-1, "1"));
  }

  static Pair cal(Pair a, String b) {
    Pair r = data.get(a.value + b);
    return new Pair(a.positive * r.positive, r.value);
  }

  static Pair cal(Pair a, Pair b) {
    Pair r = data.get(a.value + b.value);
    return new Pair(a.positive * b.positive * r.positive, r.value);
  }

  private static Pair cal(String a, Pair b) {
    Pair r = data.get(a + b.value);
    return new Pair(b.positive * r.positive, r.value);
  }

  private static boolean solve(String s, long repeat) {
    Pair p = new Pair(1, "1");
    for (int i = 0; i < s.length(); ++i) {
      p = cal(p, String.valueOf(s.charAt(i)));
    }
    Pair perL = p;

    int b = -1;
    p = new Pair(1, "1");
    for (int i = 0; i < s.length() * 4; ++i) {
      p = cal(p, String.valueOf(s.charAt(i % s.length())));
      if (p.value.equals("i") && p.positive > 0) {
        b = i;
        break;
      }
    }
    if (b == -1) {
      return false;
    }
    int e = -1;
    p = new Pair(1, "1");
    for (int i = 0; i < s.length() * 4; ++i) {
      p = cal(String.valueOf(s.charAt(s.length() - 1 - i % s.length())), p);
      if (p.value.equals("k") && p.positive > 0) {
        e = i;
        break;
      }
    }
    if (e == -1) {
      return false;
    }
    if (s.length() * repeat <= b + e + 1 + 1) {
      return false;
    }
    long remainCount = s.length() * repeat - (b + e + 1 + 1);
    long small = remainCount % (s.length() * 4);

    p = new Pair(1, "1");
    for (int i = 0; i < small; i++) {
      p = cal(p, String.valueOf(s.charAt((b + 1 + i) % s.length())));
    }
    if (p.positive > 0 && p.value.equals("j")) {
      return true;

    }

    return false;
  }

}
