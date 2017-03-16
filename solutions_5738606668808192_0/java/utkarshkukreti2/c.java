import java.io.*;
import java.util.*;

class C {
  static boolean isPrime(long n) {
    // System.out.println("isPrime: n = " + n);
    int sqrt = (int) Math.sqrt(n);
    for(int i = 2; i <= sqrt; i++) {
      if(n % i == 0) {
        // System.out.println("isPrime: return false");
        return false;
      }
    }
    // System.out.println("isPrime: return true");
    return true;
  }

  static long firstNonTrivialDivisor(long n) {
    int sqrt = (int) Math.sqrt(n);
    for(int i = 2; i <= sqrt; i++) {
      if(n % i == 0) {
        return i;
      }
    }
    return n; // Should never reach here.
  }

  static void solve(long N, long J) {
    int found = 0;
    for(long i = 0; i < 1 << (N - 2) && found < J; i++) {
      // System.out.println("i = " + i);
      boolean anyPrime = false;
      for(long base = 2; base <= 10; base++) {
        long n = 1;
        long ii = i, multiplier = base;
        for(long tmp = 0; tmp < N - 2; tmp++, multiplier *= base, ii /= 2) {
          // System.out.println("multiplier = " + multiplier + ", ii = " + ii);
          if((ii & 1) == 1) {
            n += multiplier;
          }
        }
        n += multiplier;
        // System.out.println("base = " + base + ", n = " + n);
        anyPrime = anyPrime || isPrime(n);
        if(anyPrime) break;
      }
      if(!anyPrime) {
        String s = "1" + String.format("%1$" + (N - 2) + "s", Long.toBinaryString(i)).replace(' ', '0') + "1";
        System.out.print(s);
        for(int base = 2; base <= 10; base++) {
          System.out.print(" " + firstNonTrivialDivisor(Long.parseLong(s, base)));
        }
        System.out.println();
        found++;
      }
    }
  }

  public static void main (String[] args) throws IOException {
    Scanner scanner = new Scanner(System.in);
    int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      System.out.println("Case #" + t + ":");
      solve(scanner.nextLong(), scanner.nextLong());
    }
  }
}
