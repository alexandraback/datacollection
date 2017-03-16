package r1c;

import java.io.*;
import java.util.*;

public class B {
  private static final String SUBDIR = "src/r1c";

  public abstract static class Solution extends Base {
    void doit(Scanner s) throws Exception {
      int T = s.nextInt();
      for (int t=1; t<=T; t++) {
        int X = s.nextInt();
        int Y = s.nextInt();
        emit("Case #" + t + ": " + foo(X, Y));
      }
    }
    private String foo(int x, int y) {
      if (x==0 && y==0) return "";
      String ret = "";
      for (int i=1; i<list.size(); i++) {
        Map<String, String> m = list.get(i);
        String blah = m.get(x+","+y);
        if (blah != null) {
          String[]ar = blah.split(",");
          ret = ar[2];
          for (int j=i-1; j>0; j--) {
            m = list.get(j);
            blah = m.get(ar[0]+","+ar[1]);
            ar = blah.split(",");
            ret = ar[2] + ret;
          }
          return ret;
        }
      }
      throw new Error();
    }
    List<Map<String, String>> list = new ArrayList<>();

    {
      Map<String, String> m = new HashMap<>();
      m.put("0,0", "0,0,X");
      list.add(m);
      outer:
      for (int d=1; d<100; d++) {
        Map<String, String> m2 = new HashMap<>();
        list.add(m2);
        int calcs = 0;
        for (Map.Entry<String, String> e : m.entrySet()) {
          String[] k = e.getKey().split(",");
          int x1 = Integer.parseInt(k[0]);
          int x2 = Integer.parseInt(k[1]);
          if (x1 < -1000 || x1 > 1000 || x2 < -1000 || x2 > 1000) continue;
          {
            String next = (x1+d) + "," + x2;
            if (!m.containsKey(next) && !m2.containsKey(next)) m2.put(next, e.getKey()+",E");
            calcs++;
          }
          {
            String next = (x1-d) + "," + x2;
            if (!m.containsKey(next) && !m2.containsKey(next)) m2.put(next, e.getKey()+",W");
            calcs++;
          }
          {
            String next = (x1) + "," + (x2+d);
            if (!m.containsKey(next) && !m2.containsKey(next)) m2.put(next, e.getKey()+",N");
            calcs++;
          }
          {
            String next = (x1) + "," + (x2-d);
            if (!m.containsKey(next) && !m2.containsKey(next)) m2.put(next, e.getKey()+",S");
            calcs++;
          }
        }

        int missing = 0;
        for (int ax=-100; ax<=100; ax++) {
          nexty: for (int ay=-100; ay<=100; ay++) {
            for (int i=0; i<list.size(); i++) {
              Map<String, String> map = list.get(i);
              if (map.containsKey(ax+","+ay)) {
                continue nexty;
              }
            }
            missing++;
          }
        }
        if (missing>0) {
        System.out.println(d+ " " +m2.size() +" " + calcs +" " + missing);
        m = m2;
        continue outer;
        } else
        break;
      }
    }
  }

  // boilerplate
  public static final void main(String[] args)throws Exception{
    File[] inputs = new File(new File("."), SUBDIR).listFiles(new FilenameFilter() {
      @Override public boolean accept(File dir, String name) {
        return name.endsWith(".in");
      }
    });
    System.out.println(B.class);
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
      System.out.println(B.class);
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
