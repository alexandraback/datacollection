package com.sdu.practice.codeJam.qualification;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Scanner;


public class CountingSheep {

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
                int n = Integer.parseInt(line.trim());
                int result = n;
                int i = 0;

                if (n == 0) {
                    writer.write("Case #" + caseT + ": INSOMNIA");
                    writer.newLine();
                } else {
                    HashSet<Integer> set = new HashSet<Integer>();
                    for (int j = 0; j < 10; j++) {
                        set.add(j);
                    }

                    while(set.size() != 0) {
                        i++;
                        result = n * i;
                        int tempR = result;

                        while (tempR - tempR % 10 != 0) {
                            int lastDigit = tempR % 10;
                            tempR = (tempR - lastDigit) / 10;
                            set.remove(lastDigit);
                        }
                        set.remove(tempR);
                    }

                    writer.write("Case #" + caseT + ": " + result);
                    writer.newLine();
                }
            }
            scanner.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }


    public static void main(String[] args) throws Exception {

        CountingSheep countingSheep = new CountingSheep();
        String inputFile = "codeJam/2016/CountingSheep/A-large.in";
        String outputFIle = "codeJam/CountingSheep_large.out";

        countingSheep.process(inputFile, outputFIle);

    }
}
