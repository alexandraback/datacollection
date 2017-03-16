package com.cst1.gcj2016;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.Map;
import java.util.Scanner;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * @author camiel
 */
public class GettingTheDigits {
  private final static String BASE_DIR =
    "/Users/camiel/Documents/projects/google_code_jam/solutions/2016_round1B";


  public static void main(String[] args) throws IOException {
    solveAll("A-small-attempt0");
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

  private static int Z = (int) 'Z';
  private static int O = (int) 'O';
  private static int W = (int) 'W';
  private static int H = (int) 'H';
  private static int U = (int) 'U';
  private static int I = (int) 'I';
  private static int V = (int) 'V';
  private static int S = (int) 'S';
  private static int X = (int) 'X';
  private static int G = (int) 'G';

  private static void removeAll(Map<Integer, Long> cs, long[] counts, int i) {
    numbers[i].chars().forEach(c -> cs.put(c, cs.get(c) - counts[i]));
  }

  private static String solveCase(String s) {
    System.out.println(s);
    Map<Integer, Long> cs = s.chars().boxed().collect(
      Collectors.groupingBy(Function.identity(), Collectors.counting()));

    for (int i = 0; i < 10; i++) {
      numbers[i]
        .chars()
        .filter(c -> !cs.containsKey(c))
        .distinct()
        .forEach(c -> cs.put(c, 0L));
    }

    long[] counts = new long[10];

    counts[0] = cs.get(Z);
    removeAll(cs, counts, 0);

    counts[2] = cs.get(W);
    removeAll(cs, counts, 2);

    counts[4] = cs.get(U);
    removeAll(cs, counts, 4);

    counts[6] = cs.get(X);
    removeAll(cs, counts, 6);

    counts[7] = cs.get(S);
    removeAll(cs, counts, 7);

    counts[5] = cs.get(V);
    removeAll(cs, counts, 5);

    counts[8] = cs.get(G);
    removeAll(cs, counts, 8);

    counts[3] = cs.get(H);
    removeAll(cs, counts, 3);

    counts[9] = cs.get(I);
    removeAll(cs, counts, 9);

    counts[1] = cs.get(O);


    StringBuilder result = new StringBuilder();

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < counts[i]; j++) {
        result.append(i);
      }
    }

    return result.toString();
  }

  private static String[] numbers = new String[]{
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
  };
}
