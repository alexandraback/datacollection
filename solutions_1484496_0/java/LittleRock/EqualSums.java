/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package com.demister.gcj;


import java.util.*;
import java.io.*;


/**
 *
 * @author rock
 */
public class EqualSums {

    public EqualSums() {
    }

    public int[][] getSubsets(int[] nums) {
        int count = 1 << nums.length;
        int[] sums = new int[count];
        for (int i = 0; i < count; i++) {
            sums[i] = 0;
            for (int j = 0; j < nums.length; j++) {
                if ((i & (1 << j)) != 0) {
                    sums[i] += nums[j];
                }
            }
        }
        int[][] reval = null;
        boolean found = false;
        for (int i = 1; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (sums[i] == sums[j]) {
                    reval = new int[2][];
                    reval[0] = new int[Integer.bitCount(i)];
                    reval[1] = new int[Integer.bitCount(j)];
                    int index1 = 0;
                    int index2 = 0;
                    for (int k = 0; k < nums.length; k++) {
                        if ((i & (1 << k)) != 0) {
                            reval[0][index1++] = nums[k];
                        }
                        if ((j & (1 << k)) != 0) {
                            reval[1][index2++] = nums[k];
                        }
                    }
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
            
        }
        return reval;
    }
    
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileReader("in.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
        EqualSums dealer = new EqualSums();

        int numOfTests = in.nextInt();

        for (int i = 0; i < numOfTests; i++) {
            out.printf("Case #%d: ", i + 1);

            int n = in.nextInt();
            int[] nums = new int[n];
            for (int j = 0; j < nums.length; j++) {
                nums[j] = in.nextInt();
            }
            
            int[][] subsets = dealer.getSubsets(nums);
            if (subsets == null) {
                out.print("Impossible");
            } else {
                out.println();
                for (int j = 0; j < subsets[0].length; j++) {
                    out.print(subsets[0][j] + " ");
                }
                out.println();
                for (int j = 0; j < subsets[1].length; j++) {
                    out.print(subsets[1][j] + " ");
                }
            }
            out.println();
            out.flush();
        }

        in.close();
        out.close();
    }
}
