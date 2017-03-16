package com.codejam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by dx on 3/30/16.
 */
public class Main2016FashionPolice {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        Long t = Long.parseLong(in.nextLine());
        for (int i =1; i <= t; ++i) {
            int j = in.nextInt();
            int p = in.nextInt();
            int s = in.nextInt();
            int k = in.nextInt();

            HashMap<String, Integer> used = new HashMap<>();

            int safeDays = 0;

            String combi = "";
            for(int x = 0; x < j; x++) {
                for(int y = 0; y < p; y++) {
                    for(int z = 0; z < s; z++) {
                        if(x == y && y == z) continue;

                        String keyxy = (x + 1) + "," + (y + 1) + ",z";
                        String keyxz = (x + 1) + ",y," + (z + 1);
                        String keyyz = "x," + (y + 1) + "," + (z + 1);

                        Integer usedNumxy = used.get(keyxy);
                        Integer usedNumxz = used.get(keyxz);
                        Integer usedNumyz = used.get(keyyz);

                        if(usedNumxy != null && usedNumxy >= k ||
                                usedNumxz != null && usedNumxz >= k ||
                                usedNumyz != null && usedNumyz >= k) {
                            continue;
                        }

                        if(usedNumxy == null) {
                            used.put(keyxy, 1);
                        }
                        else {
                            used.put(keyxy, usedNumxy + 1);
                        }

                        if(usedNumxz == null) {
                            used.put(keyxz, 1);
                        }
                        else {
                            used.put(keyxz, usedNumxz + 1);
                        }

                        if(usedNumyz == null) {
                            used.put(keyyz, 1);
                        }
                        else {
                            used.put(keyyz, usedNumyz + 1);
                        }

                        safeDays++;
                        combi += "\n" + (x + 1) + " " + (y + 1) + " " + (z + 1);
                    }
                }
            }

            // Re add all same numbers in the end
            for(int z = 0; z < j; z++) {
                String keyxy = (z + 1) + "," + (z + 1) + ",z";
                String keyxz = (z + 1) + ",y," + (z + 1);
                String keyyz = "x," + (z + 1) + "," + (z + 1);

                Integer usedNumxy = used.get(keyxy);
                Integer usedNumxz = used.get(keyxz);
                Integer usedNumyz = used.get(keyyz);

                if(usedNumxy != null && usedNumxy >= k ||
                        usedNumxz != null && usedNumxz >= k ||
                        usedNumyz != null && usedNumyz >= k) {
                    continue;
                }

                if(usedNumxy == null) {
                    used.put(keyxy, 1);
                }
                else {
                    used.put(keyxy, usedNumxy + 1);
                }

                if(usedNumxz == null) {
                    used.put(keyxz, 1);
                }
                else {
                    used.put(keyxz, usedNumxz + 1);
                }

                if(usedNumyz == null) {
                    used.put(keyyz, 1);
                }
                else {
                    used.put(keyyz, usedNumyz + 1);
                }

                safeDays++;
                combi += "\n" + (z + 1) + " " + (z + 1) + " " + (z + 1);
            }

            System.out.print("Case #" + i + ": " + safeDays + combi);
            System.out.println();
        }
    }

}
