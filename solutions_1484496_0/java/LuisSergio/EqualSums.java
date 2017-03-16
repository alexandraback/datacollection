import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class EqualSums {

    private static java.util.List<Long> set1 = new ArrayList<Long>();
    private static java.util.List<Long> set2 = new ArrayList<Long>();
    private static boolean possible = false;

    public static void main(String[] args) throws IOException {
        File in = new File("input.in");
        File out = new File("output.txt");
        BufferedWriter w = new BufferedWriter(new FileWriter(out));
        Scanner sc = new Scanner(in);
        int testCases = Utils.readIntegerLine(sc);
        for (int i = 1; i <= testCases; i++) {
            int numbers = Utils.readInteger(sc);
            long[] superset = new long[numbers];
            for (int j = 0; j < numbers; j++) {
                superset[j] = Utils.readLong(sc);
            }
            solve(superset);
            StringBuilder sb1 = new StringBuilder();
            for (Long d : set1) {
                sb1.append(String.format("%d", d)).append(" ");
            }
            StringBuilder sb2 = new StringBuilder();
            for (Long d : set2) {
                sb2.append(String.format("%d", d)).append(" ");
            }
            final String result;
            if (possible) {
                result = String.format("Case #%d:\n%s\n%s", i, sb1.toString()
                        .trim(), sb2.toString().trim());
            } else {
                result = String.format("Case #%d: Impossible", i);

            }
            w.write(result);
            System.err.println(result);
            w.newLine();
        }
        w.close();

    }

    private static void solve(long[] superset) {
        ArrayList<Long> all = new ArrayList<Long>();
        for (Long long1 : superset) {
            all.add(long1);
        }
        ArrayList<ArrayList<Long>> allSubsets = Subset.getSubsets(all);
        possible = false;
        Map<Long, Integer> map = new HashMap<Long, Integer>();
        // sum -> index
        int index = 0;
        for (ArrayList<Long> subset : allSubsets) {
            if (subset.size() == 0) {
                index++;
                continue;
            }
            long sum = sum(subset);
            if (map.containsKey(sum)) {
                possible = true;
                set1 = subset;
                set2 = allSubsets.get(map.get(sum));
                return;
            } else {
                map.put(sum, index);
            }
            index++;
        }

    }

    private static long sum(ArrayList<Long> subset) {
        long sum = 0;
        for (Long long1 : subset) {
            sum += long1;
        }
        return sum;
    }

    private static java.util.List<Long> findSubSetWithSum(long half,
            java.util.List<Long> all) {
        long sum = 0;
        for (long l : all) {
            sum += l;
        }
        if (sum < half) {
            return null;
        }
        if (sum == half) {
            return all;
        }
        if (all.contains(half)) {
            return Collections.singletonList(half);
        }
        Collections.sort(all);
        int size = all.size();
        Long last = all.remove(size - 1);
        if (last > half) {
            return null;
        }
        java.util.List<Long> set = new ArrayList<Long>();
        set.add(last);
        java.util.List<Long> subset = findSubSetWithSum(half - last, all);
        if (subset != null) {
            set.addAll(subset);
            return set;
        } else {
            return null;
        }
    }
}
