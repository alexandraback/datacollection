package com.seulgi.sample.service;

import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MoneyOld {

    public static boolean canMake(List<Integer> coins, int current, int target) {
        if (current == target) {
            return true;
        }
        if (coins.size() == 0 || current > target) {
            return false;
        }
        List<Integer> next = new ArrayList<>();

        for (int i = 0; i < coins.size() - 1; i++) {
            next.add(coins.get(i+1));
        }

        return canMake(next, current + coins.get(0), target) || canMake(next, current, target);
    }


    /**
     *
     * @param targets List of integers that you cannot make using the currently given coins.
     *                You need to figure out how many extra coin types to add.
     * @param coins coins already provided to you. You can use only one of each coin.
     * @return
     */
    public static int howMany(List<Integer> targets, List<Integer> coins) {
        if(targets.size() == 0) return 0;

        Collections.sort(targets);

        int maxTarget = targets.get(targets.size() - 1);

        return howManyHelper(targets, coins, 1, maxTarget, 0);
    }

    public static int howManyHelper(List<Integer> targets, List<Integer> coins, int newCoin, int maxTarget, int added) {
        if(isEnough(targets, coins)) return added;

        if(newCoin > maxTarget) return 999;
        if(coins.contains(newCoin)) return howManyHelper(targets, coins, newCoin + 1, maxTarget, added);



        // either include the new coin or don't
        List<Integer> coinsWithNewCoin = new ArrayList<>();
        for(int i=0; i < coins.size(); i++) {
            coinsWithNewCoin.add(coins.get(i));
        }
        coinsWithNewCoin.add(newCoin);

        List<Integer> newTarget = new ArrayList<>();
        for(int target : targets) {
            if(!canMake(coinsWithNewCoin, 0, target)) newTarget.add(target);
        }

//        return Math.min(howManyHelper(targets, coins, newCoin + 1, maxTarget, added), howManyHelper(newTarget, coinsWithNewCoin, newCoin + 1, maxTarget, added + 1));

        if(newTarget.size() < targets.size()) {
            return Math.min(howManyHelper(targets, coins, newCoin + 1, maxTarget, added), howManyHelper(newTarget, coinsWithNewCoin, newCoin + 1, maxTarget, added + 1));
        } else {
            return howManyHelper(targets, coins, newCoin + 1, maxTarget, added);
        }
    }

    public static boolean isEnough(List<Integer> targets, List<Integer> coins) {
        for(Integer target : targets) {
            if(!canMake(coins, 0, target)) return false;
        }

        return true;
    }


    public static void main(String[] args) throws Exception {

        List<String> file = Files.readAllLines(Paths.get("input.in"), StandardCharsets.UTF_8);
        PrintWriter writer = new PrintWriter("output.out");

        int lineNum = 0;
        int T = Integer.parseInt(file.get(lineNum++));

        for (int cid = 1; cid <= T; cid++) {
            String[] targets = file.get(lineNum++).split(" ");
            int C = Integer.parseInt(targets[0]); // number of max allowed coins per type
            int D = Integer.parseInt(targets[1]); // number of diff types of coins
            int V = Integer.parseInt(targets[2]); // max value

            String[] typeString = file.get(lineNum++).split(" ");
            List<Integer> types = new ArrayList<>();
            for (int i = 0; i < D; i++) {
                types.add(Integer.parseInt(typeString[i]));
            }

            // for small, C = 1.
            List<Integer> need = new ArrayList<>();

            for (int i = 1; i <= V; i++) {
                if (!canMake(types, 0, i)) {
                    need.add(i);
                }
            }
            int res = howMany(need, types);
            System.out.println(String.format("Case #%d: %d", cid, res));
            writer.println(String.format("Case #%d: %d", cid, res));
        }

        writer.close();
    }
}
