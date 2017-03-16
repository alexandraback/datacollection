package org.active.nerd.war;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

import org.active.nerd.code.jam.InOutProcessor;
import org.active.nerd.code.jam.InOutProcessor.LineReader;
import org.active.nerd.code.jam.InOutProcessor.Result;
import org.active.nerd.code.jam.InOutProcessor.Utility;
import org.active.nerd.war.WarGame.Game;

public class WarGame extends LineReader<Game> {

    private static final String infileName = "D-large.in";

    public static void main(String[] args) {
        InOutProcessor<WarGame, Game> reader = new InOutProcessor<WarGame, Game>(infileName, new WarGame());
        try {
            reader.processFile();
        } catch (NumberFormatException | IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    @Override
    public Collection<Result> parse(BufferedReader reader) throws NumberFormatException, IOException {
        int cases = Integer.parseInt(reader.readLine());
        List<Result> results = new LinkedList<Result>();

        for (int i = 0; i < cases; i++) {
            int stones = Integer.parseInt(reader.readLine());
            double[] naomi = Utility.toDoubleArray(reader.readLine(), " ");
            double[] ken = Utility.toDoubleArray(reader.readLine(), " ");

            results.add(new Game(naomi, ken));
        }

        return results;
    }

    public static class Game implements Result {

        // Strat: If you can beat it, beat it minimally
        // if you cannot beat it, play your lowest stone

        // Counter strat, lie saying you have just under the highest stone of
        // the opponent
        // play your lowest stone. Do this until all your stone beat their
        // stones

        private ArrayList<Double> kenList;
        private ArrayList<Double> naomiList;

        public Game(double[] naomi, double[] ken) {
            naomiList = new ArrayList<Double>(naomi.length);
            for (double d : naomi) {
                naomiList.add(Double.valueOf(d));
            }
            // Collections.sort(naomiList);

            kenList = new ArrayList<Double>(ken.length);
            for (double d : ken) {
                kenList.add(Double.valueOf(d));
            }

            // Collections.sort(kenList);
        }

        @Override
        public String getResult() {
            return getDeceitfulScore() + " " + getScore();
        }

        private String getScore() {
            ArrayList<Double> copyKenList = (ArrayList<Double>) kenList.clone();
            Collections.sort(copyKenList);
            ArrayList<Double> copyNaomiList = (ArrayList<Double>) naomiList.clone();

            int naomiPoint = 0;
            for (Double d : copyNaomiList) {
                if (d > playKen(copyKenList, d)) {
                    naomiPoint++;
                }
            }

            return String.valueOf(naomiPoint);
        }

        private String getDeceitfulScore() {
            ArrayList<Double> copyKenList = (ArrayList<Double>) kenList.clone();
            Collections.sort(copyKenList);
            ArrayList<Double> copyNaomiList = (ArrayList<Double>) naomiList.clone();
            Collections.sort(copyNaomiList);

            int points = 0;
            // while (!copyNaomiList.isEmpty()) {
            // int maxIndex = copyNaomiList.size() - 1;
            // if (maxIndex == 0) {
            // if (copyKenList.remove(0) < copyNaomiList.remove(0)) {
            // points++;
            // }
            // } else if (maxIndex < points) {
            // points += copyNaomiList.size();
            // break;
            // } else if (copyKenList.get(maxIndex) < copyNaomiList.get(maxIndex
            // - points)) {
            // points++;
            // copyKenList.remove(0);
            // copyNaomiList.remove(maxIndex);
            // } else {
            // copyKenList.remove(maxIndex);
            // copyNaomiList.remove(0);
            // }
            // }
            for (Double d : copyKenList) {
                if (d < playKen(copyNaomiList, d)) {
                    points++;
                }
            }

            return String.valueOf(points);
        }

        private Double cheat(ArrayList<Double> list, Double search) {
            int size = list.size();
            int lowIndex = 0;
            int highIndex = size - 1;

            while (highIndex - lowIndex > 1) {
                int searchIndex = (highIndex + lowIndex) / 2;
                if (list.get(searchIndex) < search) {
                    lowIndex = searchIndex;
                } else {
                    highIndex = searchIndex;
                }
            }

            if (list.get(highIndex) < search) {
                return list.remove(highIndex);
            } else {
                return list.remove(lowIndex);
            }
        }

        // Removes next highest number in the list
        // If no higher one is found, removes the lowest number
        private Double playKen(ArrayList<Double> list, Double search) {
            int size = list.size();
            int lowIndex = 0;
            int highIndex = size - 1;

            while (highIndex - lowIndex > 1) {
                int searchIndex = (highIndex + lowIndex) / 2;
                if (list.get(searchIndex) > search) {
                    highIndex = searchIndex;
                } else {
                    lowIndex = searchIndex;
                }
            }

            if (list.get(lowIndex) > search) {
                return list.remove(lowIndex);
            } else if (list.get(highIndex) > search) {
                return list.remove(highIndex);
            } else {
                return list.remove(0);
            }
        }
    }

}
