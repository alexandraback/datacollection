import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class DancingWithTheGooglers {
  
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
  
  public static void main(String[] pArgs) throws Exception {
    if(pArgs.length == 0) {
      throw new Exception("no input");
    }
    List<String> tInputCases = new ArrayList<String>();
    
    readInput(pArgs[0], tInputCases);
    for(int tCaseIndex = 0; tCaseIndex < tInputCases.size(); tCaseIndex++) {
      String[] tInputs = tInputCases.get(tCaseIndex).split("[ ]+");
      int tNumberOfGooglers = Integer.valueOf(tInputs[0]);
      int tSurprise = Integer.valueOf(tInputs[1]);
      int tPoint = Integer.valueOf(tInputs[2]);
      //System.out.print(tNumberOfGooglers);
      //System.out.print(" ");
      //System.out.print(tSurprise);
      //System.out.print(" ");
      //System.out.print(tPoint);
      //System.out.println();
      int tNumber = 0;
      for(int i = 3; i < tNumberOfGooglers + 3; ++i) {
        int tTotal = Integer.valueOf(tInputs[i]);
        //System.out.print(tInputs[i]);
        //System.out.print(" ");
        int tDifference = tTotal % 3;
        int tScore = tTotal / 3;
        //System.out.print(tDifference);
        //System.out.print(",");
        //System.out.print(tScore);
        //System.out.print(" ");
        switch(tDifference) {
          case 0:
            if(tScore >= tPoint) {
              ++tNumber;
            } else if((tScore + 1 >= tPoint) && (tScore > 0)) {
              if(tSurprise > 0) {
                ++tNumber;
                --tSurprise;
              }
            }
            break;
          case 1:
            if(tScore + 1 >= tPoint) {
              ++tNumber;
            }
            break;
          case 2:
            if(tScore + 1 >= tPoint) {
              ++tNumber;
            } else if(tScore + 2 >= tPoint) {
              if(tSurprise > 0) {
                ++tNumber;
                --tSurprise;
              }
            }
            break;
        }
        //System.out.println("Case #" + tCaseIndex + ": " + tNumber);
      }
      System.out.println("Case #" + (tCaseIndex + 1) + ": " + tNumber);
    }
  }
}
