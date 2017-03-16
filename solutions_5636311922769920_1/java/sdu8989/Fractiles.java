package com.sdu.practice.codeJam.qualification;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Fractiles {

    public void process(String inputFile, String outputFile) {
        ClassLoader classLoader = getClass().getClassLoader();
        File file = new File(classLoader.getResource(inputFile).getFile());

        try (Scanner scanner = new Scanner(file)) {

            String line = scanner.nextLine();
            int t = Integer.parseInt(line.trim());

            int caseT = 0;

            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(
                    new FileOutputStream(outputFile), "utf-8"));

            while (scanner.hasNextLine() && caseT++ <= t) {
                line = scanner.nextLine();
                String[] nums = line.trim().split(" ");

                long k = Long.parseLong(nums[0]);
                long c = Long.parseLong(nums[1]);
                long s = Long.parseLong(nums[2]);

                String result = "";

                if (c == 1) {
                    if(s < k) {
                        result = "IMPOSSIBLE";
                    } else {
                        for (int i = 1; i < k; i++) {
                            result = result + i + " ";
                        }
                        result = result + k;
                    }
                } else {
                    if (s < Math.ceil((double)k / 2)) {
                        result = "IMPOSSIBLE";
                    } else {
                        ArrayList<Long> lvPosition = new ArrayList<>();

                        int l = 2;
                        for (int i = 0; i < k; i = i+2) {
                            if (i == k-1) {
                                lvPosition.add(k * i + (i + 1));
                            } else {
                                lvPosition.add(k * i + (i + 2));
                            }
                        }

                        while (l < c) {
                            l++;
                            for (int i = 0; i < lvPosition.size(); i++) {
                                long n = lvPosition.get(i);
                                lvPosition.remove(i);
                                long newPos = (n - 1) * k + (n-1) % k + 1;
                                lvPosition.add(i, newPos);
                            }
                        }

                        for (int i = 0; i < lvPosition.size(); i++) {
                            result = result + lvPosition.get(i) + " ";
                        }
                        result = result.trim();
                    }

                }

                writer.write("Case #" + caseT + ": " + result);
                writer.newLine();

            }
            scanner.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }


    public static void main(String[] args) throws Exception {

        Fractiles fractiles = new Fractiles();
        String fileName = "D-large";
//        String fileName = "small";
        String inputFile = "codeJam/2016/Qualification/Fractiles/" + fileName + ".in";
        String outputFIle = "codeJam/Fractiles" + fileName + ".out";

        fractiles.process(inputFile, outputFIle);

    }
}