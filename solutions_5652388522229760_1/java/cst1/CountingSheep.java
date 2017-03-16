package com.cst1.gcj2016;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;
import java.util.stream.IntStream;

public class CountingSheep {

  private static class Case {
    final int i;
    final long n;

    Case(int i, long n) {
      this.i = i;
      this.n = n;
    }

    String answer() {

      return String.format("Case #%d: %s", i + 1, getLastNumber());
    }

    boolean[] getNumbers(long j) {
      boolean[] result = new boolean[10];

      do {
        result[(int) j % 10] = true;
        j /= 10;
      } while (j > 0);

      return result;
    }

    String getLastNumber() {
      if (i == 0) {
        return "INSOMNIA";
      } else {
        boolean[] seen = new boolean[10];

        for (int i = 1; i < 1000; i++) {
          boolean[] numbers = getNumbers(i * n);

          short c = 0;
          for (int k = 0; k < 10; k++) {
            seen[k] = seen[k] || numbers[k];

            if (seen[k]) {
              c++;
            }
          }

          if (c == 10) {
            return (i * n) + "";
          }
        }
      }

      return "INSOMNIA";
    }
  }

  private final static String BASE_DIR =
    "/Users/camiel/Documents/projects/google_code_jam/solutions/2016_qualification_round";

  private static void solve(String name) throws IOException {
    try (
      Scanner sc = new Scanner(new File(String.format("%s/input/%s.in", BASE_DIR, name)));
      PrintWriter out = new PrintWriter(String.format("%s/output/%s.out", BASE_DIR, name), StandardCharsets.UTF_8.name());
    ) {

      IntStream
        .range(0, sc.nextInt())
        .boxed()
        .map(i -> new Case(i, sc.nextLong()))
        .map(Case::answer)
        .forEach(out::println);
    }
  }

  public static void main(String[] args) throws IOException {
    solve("A-large");
  }
}
