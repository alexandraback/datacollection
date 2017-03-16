import java.io.*;
import java.util.*;
import java.nio.file.*;
import java.nio.charset.*;
import java.math.*;

public class CoinJam {

  public static void main(String[] args) {
    String file = args[0];
    List<String> cases = new ArrayList<>();

    Path inPath = FileSystems.getDefault().getPath(file);
    try (BufferedReader reader = Files.newBufferedReader(inPath)) {
      String line = null;
      boolean firstLine = true;
      while ((line = reader.readLine()) != null) {
        if (firstLine) {
          firstLine = false;
        } else {
          cases.add(line);
        }
      }
    } catch (IOException e) {
      System.err.format("IOException - %s", e);
    }

    Charset charset = Charset.forName("UTF-8");
    Path outPath = FileSystems.getDefault().getPath("out.txt");
    try (BufferedWriter writer = Files.newBufferedWriter(outPath, charset)) {
      for (int i = 0; i < cases.size(); i++) {
        int caseNumber = i + 1;
        String out = "Case #" + caseNumber + ": \n";
        JamNumber[] numbers = jam(cases.get(i));
        int count = 0;
        for (JamNumber j : numbers) {
          count++;
          out += j.getNumber() + " ";
          long[] divisors = j.getDivisors();
          for (int k = 0; k < divisors.length; k++) {
            out += divisors[k];
            if (k != divisors.length - 1) {
              out += " ";
            } else {
              out += "\n";
            }
          }
        }
        writer.write(out, 0, out.length());
        if (i != cases.size() - 1) {
          writer.newLine();
        }
      }
    } catch (IOException e) {
      System.err.format("IOException - %s", e);
    }

  }

  private static class JamNumber {
    private long[] divisors;
    private String number;

    public JamNumber(String number, long[] divisors) {
      this.number = number;
      this.divisors = divisors;
    }

    public long[] getDivisors() {
      return this.divisors;
    }

    public String getNumber() {
      return this.number;
    }
  }

  private static JamNumber[] jam(String s) {
    String[] in = s.split(" ");
    int n = Integer.parseInt(in[0]);
    int j = Integer.parseInt(in[1]);
    int cases = (int) Math.pow(2.0, (double) n - 2.0);
    JamNumber[] numbers = new JamNumber[j];
    int currentNumbers = 0;
    int currentCase = 0;

    while (currentNumbers < j && currentCase < cases) {
      String currentNumber = caseToJamNumber(currentCase, n - 2);
      long[] divisors = new long[9];
      boolean isJam = true;
      for (int i = 2; i <= 10; i++) {
        BigInteger convertedNum = baseConvert(currentNumber, i);
        long divisor = isPrime(convertedNum, divisors);
        if (divisor == -1) {
          isJam = false;
        } else {
          divisors[i - 2] = divisor;
        }
      }
      if (isJam) {
        numbers[currentNumbers] = new JamNumber(currentNumber, divisors);
        currentNumbers++;
      }
      currentCase++;
    }

    return numbers;
  }

  private static String caseToJamNumber(int caseNum, int len) {
    String middle = "";
    int temp = caseNum;
    while (temp != 0) {
      switch (temp % 2) {
        case 0:
          middle = '0' + middle;
          break;
        case 1:
          middle = '1' + middle;
          break;
      }
      temp /= 2;
    }
    int numZeros = len - middle.length();
    return "1" + zeros(numZeros) + middle + "1";
  }

  private static BigInteger baseConvert(String s, int base) {
    BigInteger converted = BigInteger.valueOf(0);
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s.charAt(i) == '1') {
        int power = s.length() - i - 1;
        converted = converted.add(BigInteger.valueOf(base).pow(power));
      }
    }
    return converted;
  }

  private static String zeros(int n) {
    String r = "";
    for (int i = 0; i < n; i++) {
      r += '0';
    }
    return r;
  }

  // courtesy of Edward Falk
  // source: http://stackoverflow.com/a/16804098/4412423
  private static BigInteger sqrt(BigInteger x) {
    BigInteger div = BigInteger.ZERO.setBit(x.bitLength() / 2);
    BigInteger div2 = div;
    for (;;) {
      BigInteger y = div.add(x.divide(div)).shiftRight(1);
      if (y.equals(div) || y.equals(div2)) {
        return y;
      }
      div2 = div;
      div = y;
    }
  }

  private static long isPrime(BigInteger n, long[] divisors) {
    BigInteger maxSqrt = sqrt(n);
    long maxCheck = maxSqrt.longValue();
    for (long i = 2; i < maxCheck; i++) {
      if (n.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO) && !longContains(divisors, i)) {
        return i;
      }
    }
    return -1;
  }

  private static boolean longContains(long[] arr, long val) {
    for (int i = 0; i < arr.length; i++) {
      if (arr[i] == val) {
        return true;
      }
    }
    return false;
  }

}
