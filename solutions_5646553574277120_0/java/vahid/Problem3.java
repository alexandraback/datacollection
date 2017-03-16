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
import java.util.Arrays;
import java.util.Objects;
import java.util.Scanner;
import java.util.TreeSet;

public class Problem3 {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new File("input.txt"));
        BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
        int n = input.nextInt();
        for (int counter = 1; counter <= n; counter++){
            int c= input.nextInt();
            int d = input.nextInt();
            int v = input.nextInt();
            int[] dList = new int[d];
            for (int i=0; i<d; i++)
                dList[i] = input.nextInt();

            output.write("Case #" + counter + ": " + coin(v,c,dList));
            output.newLine();
        }
        input.close();
        output.close();
    }

    private static int coin(int v, int c, int[] dList) {
        TreeSet<Long> set = buildSet(dList);

        int result =0;

        for (int i=1; i<=v; i++){
            if (!set.contains((long)i)){
                result++;
                add(set,i);
            }
        }

        return result;
    }

    private static TreeSet<Long> buildSet(int[] dList) {
        TreeSet<Long> set = new TreeSet<Long>();
        for (int i=0; i<dList.length; i++){
            add(set, dList[i]);
        }
        return set;
    }

    private static void add(TreeSet<Long> set, int x) {
        Object[] list =  set.toArray();
        set.add((long) x);
        for (Object w : list){
            Long i = ((Long)w);
            set.add(i.longValue()+x);
        }
    }
}
