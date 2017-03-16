import com.google.common.base.Splitter;
import com.google.common.collect.Lists;

import java.io.*;
import java.math.BigInteger;
import java.util.Iterator;
import java.util.List;
import java.util.TreeSet;

public class Main {
    private static final String TEST_INPUT = "3\n" +
            "5 2 2\n" +
            "2 1\n" +
            "5 2 2\n" +
            "1 2\n" +
            "3 3 4\n" +
            "4 1 3 5\n";

    private static class GameRules {
        public long startingEnergy;
        public long energyGain;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new FileReader("c:\\comp\\small.in"));
        //BufferedReader bufferedReader = new BufferedReader(new StringReader(TEST_INPUT));
        final PrintStream outStream = new PrintStream(new FileOutputStream("c:\\comp\\small.out"));
        int numCases = Integer.valueOf(bufferedReader.readLine());

        for(int i = 1; i <= numCases; i++) {
            String line = bufferedReader.readLine();
            Iterator<String> lineTokens = Splitter.on(" ").split(line).iterator();
            GameRules gameRules = new GameRules();
            gameRules.startingEnergy = Integer.valueOf(lineTokens.next());
            gameRules.energyGain = Integer.valueOf(lineTokens.next());
            int numActivities = Integer.valueOf(lineTokens.next());

            line = bufferedReader.readLine();
            lineTokens = Splitter.on(" ").split(line).iterator();
            List<Integer> activities = Lists.newArrayListWithCapacity(numActivities);
            for(int j = 0; j < numActivities; j++) {
                activities.add(Integer.valueOf(lineTokens.next()));
            }

            long currentEnergy = gameRules.startingEnergy;
            long result = 0;
            for(int j = 0; j < numActivities; j++) {
                if(j == numActivities - 1) {
                    result += currentEnergy * activities.get(j);
                } else {
                    int reach = (int) (currentEnergy % gameRules.energyGain == 0 ? currentEnergy / gameRules.energyGain : currentEnergy / gameRules.energyGain + 1);
                    List<Integer> outstandingActivities = activities.subList(j, Math.min(j + reach, numActivities));
                    long energyToSpend = findOptimalStrategy(outstandingActivities, gameRules, currentEnergy);
                    if(energyToSpend < 0) {
                        energyToSpend = 0;
                    }
                    result += energyToSpend * activities.get(j);
                    currentEnergy = currentEnergy - energyToSpend + gameRules.energyGain;
                }
            }


            System.out.println("Case #" + i + ": " + result);
            outStream.println("Case #" + i + ": " + result);
        }
    }

    private static Long findOptimalStrategy(List<Integer> outstandingActivities, GameRules gameRules, long currentEnergy) {
        if(outstandingActivities.size() == 1) {
            return currentEnergy;
        }
        if(outstandingActivities.get(0) < outstandingActivities.get(1)) {
            return currentEnergy - gameRules.startingEnergy + gameRules.energyGain;
        }
        int ind = indexOfLargestValue(outstandingActivities);
        if(ind == 0) {
            return currentEnergy;
        }
        int reach = (int) (currentEnergy % gameRules.energyGain == 0 ? currentEnergy / gameRules.energyGain : currentEnergy / gameRules.energyGain + 1);
        reach = Math.min(reach, ind);
        return findOptimalStrategy(outstandingActivities.subList(0, Math.min(reach, outstandingActivities.size() - 1)), gameRules, gameRules.energyGain * reach);
    }

    private static int indexOfLargestValue(List<Integer> outstandingActivities) {
        int largestValue = 0;
        int result = 0;
        for(int i = 0; i < outstandingActivities.size();  i++) {
            if(outstandingActivities.get(i) > largestValue) {
                result = i;
                largestValue = outstandingActivities.get(i);
            }
        }
        return result;
    }
}
