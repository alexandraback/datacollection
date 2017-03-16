import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;

public class A {
  public static void main(String[] args) throws Exception {
    if (args.length != 2) {
      System.err.println("Usage: java A <input> <output>");
      System.exit(1);
    }
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    new File(args[1]).getParentFile().mkdirs();
    BufferedWriter bw = new BufferedWriter(new FileWriter(args[1]));
    String line;
    line = br.readLine();
    int num = 1;
    while ((line = br.readLine()) != null) {
      if (line.length() == 0) {
        continue;
      }
      String[] parts = line.split(" ");
      BigInteger r = new BigInteger(parts[0]);
      BigInteger t = new BigInteger(parts[1]);
      BigInteger x = r.add(one).pow(2).subtract(r.pow(2)).subtract(two);
      BigInteger from = new BigInteger("1"),
          to = new BigInteger("10").pow(18);
      while (true) {
        if (to.subtract(one).equals(from)) {
          break;
        }
        if (!works(x, from, t)) {
          break;
        }
        BigInteger mid = from.add(to.subtract(from).divide(two));
        if (works(x, mid, t)) {
          from = mid;
        } else {
          to = mid;
        }
      }
      bw.write("Case #" + num++ + ": " + from + "\n");
    }
    br.close();
    bw.close();
  }
  private static BigInteger one = new BigInteger("1"),
      two = new BigInteger("2");
  private static boolean works(BigInteger x, BigInteger n, BigInteger t) {
    BigInteger y = x.multiply(n).add(n.pow(2).multiply(two));
    return y.compareTo(t) <= 0;
  }
}

