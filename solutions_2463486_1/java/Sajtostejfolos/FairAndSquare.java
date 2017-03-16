import java.math.*;
import java.io.*;

public class FairAndSquare {

    private static void debug(String msg) {
        System.err.println(msg);
    }
    
    private static boolean isPalindrome(BigInteger n) {
        char[] chrs = n.toString().toCharArray();
        for (int i = 0; i < chrs.length / 2; ++i)
            if (chrs[i] != chrs[chrs.length - i - 1])
                return false;
        return true;
    }
    
    // jajj, de csúnya
    private static int cnt; 
    private static BigInteger limitA;
    private static BigInteger limitB;
    
    private static void genPalindromes(char[] digits, int pos) {
        int len = digits.length;
        if (pos > (len + 1) / 2 - 1) {
            BigInteger n = new BigInteger(new String(digits));
            //debug("    testing " + n);
            BigInteger nsquare = n.multiply(n);
            
            if ((nsquare.compareTo(limitA) >= 0) && (nsquare.compareTo(limitB) <= 0) && isPalindrome(nsquare)) {
                //debug("  f&s: " + n + " ^2 = " + nsquare);
                ++cnt;
            }
        }
        else {
            int mindigit = (pos == 0) ? 1 : 0;
            int maxdigit = (len == 1) ? 3 : 2;
            for (int digit = mindigit; digit <= maxdigit; ++digit) {
                digits[pos] = digits[len - pos - 1] = Character.forDigit(digit, 10);
                genPalindromes(digits, pos + 1);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        String inputfile = args[0];
        String outputfile = args[1];
        
        BufferedReader in = new BufferedReader(new FileReader(inputfile));
        PrintWriter out = new PrintWriter(new FileWriter(outputfile));
        
        int cases = Integer.parseInt(in.readLine());
        debug("Number of test cases: " + cases);
        
        for (int i = 1; i <= cases; ++i) {
            debug("Processing Case #" + i);

            String[] limits = in.readLine().split(" ");
            assert(limits.length == 2) : "incorrect number of limits " + limits.length;
            limitA = new BigInteger(limits[0]);
            limitB = new BigInteger(limits[1]);
            assert(limitA.compareTo(limitB) <= 0) : "LimitA > LimitB! " + limitA + " " + limitB; 
            debug("  Limits are " + limitA + " and " + limitB);
            int maxlen = (limitB.toString().length() - 1) / 2 + 1;
            int minlen = (limitA.toString().length() - 1) / 2 + 1;
            debug("  maxlen is " + maxlen);
            
            cnt = 0;
            for (int len = minlen; len <= maxlen; ++len)
                genPalindromes(new char[len], 0);
            
            out.println("Case #" + i + ": " + cnt);
        }
        
        out.close();
        in.close();
    }

}
