/*
 * This submission is using the template from https://github.com/krka/codejamjavatemplate
 * Dependencies: standard java, google guava
 * Revision: e20bb6576d30168d022a1af95aa1be5d1bd35e4a
 */

import com.google.common.collect.Lists;
import com.google.common.collect.Maps;
import com.google.common.collect.Multiset;
import com.google.common.collect.Sets;
import com.google.common.collect.TreeMultiset;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class B {
  private static final String INPUT = null; // override to use a specific input (i.e. "small-1", "large-2", "sample", "stdin").

  public static void main(String[] args) throws Exception {
    new B().run();
  }

  private final PrintStream out;
  private final BufferedReader reader;
  private StringTokenizer tokenizer = new StringTokenizer("");

  public B() throws Exception {
    String problem = getClass().getSimpleName();
    if (INPUT == null) {
      File input = findInput(problem);
      if (input == null) {
        throw new IOException("No input file found");
      }
      File output = new File(input.getParent(), input.getName().replace(".in", ".out"));
      System.err.println("input:  " + input.getPath());
      System.err.println("output: " + output.getPath());
      out = new PrintStream(new FileOutputStream(output));
      reader = new BufferedReader(new FileReader(input));
    } else if (INPUT.equals("stdin")) {
      System.err.println("input:  stdin");
      System.err.println("output: stdout");
      out = System.out;
      reader = new BufferedReader(new InputStreamReader(System.in));
    } else {
      System.err.println("input:  " + problem + "-" + INPUT + ".in");
      System.err.println("output: " + problem + "-" + INPUT + ".out");
      out = new PrintStream(new FileOutputStream("source/" + problem + "-" + INPUT + ".out"));
      reader = new BufferedReader(new FileReader("source/" + problem + "-" + INPUT + ".in"));
    }
  }

  public static File findInput(String problem) throws Exception {
    File dir = new File("source");
    long bestTimestamp = -1;
    File bestFile = null;
    for (File file : dir.listFiles()) {
      if (file.getName().startsWith(problem + "-") && file.getName().endsWith(".in")) {
        long timestamp = file.lastModified();
        if (timestamp > bestTimestamp) {
          bestTimestamp = timestamp;
          bestFile = file;
        }
      }
    }
    return bestFile;
  }

  public void run() {
    try {
      runCases();
    } finally {
      out.close();
    }
  }

  public void debug(String s, Object... args) {
    System.err.printf("DEBUG: " + s + "\n", args);
  }

  private void runCases() {
    try {
      int cases = getInt();
      for (int c = 1; c <= cases; c++) {
        try {
          String answer = new Solver(c).solve();
          String s = "Case #" + c + ": " + answer;
          out.println(s);
          if (out != System.out) {
            System.out.println(s);
          }
        } catch (Exception e) {
          e.printStackTrace();
        }
      }
    } finally {
      debug("done with all!");
    }
  }

  public String readLine() {
    try {
      return reader.readLine();
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }

  public String getToken() {
    while (true) {
      if (tokenizer.hasMoreTokens()) {
        return tokenizer.nextToken();
      }
      String s = readLine();
      if (s == null) {
        return null;
      }
      tokenizer = new StringTokenizer(s, " \t\n\r");
    }
  }

  public double getDouble() {
    return Double.parseDouble(getToken());
  }

  public int getInt() {
    return Integer.parseInt(getToken());
  }

  public long getLong() {
    return Long.parseLong(getToken());
  }

  public BigInteger getBigInt() {
    return new BigInteger(getToken());
  }

  public BigDecimal getBigDec() {
    return new BigDecimal(getToken());
  }

  public class Solver {
    private static final long MODULO = 1000000007L;
    private final int caseNumber;

    int N;
    final List<Car> cars;

    public Solver(int caseNumber) {
      this.caseNumber = caseNumber;
      N = getInt();
      cars = Lists.newArrayList();
      for (int i = 0; i < N; i++) {
        cars.add(new Car(getToken()));
      }

    }

    public String solve() throws Exception {
      debug("solving case %d", caseNumber);

      List<CarSet> sets = Lists.newArrayList();
      for (Car car : cars) {
        CarSet set = new CarSet();
        set.cars.add(car);
        set.characters.addAll(car.characters);
        sets.add(set);
      }

      while (merge(sets)) {
      }

      long count = 1;
      for (CarSet set : sets) {
        long x = countSet(set);
        count *= x;
        count %= MODULO;
      }

      count *= fac(sets.size());
      count %= MODULO;
      return "" + count;
    }

    private long fac(int n) {
      long res = 1;
      while (n > 1) {
        res *= n;
        res %= MODULO;
        n--;
      }
      return res;
    }

    private long countSet(CarSet set) {
      Multiset<Character> single = TreeMultiset.create();
      Map<Character, Character> mixed = Maps.newHashMap();
      Map<Character, Character> rev = Maps.newHashMap();
      Map<Character, List<Character>> lookup = Maps.newHashMap();
      for (Car car : set.cars) {
        Character first = car.characters.get(0);
        if (singleChar(car.characters)) {
          single.add(first);
        } else {
          Character characters = mixed.get(first);
          if (characters == null) {
            Character last = car.characters.get(car.characters.size() - 1);
            mixed.put(first, last);
            lookup.put(first, car.characters);
            if (rev.containsKey(last)) {
              return 0;
            }
            rev.put(last, first);
          } else {
            return 0;
          }
        }
      }

      if (mixed.size() == 0) {
        long count = 1;
        for (Character character : single) {
          count *= fac(single.count(character));
          count %= MODULO;
        }
        return count;
      }

      Character start = rev.keySet().iterator().next();
      for (int i = 0; i < 100; i++) {
        Character start2 = rev.get(start);
        if (start2 == null) {
          break;
        }
        start = start2;
        if (i == 99) {
          return 0;
        }
      }


      Set<Character> seen = Sets.newTreeSet();
      Set<Character> seenCenter = Sets.newTreeSet();
      int visitedCount = 0;
      char prev = 0;
      while (true) {
        List<Character> characters = lookup.get(start);
        if (characters == null) {
          break;
        }
        visitedCount++;
        int i = 0;
        for (Character character : characters) {
          if (character != prev) {
            if (!seen.add(character)) {
              return 0;
            }
            if (i > 0 && i < characters.size() - 1) {
              seenCenter.add(character);
              if (single.count(character) > 0) {
                return 0;
              }
            }
            prev = character;
          }
          i++;
        }
        start = characters.get(characters.size() - 1);
      }

      for (Character character : single) {
        if (seenCenter.contains(character)) {
          return 0;
        }
      }
      if (visitedCount != mixed.size()) {
        return 0;
      }
      if (single.isEmpty()) {
        return 1;
      }

      long count = 1;
      for (Character character : single) {
        count *= fac(single.count(character));
        count %= MODULO;
      }
      return count;
    }

    private boolean merge(List<CarSet> sets) {
      for (CarSet set : sets) {
        for (CarSet set2 : sets) {
          if (set == set2) continue;
          if (!Sets.intersection(set.characters, set2.characters).isEmpty()) {
            set.characters.addAll(set2.characters);
            set.cars.addAll(set2.cars);
            sets.remove(set2);
            return true;
          }
        }
      }
      return false;
    }

    private boolean singleChar(List<Character> car) {
      return car.size() == 1;
      }
    }

  private class CarSet {
    Set<Character> characters = Sets.newTreeSet();
    List<Car> cars = Lists.newArrayList();
  }

  private class Car {
    List<Character> characters = Lists.newArrayList();

    public Car(String token) {
      char prev = 0;
      for (int i = 0; i < token.length(); i++) {
        char c = token.charAt(i);
        if (c != prev) {
          characters.add(c);
          prev = c;
        }
      }
    }
  }
}
