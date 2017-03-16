package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.regex.Pattern;

public class Main {

  public static String changeLine = System.getProperty("line.separator");

  public static void main(String[] args) throws FileNotFoundException, IOException {
    new Main();
  }

  long n;
  int c,d,v;
  long[] ori;
  int result;
  Pattern pat;
 // Matcher matcher = new Matcher();

  public Main() throws FileNotFoundException, IOException {
    BufferedReader br = new BufferedReader(new FileReader("D:/C-large.in"));
    BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
    int cases = Integer.parseInt(br.readLine());
    for (int caseNum = 0; caseNum < cases; caseNum++) {
      String[] split = br.readLine().split(" ");
      c = Integer.parseInt(split[0]);
      d = Integer.parseInt(split[1]);
      v = Integer.parseInt(split[2]);
      split = br.readLine().split(" ");
      ori = new long[d];
//      HashSet<Integer> oriSet = new HashSet<Integer>();
//      HashSet<Integer> resSet = new HashSet<Integer>();
      for (int i = 0;i < d; i++) {
        ori[i] = Long.parseLong(split[i]);
//        oriSet.add(ori[i]);
//        resSet.add(ori[i]);
      }
      Arrays.sort(ori);
      result = 0;
      long i = 0; //exist ok
      int index = 0;
      long longv = v;
      while (i < longv) {
        if (index < d && ori[index] == i+1) {
          i += ori[index] * c;
          index ++;
        } else {
          result++;
          i += (i+1) * c;
        }
        int j;
        for (j = index; j < d && ori[j] <= i; j++) {
          i += ori[j] * c;
        }
        index = j;
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
