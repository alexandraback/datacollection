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

public class Problem2 {

    static long counter = 0;
    static int max = 0;
    static long total = 0;
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new File("input.txt"));
        BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
        int n = input.nextInt();
        for (int ccounter = 1; ccounter <= n; ccounter++){
            counter = 0;
            max = 0;
            total = 0;
            int k = input.nextInt();
            int l = input.nextInt();
            int s = input.nextInt();
            input.nextLine();
            String keys = input.nextLine();
            String lookup = input.nextLine();
            output.write("Case #" + ccounter + ": " + find(keys,lookup, s));
            output.newLine();
        }
        input.close();
        output.close();
    }

    private static double find(String keys, String lookup, int s) {
        rec(keys,lookup,s, 1, "");
        return max - ((double)total/(double)counter);
    }

    private static void rec(String keys, String lookup, int s, int c, String current) {
        if (c>s) {
            counter++;
            int i = count(current,lookup);
            if (i>max) max =i;
            total += i;
            return;
        }

        for (int i =0; i< keys.length(); i++){
            rec(keys, lookup, s, c+1, current + keys.charAt(i));
        }
    }

    private static int count(String current, String lookup) {
        int result =0;

        for (int i=0; i<current.length()-lookup.length()+1; i++) {
            if (current.substring(i, i+lookup.length()).equals(lookup))
                result++;
        }
        return result;
    }


}
