package com.company;

import java.util.Objects;
import java.util.Scanner;

/**
 * Created by xietiancheng on 16/4/9.
 */
public class Pancakes {
    static Scanner in;
    static void solve()
    {
        String s = in.nextLine();
        if(Objects.equals(s, ""))
            throw new RuntimeException("no no no");
        int ans = 0;
        int encounter = 0;
        for(int i = 0; i < s.length(); )
        {
            int haveMinus = 0;
            int j;
            for(j = i; j < s.length() && s.charAt(j) == '-'; ++j)
            {
                haveMinus = 1;
            }
            i = j + 1;
            if(haveMinus != 0)
            {
                ans = ans + encounter + 1;
            }
            encounter = 1;
        }
        System.out.println(ans);
    }
    public static void main(String[] args)
    {
        in = new Scanner(System.in);
        int T = in.nextInt();
        in.nextLine();
        for(int i = 0; i < T; ++i)
        {
            System.out.print("Case #" + (i + 1) + ": ");
            solve();
        }
    }
}
