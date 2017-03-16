import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;


public class GoogleCJ2014QB {

  public static double getTime(double C, double F, double X) {
    double totalTime = 0;
    double curRate = 2.0;
    while (X / (F + curRate) < (X - C) / curRate) {
      totalTime += C / curRate;
      curRate = curRate + F;
    }
    totalTime += X / curRate;
    return totalTime;
  }
  
  public static boolean isTest = false;
  public static boolean isSmall = false;
  
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
          br = new BufferedReader(new FileReader("B-small-attempt0.in"));
          bw = new BufferedWriter(new FileWriter("B-small-out.txt"));
        }
        else {
          br = new BufferedReader(new FileReader("B-large.in"));
          bw = new BufferedWriter(new FileWriter("B-large-out.txt"));
        }
      }
      String[] line = br.readLine().trim().split("\\s+");
      int numProbs = Integer.parseInt(line[0]);
      DecimalFormat df = new DecimalFormat("0.00000000");
      for (int i = 1; i <= numProbs; i++) {
        line = br.readLine().trim().split("\\s+");
        double C = Double.parseDouble(line[0]);
        double F = Double.parseDouble(line[1]);
        double X = Double.parseDouble(line[2]);
        double result = getTime(C, F, X);
        System.out.print("Case #" + i + ": " + df.format(result) + "\n");
        bw.write("Case #" + i + ": " + df.format(result) + "\n");
      }
      br.close();
      bw.close();
    }
    catch (IOException e) {
      System.out.println("Error in IO");
    }
  }

}
