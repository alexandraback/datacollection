package com.cst1.gcj2016;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * @author camiel
 */
public class CoinJam {

  private final static String BASE_DIR =
    "/Users/camiel/Documents/projects/google_code_jam/solutions/2016_qualification_round";


  public static void main(String[] args) throws IOException {
    solveAll("C-small-attempt0");
  }

  private static void solveAll(String name) throws IOException {
    try (
      Scanner sc = new Scanner(new File(String.format("%s/input/%s.in", BASE_DIR, name)));
      PrintWriter out = new PrintWriter(String.format("%s/output/%s.out", BASE_DIR, name), StandardCharsets.UTF_8.name());
    ) {

      sc.nextInt();
      new Solver(out, sc.nextInt(), sc.nextInt()).solve();
    }
  }

  private static class Solver {
    final PrintWriter out;
    final int n;
    final int j;
    final ArrayList<Integer> primes = new ArrayList<>();

    Solver(PrintWriter out, int n, int j) {
      this.out = out;
      this.n = n;
      this.j = j;
    }

    void solve() {
      out.println("Case #1:");

      fillPrimes((int) Math.ceil(Math.sqrt(Long.valueOf(leftPad("", '1', n), 10))));

      generateJamCoins(n, j);
    }

    void fillPrimes(int maxValue) {
      int current = 2;
      BitSet seen = new BitSet();

      while (current < maxValue) {
        primes.add(current);
        seen.set(current, true);

        for (int i = current * 2; i <= maxValue && i >= 0; i += current) {
          seen.set(i, true);
        }

        do {
          current++;
        } while (current < maxValue && seen.get(current));
      }
    }

    int pow(int a, int b) {
      int r = 1;
      for (int i = 0; i < b; i++) {
        r *= a;
      }

      return r;
    }

    String leftPad(String s, char ch, int n) {
      StringBuilder builder = new StringBuilder();

      while (builder.length() < n - s.length()) {
        builder.append(ch);
      }

      builder.append(s);
      return builder.toString();
    }

    int getNonPrimeProof(long i) {
      for (int p : primes) {
        if (p < i && i % p == 0) {
          return p;
        }
      }

      return 0;
    }

    void generateJamCoins(int n, int j) {
      PriorityQueue<String> candidates = new PriorityQueue<>();

      for (int i = 0; i < pow(2, n - 2); i++) {
        candidates.add('1' + leftPad(Integer.toString(i, 2), '0', n - 2) + '1');
      }

      while (candidates.size() > 0) {
        String s = candidates.poll();
        int[] proofs = new int[11];

        boolean isValid = true;

        for (int b = 2; b <= 10; b++) {
          proofs[b] = getNonPrimeProof(Long.valueOf(s, b));

          if (proofs[b] == 0) {
            isValid = false;
            break;
          }
        }

        if (isValid) {
          out.print(s);

          for (int b = 2; b <= 10; b++) {
            out.print(" " + proofs[b]);
          }

          out.println();

          if (--j == 0) {
            return;
          }
        }
      }
    }
  }
}
