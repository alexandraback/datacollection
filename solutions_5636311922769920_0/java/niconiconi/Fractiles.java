package com.company;

import java.util.Scanner;

/**
 * Created by xietiancheng on 16/4/9.
 */
public class Fractiles {
    public static void main(String[] args)
    {
        int T, K, C, S;
        Scanner in = new Scanner(System.in);
        T = in.nextInt();
        for(int i = 0; i < T; ++i)
        {
            System.out.print("Case #" + (i + 1) + ":");
            K = in.nextInt();
            C = in.nextInt();
            S = in.nextInt();
            for(int j = 0; j < S; ++j)
                System.out.print(" " + (j + 1));
            System.out.println();
        }
    }
}
