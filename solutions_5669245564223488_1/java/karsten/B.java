import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

public class B {
  public static void main(String[] args) throws Exception {
    if (args.length != 2) {
      System.err.println("Usage: java " + B.class.getName()
          + " [input] [output]");
      System.exit(1);
    }
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    BufferedWriter bw = new BufferedWriter(new FileWriter(args[1]));
    int testCases = Integer.parseInt(br.readLine());
    for (int testCase = 1; testCase <= testCases; testCase++) {
      bw.write("Case #" + testCase + ": ");
      br.readLine(); /* skip n line */
      List<String> sets = new ArrayList<String>();
      SortedSet<String> chars = new TreeSet<String>();
      boolean valid = true;
      for (String set : br.readLine().split(" ")) {
        sets.add(set);
        for (char c : set.toCharArray()) {
          chars.add(String.valueOf(c));
        }
      }
      BigInteger possibilities = BigInteger.ONE;
      if (valid) {
        for (String c : chars) {
          List<String> startsWith = new ArrayList<String>(),
              inTheMiddle = new ArrayList<String>(),
              endsWith = new ArrayList<String>();
          List<String> newSets = new ArrayList<String>();
          for (String set : sets) {
            if (set.contains(c)) {
              if (set.startsWith(c) && set.endsWith(c)) {
                inTheMiddle.add(set);
              } else if (set.startsWith(c)) {
                startsWith.add(set);
              } else if (set.endsWith(c)) {
                endsWith.add(set);
              } else {
                inTheMiddle.add(set);
              }
            } else {
              newSets.add(set);
            }
          }
          if (endsWith.size() > 1 || startsWith.size() > 1) {
            valid = false;
            break;
          }
          for (int i = inTheMiddle.size(); i > 1; i--) {
            possibilities = possibilities.multiply(BigInteger.valueOf(i));
          }
          StringBuilder sb = new StringBuilder();
          for (String s : endsWith) {
            sb.append(s);
          }
          for (String s : inTheMiddle) {
            sb.append(s);
          }
          for (String s : startsWith) {
            sb.append(s);
          }
          String newSet = sb.toString();
          newSets.add(newSet);
          sets = newSets;
        }
        for (String set : sets) {
          char last = 0;
          Set<Character> cs = new HashSet<Character>();
          for (char c : set.toCharArray()) {
            if (last == 0 || last != c) {
              if (cs.contains(c)) {
                valid = false;
                break;
              }
              cs.add(c);
              last = c;
            }
          }
        }
      }
      if (valid) {
        BigInteger w = possibilities;
        for (int i = sets.size(); i > 0; i--) {
          w = w.multiply(BigInteger.valueOf(i));
        }
        BigInteger limit = BigInteger.valueOf(1000000007L);
        if (w.compareTo(limit) > 0) {
          w = w.mod(limit);
        }
        bw.write(w + "\n");
      } else {
        bw.write("0\n");
      }
    }
    br.close();
    bw.close();
  }
}
