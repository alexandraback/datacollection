package r1c;

import java.io.*;
import java.util.*;

public class C {
  private static final String SUBDIR = "src/r1c";

  public abstract static class Solution extends Base {
    void doit(Scanner s) throws Exception {
      int T = s.nextInt();
      for (int t=1; t<=T; t++) {
        int ntribes = s.nextInt();
        Tribe[] tribes = new Tribe[ntribes];
        for (int tribe=0; tribe<ntribes; tribe++) {
          int firstday = s.nextInt();
          int numattacks = s.nextInt();
          int west = s.nextInt();
          int east = s.nextInt();
          int strength = s.nextInt();
          int delta_day = s.nextInt();
          int delta_pos = s.nextInt();
          int delta_str = s.nextInt();
          tribes[tribe] = new Tribe(firstday, numattacks,
              west, east, strength, delta_day, delta_pos, delta_str);
        }
        emit("Case #" + t + ": " + foo(tribes));
      }
    }

    private String foo(Tribe[] tribes) {
      Map<String, Integer> wall = new HashMap<>();
      List<Tribe> list = new ArrayList<>();
      for (Tribe t : tribes) list.add(t);
      int num = 0;
      for (int day = 0; day < 700000; day++) {
        Map<String, Integer> wall2 = new HashMap<>();
        for (Tribe t : list) {
          if (t.firstday == day) {
            boolean breach = false;
            for (int pos = t.west; pos < t.east; pos++) {
              String id = pos+","+(pos+1);
              Integer height = wall.get(id);
              if (height == null || t.strength > height) {
                breach = true;
                Integer prev = wall2.put(id, t.strength);
                if (prev != null && prev > t.strength) {
                  wall2.put(id, prev);
                }
              }
            }
            if (breach) num++;
            t.numattacks--;
            if (t.numattacks == 0) {
              t.firstday = -1;
            } else {
              t.firstday += t.delta_day;
              t.west += t.delta_pos;
              t.east += t.delta_pos;
              t.strength += t.delta_str;
            }
          }
        }
        wall.putAll(wall2);
      }

      return ""+num;
    }
  }

  static class Tribe {
    int firstday, numattacks, west, east, strength, delta_day, delta_pos, delta_str;

    public Tribe(int firstday, int numattacks, int west, int east, int strength, int delta_day, int delta_pos,
        int delta_str) {
      this.firstday = firstday;
      this.numattacks = numattacks;
      this.west = west;
      this.east = east;
      this.strength = strength;
      this.delta_day = delta_day;
      this.delta_pos = delta_pos;
      this.delta_str = delta_str;
    }

  }

  // boilerplate
  public static final void main(String[] args)throws Exception{
    File[] inputs = new File(new File("."), SUBDIR).listFiles(new FilenameFilter() {
      @Override public boolean accept(File dir, String name) {
        return name.endsWith(".in");
      }
    });
    System.out.println(C.class);
    for (int i=0; i<inputs.length; i++) System.out.println(i+": " + inputs[i]);
    System.out.print("> ");
    try (BufferedReader r = new BufferedReader(new InputStreamReader(System.in))) {
      int x = Integer.parseInt(r.readLine());
      String infile = inputs[x].getAbsolutePath();
      System.out.println("SELECTED: " + infile);
      String outfile = outify(infile);
      try (Scanner s = new Scanner(new File(infile));
          PrintStream out = new PrintStream(new FileOutputStream(outfile))) {

        new Solution() {
          @Override void emit(String s) throws Exception {
            System.out.println(s);
            out.println(s);
          }
        }.doit(s);
      }
      System.out.println(C.class);
      System.out.println("SELECTED: " + infile);
      System.out.println("OUTPUT: " + outfile);
    }
  }

  private static String outify(String string) {
    return (string.endsWith(".in") ? string.substring(0,  string.length() - 3) : string)+ ".out";
  }

  static abstract class Base {
    abstract void emit(String s) throws Exception;
    static final BitSet bs = new BitSet();
    {
      // primes under 2 million
      if ("".length() == 2) {
        bs.set(2);
        int x = 2;
        outer: while (x<2000000) {
          x++;
          for (int j=2; j<1+Math.sqrt(x) && j != -1; j = bs.nextSetBit(j+1)) {
            if (x % j == 0) {
              continue outer;
            }
          }
          bs.set(x);
        }
        System.out.println(bs.cardinality()+" primes");
      }
    }
  }
}
