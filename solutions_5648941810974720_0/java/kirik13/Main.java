
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collector;


// 10^6 ~ 2 sec
public class Main {

    private static final String IN_FILENAME = "/Users/kyesipau/dev/personal/src/A-small-attempt0.in";
    private static final String OUT_FILENAME = "/Users/kyesipau/dev/personal/src/out.txt";

    private static final String[] WORDS = new String[]{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
        "SIX", "SEVEN", "EIGHT", "NINE"};

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(IN_FILENAME));
        PrintWriter writer = new PrintWriter(OUT_FILENAME, "UTF-8");
        int t = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < t; i++) {
            int caseNum = i + 1;
            writer.println("Case #" + caseNum + ": " + solve(reader.readLine().trim()));
        }

        reader.close();
        writer.close();
    }

    private static String solve(String input) {
        int len = input.length();
        Map<Character, Integer> occurrenceMap = new HashMap<>();
        for (int i = 0; i < len; i++) {
            char symbol = input.charAt(i);
            addToMap(occurrenceMap, symbol);
        }

        Map<Character, Set<Integer>> symbolToWordPointer = new HashMap<>();
        for (int i = 0; i < 10; i++) {
            String word = WORDS[i];
            int wordLen = word.length();
            for (int j = 0; j < wordLen; j++) {
                addToMap(symbolToWordPointer, word.charAt(j), i);
            }
        }

        return solve(occurrenceMap, symbolToWordPointer);
    }

    private static void addToMap(Map<Character, Integer> map, Character c) {
        Integer number = map.get(c);
        if (number == null) {
            map.put(c, 1);
        } else {
            map.put(c, number + 1);
        }
    }

    private static void removeFromMap(Map<Character, Integer> map, Character c) {
        Integer number = map.get(c);
        if (number == 1) {
            map.remove(c);
        } else {
            map.put(c, number - 1);
        }
    }

    private static void addToMap(Map<Character, Set<Integer>> pointerMap, Character symbol, int wordNumber) {
        Set<Integer> pointerSet = pointerMap.get(symbol);
        if (pointerSet == null) {
            Set<Integer> newSet = new HashSet<>();
            newSet.add(wordNumber);
            pointerMap.put(symbol, newSet);
        } else {
            pointerSet.add(wordNumber);
        }
    }

    private static String solve(Map<Character, Integer> occurrenceMap, Map<Character, Set<Integer>> symbolToWordPointer) {
        LinkedList<Integer> resultDeque = new LinkedList<>();
        List<Character> varietyList = sortByVariety(symbolToWordPointer);

        doIteration(occurrenceMap, symbolToWordPointer, resultDeque, varietyList);
        Collections.sort(resultDeque);

        StringBuilder result = new StringBuilder();
        for (Integer number : resultDeque) {
            result.append(number);
        }

        return result.toString();
    }

    private static void doIteration(Map<Character, Integer> occurrenceMap, Map<Character, Set<Integer>> symbolToWordPointer,
                                    Deque<Integer> resultDeque, List<Character> varietyList) {

        for (Character next : varietyList) {
            if (occurrenceMap.get(next) == null) {
                continue;
            }

            Set<Integer> possibleWords = symbolToWordPointer.get(next);
            for (Integer word : possibleWords) {
                if (!useWord(occurrenceMap, word)) {
                    continue;
                }

                resultDeque.addLast(word);
                doIteration(occurrenceMap, symbolToWordPointer, resultDeque, varietyList);
                if (occurrenceMap.isEmpty()) {
                    return;
                }
                resultDeque.removeLast();

                String sWord = WORDS[word];
                for (int i = 0; i < sWord.length(); i++) {
                    addToMap(occurrenceMap, sWord.charAt(i));
                }
            }
        }

    }

    private static boolean useWord(Map<Character, Integer> occurrenceMap, int word) {
        String sWord = WORDS[word];
        int len = sWord.length();

        Map<Character, Integer> wordOccurrence = new HashMap<>();
        for (int i = 0; i < len; i++) {
            addToMap(wordOccurrence, sWord.charAt(i));
        }

        Set<Character> wordCharacterSet = wordOccurrence.keySet();
        for (Character wordCharacter : wordCharacterSet) {
            if (occurrenceMap.get(wordCharacter) == null || occurrenceMap.get(wordCharacter) < wordOccurrence.get(wordCharacter)) {
                return false;
            }
        }

        for (int i = 0; i < len; i++) {
            removeFromMap(occurrenceMap, sWord.charAt(i));
        }
        return true;
    }

    private static List<Character> sortByVariety(Map<Character, Set<Integer>> symbolToWordPointer) {
        Set<Character> symbolSet = symbolToWordPointer.keySet();
        List<VarChar> varCharList = new ArrayList<>();
        for (Character symbol : symbolSet) {
            varCharList.add(new VarChar(symbol, symbolToWordPointer.get(symbol).size()));
        }
        Collections.sort(varCharList);

        List<Character> resultList = new ArrayList<>();
        for (VarChar varChar : varCharList) {
            resultList.add(varChar.getSymbol());
        }
        return resultList;
    }

    public static class VarChar implements Comparable<VarChar> {
        private Character symbol;
        private Integer occurrence;

        public VarChar(Character symbol, Integer occurrence) {
            this.symbol = symbol;
            this.occurrence = occurrence;
        }

        public Character getSymbol() {
            return symbol;
        }

        public Integer getOccurrence() {
            return occurrence;
        }

        @Override
        public int compareTo(VarChar other) {
            if (occurrence < other.getOccurrence()) {
                return -1;
            } else if (occurrence > other.getOccurrence()) {
                return 1;
            } else {
                return hashCode() < other.hashCode() ? -1 : 1;
            }
        }
    }
}
