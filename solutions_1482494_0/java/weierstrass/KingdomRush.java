package javaapplication2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.Map.Entry;

public class KingdomRush {

    private final static String INPUT_PATH = "resources/kingdom_rush.in";
    private final static String OUTPUT_PATH = "resources/kingdom_rush.out";
    private static int caseNumber = 0;

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scanner = new Scanner(new File(INPUT_PATH));

        int T = scanner.nextInt();

        //scanner.useDelimiter("\n|");
        try (FileWriter out = new FileWriter(OUTPUT_PATH)) {
            while (scanner.hasNext()) {
                processCase(scanner, out);
            }
        }
    }
    private static int[] a = new int[2001];
    private static int[] b = new int[2001];

    private static void processCase(Scanner scanner, FileWriter out) throws IOException {
        out.write("Case #" + (++caseNumber) + ": ");
        int N = scanner.nextInt();
        Set<Integer> unfinishedLevels = new HashSet<>();
        Map<Integer, Integer> twoStarsLevels = new HashMap<>();
        Map<Integer, Integer> oneStarLevels = new HashMap<>();
        for (int i = 0; i < N; ++i) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
            unfinishedLevels.add(i);
            oneStarLevels.put(i, a[i]);
            twoStarsLevels.put(i, b[i]);
        }
        
        Map<Integer, Integer> sortedTwoStarsLevels = new TreeMap<>(new ValueComparator(twoStarsLevels));
        sortedTwoStarsLevels.putAll(twoStarsLevels);
        Map<Integer, Integer> sortedOneStarLevels = new TreeMap<>(new ValueComparator(oneStarLevels));
        sortedOneStarLevels.putAll(oneStarLevels);
        int result = 0;
        int currentRaiting = 0;
        
        while (!unfinishedLevels.isEmpty()) {
            if (!sortedTwoStarsLevels.isEmpty()) {
                Entry<Integer, Integer> entry = sortedTwoStarsLevels.entrySet().iterator().next();
                if (currentRaiting >= entry.getValue()) {
                    ++result;
                    int level = entry.getKey();
                    sortedTwoStarsLevels.remove(level);
                    currentRaiting += sortedOneStarLevels.remove(level) == null ? 1 : 2;
                    unfinishedLevels.remove(level);
                    continue;
                }
            }
            if (!sortedOneStarLevels.isEmpty()) {
                Entry<Integer, Integer> entry = sortedOneStarLevels.entrySet().iterator().next();
                if (currentRaiting >= entry.getValue()) {
                    ++result;
                    ++currentRaiting;
                    int level = entry.getKey();
                    sortedOneStarLevels.remove(level);
                    continue;
                }
            }
            out.write("Too Bad\n");
            return;
        }
        out.write(result + "");
        out.write("\n");
    }

    private static class ValueComparator implements Comparator {

        Map<Integer, Integer> base;

        public ValueComparator(Map<Integer, Integer> base) {
            this.base = base;
        }

        @Override
        public int compare(Object a, Object b) {
            Integer c = (Integer) a;
            Integer d = (Integer) b;
            Integer A = base.get(c);
            Integer B = base.get(d);
            if (A > B) {
                return 1;
            }
            if (A < B) {
                return -1;
            }
            return c.compareTo(d);
        }
    }
}
