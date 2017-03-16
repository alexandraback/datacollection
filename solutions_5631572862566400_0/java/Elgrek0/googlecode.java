/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Paris
 */
public class googlecode {

    public static void main(String args[]) throws FileNotFoundException, IOException {

        BufferedReader in = new BufferedReader(new FileReader("C-small-attempt2.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
        int T = Integer.parseInt(in.readLine());

        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(in.readLine());
            int[] bffs = new int[N];
            String[] bffs_s = in.readLine().split(" ");
            for (int k = 0; k < N; k++) {
                bffs[k] = Integer.parseInt(bffs_s[k]) - 1;
            }
            int max = -1;
            int curr;

            List<Integer> passed = new ArrayList<>();
            List<List<Integer>> best = new ArrayList<>();
            List<List<Integer>> best2 = new ArrayList<>();
            for (int k = 0; k < N; k++) {
                passed = new ArrayList<>();

                passed.add(k);
                curr = bffs[k];
                passed.add(curr);

                while (!passed.contains(bffs[curr])) {
                    curr = bffs[curr];
                    passed.add(curr);
                }
                while (passed.size() > 2 && bffs[passed.get(passed.size() - 1)] != passed.get(0)
                        && bffs[passed.get(passed.size() - 1)] != passed.get(passed.size() - 2)) {
                    passed.remove(passed.size() - 1);
                }
                if (passed.size() == 2 && bffs[passed.get(1)] != passed.get(0)) {
                    passed.remove(passed.size() - 1);
                }
                if (passed.size() == 1) {
                    passed.remove(0);
                }
                if (passed.size() > max) {
                    best.clear();
                    best.add(passed);
                    max = passed.size();

                } else if (passed.size() == max) {
                    best.add(passed);
                }
            }
            int max2 = 0;
            for (int k = 0; k < best.size(); k++) {
                List<Integer> currlist = best.get(k);
                for (int m = 0; m < currlist.size(); m++) {

                    if (!currlist.contains(m)) {
                        passed.clear();
                        curr = m;
                        passed.add(curr);
                        int tail = 1;
                        int next = bffs[curr];
                        while (!currlist.contains(next) && !passed.contains(next)) {
                            curr = next;
                            passed.add(curr);
                            next = bffs[curr];
                            tail++;
                        }
                        if (next == currlist.get(currlist.size() - 1)) {
                            if (max2 < tail) {
                                max2 = tail;
                                best2.add(passed);
                            }
                        }
                    }
                }

            }

            if (false) {
                for (int k = 0; k < N; k++) {
                    System.out.print(bffs[k] + " ");
                }
            }

            //System.out.println("");

            if (false) {
                for (int k = 0; k < best.size(); k++) {
                    System.out.print(best.get(k) + " ");
                }
            }

           // System.out.println("");

           // System.out.println();

            out.append("Case #" + (i + 1) + ": "+(max + max2));
            out.append("\n");

        }
        out.close();

    }
}
