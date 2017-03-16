package com.company;

import java.math.BigInteger;

/**
 * Created by xietiancheng on 16/4/9.
 */
public class CoinJam {
    public static void main(String[] args)
    {
        int N, J;
        N = 16; J = 50;
        long one = 1;
        System.out.println("Case #1:");
        for(long i = 0; i < (one << N) && J > 0; ++i)
        {
            if((i & (one << (N - 1))) == 0 || (i & 1) == 0)
                continue;
            String str = "";
            BigInteger sum;

            for(int j = 0; j < N; ++j)
            {
                if((i & (one << j)) == 0)
                    str = str + "0";
                else
                    str = str + "1";
            }

            boolean succ = true;
            for(int b = 2; b <= 10; ++b)
            {
                sum = BigInteger.valueOf(0);
                BigInteger t = BigInteger.valueOf(1);
                for(int j = str.length() - 1; j >= 0; --j)
                {
                    if(str.charAt(j) == '1')
                        sum = sum.add(t);
                    t = t.multiply(BigInteger.valueOf(b));
                }
                if(sum.isProbablePrime(1000))
                    succ = false;
            }
            if(succ)
            {
                J--;
                System.out.print(str);
                for(int b = 2; b <= 10; ++b)
                {
                    sum = BigInteger.valueOf(0);
                    BigInteger t = BigInteger.valueOf(1);
                    for(int j = str.length() - 1; j >= 0; --j)
                    {
                        if(str.charAt(j) == '1')
                            sum = sum.add(t);
                        t = t.multiply(BigInteger.valueOf(b));
                    }
                    BigInteger divisor;
                    System.out.print(" ");
                    for(divisor = BigInteger.valueOf(2); ; divisor = divisor.add(BigInteger.ONE))
                    {
                        if(sum.mod(divisor).equals(BigInteger.ZERO))
                            break;
                    }
                    System.out.print(divisor);
                }
                System.out.println();
            }

        }
    }
}
