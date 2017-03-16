package round1c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.StringTokenizer;

/*
 * Google Code Jam 2013
 * Round 1C 2013
 * raguenets@gmail.com
 * Usage : java ProblemA inputFileName outputFileName
 */
public class Consonants {

  public static final char[] VOWELS = new char[] { 'a', 'e', 'i', 'o', 'u' };

  /**
   * @param args
   */
  public static void main(String[] args) {
    int T = 0;
    int N = 0;
    if (args.length == 2) {
      String inputFilename = args[0];
      File finput = new File(inputFilename);
      String outputFilename = args[1];
      File foutput = new File(outputFilename);
      Scanner scanner = null;
      BufferedWriter bw = null;
      try {
        bw = new BufferedWriter(new FileWriter(foutput));
      }
      catch (IOException e1) {
        e1.printStackTrace();
      }
      if (finput.exists()) {
        try {
          scanner = new Scanner(finput);
          // Reads first line : number of Tests
          if (scanner.hasNextInt()) {
            T = scanner.nextInt();
          }
          for (int k = 0; k < T; k++) {
            String name = "";
            if (scanner.hasNext()) {
              name = scanner.next();
            }
            if (scanner.hasNextInt()) {
              N = scanner.nextInt();
            }
            String result = getNValue(N, name);
            bw.write("Case #" + (k + 1) + ": " + result + "\n");
          }
        }
        catch (FileNotFoundException e) {
          // TODO Auto-generated catch block
          e.printStackTrace();
        }
        catch (IOException e) {
          // TODO Auto-generated catch block
          e.printStackTrace();
        }
        finally {
          try {
            bw.close();
            if (scanner != null) {
              scanner.close();
            }
          }
          catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
          }
        }
      }
    }
  }

  private static String getNValue(int N, String name) {
    int length = name.length();
    int score = 0;
    String newName = new String(name);
    for (char c : VOWELS) {
      String s = newName.replace(c, '?');
      newName = s;
    }
    for (int j = N; j <= length; j++) {
      for (int i = 0; i <= length - j; i++) {
        String sub = newName.substring(i, i + j);
        StringTokenizer st = new StringTokenizer(sub, "?");
        while (st.hasMoreTokens()) {
          String token = st.nextToken();
          if (token.length() >= N) {
            score++;
            break;
          }
        }
      }
    }
    return Integer.toString(score);
  }

}
