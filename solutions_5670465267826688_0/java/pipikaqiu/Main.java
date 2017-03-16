package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {

  public static String changeLine = System.getProperty("line.separator");

  public static void main(String[] args) throws FileNotFoundException, IOException {
    new Main();
  }

  int l,x;
  String base;
  boolean result;
  Ijk I = new Ijk('i', 1);
  Ijk J = new Ijk('j', 1);
  Ijk K = new Ijk('k', 1);

  public Main() throws FileNotFoundException, IOException {
    BufferedReader br = new BufferedReader(new FileReader("D:/C-small-attempt0.in"));
    BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
    int cases = Integer.parseInt(br.readLine());
    for (int caseNum = 0; caseNum < cases; caseNum++) {
      String[] split = br.readLine().split(" ");
      l = Integer.parseInt(split[0]);
      x = Integer.parseInt(split[1]);
      x = x > 12 ? (x % 4 + 12) : x;
      base = br.readLine();
      StringBuffer buffer = new StringBuffer(base.length() * x);
      for (int i = 0; i < x; i++) {
        buffer.append(base);
      }
      char[] str = buffer.toString().toCharArray();
      int length = str.length;
      Ijk ii = new Ijk('h', 1);
      int i;
      result = false;
      for (i = 0; i < length; i++) {
        ii.times(new Ijk(str[i], 1));
        if (ii.equals(I)) {
          Ijk jj = new Ijk('h', 1);
          for (i++; i < length; i++) {
            jj.times(new Ijk(str[i], 1));
            if (jj.equals(J)) {
              Ijk kk = new Ijk('h', 1);
              for (i++; i < length; i++) {
                kk.times(new Ijk(str[i], 1));
              }
              if (kk.equals(K)) {
                result = true;
              }
            }
          }
        }
      }
      // output
      System.out.println("Case #" + (caseNum + 1) + ": " + getResult());
      bw.write("Case #" + (caseNum + 1) + ": " + getResult());
      bw.write(changeLine);
    }
    br.close();
    bw.close();
  }

  public String getResult() {
    return result ? "YES" : "NO";
  }

  public static class Ijk {
    private static final int[][] VALUE_TABLE = new int[][] {
      new int[] {0, 1, 2, 3},
      new int[] {1, 0, 3, 2},
      new int[] {2, 3, 0, 1},
      new int[] {3, 2, 1, 0}
    };
    private static final int[][] NEG_TABLE = new int[][] {
      new int[] {1, 1, 1, 1},
      new int[] {1, -1, 1, -1},
      new int[] {1, -1, -1, 1},
      new int[] {1, 1, -1, -1}
    };
    public int value; //0 - 3 = 1ijk = hijk
    public int neg; // 1, -1

    public Ijk(char a, int neg) {
      value = a - 'h';
      this.neg = neg;
    }

    public void times(Ijk that) {
      this.neg = this.neg * that.neg * NEG_TABLE[this.value][that.value];
      this.value = VALUE_TABLE[this.value][that.value];
    }

    @Override
    public boolean equals(Object that) {
      if (that instanceof Ijk) {
        return this.value == ((Ijk) that).value && this.neg == ((Ijk) that).neg;
      }
      return false;
    }
  }
}
