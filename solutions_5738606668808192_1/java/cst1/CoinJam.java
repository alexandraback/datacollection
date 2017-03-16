package com.cst1.gcj2016;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.Scanner;

/**
 * @author camiel
 */
public class CoinJam {

  private final static String BASE_DIR =
    "/Users/camiel/Documents/projects/google_code_jam/solutions/2016_qualification_round";


  public static void main(String[] args) throws IOException {
    solveAll("C-large");
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
    final ArrayList<BigInteger> primes = new ArrayList<>();

    Solver(PrintWriter out, int n, int j) {
      this.out = out;
      this.n = n;
      this.j = j;
    }

    void solve() {
      out.println("Case #1:");

      fillPrimes(1_000_000);

      generateJamCoins();
    }

    void generateJamCoins() {
      int tot = j;

      for (int i = 0; i < Integer.MAX_VALUE && tot > 0; i++) {
        String s = '1' + leftPad(Integer.toString(i, 2), '0', n - 2) + '1';
        int[] proofs = null;

        boolean isValid = true;
        for (int b = 2; b <= 10; b++) {
          if (new BigInteger(s, b).isProbablePrime(1)) {
            isValid = false;
            break;
          }
        }

        if (isValid) {
          proofs = new int[11];

          for (int b = 2; b <= 10; b++) {
            proofs[b] = getNonPrimeProof(new BigInteger(s, b));

            if (proofs[b] == 0) {
              isValid = false;
              break;
            }
          }
        }

        if (isValid) {
          out.print(s);

          for (int b = 2; b <= 10; b++) {
            out.print(" " + proofs[b]);
          }

          out.println();
          tot--;
        }
      }
    }

    String leftPad(String s, char ch, int n) {
      StringBuilder builder = new StringBuilder();

      while (builder.length() < n - s.length()) {
        builder.append(ch);
      }

      builder.append(s);

      return builder.toString();
    }

    void fillPrimes(int maxValue) {
      int current = 2;
      BitSet seen = new BitSet();

      while (current < maxValue) {
        primes.add(BigInteger.valueOf(current));

        for (int i = current * 2; i <= maxValue && i >= 0; i += current) {
          seen.set(i, true);
        }

        do {
          current++;
        } while (current < maxValue && seen.get(current));
      }
    }

    int getNonPrimeProof(BigInteger i) {
      for (BigInteger p : primes) {
        if (p.compareTo(i) < 0 && i.mod(p).compareTo(BigInteger.ZERO) == 0) {
          return (int) p.longValue();
        }
      }

      return 0;
    }
  }
}
