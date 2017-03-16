/*
 * (C) 2015 National Australia Bank
 *
 * [All rights reserved]. This product and related documentation are protected
 * by copyright restricting its use, copying, distribution, and decompilation.
 * No part of this product or related documentation may be reproduced in any
 * form by any means without prior written authorization of
 * National Australia Bank. Unless otherwise arranged, third parties may not
 * have access to this product or related documents.
 */
package com.vahid.contest.codejam.codejam2015.round1c;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Problem1 {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new File("input.txt"));
        BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
        int n = input.nextInt();
        for (int counter = 1; counter <= n; counter++){
            int r = input.nextInt();
            int c = input.nextInt();
            int w = input.nextInt();
            output.write("Case #" + counter + ": " + solve(r,c,w));
            output.newLine();
        }
        input.close();
        output.close();
    }

    private static int solve(int r, int c, int w) {
        int result = c / w;

        if (result*w != c)
            result++;

        return result + (w-1) + ((r-1)*(c/w));

    }
}
