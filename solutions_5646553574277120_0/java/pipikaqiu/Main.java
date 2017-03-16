package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.regex.Pattern;

public class Main {

  public static String changeLine = System.getProperty("line.separator");

  public static void main(String[] args) throws FileNotFoundException, IOException {
    new Main();
  }

  long n;
  int c,d,v;
  int[] ori;
  int result;
  Pattern pat;
 // Matcher matcher = new Matcher();

  public Main() throws FileNotFoundException, IOException {
    BufferedReader br = new BufferedReader(new FileReader("D:/C-small-attempt0.in"));
    BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
    int cases = Integer.parseInt(br.readLine());
    for (int caseNum = 0; caseNum < cases; caseNum++) {
      String[] split = br.readLine().split(" ");
      c = Integer.parseInt(split[0]);
      d = Integer.parseInt(split[1]);
      v = Integer.parseInt(split[2]);
      split = br.readLine().split(" ");
      ori = new int[d];
      HashSet<Integer> oriSet = new HashSet<Integer>();
      HashSet<Integer> resSet = new HashSet<Integer>();
      for (int i = 0;i < d; i++) {
        ori[i] = Integer.parseInt(split[i]);
        oriSet.add(ori[i]);
        resSet.add(ori[i]);
      }
      Arrays.sort(ori);
      result = 0;
      boolean [] cap = new boolean[v+1];
      cap[0] = true;
      for (int i = 0; i < d; i++) {
        for (int j = v; j >= 0; j--) {
          if (cap[j] && ori[i]+j <= v) {
            cap[ori[i]+j] = true;
          }
        }
      }
      for (int i = 0; i <= v; i++) {
        if (!cap[i]) {
          result++;
          for (int j = v; j >= 0; j--) {
            if (cap[j] && i+j <= v) {
              cap[i+j] = true;
            }
          }
        }
      }
      // output
      System.out.println(getResult(caseNum));
      bw.write(getResult(caseNum));
      bw.write(changeLine);
    }
    br.close();
    bw.close();
  }

  public String getResult(int caseNum) {
    String str = "Case #" + (caseNum + 1) + ": ";
    str += result;
    return str;
  }
}
