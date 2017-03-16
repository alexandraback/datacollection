package codejam2014;

import java.io.*;

public class QualsB {

  // variables here
  private static final boolean DEBUG = false;
  private static final double INITIAL_RATE = 2;
  private double target, farmCost, farmBonus;
  private double currentRate, currentTime;

  // solution algorithm here
  public void solveCases(String inputSize) throws IOException {
    String infilename = "B" + inputSize + "in.in";
    String outfilename = "B" + inputSize + "out.in";

    // create output file if it does not exist, otherwise overwrite everything
    // in it
    File file = new File("data/quals/" + outfilename);
    if (!file.exists()) {
      file.createNewFile();
    }

    // create reader and writer for the input and output files
    BufferedReader br = new BufferedReader(new FileReader("data/quals/"
        + infilename));
    BufferedWriter bw = new BufferedWriter(new FileWriter(
        file.getAbsoluteFile()));

    // get the number of test cases to use throughout solving process
    int numCases = Integer.parseInt(br.readLine());

    // create some temporary variables to use for storing input variabes and
    // output string
    String line;
    String[] splitted;
    for (int i = 1; i <= numCases; i++) {
      // read in variables here
      line = br.readLine();
      splitted = line.split(" ");
      farmCost = Double.parseDouble(splitted[0]);
      farmBonus = Double.parseDouble(splitted[1]);
      target = Double.parseDouble(splitted[2]);

      if(DEBUG){
        System.out.println("Solving case " + i);
      }
      line = "Case #" + i + ": " + solve() + "\n"; // solve here
      if(DEBUG){
        System.out.println(line);
      }
      bw.write(line);
    }
    br.close();
    bw.close();
  }
  
  private void buyUpgrade(){
    currentTime += farmCost/currentRate;
    currentRate += farmBonus;
  }

  private String solve() {
    long startTime;
    if(DEBUG){
      System.out.println("Farm Cost: " + farmCost);
      System.out.println("Farm Bonus: " + farmBonus);
      System.out.println("Target: " + target);
      startTime = System.currentTimeMillis();
    }
    currentRate = INITIAL_RATE;
    currentTime = 0;
    
    while(true){
      double timeWithoutUpgrade = currentTime + target/currentRate;
      double timeWithUpgrade = currentTime + farmCost/currentRate + target/(currentRate+farmBonus);
      
      if(timeWithoutUpgrade<timeWithUpgrade){
        currentTime = timeWithoutUpgrade;
        break;
      }
      
      buyUpgrade();
    }
    
    if(DEBUG){
      long endTime = System.currentTimeMillis();
      System.out.println("Solution took: " + (endTime-startTime) + "ms");
    }
    return Double.toString(currentTime);
  }

  public static void main(String[] args) {
    QualsB prob = new QualsB();
    try {
      prob.solveCases("s");
    } catch (IOException e) {
      System.out.println("Cannot read or write to files.");
      System.out.println(e.getMessage());
    }
  }
}
