

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;

public class PasswordProblem {
  
  public static void main(String[] pArgs) throws Exception {
    if(pArgs.length == 0) {
      throw new Exception("no input");
    }
    File tFile = new File(pArgs[0]);
    try {
      BufferedReader tBufferedReader = new BufferedReader(
          new InputStreamReader(new FileInputStream(tFile)), 4096);
      String tLineRead = tBufferedReader.readLine().trim();
      int tCaseSize = Integer.valueOf(tLineRead);
      int tLineIndex = 0;
      while(tLineIndex < tCaseSize) {
        tLineRead = tBufferedReader.readLine().trim();
        String[] tNumbers = tLineRead.split("[ ]+");
        int tKeyTyped = Integer.valueOf(tNumbers[0]);
        int tKeyTotal = Integer.valueOf(tNumbers[1]);
        
        tLineRead = tBufferedReader.readLine().trim();
        double[] tProbabilities = new double[tKeyTyped];
        String[] tInputs = tLineRead.split("[ ]+");
        for(int i = 0; i < tKeyTyped; ++i) {
          tProbabilities[i] = Double.valueOf(tInputs[i]);
        }
        
        for(int i = 1; i < tKeyTyped; ++i) {
          tProbabilities[i] *= tProbabilities[i - 1]; 
        }
        
        double tExpected = Double.MAX_VALUE;
        double tPossible = 0;

        tPossible = tKeyTotal + 1 + 1;
        if(tPossible < tExpected) {
          tExpected = tPossible;
        }
        
        tPossible = tKeyTotal + 1 + tKeyTyped;
        if(tPossible < tExpected) {
          tExpected = tPossible;
        }
        
        for(int i = 0; i < tKeyTyped; ++i) {
          tPossible = tProbabilities[tKeyTyped - 1 - i] * (tKeyTotal - tKeyTyped + i + 1 + i)
              + (1 - tProbabilities[tKeyTyped - 1 - i]) * (tKeyTotal - tKeyTyped + i + 1 + i + (tKeyTotal + 1));
          if(tPossible < tExpected) {
            tExpected = tPossible;
          }
        }
        
        tLineIndex++;
        DecimalFormat tDecimalFormat = new DecimalFormat("0.000000");
        System.out.println("Case #" + tLineIndex + ": " + tDecimalFormat.format(tExpected));
      }
    } catch(FileNotFoundException pException) {
      pException.printStackTrace();
    } catch(IOException pException) {
      pException.printStackTrace();
    }
  }
}
