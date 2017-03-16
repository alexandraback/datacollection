import com.google.common.base.Joiner;
import com.google.common.base.Splitter;
import com.google.common.collect.Lists;
import com.google.common.collect.Sets;

import java.io.*;
import java.util.*;

public class Main {
    public static class Chest implements Comparable<Chest> {
        int chestNumber;
        int keyToOpen;
        List<Integer> keysInside = Lists.newArrayList();

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Chest chest = (Chest) o;

            if (chestNumber != chest.chestNumber) return false;

            return true;
        }

        @Override
        public int compareTo(Chest o) {
            return Integer.valueOf(chestNumber).compareTo(o.chestNumber);
        }

        @Override
        public String toString() {
            return String.valueOf(chestNumber);
        }
    }

    public static class TestCase {
        List<Integer> startKeys = Lists.newArrayList();
        List<Chest> chests = Lists.newArrayList();
    }

    private static List<TestCase> readInput(Reader reader) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(reader);
        int numCases = Integer.valueOf(bufferedReader.readLine());

        List<TestCase> result = Lists.newArrayListWithCapacity(numCases);

        for (int i = 0; i < numCases; i++) {
            TestCase testCase = new TestCase();

            String firstLine = bufferedReader.readLine();
            Iterator<String> firstLineTokens = Splitter.on(" ").split(firstLine).iterator();
            int k = Integer.valueOf(firstLineTokens.next());
            int n = Integer.valueOf(firstLineTokens.next());

            String secondLine = bufferedReader.readLine();
            Iterator<String> secondLineTokens = Splitter.on(" ").split(secondLine).iterator();
            for (int j = 0; j < k; j++) {
                testCase.startKeys.add(Integer.valueOf(secondLineTokens.next()));
            }

            for (int j = 0; j < n; j++) {
                Chest chest = new Chest();
                chest.chestNumber = j + 1;
                String line = bufferedReader.readLine();
                Iterator<String> lineTokens = Splitter.on(" ").split(line).iterator();
                chest.keyToOpen = Integer.valueOf(lineTokens.next());
                int numKeys = Integer.valueOf(lineTokens.next());
                for (int l = 0; l < numKeys; l++) {
                    chest.keysInside.add(Integer.valueOf(lineTokens.next()));
                }
                testCase.chests.add(chest);
            }
            result.add(testCase);
        }

        return result;
    }

    private static final String TEST_INPUT = "3\n" +
            "1 4\n" +
            "1\n" +
            "1 0\n" +
            "1 2 1 3\n" +
            "2 0\n" +
            "3 1 2\n" +
            "3 3\n" +
            "1 1 1\n" +
            "1 0\n" +
            "1 0\n" +
            "1 0\n" +
            "1 1\n" +
            "2\n" +
            "1 1 1\n";

    public static class State {
        public List<Chest> frontOpenedChests = Lists.newLinkedList();
        public List<Chest> backOpenedChests = Lists.newLinkedList();
        public List<Integer> availableKeys = Lists.newArrayList();
        public List<Integer> neededKeys = Lists.newArrayList();
        public NavigableSet<Chest> unopenedChests = Sets.newTreeSet();

        public State copy() {
            State result = new State();
            result.frontOpenedChests.addAll(frontOpenedChests);
            result.backOpenedChests.addAll(backOpenedChests);
            result.availableKeys.addAll(availableKeys);
            result.neededKeys.addAll(neededKeys);
            result.unopenedChests.addAll(unopenedChests);
            return result;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            State state = (State) o;

            if (unopenedChests != null ? !unopenedChests.equals(state.unopenedChests) : state.unopenedChests != null)
                return false;

            return true;
        }

        @Override
        public int hashCode() {
            return unopenedChests != null ? unopenedChests.hashCode() : 0;
        }
    }

    public static Set<State> failingStates;


    public static void main(String[] args) throws IOException, InterruptedException {
        //List<TestCase> testCases = readInput(new StringReader(TEST_INPUT));
        List<TestCase> testCases = readInput(new FileReader("c:\\comp\\small.in"));
        PrintStream outStream = new PrintStream(new FileOutputStream("c:\\comp\\small.out"));

        int currentCase = 1;
        for (TestCase testCase : testCases) {
            failingStates = new HashSet<State>();

            State state = new State();
            state.availableKeys.addAll(testCase.startKeys);
            state.unopenedChests.addAll(testCase.chests);

            //backOpenChests(state);

            if(!state.unopenedChests.isEmpty()) {
                state = descendRecursively(state);
            }

            state.frontOpenedChests.addAll(state.backOpenedChests);
            List<Chest> chests =  state.frontOpenedChests;

            if(!state.unopenedChests.isEmpty() || !isSolution(chests, testCase.startKeys)) {
                System.out.println("Case #" + currentCase + ": IMPOSSIBLE");
                outStream.println("Case #" + currentCase + ": IMPOSSIBLE");
            } else {
                /*for(int i = 0; i < chests.size(); i++) {
                    chests = reorder1(chests, testCase.startKeys);
                    chests = reorder2(chests, testCase.startKeys);
                }*/
                if(!isSolution(chests, testCase.startKeys)) {
                    return;
                }
                String result = Joiner.on(" ").join(chests);
                System.out.println("Case #" + currentCase + ": " + result);
                outStream.println("Case #" + currentCase + ": " + result);
            }

            currentCase++;
        }
    }

    private static List<Chest> reorder1(List<Chest> frontOpenedChests, List<Integer> startKeys) {
        Object[] chests = Sets.newTreeSet(frontOpenedChests).toArray();
        List<Chest> result = Lists.newArrayList(frontOpenedChests);
        for(int i = 0; i < frontOpenedChests.size(); i++) {
            Chest currentChest = (Chest) chests[i];
            for(int j = result.indexOf(currentChest) - 1; j >= 0; j--) {
                if(result.get(j).chestNumber < currentChest.chestNumber) {
                    continue;
                }
                int position = result.indexOf(currentChest);
                result.remove(currentChest);
                result.add(j, currentChest);
                if(!isSolution(result, startKeys)) {
                    result.remove(currentChest);
                    result.add(position, currentChest);
                }
            }
        }
        return result;
    }

    private static List<Chest> reorder2(List<Chest> frontOpenedChests, List<Integer> startKeys) {
        Object[] chests = Sets.newTreeSet(frontOpenedChests).toArray();
        List<Chest> result = Lists.newArrayList(frontOpenedChests);
        for(int i = 0; i < frontOpenedChests.size(); i++) {
            Chest currentChest = (Chest) chests[i];
            for(int j = result.indexOf(currentChest) - 1; j >= 0; j--) {
                if(result.get(j).chestNumber < currentChest.chestNumber) {
                    continue;
                }
                Chest movedChest = result.get(j);
                int position = result.indexOf(movedChest);
                for(int k = position + 1; k < frontOpenedChests.size(); k++) {
                    if(movedChest.chestNumber < result.get(k).chestNumber) {
                        break;
                    }
                    result.remove(movedChest);
                    result.add(k, movedChest);
                    if(isSolution(result, startKeys)) {
                        break;
                    } else {
                        result.remove(movedChest);
                        result.add(position, movedChest);
                    }
                }
            }
        }
        return result;
    }

    private static boolean isSolution(List<Chest> result, List<Integer> startKeys) {
        List<Integer> keys = Lists.newArrayList(startKeys);
        for (Chest chest : result) {
            if(!keys.contains(chest.keyToOpen)) {
                return false;
            }
            keys.remove(Integer.valueOf(chest.keyToOpen));
            keys.addAll(chest.keysInside);
        }

        return true;
    }

    private static State descendRecursively(State state) {
        if(failingStates.contains(state)) {
            return state;
        }

        for (Chest unopenedChest : state.unopenedChests) {
            if(!state.availableKeys.contains(unopenedChest.keyToOpen)) {
                continue;
            }

            State stateCopy = state.copy();
            stateCopy = tryFrontOpen(stateCopy, unopenedChest);
            if(stateCopy.unopenedChests.isEmpty()) {
               if(stateCopy.availableKeys.containsAll(stateCopy.neededKeys)) {
                   return stateCopy;
               }
            }
        }
        failingStates.add(state);
        return state;
    }

    private static State tryFrontOpen(State state, Chest unopenedChest) {
        frontOpen(state, unopenedChest);
        if(!state.unopenedChests.isEmpty()) {
            return descendRecursively(state);
        }

        return state;
    }

    private static void backOpenChests(State state) {
       outer: while (true) {
            for (Chest unopenedChest : state.unopenedChests.descendingSet()) {
                if(unopenedChest.keysInside.isEmpty()) {
                    backOpen(state, unopenedChest);
                    continue outer;
                }
            }
            break;
        }
    }

    private static void backOpen(State state, Chest unopenedChest) {
        for (Integer key : unopenedChest.keysInside) {
            state.neededKeys.remove(key);
        }
        state.neededKeys.add(unopenedChest.keyToOpen);
        state.unopenedChests.remove(unopenedChest);
        state.backOpenedChests.add(0, unopenedChest);
    }

    private static void frontOpen(State state, Chest unopenedChest) {
        state.availableKeys.remove(Integer.valueOf(unopenedChest.keyToOpen));
        state.availableKeys.addAll(unopenedChest.keysInside);
        state.unopenedChests.remove(unopenedChest);
        state.frontOpenedChests.add(unopenedChest);
    }
}