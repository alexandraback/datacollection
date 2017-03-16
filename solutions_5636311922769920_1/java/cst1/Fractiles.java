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
public class Fractiles {

  private final static String BASE_DIR =
    "/Users/camiel/Documents/projects/google_code_jam/solutions/2016_qualification_round";


  public static void main(String[] args) throws IOException {
    solveAll("D-large");
  }

  private static void solveAll(String name) throws IOException {
    try (
      Scanner sc = new Scanner(new File(String.format("%s/input/%s.in", BASE_DIR, name)));
      PrintWriter out = new PrintWriter(String.format("%s/output/%s.out", BASE_DIR, name), StandardCharsets.UTF_8.name());
    ) {

      IntStream
        .range(0, sc.nextInt())
        .boxed()
        .map(i -> new Solver(out, i, sc.nextInt(), sc.nextInt(), sc.nextInt()))
        .forEach(Solver::solve);
    }
  }

  private static class Solver {
    final PrintWriter out;
    final int i;
    final int k;
    final int c;
    final int s;

    Solver(PrintWriter out, int i, int k, int c, int s) {
      this.out = out;
      this.i = i;
      this.k = k;
      this.c = c;
      this.s = s;
    }


    long pow(int a, int b) {
      long c = 1;

      for (int j = 0; j < b; j++) {
        c *= a;
      }

      return c;
    }

    void solve() {
      out.print(String.format("Case #%d:", i + 1));

      int needed = k / c + ((k % c) > 0 ? 1 : 0);

      if (needed > s) {
        out.print(" IMPOSSIBLE");
      } else {
        long maxRi = pow(k, c) - 1;

        for (int i = 0; i < needed; i++) {
          long offset = i * c;
          long ri = 0;

          for (int l = 0; l < c; l++) {
            ri = Math.min(maxRi, ri + offset * pow(k, c - l - 1));
            offset++;
          }

          out.print(" " + (ri + 1));
        }
      }

      out.println();
    }
  }
}
