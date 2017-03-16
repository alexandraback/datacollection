package round1c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/*
 * Google Code Jam 2013
 * Round 1C 2013
 * raguenets@gmail.com
 * Usage : java Pogo inputFileName outputFileName
 */
public class Pogo {

  /**
   * @param args
   */
  public static void main(String[] args) {
    int T = 0;
    int X = 0;
    int Y = 0;
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
            if (scanner.hasNextInt()) {
              X = scanner.nextInt();
            }
            if (scanner.hasNextInt()) {
              Y = scanner.nextInt();
            }
            String result = getDirections(X, Y);
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

  private static String getDirections(int X, int Y) {
    int distanceX = Math.abs(X);
    int distanceY = Math.abs(Y);
    StringBuilder sb = new StringBuilder();
    for (int y = 0; y < distanceY; y++) {
      if (Y < 0) {
        sb.append("NS");
      }
      else {
        sb.append("SN");
      }
    }
    for (int x = 0; x < distanceX; x++) {
      if (X < 0) {
        sb.append("EW");
      }
      else {
        sb.append("WE");
      }
    }
    return sb.toString();
  }

}
