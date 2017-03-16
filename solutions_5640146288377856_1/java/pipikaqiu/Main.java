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

  long n;
  int r,c,w;
  long [] data;
  long result;

  public Main() throws FileNotFoundException, IOException {
    BufferedReader br = new BufferedReader(new FileReader("D:/A-large.in"));
    BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
    int cases = Integer.parseInt(br.readLine());
    for (int caseNum = 0; caseNum < cases; caseNum++) {
      String[] split = br.readLine().split(" ");
      r = Integer.parseInt(split[0]);
      c = Integer.parseInt(split[1]);
      w = Integer.parseInt(split[2]);
      result = 0;
      int eachRow = c / w;
      result += eachRow * (r - 1);
      while (c >= 2 * w) {
        result++;
        c -= w;
      }
      if (c == w) {
        result += w;
      } else {
        result += (w + 1);
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
