/** Suvesh Pratapa
 *  suveshp@gmail.com
 *
 *  2013 Google Code Jam - Qualification Round
 *  Question B - Lawnmower
 */

package qualb;

import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class QualB2013 {

  public static boolean isLawnPatternPossible(ArrayList<ArrayList<Integer>> lawnPattern)
  {
    // Think of the lawn pattern as a state machine. We try to revert it
    // back to a state where it exists in a pattern that is "possible".
    // Each iteration of mowing the lawn takes it to a valid state, so
    // we try to backtrack as much as we can. 
    while(true) {
      int i = 0;
      // At the beginning of each iteration, remove rows that are empty.
      // This can be thought of as the lawnmower going in the same path
      // back and forth -- we're not interested in this.
      while(i < lawnPattern.size()) {
        if (lawnPattern.get(i).isEmpty()) {
          lawnPattern.remove(i);
          continue;
        }
        i++;
      }
      if(lawnPattern.isEmpty()) break;

      int min = Integer.MAX_VALUE;
      int minr = 0;
      int minc = 0;

      // Find the minimum most height. This is part of the path the lawnmower mowed
      // the most.
      for(int row = 0; row < lawnPattern.size(); row++) {
        for(int col = 0; col < lawnPattern.get(0).size(); col++) {
          if (min > lawnPattern.get(row).get(col)) {
            minr = row;
            minc = col;
            min = lawnPattern.get(row).get(col);
          }
        }
      }

      // If all squares on this path are NOT the same size (either the row or column)
      // then something's wrong -- We're told that the lawnmower enters one edge and
      // goes all the way through.
      int first = 0;
      boolean rowMowedFully = true, columnMowedFully = true;

      first = lawnPattern.get(minr).get(0);
      for (int col = 1; col < lawnPattern.get(minr).size(); col++) {
        if (lawnPattern.get(minr).get(col) != first) {
          rowMowedFully = false;
        }
      }

      first = lawnPattern.get(0).get(minc);
      for(int row = 1; row < lawnPattern.size(); row++) {
        if (lawnPattern.get(row).get(minc) != first) {
          columnMowedFully = false;
        }
      }

      // If both the row and column aren't mowed fully, something's wrong
      if(! rowMowedFully && !columnMowedFully) {
        return false;
      }

      // We can discard the mowed row or column
      if (columnMowedFully) {
        for(int row = 0; row < lawnPattern.size(); row++) {
          lawnPattern.get(row).remove(minc);
        }
      } else if(rowMowedFully) {
        lawnPattern.remove(minr);
      }
      continue;
    }
    return true;
  }

  public static void main(String args[])
  {
    File file = new File("./suveshp-2013-qual-B-large.out");
    BufferedReader br;
    try {
      if (!file.exists()) {
        file.createNewFile();
      }
      FileWriter fw = new FileWriter(file.getAbsoluteFile());
      BufferedWriter bw = new BufferedWriter(fw);

      br = new BufferedReader(new FileReader("./B-large.in"));

      // First read the no. of test cases
      int noOfTestCases = Integer.parseInt(br.readLine());

      for(int i = 0; i < noOfTestCases; i++) {
        String[] tokens = br.readLine().split(" ");
        // No. of rows and columns on this lawnPattern
        int rows = Integer.parseInt(tokens[0]);
        int cols = Integer.parseInt(tokens[1]);

        // Read the data into lawnPatterm
        ArrayList<ArrayList<Integer>> lawnPattern = new ArrayList<ArrayList<Integer>>();

        for(int row = 0; row < rows; row++) {
          lawnPattern.add(new ArrayList<Integer>());
          String[] rowHeights = br.readLine().split(" ");
          for(int col = 0; col < cols; col++) {
            lawnPattern.get(row).add(Integer.parseInt(rowHeights[col]));
          }
        }
        // Output for this test case
        bw.write("Case #"
                 + (i+1)
                 + ": "
                 + (isLawnPatternPossible(lawnPattern)
                    ? "YES"
                    : "NO")
                 + "\n");
      }
      bw.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}