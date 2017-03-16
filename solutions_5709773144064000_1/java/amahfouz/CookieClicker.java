/*
 * CONFIDENTIAL
 * Copyright 2013 Webalo, Inc.  All rights reserved.
 */

package mahfouz.google.codejam.y2014.qual;

import java.io.File;
import java.io.PrintStream;
import java.text.DecimalFormat;
import java.util.Scanner;

/**
 *
 */
public final class CookieClicker {

    public static void main(String[] args) throws Exception{
        Scanner s = new Scanner(new File("C:\\Users\\amahfouz\\Downloads\\cj.in"));
        PrintStream out = new PrintStream(new File("C:\\Users\\amahfouz\\Desktop\\solution.txt"));

        int numCases = s.nextInt();

        for (int i = 0; i < numCases; i++) {
            solveCase(i + 1, s, out);
        }
    }

    private static void solveCase(int caseNum, Scanner s, PrintStream out) {

        double baseRate = 2.0;

        double farmPrice = s.nextDouble();
        double ratePerFarm = s.nextDouble();
        double target = s.nextDouble();

        double curCookies = 0;
        double curTime = 0;
        int numFarms = 0;

        while (true) {
            double curRate = baseRate + ratePerFarm * numFarms;

            // target = cur + (t * rate)
            // t = (target - cur) / rate

            double timeWithNoPurchase = (target - curCookies) / curRate;

            if (curCookies >= farmPrice) {


                // if purchase, you lose farm price but gain speed

                double timeIfPurchased = (target - (curCookies - farmPrice)) / (curRate + ratePerFarm);

                if (timeWithNoPurchase < timeIfPurchased) {
                    curTime += timeWithNoPurchase;
                    break;
                }
                else {
                    curCookies -= farmPrice;
                    numFarms++;
                }
            }
            else {
                // curCookies < farmPrice
                double timeTillNextFarm = (farmPrice - curCookies) / curRate;

                if (timeWithNoPurchase < timeTillNextFarm) {
                    curTime += timeWithNoPurchase;
                    break;
                }
                else {
                    curTime += timeTillNextFarm;
                    curCookies += (timeTillNextFarm * curRate);
                }
            }
        }

        DecimalFormat format = new DecimalFormat("#.#######");
        format.setMinimumFractionDigits(7);
        String output = format.format(curTime);
        outputCase(out, caseNum, output);
    }

    private static void outputCase(PrintStream out, int caseNum, String output) {
        out.println("Case #" + caseNum + ": " + output);
    }
}
