package codejam.round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class PogoStick {
  
  private static final String TO_NORTH = "SN";
  private static final String TO_WEST = "EW";
  private static final String TO_SOUTH = "NS";
  private static final String TO_EAST = "WE";
  
  public static void main(String[] args) {
    PogoStick pogo = new PogoStick();
    pogo.readAndSolve(args[0], args[1]);
  }
  
  private void readAndSolve(String filePath, String outFilePath) {
    try {
      BufferedReader reader = new BufferedReader(new FileReader(filePath));
      BufferedWriter writer = new BufferedWriter(new FileWriter(outFilePath));
      String line = reader.readLine();
      int numberOfTestCases = Integer.valueOf(line);
      for (int caseNum = 0; caseNum < numberOfTestCases; ++caseNum) {
        line = reader.readLine();
        String[] splittedLine = line.split(" ");
        int x = Integer.valueOf(splittedLine[0]);
        int y = Integer.valueOf(splittedLine[1]);
        //System.err.println("Case #" + (caseNum + 1) + ": " + solve(name, n));
        writer.write("Case #" + (caseNum + 1) + ": " + solve(x, y) + "\n");
      }
      //System.err.println(solve(7, 4, 0));
      reader.close();
      writer.close();
    } catch (IOException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }
  }
  private String solve(int x, int y) {
    String result = "";
    String toAppend = "";
    if (x < 0) {
      toAppend = TO_WEST;
    } else {
      toAppend = TO_EAST;
    }
    for (int i = 0; i < Math.abs(x); ++i)
      result += toAppend;
    if (y < 0) {
      toAppend = TO_SOUTH;
    } else {
      toAppend = TO_NORTH;
    }
    for (int i = 0; i < Math.abs(y); ++i)
      result += toAppend;
    return result;
  }
}
