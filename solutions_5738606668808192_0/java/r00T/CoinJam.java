package gcj16.qualification.c;

import java.util.Scanner;

public class CoinJam {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    scanner.nextInt();
    int n = scanner.nextInt();
    int j = scanner.nextInt();
    processTestCase(n, j);
  }

  private static void processTestCase(int n, int times) {
    System.out.println("Case #1:");
    String sequence = "1";
    for(int i = 1 ;i< n; i++) {
      sequence += "0";
    }
    int count = 0;
    while(count < times) {
      if(isValidJamCoin(sequence)) {
        count++;
        System.out.print(sequence);
        for(int i = 2 ; i<= 10; i++) {
          System.out.print(" " + getNonTrivialDivisor(Long.parseLong(sequence, i)));
        }
        System.out.println();
      }
      sequence = getNextSequence(sequence);
    }
  }

  private static long getNonTrivialDivisor(long n) {
    for (long i = 2; i*i <= n; i++) {
      if(n%i == 0) {
        return i;
      }
    }
    return 0;
  }

  private static boolean isPrime(long n) {
    for (long i = 2; i*i <= n; i++) {
      if(n%i == 0) {
        return false;
      }
    }
    return true;
  }
  private static boolean isValidJamCoin(String sequence) {
    if(sequence.charAt(sequence.length() - 1) == '0') {
      return false;
    }
    if(sequence.charAt(0) == '0') {
      return false;
    }
    for (int i = 2; i <= 10; i++) {
      long number = Long.parseLong(sequence, i);
      if(isPrime(number)) {
        return false;
      }
    }
    return true;
  }

  public static String getNextSequence(String sequence) {
    int lasIndexOfZero = sequence.lastIndexOf('0');
    if(lasIndexOfZero < 0) {
      return "NA";
    }
    String nextSequence = sequence.substring(0, lasIndexOfZero) + "1";
    String trailingZeroes = "";
    for(int i = 0 ; i < sequence.length() - lasIndexOfZero -1; i++) {
      trailingZeroes += "0";
    }
    return nextSequence + trailingZeroes;
  }

}
