import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/*
 * Google Code Jam 2013
 * Qualification Round 2013
 * raguenets@gmail.com
 * Usage : java TicTacToeTomek inputFileName outputFileName
 */
public class TicTacToeTomek {
  public static String XWON = "X won";
  public static String OWON = "O won";
  public static String DRAW = "Draw";
  public static String UNKNOWN = "Unknown";
  public static String NOTCOMPLETED = "Game has not completed";
  public static int[][] CONFIGURATIONS = new int[][] { { 0, 1, 2, 3 }, // line 1
      { 4, 5, 6, 7 }, // line 2
      { 8, 9, 10, 11 }, // line 3
      { 12, 13, 14, 15 }, // line 4
      { 0, 4, 8, 12 }, // column 1
      { 1, 5, 9, 13 }, // column 2
      { 2, 6, 10, 14 }, // column 3
      { 3, 7, 11, 15 }, // column 4
      { 0, 5, 10, 15 }, // diagonal 1
      { 3, 6, 9, 12 }, // diagonal 2
  };

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
          for (int i = 0; i < T; i++) {
            // Read grid
            String[] grid = new String[4];
            for (int j = 0; j < 4; j++) {
              String line = scanner.next();
              grid[j] = line;
            }

            String result = checkConfiguration(grid);
            bw.write("Case #" + (i + 1) + ": " + result + "\n");
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

  private static String checkConfiguration(String[] grid) {
    // Test lines
    StringBuilder gr = new StringBuilder();
    gr.append(grid[0]);
    gr.append(grid[1]);
    gr.append(grid[2]);
    gr.append(grid[3]);

    String gridDesc = gr.toString();

    String first = checkConfiguration(gridDesc);

    String gridDesc1 = gr.toString().replace('T', 'X');
    String second = checkConfiguration(gridDesc1);

    String gridDesc2 = gr.toString().replace('T', 'O');
    String third = checkConfiguration(gridDesc2);

    if (first.equals(UNKNOWN) && second.equals(UNKNOWN) && third.equals(UNKNOWN)) {
      if (gridDesc.indexOf('.') == -1) {
        return DRAW;
      }
      else {
        return NOTCOMPLETED;
      }
    }
    if (!first.equals(UNKNOWN)) { return first; }
    if (!second.equals(UNKNOWN)) { return second; }
    if (!third.equals(UNKNOWN)) { return third; }

    return null;
  }

  private static String checkConfiguration(String gridDesc) {
    for (int i = 0; i < CONFIGURATIONS.length; i++) {
      StringBuilder config = new StringBuilder();
      for (int j = 0; j < CONFIGURATIONS[i].length; j++) {
        config.append(gridDesc.charAt(CONFIGURATIONS[i][j]));
      }
      String conf = config.toString();
      if (conf.equals("XXXX")) {
        return XWON;
      }
      else if (conf.equals("OOOO")) { return OWON; }
    }
    return UNKNOWN;
  }

}
