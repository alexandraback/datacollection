package com.sdu.practice.codeJam.qualification;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;


public class RevengeOfThePancakes {

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
                char[] chars = line.trim().toCharArray();

                int count = 0;

                if (chars.length > 1) {
                    for (int i = 1; i < chars.length; i++) {
                        if (chars[i] != chars[i - 1]) {
                            count++;

                        }
                    }
                }

                if (chars[chars.length - 1] == '-') {
                    count++;
                }

                writer.write("Case #" + caseT + ": " + count);
                writer.newLine();

            }
            scanner.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }


    public static void main(String[] args) throws Exception {

        RevengeOfThePancakes revengeOfThePancakes = new RevengeOfThePancakes();
//        String fileName = "B-small-attempt0";
        String fileName = "B-large";
        String inputFile = "codeJam/2016/Pancakes/" + fileName + ".in";
        String outputFIle = "codeJam/Pancakes_" + fileName + ".out";

        revengeOfThePancakes.process(inputFile, outputFIle);

    }
}
