package r1c;

import java.io.*;
import java.util.*;

public class A {
  private static final String SUBDIR = "src/r1c";

  public abstract static class Solution extends Base {
    void doit(Scanner s) throws Exception {
      int T = s.nextInt();
      for (int t=1; t<=T; t++) {
        String name = s.next();
        int n = s.nextInt();
        emit("Case #" + t + ": " + foo2(name, n));
      }
    }
    private int foo2(String name, int n) {
      int prev = 0;
      int[] run = new int[name.length()];
      for (int x = 0; x < name.length(); x++) {
        switch (name.charAt(x)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          run[x] = 0;
          break;
          default:
            if (x == 0) run[0] = 1;
            else run[x] = run[x-1] + 1;
        }
      }

      int whatsit = 0;
      int lastidx = -1;
      for (int i=n-1; i<name.length(); i++) {
        if (run[i] >= n) {
          lastidx = i;
          whatsit++;
          prev += (i+1) - n + 1;
//          System.out.println(name.substring(0, i + 1)+" " + prev+" " + i + " " + lastidx);
        } else {
          if (lastidx != -1) {
            prev += 1 + lastidx + 1 - n;
          }
//          System.out.println(name.substring(0, i + 1)+" " + prev+" " + i + " " + lastidx);
        }
      }
      return prev;
    }

    private int foo(String name, int n) {
      int x = 0;
      for (int a=0; a<name.length(); a++) {
        for (int b = a+1; b<=name.length(); b++) {
//          System.out.println(name.substring(a,b));
          if (has(name.substring(a,b),n)) x++;
        }
      }
      return x;
    }

    private boolean has(String s, int n) {
      if (s.length() < n) return false;
      int run = 0;
      for (int x = 0; x < s.length(); x++) {
        switch (s.charAt(x)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          if (run >= n) return true;
          run = 0;
          break;
          default:
            run++;
            if (run >= n) return true;
        }
      }
      return false;
    }
  }

  // boilerplate
  public static final void main(String[] args)throws Exception{
    File[] inputs = new File(new File("."), SUBDIR).listFiles(new FilenameFilter() {
      @Override public boolean accept(File dir, String name) {
        return name.endsWith(".in");
      }
    });
    System.out.println(A.class);
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
      System.out.println(A.class);
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
