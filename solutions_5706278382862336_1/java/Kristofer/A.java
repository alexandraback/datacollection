/*
 * This submission is using the template from https://github.com/krka/codejamjavatemplate
 * Dependencies: standard java, google guava
 * Revision: e20bb6576d30168d022a1af95aa1be5d1bd35e4a
 */

import com.google.common.collect.Maps;
import com.google.common.math.LongMath;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.StringTokenizer;

public class A {
  private static final String INPUT = null; // override to use a specific input (i.e. "small-1", "large-2", "sample", "stdin").

  public static void main(String[] args) throws Exception {
    new A().run();
  }

  private final PrintStream out;
  private final BufferedReader reader;
  private StringTokenizer tokenizer = new StringTokenizer("");

  public A() throws Exception {
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
    private final int caseNumber;
    long P;
    long Q;

    public Solver(int caseNumber) {
      this.caseNumber = caseNumber;
      String frac = getToken();
      String[] split = frac.split("/");
      P = Long.parseLong(split[0]);
      Q = Long.parseLong(split[1]);

    }

    boolean pow2(long x) {
        return (x & (x - 1)) == 0;
    }

    public String solve() throws Exception {
      debug("solving case %d", caseNumber);

      long gcd = LongMath.gcd(P, Q);
      P /= gcd;
      Q /= gcd;

      if (!pow2(Q)) {
        return "Impossible";
      }

      int gen = 0;
      while (P != Q) {
        gen++;
        if (gen >= 41) {
          return "Impossible";
        }

        if (2 * P >= Q) {
          return "" + gen;
        }

        P *= 2;
      }

      return "" + gen;
    }
  }
}
