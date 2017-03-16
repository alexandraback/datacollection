package com.cst1.gcj2016;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;
import java.util.stream.IntStream;

/**
 * @author camiel
 */
public class RevengeOfThePancakes {

  private final static String BASE_DIR =
    "/Users/camiel/Documents/projects/google_code_jam/solutions/2016_qualification_round";


  public static void main(String[] args) throws IOException {
    solveAll("B-large");
  }

  private static String formatAnswer(int i, String answer) {
    return String.format("Case #%d: %s", i + 1, answer);
  }

  private static void solveAll(String name) throws IOException {
    try (
      Scanner sc = new Scanner(new File(String.format("%s/input/%s.in", BASE_DIR, name)));
      PrintWriter out = new PrintWriter(String.format("%s/output/%s.out", BASE_DIR, name), StandardCharsets.UTF_8.name());
    ) {

      IntStream
        .range(0, Integer.parseInt(sc.nextLine()))
        .boxed()
        .map(i -> formatAnswer(i, solveCase(sc.nextLine())))
        .forEach(out::println);
    }
  }

  private static String solveCase(String s) {
    return minSteps(s.toCharArray()) + "";
  }

  private static int minSteps(char[] stack) {
    int l = stack.length - 1;
    int c = 0;

    while (l >= 0) {
      while (l >= 0 && stack[l] == '+') {
        l--;
      }

      if (l >= 0) {
        int negsBack = 0;

        while (l - negsBack >= 0 && stack[l - negsBack] == '-') {
          negsBack++;
        }

        while (true) {
          int negsFront = 0;

          while (negsFront <= l && stack[negsFront] == '-') {
            negsFront++;
          }

          if (negsFront >= negsBack) {
            c++;
            flip(stack, l + 1);
            break;
          } else {
            int i = 1;

            while (i <= l && stack[i] == stack[i - 1]) {
              i++;
            }

            c++;
            flip(stack, i);
          }
        }
      }
    }

    return c;
  }

  private static void flip(char[] stack, int i) {
    for (int j = 0; j < i / 2; j++) {
      char tmp = stack[j];
      stack[j] = reverse(stack[i - 1 - j]);
      stack[i - 1 - j] = reverse(tmp);
    }

    if (i % 2 == 1) {
      stack[i / 2] = reverse(stack[i / 2]);
    }
  }

  private static char reverse(char c) {
    return c == '-' ? '+' : '-';
  }
}
