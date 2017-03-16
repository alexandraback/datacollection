import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * Created by Derick on 4/8/2016.
 */
public class Main {

  static HashSet<Integer> primeSet;
  static List<Integer> primeList;

  public static void main(String[] args) throws IOException {
    BufferedReader input = new BufferedReader(new FileReader("testIn"));
    BufferedWriter output = new BufferedWriter(new FileWriter("out.out"));

    int numCases = Integer.valueOf(input.readLine());
    primeList = genPrimesErastothenes(1 << 16);
    primeSet = new HashSet<>(primeList);
    ArrayList<String> answers = new ArrayList<>();

    for (int caseNo = 0; caseNo < numCases; caseNo++) {
      String[] tokens = input.readLine().split(" ");
      int n = Integer.valueOf(tokens[0]);
      int j = Integer.valueOf(tokens[1]);
      Set<String> goodCoins = new HashSet<>();

      long maxInternal = (1 << (n - 2));
      for (long i = 0; i < maxInternal && answers.size() < j; i++) {
        String jamCoin = "1" + toFixWidthBinaryString(i, n - 2) + "1";
        List<String> divisors = checkCoin(jamCoin);
        if (divisors != null) {
          answers.add(jamCoin + " " + String.join(" ", divisors));
        }
      }

      output.write("Case #1:\n");
      for (String answer : answers) {
        output.write(answer);
        output.newLine();
      }
      output.flush();
    }



  }

  static List<String> checkCoin(String jamCoin) {
    List<String> divisors = new ArrayList<>();
    nextBase:
    for (int base = 2; base <= 10; base++) {
      BigInteger valueInBase = new BigInteger(jamCoin, base);
      for (long divisor : primeList) {
        BigInteger divisorBI = BigInteger.valueOf(divisor);
        if (valueInBase.mod(divisorBI).equals(BigInteger.ZERO) && !divisorBI.equals(valueInBase)) {
          divisors.add(Long.toString(divisor));
          continue nextBase;
        }
      }
      return null;
    }
    return divisors;
  }

  static String toFixWidthBinaryString(long num, int width) {
    char[] result = new char[width];
    for (int i = 0; i < width; i++) {
      result[i] = ((num >> i) & 1) == 1 ? '1' : '0';
    }
    return String.valueOf(result);
  }

  static ArrayList<Integer> genPrimesErastothenes(int to) {
    ArrayList<Integer> primes = new ArrayList<>();
    ArrayList<Integer> toCheck = new ArrayList<>();
    for (int i = 2; i <= to; i++) {
      toCheck.add(i);
    }
    while (toCheck.get(0) < Math.sqrt(to)) {
      ArrayList<Integer> newC = new ArrayList<>();
      int n = toCheck.get(0);
      primes.add(n);
      for (Integer i : toCheck) {
        if (i % n != 0) {
          newC.add(i);
        }
      }
      toCheck = newC;

    }
    for (Integer i : toCheck) {
      primes.add(i);
    }

    return primes;
  }
}
