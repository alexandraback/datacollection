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
    Main main = new Main();
  }

  int d;
  int x,r,c;
  boolean result;

  public Main() throws FileNotFoundException, IOException {
    BufferedReader br = new BufferedReader(new FileReader("D:/D-small-attempt0.in"));
    BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
    int cases = Integer.parseInt(br.readLine());
    for (int caseNum = 0; caseNum < cases; caseNum++) {
      String[] split = br.readLine().split(" ");
      x = Integer.parseInt(split[0]);
      r = Integer.parseInt(split[1]);
      c = Integer.parseInt(split[2]);
      if (r * c % x != 0) {
        result = false;
      } else if (x == 1 || x == 2) {
        result = true;
      } else if (x == 3) {
        result = (r != 1 && c != 1);
      } else {
        // x == 4
        result = (r > 2 && c > 2);
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
    return result ? "GABRIEL" : "RICHARD";
  }
}
