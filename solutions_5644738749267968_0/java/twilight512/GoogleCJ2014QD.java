import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class GoogleCJ2014QD {

  public static int[] getPoints(double[] myPoints, double[] otherPoints, int size) {
    int[] result = new int[2];
    Arrays.sort(myPoints);
    Arrays.sort(otherPoints);
    int oIndex = -1;
    int count = 0;
    for (int i = 0; i < size; i++) {
      while (oIndex < size-1 && otherPoints[oIndex+1] < myPoints[i]) {
        oIndex++;
      }
      if (oIndex+1 > count) {
        count++;
      }
    }
    result[0] = count;
    count = 0;
    oIndex = 0;
    for (int i = 0; i < size; i++) {
      while (oIndex < size && otherPoints[oIndex] < myPoints[i]) {
        oIndex++;
      }
      if (oIndex < size) {
        count++;
        oIndex++;
      }
    }
    result[1] = size - count;
    return result;
  }
  
  public static boolean isTest = false;
  public static boolean isSmall = true;
  
  public static void main(String[] args) {
    try {
      BufferedReader br;
      BufferedWriter bw;
      if (isTest) {
        br = new BufferedReader(new FileReader("test.txt"));
        bw = new BufferedWriter(new FileWriter("test_out.txt"));
      }
      else {
        if (isSmall) {
          br = new BufferedReader(new FileReader("D-small-attempt0.in"));
          bw = new BufferedWriter(new FileWriter("D-small-out.txt"));
        }
        else {
          br = new BufferedReader(new FileReader("D-large.in"));
          bw = new BufferedWriter(new FileWriter("D-large-out.txt"));
        }
      }
      String[] line = br.readLine().trim().split("\\s+");
      int numProbs = Integer.parseInt(line[0]);
      for (int i = 1; i <= numProbs; i++) {
        line = br.readLine().trim().split("\\s+");
        int N = Integer.parseInt(line[0]);
        line = br.readLine().trim().split("\\s+");
        double[] naomiBlocks = new double[N];
        double[] kenBlocks = new double[N];
        for (int j = 0; j < N; j++) {
          naomiBlocks[j] = Double.parseDouble(line[j]);
        }
        line = br.readLine().trim().split("\\s+");
        for (int j = 0; j < N; j++) {
          kenBlocks[j] = Double.parseDouble(line[j]);
        }
        int[] result = getPoints(naomiBlocks, kenBlocks, N);
        System.out.print("Case #" + i + ": " + result[0] + " " + result[1] + "\n");
        bw.write("Case #" + i + ": " + result[0] + " " + result[1] + "\n");
      }
      br.close();
      bw.close();
    }
    catch (IOException e) {
      System.out.println("Error in IO");
    }
  }

}
