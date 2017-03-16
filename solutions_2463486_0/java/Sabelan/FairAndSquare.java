import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class FairAndSquare {

  static ArrayList<BigInteger> specialSet;

  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("FairAndSquare.in"));
    PrintWriter out = new PrintWriter(new File("FairAndSquare.out"));

    ArrayList<Long> goodVals = new ArrayList<Long>();
    for (long i = 1; i <= 1e7; i++) {
      if (isPalindrome(i * i) && isPalindrome(i)) {
        goodVals.add(i * i);
//        System.out.println(i * i);
      }
    }

    specialSet = new ArrayList<BigInteger>();
    specialSet.add(BigInteger.ONE);
    specialSet.add(new BigInteger("4"));
    specialSet.add(new BigInteger("9"));
    for (int digits = 2; digits <= 100; digits++) {
      ArrayList<BigInteger> twoSet = genTwoSet(digits);
      for (BigInteger b : twoSet) {
        specialSet.add(b.multiply(b));
      }
    }

    int cases = in.nextInt();

    for (int caseOn = 1; caseOn <= cases; caseOn++) {
      String a = in.next();
      String b = in.next();

      long aa = Long.parseLong(a);
      long bb = Long.parseLong(b);

      long otherAns = 0;
      for (long goodV : goodVals) {
        if (aa <= goodV && goodV <= bb) {
          otherAns++;
        }
      }

      long ans = CountLessThanOrEqual(b, false);
      ans -= CountLessThanOrEqual(a, true);
      
      System.out.printf("FAST ANSWER = %d\n", ans);

      if (otherAns != ans) {
        System.out.printf("ANSWER DESCREPENCY FOR [%s, %s]\n", a, b);
      }

      out.printf("Case #%d: %d\n", caseOn, otherAns);
      System.out.println();
    }

    out.close();
  }

  public static long CountLessThanOrEqual(String s, boolean subOne) {
    BigInteger b = new BigInteger(s);
    if (subOne) {
      b = b.subtract(BigInteger.ONE);
      if (b.equals(BigInteger.ZERO)) return 0;
    }
    s = b.toString();
    long count = 0;
    for (BigInteger special : specialSet) {
      if (b.compareTo(special) >= 0) {
        // System.out.printf("%s used for %s\n",special,s);
        count++;
      }
    }

    if (s.length() <= 2) return count;

    int len = s.length();
    int lenPalin = (len + 1) / 2;
    int techFreeDig = (lenPalin - 1) / 2;
    for (int i = 0; i < (1 << techFreeDig); i++) {
      long value = (i << 1) | 1;
      long vP = makePalindrome(value, lenPalin);
      BigInteger bval = new BigInteger(Long.toBinaryString(vP));
      bval = bval.multiply(bval);
      if (b.compareTo(bval) >= 0) {
        count++;
      }
    }

    for (int i = 2; i < lenPalin; i++) {
      int shift = (i - 1) / 2;
      count += (1L << shift);
    }
    return count;
  }

  public static long makePalindrome(long value, int newLength) {
    if (newLength % 2 == 1) {
      String s = Long.toBinaryString(value);
      while (s.length() * 2 < newLength) {
        s = '0' + s;
      }
      String ss = s.substring(1);
      StringBuilder sb = new StringBuilder(ss);
      return Long.parseLong(sb.reverse().toString() + s, 2);
    }
    String s = Long.toBinaryString(value);
    while (s.length() * 2 < newLength) {
      s = '0' + s;
    }
    StringBuilder sb = new StringBuilder(s);
    return Long.parseLong(sb.reverse().toString() + s, 2);

  }

  public static ArrayList<BigInteger> genTwoSet(int digits) {
    // digits >= 2
    ArrayList<BigInteger> ret = new ArrayList<BigInteger>();
    if (digits % 2 == 0) {
      String s = "2";
      for (int i = 0; i < digits - 2; i++)
        s += '0';
      s += '2';
      ret.add(new BigInteger(s));
    } else {
      // start 2 string 2...0...2
      String s = "2";
      for (int i = 0; i < digits - 2; i++)
        s += '0';
      s += '2';
      ret.add(new BigInteger(s));

      // start 2 string 2...1...2
      s = "2";
      for (int i = 0; i < (digits / 2) - 1; i++)
        s += '0';
      s += '1';
      for (int i = 0; i < (digits / 2) - 1; i++)
        s += '0';
      s += '2';
      ret.add(new BigInteger(s));

      for (int OnePos = 0; OnePos < digits / 2; OnePos++) {
        s = "1";
        for (int pos = (digits / 2) - 1; pos >= 1; pos--) {
          if (pos == OnePos)
            s += "1";
          else
            s += "0";
        }
        s += "2";
        for (int pos = 1; pos <= (digits / 2) - 1; pos++) {
          if (pos == OnePos)
            s += "1";
          else
            s += "0";
        }
        s += "1";
        ret.add(new BigInteger(s));
      }
    }

    Collections.sort(ret);

    // for (BigInteger b : ret) {
    // System.out.println(b);
    // }

    return ret;
  }

  // Functions used to find the pattern:
  public static boolean isPalindrome(long a) {
    ArrayList<Integer> aList = new ArrayList<Integer>();
    while (a != 0) {
      aList.add((int) (a % 10));
      a /= 10;
    }
    return isPalindrome(aList);
  }

  public static boolean isPalindrome(ArrayList<Integer> alist) {
    for (int i = 0; i < alist.size() / 2; i++) {
      if (alist.get(i) != alist.get(alist.size() - 1 - i)) return false;
    }
    return true;
  }
}
