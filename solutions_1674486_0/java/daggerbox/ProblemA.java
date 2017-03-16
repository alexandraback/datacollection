package com.forthgo.google.g2012r1c;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.BitSet;
import java.util.Scanner;

/**
 * Created by Xan Gregg.
 * Date: 4/27/12
 */
public class ProblemA {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("A.in"));
            PrintWriter out = new PrintWriter(new FileWriter("A.out"));
//            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                int nn = in.nextInt();
                out.printf("Case #%d:", i + 1);
                boolean diamond = solve(in, nn);
                out.printf(" %s%n", diamond ? "Yes" : "No");
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    private static boolean solve(Scanner in,int n) {
        BitSet[] parents = new BitSet[n];
        int[] nParents = new int[n];
        for (int i = 0; i < n; i++) {
            nParents[i] = in.nextInt();
            parents[i] = new BitSet();
            for (int j = 0; j < nParents[i]; j++) {
                parents[i].set(in.nextInt() - 1);
            }
        }

        for (int i = 0; i < n; i++) {
            int[] todo = new int[n];
            BitSet anc = new BitSet();
            int q = 0;
                for (int j = parents[i].nextSetBit(0); j >= 0; j = parents[i].nextSetBit(j + 1)) {
                    if (!anc.get(j)) {
                        anc.set(j);
                        todo[q++] = j;
                    }
                    else {
                        return true;
                    }
                }
                for (int k = 0; k < q; k++) {
                    for (int j = parents[todo[k]].nextSetBit(0); j >= 0; j = parents[todo[k]].nextSetBit(j + 1)) {
                        if (!anc.get(j)) {
                            anc.set(j);
                            todo[q++] = j;
                        }
                        else {
                            return true;
                        }
                    }

                }

        }
        return false;
    }


}

