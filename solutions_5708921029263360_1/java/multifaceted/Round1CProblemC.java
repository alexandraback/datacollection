package Round1C;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


/**
 * Created by mayank on 10/4/16.
 */
public class Round1CProblemC {

  private static Object[] ioResource()
      throws IOException {
    String problemFileName = "C-large";
    String inputFileName = problemFileName + ".txt";
    String outputFileName = problemFileName + "-out.txt";
    File homedir = new File(System.getProperty("user.home"));
    File CurrentIODir = new File(homedir, "IdeaProjects/CodeJam2016/ioFiles/round1C");
    File inputFile = new File(CurrentIODir, inputFileName);
    FileReader inputFileReader = new FileReader(inputFile);
    BufferedReader br = new BufferedReader(inputFileReader);

    File outputFile = new File(CurrentIODir, outputFileName);
    if (!outputFile.exists()) {
      outputFile.createNewFile();
    }
    FileWriter outputFileWriter = new FileWriter(outputFile.getAbsoluteFile());
    BufferedWriter bufferedWriter = new BufferedWriter(outputFileWriter);
    Object[] ioBuffers = new Object[2];
    ioBuffers[0] = br;
    ioBuffers[1] = bufferedWriter;
    return ioBuffers;
  }

  public static void main(String[] args)
      throws IOException {
    Object[] ioBuffers = ioResource();
    BufferedReader br = (BufferedReader) ioBuffers[0];
    BufferedWriter bufferedWriter = (BufferedWriter) ioBuffers[1];
    int t = Integer.parseInt(br.readLine());
    for (int i = 1; i <= t; i++) {
      String[] answer = solve(br);
      System.out.println("Case #" + i + ": " + answer[0]);
      bufferedWriter.write("Case #" + i + ": " + answer[0]);
      bufferedWriter.newLine();
      for (int j = 1; j < answer.length; j++) {
        System.out.println(answer[j]);
        bufferedWriter.write(answer[j]);
        bufferedWriter.newLine();
      }
    }
    bufferedWriter.flush();
    bufferedWriter.close();
  }

  public static String[] solve(BufferedReader br)
      throws IOException {
    String input[] = br.readLine().trim().split(" ");
    int j = Integer.parseInt(input[0]);
    int p = Integer.parseInt(input[1]);
    int s = Integer.parseInt(input[2]);
    int k = Integer.parseInt(input[3]);
    int jp[][] = new int[j][p];
    int ps[][] = new int[p][s];
    int js[][] = new int[j][s];
    jp = setArray0(jp);
    ps = setArray0(ps);
    js = setArray0(js);
    int aIndex = 0;
    int bIndex = 0;
    int cIndex = 0;
    int count = 0;
    ArrayList<String> possibleCombos = new ArrayList<String>();
    for (int a = 1; a <= j; a++, aIndex++) { //j
      for (int b = 1; b <= p; b++, bIndex++) { //p
        bIndex = b-1;
        for (int c = 1; c <= s; c++, cIndex++) { //s
          cIndex = c-1;
          if (jp[aIndex][bIndex] >= k || ps[bIndex][cIndex] >= k || js[aIndex][cIndex] >= k || (a == b && b == c)) {
            continue;
          } else {
            jp[aIndex][bIndex] += 1;
            ps[bIndex][cIndex] += 1;
            js[aIndex][cIndex] += 1;
            count += 1;
            String combo = a + " " + b + " " + c;
            possibleCombos.add(combo);
          }
        }
      }
    }
    aIndex = 0;
    bIndex = 0;
    cIndex = 0;
    for (int a = 1; a <= j; a++, aIndex++) { //j
      for (int b = 1; b <= p; b++, bIndex++) { //p
        bIndex = b-1;
        for (int c = 1; c <= s; c++, cIndex++) { //s
          cIndex = c-1;
          if (jp[aIndex][bIndex] >= k || ps[bIndex][cIndex] >= k || js[aIndex][cIndex] >= k || !(a == b && b == c)) {
            continue;
          } else {
            jp[aIndex][bIndex] += 1;
            ps[bIndex][cIndex] += 1;
            js[aIndex][cIndex] += 1;
            count += 1;
            String combo = a + " " + b + " " + c;
            possibleCombos.add(combo);
          }
        }
      }
    }
    String result[] = new String[(possibleCombos.size() + 1)];
    result[0] = String.valueOf(count);
    for (int i = 1; i < result.length; i++) {
      result[i] = possibleCombos.get(i - 1);
    }
    return result;
  }

  public static int[][] setArray0(int[][] array) {
    int r = array.length;
    int c = array[0].length;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        array[i][j] = 0;
      }
    }
    return array;
  }
}
