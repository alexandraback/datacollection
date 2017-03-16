package codejam.round1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class EnergyManager {
  
  long [][] table;
  
  public static void main(String[] args) {
    EnergyManager em = new EnergyManager();
    em.readAndSolve(args[0], args[1]);
  }
  
  
  private void readAndSolve(String filePath, String outFilePath) {
    try {
      BufferedReader reader = new BufferedReader(new FileReader(filePath));
      BufferedWriter writer = new BufferedWriter(new FileWriter(outFilePath));
      String line = reader.readLine();
      int numberOfTestCases = Integer.valueOf(line);
      for (int caseNum = 0; caseNum < numberOfTestCases; ++caseNum) {
        line = reader.readLine();
        String[] ERN = line.split(" ");
        int E = Integer.valueOf(ERN[0]);
        int R = Integer.valueOf(ERN[1]);
        int N = Integer.valueOf(ERN[2]);
        line = reader.readLine();
        String[] values = line.split(" ");
        System.err.println("Case #" + (caseNum + 1) + ": " + solve(E, R, N, values));
        writer.write("Case #" + (caseNum + 1) + ": " + solve(E, R, N, values) + "\n");
      }
      reader.close();
      writer.close();
    } catch (IOException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }
  }
  private long solve(int E, int R, int N, String[] values) {
    int size = E < R ? E + 1 : E - R + 1;
    long[][] table = new long [N][size];
    int activityIndex = 0;
    long valueOfActivity = Long.valueOf(values[0]);
    for (int remainingEnergy = 0; remainingEnergy < size; ++remainingEnergy) {
      table[0][remainingEnergy] = valueOfActivity * (E - remainingEnergy);
    }
    
    for (++activityIndex;activityIndex < N ;++activityIndex ) {
      valueOfActivity = Long.valueOf(values[activityIndex]);
      for (int remainingEnergy = 0; remainingEnergy < size; ++remainingEnergy) {
        table[activityIndex][remainingEnergy] = table[activityIndex - 1][size - 1];
        int minEnergy = Math.max(0, remainingEnergy - R);
        for (int startingEnergy = size - 1; startingEnergy >= minEnergy; --startingEnergy) {
          int energyToUse = Math.min(E, startingEnergy + R);
          long value = table[activityIndex - 1][startingEnergy] + valueOfActivity *
              (energyToUse - remainingEnergy);
          if (value > table[activityIndex][remainingEnergy]) {
            table[activityIndex][remainingEnergy] = value;
          }
        } 
      }
    }
    return table[N - 1][0];
  }
}
