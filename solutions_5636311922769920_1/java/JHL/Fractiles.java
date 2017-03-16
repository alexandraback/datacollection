import java.io.*;
import java.util.*;
import java.nio.file.*;
import java.nio.charset.*;
import java.math.*;

public class Fractiles {

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

    Path outPath = FileSystems.getDefault().getPath("out.txt");
    Charset charset = Charset.forName("UTF-8");
    try (BufferedWriter writer = Files.newBufferedWriter(outPath, charset)) {
      for (int i = 0; i < cases.size(); i++) {
        int caseNumber = i + 1;
        String out = "Case #" + caseNumber + ": ";
        BigInteger[] pos = fractileCheck(cases.get(i));
        if (pos == null) {
          out += "IMPOSSIBLE\n";
        } else {
          for (int j = 0; j < pos.length; j++) {
            out += pos[j].toString();
            if (j != pos.length - 1) {
              out += " ";
            } else {
              out += "\n";
            }
          }
        }
        writer.write(out, 0, out.length());
      }
    } catch (IOException e) {
      System.err.format("IOException - %s", e);
    }
  }

  private static BigInteger[] fractileCheck(String in) {
    String[] input = in.split(" ");
    int k = Integer.parseInt(input[0]);
    int c = Integer.parseInt(input[1]);
    int s = Integer.parseInt(input[2]);
    int required = ceiling(k, c);
    if (required > s) {
      return null;
    }

    BigInteger[] pos = new BigInteger[required];
    for (int i = 0; i < required; i++) {
      pos[i] = pos(i, k, c).add(BigInteger.ONE);
    }
    return pos;
  }

  private static BigInteger pos(int caseNum, int base, int pow) {
    BigInteger position = BigInteger.ZERO;
    int current = Math.min(base - 1, (caseNum + 1) * pow - 1);
    int minimum = caseNum * pow;
    for (int i = 0; i < pow && current >= minimum; i++) {
      BigInteger baseBig = BigInteger.valueOf(base);
      BigInteger currentBig = BigInteger.valueOf(current);
      position = position.add(baseBig.pow(i).multiply(currentBig));
      current--;
    }
    return position;
  }

  private static int ceiling(int num, int div) {
    int r = num / div;
    if (num % div == 0) {
      return r;
    } else {
      return (r + 1);
    }
  }

}
