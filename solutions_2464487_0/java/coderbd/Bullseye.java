import java.io.*;
import java.util.*;
import java.math.*;

public class Bullseye {
  public BufferedReader br;
  public int test;
  public BigInteger r, t, low, up, mid;
  public String ans;
  public static BigInteger TWO = new BigInteger("2");
  public void go() throws Throwable {
    br = new BufferedReader(new InputStreamReader(System.in));
    test = Integer.parseInt(br.readLine());
    for (int caseNo = 1; caseNo <= test; caseNo++) {
      String[] ss = br.readLine().split(" +");
      r = new BigInteger(ss[0]);
      t = new BigInteger(ss[1]);
      low = BigInteger.ONE;
      up = new BigInteger("1000000000000000000000");
      while (low.compareTo(up) <= 0) {
        mid = low.add(up).divide(TWO);
        if (mid.multiply(r.multiply(TWO).add(mid.multiply(TWO)).subtract(BigInteger.ONE)).compareTo(t) <= 0) {
          ans = mid.toString();
          low = mid.add(BigInteger.ONE);
        }
        else
          up = mid.subtract(BigInteger.ONE);
      }
      System.out.println("Case #" + caseNo + ": " + ans);
    }
  }
  public static void main(String[] args) throws Throwable {
    new Bullseye().go();
  }
}
