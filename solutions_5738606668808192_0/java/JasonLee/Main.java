package com.zhixiangli.charconv;

import java.math.BigInteger;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Random;
import java.util.Set;

/**
 * Hello world!
 *
 */

public class Main {
    
    public static BigInteger trans(long n, int base) {
        BigInteger v = BigInteger.ZERO;
        BigInteger tmp = BigInteger.ONE;
        BigInteger b = BigInteger.valueOf(base);
        while (n > 0) {
            if ((n & 1) == 1) {
                v = v.add(tmp);
            }
            tmp = tmp.multiply(b);
            n >>= 1;
        }
        return v;
    }
    
    public static boolean check(long n) {
        for (int i = 2; i <= 10; ++i) {
            BigInteger v = trans(n, i);
            if (v.isProbablePrime(1000)) {
                return false;
            }
        }
        return true;
    }
    
    public static boolean output(long n) {
        List<String> res = new ArrayList<>();
        res.add(Long.toBinaryString(n));
        for (int i = 2; i <= 10; ++i) {
            BigInteger v = trans(n, i);
            for (int j = 2;; ++j) {
                if (v.mod(BigInteger.valueOf(j)) == BigInteger.ZERO) {
                    res.add(String.valueOf(j));
                    break;
                }
            }
        }
        System.out.println(String.join(" ", res));
        return true;
    }
    
    public static void gen(long N, long J) {
        Random r = new SecureRandom();
        Set<Long> set = new HashSet<>();
        while (J > 0) {
            long n = r.nextInt(1 << (N - 2));
            if (set.contains(n)) {
                continue;
            } else {
                set.add(n);
            }
            n = (n << 1) | 1 | (1L << (N - 1));
            if (check(n)) {
                output(n);
                --J;
            }
        }
        
    }
    
    public static void main(String[] args) {
        System.out.println("Case #1:");
        gen(16, 50);
        
    } // main
    
}