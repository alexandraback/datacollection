package org.active.nerd.cookie;

import java.io.BufferedReader;
import java.io.IOException;
import java.math.BigDecimal;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;

import org.active.nerd.code.jam.InOutProcessor;
import org.active.nerd.code.jam.LineReader;
import org.active.nerd.code.jam.Result;
import org.active.nerd.code.jam.Utility;
import org.active.nerd.cookie.CookieFarm.CookieFarmer;

public class CookieFarm extends LineReader<CookieFarmer> {

    private static final String infileName = "B-small-attempt0.in";

    public static void main(String[] args) {
        InOutProcessor<CookieFarm, CookieFarmer> reader = new InOutProcessor<CookieFarm, CookieFarmer>(
                infileName, new CookieFarm());
        try {
            reader.processFile();
        } catch (NumberFormatException | IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    @Override
    public Collection<Result> parse(BufferedReader reader)
            throws NumberFormatException, IOException {
        int cases = Integer.parseInt(reader.readLine());
        List<Result> results = new LinkedList<Result>();

        for (int i = 0; i < cases; i++) {
            double[] contents = Utility.toDoubleArray(reader.readLine(), " ");

            results.add(new CookieFarmer(contents[0], contents[1], contents[2]));
        }

        return results;
    }

    public static class CookieFarmer implements Result {

        private double farmCost;
        private double cookIncrease;
        private double goal;
        private double lowestTotal;

        public CookieFarmer(double farmCost, double cookincrease, double goal) {
            this.farmCost = farmCost;
            this.cookIncrease = cookincrease;
            this.goal = goal;
            this.lowestTotal = Double.MAX_VALUE;
        }

        @Override
        public String getResult() {
            simulateCookieFarm();

            BigDecimal bd = new BigDecimal(lowestTotal);
            BigDecimal formatted = bd.setScale(7, BigDecimal.ROUND_HALF_UP);

            return String.valueOf(formatted.doubleValue());
        }

        private void simulateCookieFarm() {
            double rate = 2.0F;
            double time = 0.0F;
            simulateWaitForCookies(time, rate);
            simulateBuyFarm(time, rate);
        }

        // number of cookies at this point is always 0
        private void simulateWaitForCookies(double time, double rate) {
            double cookieTime = time + (goal / rate);
            checkIsLowest(cookieTime);
        }

        private void checkIsLowest(double cookieTime) {
            if (cookieTime < lowestTotal) {
                lowestTotal = cookieTime;
            }
        }

        private void simulateBuyFarm(double timePassed, double currentRate) {
            double buyTime = timePassed + (farmCost / currentRate);
            double newRate = currentRate + cookIncrease;
            if (buyTime > lowestTotal) {
                return;
            }

            simulateWaitForCookies(buyTime, newRate);
            simulateBuyFarm(buyTime, newRate);
        }
    }
}
