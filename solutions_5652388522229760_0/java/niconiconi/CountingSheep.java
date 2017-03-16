package com.company;

import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class CountingSheep {

    static Scanner in;
    static boolean check(int[] arr)
    {
        for(int i = 0; i < 10; ++i)
            if(arr[i]==(0))
                return true;
        return false;
    }
    static int ord(char x)
    {
        if(x == '0')
            return 0;
        if(x == '1')
            return 1;
        if(x == '2')
            return 2;
        if(x == '3')
            return 3;
        if(x == '4')
            return 4;
        if(x == '5')
            return 5;
        if(x == '6')
            return 6;
        if(x == '7')
            return 7;
        if(x == '8')
            return 8;

        if(x == '9')
            return 9;
        throw new RuntimeException("fuck");
    }

    static void solve()
    {
        BigInteger t = BigInteger.valueOf(in.nextInt()), sum = BigInteger.valueOf(0);
        if(t.equals(BigInteger.ZERO))
            System.out.println("INSOMNIA");
        else
        {
            int[] arr = new int[10];
            int ans = 0;
            while(check(arr))
            {
                ans++;
                sum = sum.add(t);
                String s = sum.toString();
                for(int i = 0; i < s.length(); ++i)
                {
                    int Ord = ord(s.charAt(i));
                    arr[Ord]++;
                }
            }
            System.out.println(sum);
        }
    }
    public static void main(String[] args) {
        in = new Scanner(new InputStreamReader(System.in));
        int T = in.nextInt();
        for(int i = 0; i < T; ++i)
        {
            System.out.print("Case #" + (i + 1) + ": ");
            solve();
        }
    }
}
