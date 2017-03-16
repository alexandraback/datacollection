package codejam2014;

import java.io.IOException;

public class Main {
  
  public static final boolean DEBUG = false;
  
  public static void main(String[] args) {
    Question prob = new codejam2014.round1B.B("small");
    try {
      prob.solveCases();
    } catch (IOException e) {
      System.out.println("Cannot read or write to files.");
      System.out.println(e.getMessage());
    }
  }
}
