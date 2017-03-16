/** Suvesh Pratapa
 *  suveshp@gmail.com
 *
 *  2013 Google Code Jam - Qualification Round
 *  Question C - Fair and Square
 */

package qualc;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;

public class QualC2013 {

  // First let's make a lookup table of all known fair and square
  // numbers <= 10^14
  // I'd like to note here that this is in NO way a mathematical
  // or computing problem. The palindromic feature is purely
  // lexical, and finding palindromes that are "fair and square"
  // now becomes a problem of how fast we can sieve through known
  // data to get to the interesting points. So why not use lookups?
  // This information is out there for public consumption, and as
  // far as I know Code Jam rules don't prohibit lookup tables.

  // This sort of method is of course not feasible for numbers
  // up to 10^100; I suspect I will have to search for patterns
  // here to try and see how to approach that. But this works fine
  // for both small and large-1 sets of this question.

  public static int NO_OF_KNOWN_FAIR_AND_SQUARES = 39;
  public static String[] knownFairAndSquares = {
                /*1*/                   "1",
                /*2*/                   "4",
                /*3*/                   "9",
                /*11*/                "121",
                /*22*/                "484",
                /*101*/             "10201",
                /*111*/             "12321",
                /*121*/             "14641",
                /*202*/             "40804",
                /*212*/             "44944",
                /*1001*/          "1002001",
                /*1111*/          "1234321",
                /*2002*/          "4008004",
                /*10001*/       "100020001",
                /*10101*/       "102030201",
                /*10201*/       "104060401",
                /*11011*/       "121242121",
                /*11111*/       "123454321",
                /*11211*/       "125686521",
                /*20002*/       "400080004",
                /*20102*/       "404090404",
                /*100001*/    "10000200001",
                /*101101*/    "10221412201",
                /*110011*/    "12102420121",
                /*111111*/    "12345654321",
                /*200002*/    "40000800004",
                /*1000001*/ "1000002000001",
                /*1001001*/ "1002003002001",
                /*1002001*/ "1004006004001",
                /*1010101*/ "1020304030201",
                /*1011101*/ "1022325232201",
                /*1012101*/ "1024348434201",
                /*1100011*/ "1210024200121",
                /*1101011*/ "1212225222121",
                /*1102011*/ "1214428244121",
                /*1110111*/ "1232346432321",
                /*1111111*/ "1234567654321",
                /*2000002*/ "4000008000004",
                /*2001002*/ "4004009004004"
  };

  public static int numberOfFairAndSquares(BigInteger min, BigInteger max)
  {
    int rangeLeft = 0, rangeRight = 0;
    for (int i = 0; i < NO_OF_KNOWN_FAIR_AND_SQUARES; i++)
    {
      if(min.compareTo(new BigInteger(knownFairAndSquares[i])) <= 0) {
        rangeLeft = i;
        break;
      }
    }
    
    for (int i = NO_OF_KNOWN_FAIR_AND_SQUARES - 1; i >= 0; i--)
    {
      if(max.compareTo(new BigInteger(knownFairAndSquares[i])) >= 0) {
        rangeRight = i;
        break;
      }
    }
    return rangeRight - rangeLeft + 1;
  }

  public static void main(String args[])
  {
    BufferedReader br;
    try {
      br = new BufferedReader(new FileReader("./C-small-attempt0.in"));
      String line = br.readLine();
      int testCases = Integer.parseInt(line);
      for (int i = 0; i < testCases; i++) {
        line = br.readLine();
        String[] tokens = line.split(" ");
        System.out.println("Case #" + (i+1) + ": " + numberOfFairAndSquares(new BigInteger(tokens[0]), new BigInteger(tokens[1])));
      }
      br.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
