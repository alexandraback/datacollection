package codejam.round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Consonants {

    public static void main(String[] args) {
      Consonants cons = new Consonants();
      cons.readAndSolve(args[0], args[1]);
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
          String name = splittedLine[0];
          int n = Integer.valueOf(splittedLine[1]);
          //System.err.println("Case #" + (caseNum + 1) + ": " + solve(name, n));
          writer.write("Case #" + (caseNum + 1) + ": " + solve(name, n) + "\n");
        }
        //System.err.println(solve(7, 4, 0));
        reader.close();
        writer.close();
      } catch (IOException e) {
        // TODO Auto-generated catch block
        e.printStackTrace();
      }
    }
    private int solve(String name, int n) {
      int result = 0;
      for (int start = 0; start <= name.length() - n; ++start) {
        for (int end = start + n; end <= name.length(); ++ end) {
          int conNum = 0;
          for (int i = start; i < end; ++ i) {
            char c = name.charAt(i);
            if ('a' == c || 'e' == c || 'i' == c || 'o' == c|| 'u' == c) {
              conNum = 0;
            } else {
              conNum++;
            }
            if (conNum == n) {
              // System.err.println(name.substring(start, end));
              result++;
              break;
            }
          }
        }
      }
      return result;
    }
}
