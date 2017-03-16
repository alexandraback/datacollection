package com.gmail.danielcomsa.codejam.y2014.qualification;

import com.gmail.danielcomsa.codejam.Utility;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.RoundingMode;

import static java.math.RoundingMode.HALF_UP;

/**
 * Created by daniel on 4/12/14.
 */
public class CookieClickerAlpha {
    private static final int PRECISION = 7;

    public static void main(String[] args) throws IOException {
//        String file = "sample";
//        String file = "B-small-attempt0.in";
        String file = "B-large.in";
        BufferedReader reader = Utility.getReader(CookieClickerAlpha.class, file);
        PrintStream out = Utility.getPrintStream(CookieClickerAlpha.class, file);

        CookieClickerAlpha cookieClickerAlpha = new CookieClickerAlpha();
        int testCases = Utility.readInt(reader);

        for (int i = 1; i <= testCases; i++) {
            BigDecimal[] input = Utility.readBigDecimals(reader);
            BigDecimal resultAsBigDecimal = cookieClickerAlpha.solve(input);
            String result = "Case #" + i + ": " + resultAsBigDecimal.toString();
            System.out.println(result);
            out.println(result);
        }

        out.flush();
        out.close();
    }

    private BigDecimal solve(BigDecimal[] input) {
        BigDecimal farmCost = input[0];
        BigDecimal farmIncome = input[1];
        BigDecimal target = input[2];

        BigDecimal currentIncome = new BigDecimal(2);
        BigDecimal carriedSeconds = new BigDecimal(0);
        BigDecimal noFarm = new BigDecimal(0);
        BigDecimal withFarm = new BigDecimal(-1);
        while (withFarm.compareTo(noFarm) < 0) {
            noFarm = carriedSeconds.add(target.divide(currentIncome, PRECISION, HALF_UP));
            withFarm = carriedSeconds.add(farmCost.divide(currentIncome, PRECISION, HALF_UP)).add(target.divide(currentIncome.add(farmIncome), PRECISION, HALF_UP));

            carriedSeconds = carriedSeconds.add(farmCost.divide(currentIncome, PRECISION, HALF_UP));
            currentIncome = currentIncome.add(farmIncome);
        }
        return noFarm;
    }
}
