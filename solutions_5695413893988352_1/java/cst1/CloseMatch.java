package com.cst1.gcj2016;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

/**
 * @author camiel
 */
@SuppressWarnings({"Duplicates", "ForLoopReplaceableByForEach"})
public class CloseMatch {
  private final static String BASE_DIR =
    "/Users/camiel/Documents/projects/google_code_jam/solutions/2016_round1B";


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

  // try for n and n - 1

  private static class Result {
    int i = 0;
    char[] c;
    char[] j;

    int diff = 0;

    Result(int i, char[] c, char[] j) {
      this.i = i;
      this.c = Arrays.copyOf(c, c.length);
      this.j = Arrays.copyOf(j, c.length);

      for (int k = 0; k < i; k++) {
        if (c[k] < j[k]) {
          diff = -1;
          break;
        } else if (c[k] > j[k]) {
          diff = 1;
          break;
        }
      }
    }

    Result(Result result) {
      this(result.i, result.c, result.j);
    }

    boolean isDone() {
      return i == c.length;
    }

    char currentC() {
      return c[i];
    }

    char currentJ() {
      return j[i];
    }

    Result setCurrentC(char ch) {
      c[i] = ch;
      return this;
    }

    Result setCurrentJ(char ch) {
      j[i] = ch;
      return this;
    }

    Result proceed() {
      this.i++;
      return this;
    }

    Long scoreDiff() {
      return Math.abs(Long.parseLong(new String(c)) - Long.parseLong(new String(j)));
    }

    Result copy() {
      return new Result(this);
    }
  }

  private static Result minimizeDiff(Result result) {
    if (result.isDone()) {
      return result;
    }

    if (result.currentC() == '?' && result.currentJ() == '?') {
      if (result.diff == 0) {
        result
          .setCurrentC('0')
          .setCurrentJ('0');
      } else if (result.diff == -1) {
        result
          .setCurrentC('9')
          .setCurrentJ('0');
      } else {
        result
          .setCurrentC('0')
          .setCurrentJ('9');
      }

      return minimizeDiff(result.proceed());
    } else if (result.currentC() == '?') {

      if (result.diff == 0) {
        Result result1 = minimizeDiff(
          result
            .copy()
            .setCurrentC(result.currentJ() > '0' ? (char) (result.currentJ() - 1) : '0')
            .proceed());

        Result result2 = minimizeDiff(
          result
            .copy()
            .setCurrentC(result.currentJ())
            .proceed());

        Result result3 = minimizeDiff(
          result
            .copy()
            .setCurrentC(result.currentJ() < '9' ? (char) (result.currentJ() + 1) : '9')
            .proceed());

        if (result1.scoreDiff() <= result2.scoreDiff() && result1.scoreDiff() <= result3.scoreDiff()) {
          return result1;
        } else if (result2.scoreDiff() <= result3.scoreDiff()) {
          return result2;
        } else {
          return result3;
        }
      } else if (result.diff == -1) {
        result.setCurrentC('9');
      } else {
        result.setCurrentC('0');
      }

    } else if (result.currentJ() == '?') {

      if (result.diff == 0) {
        Result result1 = minimizeDiff(
          result
            .copy()
            .setCurrentJ(result.currentC() > '0' ? (char) (result.currentC() - 1) : '0')
            .proceed());

        Result result2 = minimizeDiff(
          result
            .copy()
            .setCurrentJ(result.currentC())
            .proceed());

        Result result3 = minimizeDiff(
          result
            .copy()
            .setCurrentJ(result.currentC() < '9' ? (char) (result.currentC() + 1) : '9')
            .proceed());

        if (result1.scoreDiff() <= result2.scoreDiff() && result1.scoreDiff() <= result3.scoreDiff()) {
          return result1;
        } else if (result2.scoreDiff() <= result3.scoreDiff()) {
          return result2;
        } else {
          return result3;
        }
      } else if (result.diff == -1) {
        result.setCurrentJ('0');
      } else {
        result.setCurrentJ('9');
      }
    }

    return minimizeDiff(result.proceed());
  }

  private static String solveCase(String s) {
    System.out.println(s);

    String c = s.split(" ")[0];
    String j = s.split(" ")[1];

    char[] rc = new char[c.length()];
    char[] rj = new char[j.length()];

    Result result = minimizeDiff(new Result(0, s.split(" ")[0].toCharArray(), s.split(" ")[1].toCharArray()));

    System.out.println(new String(result.c) + " " + new String(result.j));

    return new String(result.c) + " " + new String(result.j);
  }
}
