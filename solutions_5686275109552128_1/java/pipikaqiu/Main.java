package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class Main {

  public static String changeLine = System.getProperty("line.separator");

  public static void main(String[] args) throws FileNotFoundException, IOException {
    Main main = new Main();
  }

  int d;
  int [] data;
  int result;

  public Main() throws FileNotFoundException, IOException {
    BufferedReader br = new BufferedReader(new FileReader("D:/B-large.in"));
    BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
    int cases = Integer.parseInt(br.readLine());
    for (int caseNum = 0; caseNum < cases; caseNum++) {
      String[] split = br.readLine().split(" ");
      d = Integer.parseInt(split[0]);
      split = br.readLine().split(" ");
      data = new int[d];
      for (int i = 0; i < d; i++) {
        data[i] = Integer.parseInt(split[i]);
      }
      Arrays.sort(data);
      int max = data[d-1];
      int roundLeft = 1;
      int roundRight = max;
      while (roundLeft < roundRight) {
        int guessRound = (roundLeft + roundRight) / 2;
        if (canEat(guessRound)) {
          roundRight = guessRound;
        } else {
          roundLeft = guessRound + 1;
        }
      }
      result = roundRight;
      // output
      System.out.println("Case #" + (caseNum + 1) + ": " + getResult());
      bw.write("Case #" + (caseNum + 1) + ": " + getResult());
      bw.write(changeLine);
    }
    br.close();
    bw.close();
  }

  public boolean canEat(int guessRound) {
    for (int eatRound = guessRound; eatRound > 0; eatRound--) {
      boolean done = true;
      int moveRound = guessRound - eatRound;
      for (int i = d - 1; i >= 0; i--) {
        if (data[i] <= eatRound) {
          return true;
        }
        moveRound -= (data[i] - 1) / eatRound;
        if (moveRound < 0) {
          done = false;
          break;
        }
      }
      if (done) {
        return true;
      }
    }
    return false;
  }

  public String getResult() {
    return Integer.toString(result);
  }
}
