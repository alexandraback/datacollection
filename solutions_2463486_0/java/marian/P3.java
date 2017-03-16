package codejam.y2013.q;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.text.DecimalFormat;
import java.text.FieldPosition;
import java.util.StringTokenizer;

public class P3 {

  public static long[] precomputedFairAndSquare = new long[] {
    0l, // 0
    1l, // 1
    4l, // 2
    9l, // 3
    121l, // 11
    484l, // 22
    10201l, // 101
    12321l, // 111
    14641l, // 121
    40804l, // 202
    44944l, // 212
    1002001l, // 1001
    1234321l, // 1111
    4008004l, // 2002
    100020001l, // 10001
    102030201l, // 10101
    104060401l, // 10201
    121242121l, // 11011
    123454321l, // 11111
    125686521l, // 11211
    400080004l, // 20002
    404090404l, // 20102
    10000200001l, // 100001
    10221412201l, // 101101
    12102420121l, // 110011
    12345654321l, // 111111
    40000800004l, // 200002
    1000002000001l, // 1000001
    1002003002001l, // 1001001
    1004006004001l, // 1002001
    1020304030201l, // 1010101
    1022325232201l, // 1011101
    1024348434201l, // 1012101
    1210024200121l, // 1100011
    1212225222121l, // 1101011
    1214428244121l, // 1102011
    1232346432321l, // 1110111
    1234567654321l, // 1111111
    4000008000004l, // 2000002
    4004009004004l, // 2001002
    100000020000001l, // 10000001
    100220141022001l, // 10011001
    102012040210201l, // 10100101
    102234363432201l, // 10111101
    121000242000121l, // 11000011
    121242363242121l, // 11011011
    123212464212321l, // 11100111
    123456787654321l, // 11111111
    400000080000004l, // 20000002
    10000000200000001l, // 100000001
    10002000300020001l, // 100010001
    10004000600040001l, // 100020001
    10020210401202001l, // 100101001
    10022212521222001l, // 100111001
    10024214841242001l, // 100121001
    10201020402010201l, // 101000101
    10203040504030201l, // 101010101
    10205060806050201l, // 101020101
    10221432623412201l, // 101101101
    10223454745432201l, // 101111101
    12100002420000121l, // 110000011
    12102202520220121l, // 110010011
    12104402820440121l, // 110020011
    12122232623222121l, // 110101011
    12124434743442121l, // 110111011
    12321024642012321l, // 111000111
    12323244744232321l, // 111010111
    12343456865434321l, // 111101111
    12345678987654321l, // 111111111
    40000000800000004l, // 200000002
    40004000900040004l, // 200010002
  };
  public static void main(String[] args) throws Exception {
    //calculateAllFairAndSquareNumbers(100000000, true);

    BufferedReader inputFile = new BufferedReader(new InputStreamReader(
        new FileInputStream(args[0])));
    int cases = Integer.parseInt(inputFile.readLine());

    PrintStream outFile = new PrintStream(new FileOutputStream(args[1]));
    for (int inputNo = 1; inputNo <= cases; inputNo++) {
      String[] ab = tokenize(inputFile.readLine());
      long a = Long.parseLong(ab[0]);
      long b = Long.parseLong(ab[1]);

      int result = 0;
      // the array is so small that dumb search is fast enough.
      // otherwise, binary search for both ends would be optimal
      for (long fs : precomputedFairAndSquare) {
        if (a <= fs && fs <= b)
          result++;
      }

      outFile.println("Case #" + inputNo + ": " + result);
    }
    outFile.close();
    inputFile.close();
  }

  // boringly fast for large input #1
  public static void calculateAllFairAndSquareNumbers(long limit, boolean javaCode) {
    for (long i = 0; i <= limit; i++) {
      if (isPalindrome(i) && isPalindrome(i * i))
        if (javaCode)
          System.out.println(i * i + "l, // " + i);
        else
          System.out.println(i + " -> " + i * i);
    }
  }
  public static boolean isPalindrome(long a) {
    String as = Long.toString(a);
    return isPalindrome(as);
  }
  private static boolean isPalindrome(String as) {
    int l = as.length();
    int m = l / 2;
    for (int i = 0; i < m; i++) {
      if (as.charAt(i) != as.charAt(l - 1 - i))
        return false;
    }
    return true;
  }

  public static String[] tokenize(String input) {
    StringTokenizer st = new StringTokenizer(input);
    String[] k = new String[st.countTokens()];
    for (int i = 0; i < k.length; i++)
      k[i] = st.nextToken();
    return k;
  }

  public static String[] tokenize(String input, String sep) {
    StringTokenizer st = new StringTokenizer(input, sep);
    String[] k = new String[st.countTokens()];
    for (int i = 0; i < k.length; i++)
      k[i] = st.nextToken();
    return k;
  }

  public static String formatDouble(double myDouble, String format) {
    DecimalFormat dfFormat = new DecimalFormat(format);
    FieldPosition f = new FieldPosition(0);
    StringBuffer s = new StringBuffer();
    dfFormat.format(myDouble, s, f);
    return s.toString();
  }
}
