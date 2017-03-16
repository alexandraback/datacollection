// CodeJam 2014
// Author: Jon Eisen
// Round: Qualifier
// Problem: D - Deceitful War

// Run with
// javac file.java && java klass file.in

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;
import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;
import java.util.Arrays;

public class DeceitfulWar {

  static String parseAndSolve(BufferedReader br) throws IOException {
    int n = Integer.parseInt(br.readLine());
    String[] naomiline = br.readLine().split(" ");
    String[] kenline = br.readLine().split(" ");

    Vector<Double> naomi = new Vector<Double>(n);
    Vector<Double> ken = new Vector<Double>(n);
    for (int i = 0; i < n; i++) {
      naomi.add(Double.parseDouble(naomiline[i]));
      ken.add(Double.parseDouble(kenline[i]));
    }

    Collections.sort(naomi);
    Collections.sort(ken);
    Vector<Double> ken2 = new Vector<Double>(n);
    ken2.setSize(n);
    Collections.copy(ken2,ken);

    // Deceitful War
    int dscore = 0;
    for (Double el : naomi) {
      if (el > ken.firstElement()) {
        ken.remove(0);
        dscore++;
      } else {
        ken.remove(ken.size() - 1);
      }
    }

    // Normal War
    int nscore = 0;
    Collections.reverse(naomi);
    for (Double el : naomi) {
      if (el > ken2.lastElement()) {
        ken2.remove(0);
        nscore++;
      } else {
        ken2.remove(ken2.size() - 1);
      }
    }

    return dscore + " " + nscore;
  }

  /**
   * @param args
   */
  public static void main(String[] args) {

    if (args.length < 1) {
      System.out
          .println("Not enough command line arguments specified. Need Input file path");
      return;
    }

    String inputFilePath = args[0];
    String outpuFilePath = inputFilePath.replaceFirst("\\..*$", ".out");

    if (args.length > 1) {
      outpuFilePath = args[1];
    }

    System.out.println("Using Input file " + inputFilePath + " and output file " + outpuFilePath);

    try {

      // read and parse input file
      FileInputStream fstream = new FileInputStream(inputFilePath);
      DataInputStream in = new DataInputStream(fstream);
      BufferedReader br = new BufferedReader(new InputStreamReader(in));

      // Pass output string to method to write to file
      FileWriter fwstream = new FileWriter(outpuFilePath);
      BufferedWriter out = new BufferedWriter(fwstream);

      int noOfTestCases = Integer.parseInt(br.readLine());

      for (int i = 0; i < noOfTestCases; i++) {
        String solution = parseAndSolve(br);
        String outline = "Case #" + (i+1) + ": " + solution;
        System.out.println(outline);
        out.write(outline + "\n");
      }

      in.close();
      out.flush();
      out.close();

    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    } finally {
      // File read cleanup
    }
  }
}