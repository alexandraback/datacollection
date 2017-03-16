package gcj2013.qualification;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {
    List<Long> palindromes = new ArrayList<Long>();
    long[] pow = new long[11];

    long reverse(long d) {
        long res = 0;
        while (d > 0) {
            res = res * 10 + d % 10;
            d /= 10;
        }
        return res;
    }

    boolean isPalindrome(long d) {
        char[] digits = Long.toString(d).toCharArray();
        for (int i = 0, j = digits.length - 1; i < j; i++, j--) {
            if (digits[i] != digits[j]) {
                return false;
            }
        }
        return true;
    }
    
    void check(long d) {
        if (isPalindrome(d * d)) {
            palindromes.add(d);
        }
    }

    void gen1(int l) {
        for (long i = l == 1 ? 0 : pow[l/2-1]; i <= pow[l/2] - 1; i++) {
            for (int j = 0; j <= 9; j ++) {
                check(i * pow[l/2+1] + j * pow[l/2] + reverse(i));
            }
        }
    }

    void gen2(int l) {
        for (long i = l == 2 ? 1 : pow[l/2-1]; i <= pow[l/2] - 1; i++) {
            check(i * pow[l/2] + reverse(i));
        }
    }

    void doOneCase(Scanner scan) {
        long a = scan.nextLong();
        long b = scan.nextLong();

        long sa = (long)Math.sqrt(a);
        while (sa * sa < a) {
            sa++;
        }
        long sb = (long)(Math.sqrt(b)+1);
        while (sb * sb > b) {
            sb--;
        }

        int res = 0;
        for (int i = 0; i < palindromes.size(); i++) {
            long p = palindromes.get(i);
            if (p >= sa && p <= sb) {
                res++;
            }
            if (p > sb) {
                break;
            }
        }

        System.out.println(res);
    }
    
    public void solve() {
        pow[0] = 1;
        for (int i = 1; i <= 10; i++) {
            pow[i] = pow[i-1] * 10;
            if (i % 2 == 1) {
                gen1(i);
            } else {
                gen2(i);
            }
        }
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.print("Case #" + i + ": ");
            doOneCase(scan);
        }
    }
    
    public static final void main(final String[] args) {
        new C().solve();
    }


}
