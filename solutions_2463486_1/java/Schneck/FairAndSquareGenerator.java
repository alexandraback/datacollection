// This class was used to generate a list of all fair and square numbers up to 10^100, 
// which was saved as a file used as input to the other class.
// Some manual command-line post-processing was done to remove extra data, add "9", and sort.

import java.math.BigInteger;

public class FairAndSquareGenerator {

    static boolean isPalindrome(BigInteger n) {
        return isPalindrome(String.valueOf(n));
    }
    
    static boolean isPalindrome(String s) {
        for(int i = 0; i<s.length()/2; i++) {
            if(s.charAt(i)!=s.charAt(s.length()-1-i)) return false;
        }
        return true;
    }

    public static String getNext(String s) {
        StringBuilder sb = new StringBuilder(s);
        for(int i = sb.length() - 1; i>=0; i--) {
            if(sb.charAt(i)=='0') {
                sb.setCharAt(i,'1');
                return sb.toString();
            } else {
                sb.setCharAt(i, '0');
            }
        }
        return "1" + sb.toString();
    }
    
    /**
     * @param args
     */
    public static void main(String[] args) {
        String s = "";
        while(true) {
            checkPrefix(s);
            String next = getNext(s);
            if(next.length() > s.length()) {
                checkPrefix(twoAndZeros(s.length()));
                System.out.println(">" + next.length());
            }
            s = next;
        }
    }
    
    private static String twoAndZeros(int n) {
        StringBuilder sb = new StringBuilder("2");
        for(int i = 0; i < n; i++) {
            sb.append("0");
        }
        return sb.toString();
    }

    private static void checkPrefix(String s) {
        for(int i = -1; i <= 2; i++) {
            BigInteger m;
            String srev = new StringBuilder(s).reverse().toString();
            if(i==-1) {
                if(s.isEmpty()) continue;
                m = new BigInteger(s + srev);
            }
            else m = new BigInteger(s + i + srev);
            if(isPalindrome(m)) {
                BigInteger square = m.multiply(m);
                if(isPalindrome(square)) {
                    System.out.println(m + " -> " + square);
                }
            }
        }
    }

}
