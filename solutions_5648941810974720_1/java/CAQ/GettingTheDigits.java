/**
 * 
 * Copyright 2016 RSVP Technologies Inc. All rights reserved. GettingTheDigits.java
 * 
 */
package round1B;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @author Anqi Cui (caq@rsvptech.ca)
 * @date Apr 30, 2016
 */
public class GettingTheDigits {
  static final String PROB = "A", SIZE = "large", NUMTRY = "0";
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

  public static void main(String[] args) throws Exception {
    try (Scanner scanner = new Scanner(new File("input/" + FILENAME + ".in"))) {
      int T = scanner.nextInt();
      scanner.nextLine();
      for (int t = 0; t < T; t++) {
        print("Case #" + (t + 1) + ": ");
        Map<Character, Integer> letters = new HashMap<>();
        int[] numbers = new int[10];

        String S = scanner.nextLine();
        for (char c : S.trim().toCharArray()) {
          Integer count = letters.get(c);
          if (count == null)
            count = 0;
          letters.put(c, count + 1);
        }

        /*
         * ZERO
         */
        while (letters.containsKey('Z')) {
          numbers[0]++;
          for (char c : new char[] {'Z', 'E', 'R', 'O'}) {
            letters.put(c, letters.get(c) - 1);
            if (letters.get(c) == 0)
              letters.remove(c);
          }
        }

        /*
         * TWO
         */
        while (letters.containsKey('W')) {
          numbers[2]++;
          for (char c : new char[] {'T', 'W', 'O'}) {
            letters.put(c, letters.get(c) - 1);
            if (letters.get(c) == 0)
              letters.remove(c);
          }
        }

        /*
         * FOUR
         */
        while (letters.containsKey('U')) {
          numbers[4]++;
          for (char c : new char[] {'F', 'O', 'U', 'R'}) {
            letters.put(c, letters.get(c) - 1);
            if (letters.get(c) == 0)
              letters.remove(c);
          }
        }

        /*
         * SIX
         */
        while (letters.containsKey('X')) {
          numbers[6]++;
          for (char c : new char[] {'S', 'I', 'X'}) {
            letters.put(c, letters.get(c) - 1);
            if (letters.get(c) == 0)
              letters.remove(c);
          }
        }

        /*
         * EIGHT
         */
        while (letters.containsKey('G')) {
          numbers[8]++;
          for (char c : new char[] {'E', 'I', 'G', 'H', 'T'}) {
            letters.put(c, letters.get(c) - 1);
            if (letters.get(c) == 0)
              letters.remove(c);
          }
        }

        /*
         * THREE
         */
        while (letters.containsKey('R')) {
          numbers[3]++;
          for (char c : new char[] {'T', 'H', 'R', 'E', 'E'}) {
            letters.put(c, letters.get(c) - 1);
            if (letters.get(c) == 0)
              letters.remove(c);
          }
        }

        /*
         * FIVE
         */
        while (letters.containsKey('F')) {
          numbers[5]++;
          for (char c : new char[] {'F', 'I', 'V', 'E'}) {
            letters.put(c, letters.get(c) - 1);
            if (letters.get(c) == 0)
              letters.remove(c);
          }
        }

        /*
         * SEVEN
         */
        while (letters.containsKey('S')) {
          numbers[7]++;
          for (char c : new char[] {'S', 'E', 'V', 'E', 'N'}) {
            letters.put(c, letters.get(c) - 1);
            if (letters.get(c) == 0)
              letters.remove(c);
          }
        }

        /*
         * ONE
         */
        while (letters.containsKey('O')) {
          numbers[1]++;
          for (char c : new char[] {'O', 'N', 'E'}) {
            letters.put(c, letters.get(c) - 1);
            if (letters.get(c) == 0)
              letters.remove(c);
          }
        }

        /*
         * NINE
         */
        while (letters.containsKey('I')) {
          numbers[9]++;
          for (char c : new char[] {'N', 'I', 'N', 'E'}) {
            letters.put(c, letters.get(c) - 1);
            if (letters.get(c) == 0)
              letters.remove(c);
          }
        }

        for (int n = 0; n <= 9; n++) {
          for (int c = 0; c < numbers[n]; c++) {
            print(n + "");
          }
        }
        println();
      }
    }
    bw.close();
  }
}
