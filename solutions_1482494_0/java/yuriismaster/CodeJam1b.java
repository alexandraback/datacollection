import com.sun.tools.javac.util.Pair;

import java.util.*;

/**
 * Created by IntelliJ IDEA.
 * User: nickg
 * Date: 4/13/12
 * Time: 9:57 PM
 * To change this template use File | Settings | File Templates.
 */
public class CodeJam1b {

    public static void main(String[] args) {

        //doSomething(new Scanner(System.in));

        Scanner scanner = new Scanner(System.in);
        int numTrials = scanner.nextInt();
        for(int i = 0; i < numTrials; i++){
            System.out.println("Case #" + (i+1) + ": " + doSomething(scanner));
        }
    }

    private static String doSomething(Scanner scanner) {
        int numberOfGames = scanner.nextInt();
        SortedSet<Pair> pairSet = new TreeSet<Pair>();

        int pointsSoFar = 0; int totalDone = 0;
        for(int i = 0; i < numberOfGames; i++){
            Pair pair = new Pair(i, scanner.nextInt(), scanner.nextInt());
            pairSet.add(pair);
        }

        List<Pair> pairs = new ArrayList<Pair>(pairSet);
        Set<Pair> oneOnes = new HashSet<Pair>();

        pair: while(!pairs.isEmpty()){

            // Search, finding max b <= pointsSoFar
            for (int pairsSize = pairs.size(), i = pairsSize - 1;  i >= 0; i--) {
                Pair pair = pairs.get(i);
                if(pair.b <= pointsSoFar){
                    HashMap<Integer, Integer> equalToCurrentB = new HashMap<Integer, Integer>();
                    boolean sawATwoFer = !pair.doneWithOne;
                    equalToCurrentB.put(i, pair.a);
                    i--;
                    while(i >= 0 && pairs.get(i).b.equals(pair.b)){
                        Pair newPair =pairs.get(i);
                        if(!sawATwoFer && !newPair.doneWithOne){
                            equalToCurrentB.clear(); sawATwoFer = true; equalToCurrentB.put(i, newPair.a);
                        }
                        if(!(sawATwoFer && pair.doneWithOne)){
                            equalToCurrentB.put(i, newPair.a);
                        }
                        i--;
                    }

                    Integer toRemoveIndex = null, maxValue = null;
                    for (Map.Entry<Integer, Integer> entry : equalToCurrentB.entrySet()) {
                    if(maxValue == null || entry.getValue() > maxValue){
                        maxValue = entry.getValue();
                        toRemoveIndex = entry.getKey();
                    }
                    }

                    Pair removed = pairs.get(toRemoveIndex);
                    pairs.remove((int)toRemoveIndex);
                    if(removed.doneWithOne){
                        pointsSoFar++;
                        oneOnes.remove(removed);
                    }else {
                        //If I got a twofer, but a previous one-only had a >= me a, remove that one and make this into a one-one
                        Pair prev = removed;
                        for (Pair oneOne : oneOnes) {
                            if(oneOne.a >= prev.a){
                                prev = oneOne;
                            }
                        }
                        if(prev != removed){
                            prev.doneWithOne = false;
                            oneOnes.remove(prev);
                        }
                        pointsSoFar += 2;
                    }
                     totalDone++;
                    continue pair;
                }
            }

            Integer maxVal = null;
            HashMap<Integer, Integer> equalToCurrentSmallestA = new HashMap<Integer, Integer>();
            for(int i = 0; i < pairs.size(); i++){
                Integer newVal = pairs.get(i).a;
                if(newVal <= pointsSoFar && !pairs.get(i).doneWithOne){
                    if((maxVal == null || maxVal <= newVal)){
                        if(maxVal == null || maxVal < newVal){
                            equalToCurrentSmallestA.clear();
                            maxVal = newVal;
                        }
                        equalToCurrentSmallestA.put(i, pairs.get(i).b);
                    }
                }
            }
            if(maxVal == null) return "Too Bad";

            Integer toRemoveIndex = null, minValue = null;
            for (Map.Entry<Integer, Integer> entry : equalToCurrentSmallestA.entrySet()) {
                if(minValue == null || entry.getValue() > minValue){
                    minValue = entry.getValue();
                    toRemoveIndex = entry.getKey();
                }
            }


            Pair maxPair = pairs.get(toRemoveIndex);
            maxPair.doneWithOne = true;
            oneOnes.add(maxPair);
            pointsSoFar++; totalDone++;
        }

        return String.valueOf(totalDone);
    }

    static class Pair implements Comparable<Pair>{
        Integer a, b, index;
        boolean doneWithOne = false;

        Pair(int index, int a, int b) {
            this.index = index;
            this.a = a;
            this.b = b;
        }

        public int compareTo(Pair pair) {
            int i = b.compareTo(pair.b);
            if(i == 0){
                i = a.compareTo(pair.a);
                if(i == 0){
                    i = index.compareTo(pair.index);
                }
            }
            return i;
        }
    }
}
