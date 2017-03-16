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


public class SpeakingInTongues {
  
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
  
  public static final String TABLE = "yhesocvxduiglbkrztnwjpfmaq";
  
  public static void main(String[] pArgs) throws Exception {
    if(pArgs.length == 0) {
      throw new Exception("no input");
    }
    
    List<String> tInputCases = new ArrayList<String>();
    readInput(pArgs[0], tInputCases);
    for(int tCaseIndex = 0; tCaseIndex < tInputCases.size(); tCaseIndex++) {
      StringBuilder tStringBuilder = new StringBuilder();
      String tInput = tInputCases.get(tCaseIndex);
      for(int i = 0; i < tInput.length(); ++i) {
        char tChar = tInput.charAt(i);
        tStringBuilder.append((tChar == ' ') ? tChar : TABLE.charAt(tChar - 'a'));
      }
      System.out.println("Case #" + (tCaseIndex + 1) + ": " + tStringBuilder.toString());
    }
  }
}
