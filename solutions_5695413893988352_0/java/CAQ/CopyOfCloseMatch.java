/**
 * 
 * Copyright 2016 RSVP Technologies Inc. All rights reserved. CloseMatch.java
 * 
 */
package round1B;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Anqi Cui (caq@rsvptech.ca)
 * @date Apr 30, 2016
 */
public class CopyOfCloseMatch {
  static final String PROB = "B", SIZE = "small", NUMTRY = "3";
  static final String FILENAME = PROB + "-" + SIZE
      + (SIZE.equals("large") ? "" : "-attempt" + NUMTRY);

  static BufferedWriter bw;
  static {
    try {
      bw = new BufferedWriter(new FileWriter("output/" + FILENAME + ".out"));
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  static void print(String s) throws IOException {
    System.out.print(s);
    bw.write(s);
  }

  static void println() throws IOException {
    System.out.println();
    bw.newLine();
  }

  static List<String> generatePossibleStrings(String input) {
    List<String> result = new ArrayList<>();
    if (input.length() == 0)
      return result;

    List<String> first = new ArrayList<>();
    if (input.charAt(0) == '?') {
      for (char c = '0'; c <= '9'; c++) {
        first.add(c + "");
      }
    } else {
      first.add(input.charAt(0) + "");
    }
    List<String> next = generatePossibleStrings(input.substring(1));

    for (String f : first) {
      if (next.size() > 0) {
        for (String n : next) {
          result.add(f + n);
        }
      } else
        result.add(f);
    }

    return result;
  }

  public static void main(String[] args) throws Exception {
    try (Scanner scanner = new Scanner(new File("input/" + FILENAME + ".in"))) {
      int T = scanner.nextInt();
      scanner.nextLine();
      for (int t = 0; t < T; t++) {
        print("Case #" + (t + 1) + ": ");

        String S = scanner.nextLine();
        String[] hiddenScores = S.trim().split(" ");
        String C = hiddenScores[0], J = hiddenScores[1];

        List<String> possibleCs = generatePossibleStrings(C), possibleJs =
            generatePossibleStrings(J);

        String answer = "";
        int difference = -1;
        for (String pc : possibleCs) {
          for (String pj : possibleJs) {
            int intC = Integer.parseInt(pc, 10), intJ = Integer.parseInt(pj, 10);
            int diff = intC - intJ;
            if (diff < 0)
              diff = -diff;
            if (difference < 0 || diff < difference) {
              difference = diff;
              answer = pc + " " + pj;
            }
          }
        }

        print(answer);
        println();
      }
    }
    bw.close();
  }
}
