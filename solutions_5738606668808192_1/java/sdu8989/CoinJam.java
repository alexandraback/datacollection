package com.sdu.practice.codeJam.qualification;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
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
                        BigInteger baseXInterpretation = baseXInterpretation(i, k, n);
                        BigInteger divisor = getDivisors(baseXInterpretation);
                        if (!divisor.equals(BigInteger.ONE)) {
                            divisors.add(divisor.longValue());
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
                        System.out.println(sb.toString());
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

    private BigInteger baseXInterpretation(long num, int x, int n) {
        BigInteger result = BigInteger.valueOf(0);
        BigInteger bx = BigInteger.valueOf(x);

        for (int i = 0; i < n; i++) {
            BigInteger bxPow = bx.pow(i);
            result = result.add(bxPow.multiply(BigInteger.valueOf((num >> i) & (long)1)));
        }

        return result;
    }

    private BigInteger getDivisors(BigInteger interpretation) {
        BigInteger divisor = BigInteger.ONE;
        for (long i = 2; i < 100000; i++) {
            if (interpretation.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO)) {
                divisor = BigInteger.valueOf(i);
                break;
            }
        }

        return divisor;
    }


    public static void main(String[] args) throws Exception {

        CoinJam coinJam = new CoinJam();
        String fileName = "C-large";
        String inputFile = "codeJam/2016/Qualification/CoinJam/" + fileName + ".in";
        String outputFIle = "codeJam/CoinJam_" + fileName + ".out";

        coinJam.process(inputFile, outputFIle);

    }
}
