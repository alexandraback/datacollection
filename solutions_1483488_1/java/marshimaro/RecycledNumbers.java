import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class RecycledNumbers {
  
  public static void readInput(String pFileName, List<String> pInputCases) {
    File tFile = new File(pFileName);
    try {
      BufferedReader tBufferedReader = new BufferedReader(
          new InputStreamReader(new FileInputStream(tFile)), 4096);
      String tLineRead = tBufferedReader.readLine().trim();
      int tCaseSize = Integer.valueOf(tLineRead);
      int tLineIndex = 0;
      while(tLineIndex < tCaseSize) {
        tLineRead = tBufferedReader.readLine().trim();
        pInputCases.add(tLineRead);
        tLineIndex++;
      }
    } catch(FileNotFoundException pException) {
      pException.printStackTrace();
    } catch(IOException pException) {
      pException.printStackTrace();
    }
  }
  
  public static final int[] UNITS = { 1, 1, 10, 100, 1000, 10000, 100000, 1000000 };
  
  public static void main(String[] pArgs) {
    if(pArgs.length == 0) {
      System.out.println("no input");
      return;
    }
    List<String> tInputCases = new ArrayList<String>();
    
    readInput(pArgs[0], tInputCases);
    for(int tCaseIndex = 0; tCaseIndex < tInputCases.size(); tCaseIndex++) {
      String[] tInputs = tInputCases.get(tCaseIndex).split("[ ]+");
      int tLower = Integer.valueOf(tInputs[0]);
      int tUpper = Integer.valueOf(tInputs[1]);
      
      int tPairs = 0;
      Map<Long, Integer> tMapPairs = new HashMap<Long, Integer>();
      for(int tNumber = tLower; tNumber < tUpper; ++tNumber) {
        int tLength = String.valueOf(tNumber).length();
        int tValue = tNumber;
        List<Integer> tValues = new ArrayList<Integer>();
        tValues.add(tNumber);
        for(int i = 1; i < tLength; ++i) {
          int tHead = tValue / UNITS[tLength];
          int tTail = tValue - tHead * UNITS[tLength];
          int tNewValue = tTail * 10 + tHead;
          if((tLower <= tNewValue) && (tNewValue <= tUpper)) {
            tValues.add(tNewValue);
          }
          tValue = tNewValue;
        }
        if(tValues.size() > 1) {
          for(int i = 0; i < tValues.size() - 1; ++i) {
            for(int j = i + 1; j < tValues.size(); ++j) {
              int tOldValue = tValues.get(i);
              int tNewValue = tValues.get(j);
              long tKey = tOldValue * 10000000l + tNewValue;
              if((tOldValue < tNewValue) && (tOldValue != tNewValue)) {
                if(!tMapPairs.containsKey(tKey)) {
                  ++tPairs;
                  tMapPairs.put(tKey, 1);
                }
              }
            }
          }
        }
      }
      System.out.println("Case #" + (tCaseIndex + 1) + ": " + tPairs);
    }
  }
}
