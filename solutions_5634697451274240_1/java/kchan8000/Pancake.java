import java.util.*;
import java.io.*;

public class Pancake {
  public static void main(String args[]) throws Exception {
    long time = System.currentTimeMillis();

    String filename = args[0];

    BufferedWriter writer =
      new BufferedWriter(new PrintWriter(filename + "-output.txt", "UTF-8"));
    BufferedReader reader = new BufferedReader(new FileReader(filename));

    String nextLine;
    nextLine = reader.readLine(); // ignore count
    int caseNum = 1;
    while ((nextLine = reader.readLine()) != null) {
      // top is 0th idx
      String stack = nextLine;
      writer.write("Case #" + caseNum + ": ");
      String output = null; // # of changes + 1 IFF bottom is '-'
      output = "" + slow(stack);
      writer.write(output);
      caseNum++;
      writer.newLine();
    }
    writer.close();
    System.out.println(System.currentTimeMillis() - time);
  }

  /* broken
  public static int fast(String stack) {
    System.out.println(stack);
    //2*'-+' +1 if start with +, + 1 if end with -
    int changes = (stack.length() - stack.replaceAll("(-\\+|\\+-)", "").length()) / 2;
    
    System.out.println(changes);
    if (changes == 0) {
      if (stack.charAt(0) == '+') {
        return 0;
      } else {
        return 1;
      }
    }
    if (stack.charAt(0) == '+') {
      changes++;
    }
    if (stack.charAt(stack.length() - 1) == '-') {
      changes++;
    }
    return changes;
  }
  */

  public static int slow(String stack) {
    char lastPancake = stack.charAt(0);
    int changes = 0;
    for (char pancake : stack.toCharArray()) {
      if (pancake == lastPancake) {
        continue;
      }
      changes++;
      lastPancake = pancake;
    }
    if (stack.endsWith("-")) {
      changes++;
    }
    return changes;
  }
}
