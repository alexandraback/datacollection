package com.cst1.gcj2016;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;
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
    solveAll("B-small-attempt2");
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

  private static final char[] numbers = new char[]{'0','1','2','3','4','5','6','7','8','9'};

  private static final char[] getChars(char c) {
    return c == '?' ? numbers : new char[]{c};
  }

  private static String solveCase(String s) {

    String c = s.split(" ")[0];
    String j = s.split(" ")[1];

    List<String> cPos = new ArrayList<>();
    List<String> jPos = new ArrayList<>();
    cPos.add("");
    jPos.add("");

    for (int i = 0; i < c.length(); i++) {
      List<String> newCPos = new ArrayList<>();
      List<String> newJPos = new ArrayList<>();

      char[] cChars = getChars(c.charAt(i));
      char[] jChars = getChars(j.charAt(i));

      for (int ci = 0; ci < cChars.length; ci++) {
        for (String pos : cPos) {
          newCPos.add(pos + cChars[ci]);
        }
      }

      for (int ci = 0; ci < jChars.length; ci++) {
        for (String pos : jPos) {
          newJPos.add(pos + jChars[ci]);
        }
      }

      cPos = newCPos;
      jPos = newJPos;
    }

    long minDiff = Integer.MAX_VALUE;
    List<String> minCombs = new ArrayList<>();

    for (String pc : cPos) {
      for (String jc : jPos) {
        long diff = Math.abs(Long.parseLong(pc) - Long.parseLong(jc));

        if (diff < minDiff) {
          minDiff = diff;
          minCombs = new ArrayList<>();
        }

        if (diff == minDiff) {
          minCombs.add(pc + " " + jc);
        }
      }
    }

    long minC = Long.parseLong(minCombs.get(0).split(" ")[0]);
    long minJ = Long.parseLong(minCombs.get(0).split(" ")[1]);

    for (String comb : minCombs) {
      long pc = Long.parseLong(comb.split(" ")[0]);
      long pj = Long.parseLong(comb.split(" ")[1]);

      if (pc < minC) {
        minC = pc;
        minJ = pj;
      } else if (pc == minC && pj < minJ) {
        minJ = pj;
      }
    }

    return String.format("%0" + c.length() + "d %0" + j.length() + "d", minC, minJ);
  }
}
