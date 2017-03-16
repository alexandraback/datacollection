package com.sdu.practice.codeJam.qualification;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class CoinJam {

    public void process(String inputFile, String outputFile) {
        ClassLoader classLoader = getClass().getClassLoader();
        File file = new File(classLoader.getResource(inputFile).getFile());

        try (Scanner scanner = new Scanner(file)) {

            String line = scanner.nextLine();
            int totalCases = Integer.parseInt(line.trim());

            int caseT = 0;

            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(
                    new FileOutputStream(outputFile), "utf-8"));

            while (scanner.hasNextLine() && caseT++ <= totalCases) {
                writer.write("Case #" + caseT + ":");
                writer.newLine();

                line = scanner.nextLine();
                String[] nums = line.trim().split(" ");
                int n = Integer.parseInt(nums[0]);
                int j = Integer.parseInt(nums[1]);

                //range: Math.pow(2, n-1) + 1 to Math.pow(2, n) - 1
                for (long i = (long)Math.pow(2, n-1) + 1, h = 0; i < Math.pow(2, n) && h < j; i++) {
                    ArrayList<Long> divisors = new ArrayList<>();

                    if (i % 2 == 0) {
                        continue;
                    }

                    boolean isCoin = true;
                    for (int k = 2; k < 11; k++) {
                        long baseXInterpretation = baseXInterpretation(i, k, n);
                        long divisor = getDivisors(baseXInterpretation);
                        if (divisor != 1) {
                            divisors.add(divisor);
                        } else {
                            isCoin = false;
                            break;
                        }
                    }

                    if (isCoin) {
                        h++;
                        StringBuilder sb = new StringBuilder();
                        sb.append(baseXInterpretation(i, 10, n));
                        for (Long divisor : divisors) {
                            sb.append(" ").append(divisor);
                        }
                        writer.write(sb.toString());
                        writer.newLine();
                    }

                }
            }
            scanner.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private long baseXInterpretation(long num, int x, int n) {
        long result = 0;
        int index = 1;
        for (int i = 0; i < n; i++) {
            result += ((num >> i) & (long)1) * (long)(Math.pow(x, i));
        }

        return result;
    }

    private long getDivisors(long interpretation) {
        int divisor = 1;
        for (int i = 2; i < Math.ceil(Math.sqrt(interpretation)); i++) {
            if (interpretation % i == 0) {
                divisor = i;
                break;
            }
        }

        return divisor;
    }


    public static void main(String[] args) throws Exception {

        CoinJam coinJam = new CoinJam();
        String fileName = "C-small-attempt1";
        String inputFile = "codeJam/2016/Qualification/CoinJam/" + fileName + ".in";
        String outputFIle = "codeJam/CoinJam_" + fileName + ".out";

        coinJam.process(inputFile, outputFIle);

    }
}
