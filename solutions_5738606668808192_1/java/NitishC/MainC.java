import java.math.BigInteger;
import java.util.Scanner;

public class MainC {

    private static BigInteger sqrt(BigInteger x) {
        BigInteger div = BigInteger.ZERO.setBit(x.bitLength()/2);
        BigInteger div2 = div;
        // Loop until we hit the same value twice in a row, or wind
        // up alternating.
        for(;;) {
            BigInteger y = div.add(x.divide(div)).shiftRight(1);
            if (y.equals(div) || y.equals(div2))
                return y;
            div2 = div;
            div = y;
        }
    }

    private static boolean isPalindrome(String s) {
        int i=0, j=s.length() -1;
        while(i<j) {
            if(s.charAt(i++) != s.charAt(j--))
                return false;

        }
        return true;
    }

    private static BigInteger prime(BigInteger big) {
        BigInteger two = BigInteger.ONE.add(BigInteger.ONE);
        for(BigInteger i = two; sqrt(big).compareTo(i) >= 0; i = i.add(BigInteger.ONE)) {
            if(big.remainder(i).equals(BigInteger.ZERO)) {
                return i;
            }
        }
        return BigInteger.ZERO;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Case #1:");
        int J=0, i=0;
        BigInteger arr[] = new BigInteger[9];
        String s = "10000000000000000000000000000001";
        outer: while(J<500) {
            char c[] = s.toCharArray();
            String b = Integer.toBinaryString(i);
            i++;
            for(int j=s.length()-2, k=b.length()-1; k>=0; k--, j--) {
                c[j] = b.charAt(k);
            }
            b=new String(c);
            if(!isPalindrome(b)) {
                continue;
            }
            for(int j=2; j<=10;j++) {
                BigInteger big = new BigInteger(b, j);
                arr[j-2] = prime(big);
                if(BigInteger.ZERO.equals(arr[j-2])) {
                    continue outer;
                }
            }
            J++;
            System.out.print(b);
            for(int j=0; j<9;j++) {
                System.out.print(" " + arr[j]);
            }
            System.out.println();

        }
    }
}
