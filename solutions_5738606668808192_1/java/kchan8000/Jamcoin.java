import java.util.*;
import java.io.*;
import java.math.*;

public class Jamcoin {

  private final static int[] PRIMES = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

  private final static int[] RADIXES = {2,3,4,5,6,7,8,9,10};

  private final static int PRIME_CERTAINTY = 2;
  
  public static void main(String cmdArgs[]) throws Exception {
    long time = System.currentTimeMillis();

    String filename = cmdArgs[0];

    BufferedWriter writer =
      new BufferedWriter(new PrintWriter(filename + "-output.txt", "UTF-8"));
    BufferedReader reader = new BufferedReader(new FileReader(filename));

    String nextLine;
    nextLine = reader.readLine(); // ignore count
    int caseNum = 1;
    while ((nextLine = reader.readLine()) != null) {
      String[] args = nextLine.split(" ");
      writer.write("Case #" + caseNum + ": ");
      writer.newLine();
      alg(writer, Integer.valueOf(args[0]), Integer.valueOf(args[1]));
      caseNum++;
    }
    writer.close();
    System.out.println(System.currentTimeMillis() - time);
  }

  // dumb
  public static void alg(BufferedWriter writer, int N, int J) throws Exception {
    int j = 0;
    int trialNum = 0;
    while (j < J) {
      String trial = getBitRepresentation(trialNum, N);
      String output = testTrial(trial);
      if (output != null) {
        writer.write(trial);
        writer.write(output);
        writer.newLine();
        j++;
      }
      trialNum++;
    }
  }

  /**
   * Given a bit encoding, output either a string of 9 factors
   * of each radixes interpretation or null if one of the interpretations
   * is not prime.
   */
  public static String testTrial(String trial) {
    StringBuilder output = new StringBuilder();
    for (int radix : RADIXES) {
      BigInteger num = new BigInteger(trial, radix);
      if (num.isProbablePrime(PRIME_CERTAINTY)) {
        return null;
      }
      boolean factorFound = false;
      for (int prime : PRIMES) {
        if (num.mod(BigInteger.valueOf(prime)).equals(BigInteger.ZERO)) {
          output.append(" " + prime);
          factorFound = true;
          break;
        }
      }
      if (!factorFound) {
        return null;
      }
    }
    return output.toString();
  }

  /**
   * given an int, transform it into 1....
   */
  public static String getBitRepresentation(int trialNum, int length) {
    String trialRepresentation = Integer.toBinaryString(trialNum);
    StringBuilder representation = new StringBuilder();
    representation.append("1");
    for (int i = 0; i < length - trialRepresentation.length() - 2; i++) {
      representation.append("0");
    }
    representation.append(trialRepresentation);
    representation.append("1");
    return representation.toString();
  }
}
