import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class CodeJamA {

    public static final String INPUT = "/opt/dev/TopCoder/src/A-large.in";
    public static final String OUTPUT = "/opt/dev/TopCoder/src/out.txt";

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter writer = new PrintWriter(OUTPUT, "UTF-8");
        try {
            solve(br, writer);
        } finally {
            br.close();
            writer.close();
        }
    }

    private static void solve(BufferedReader reader, PrintWriter writer) throws Exception {
        TreeMap<Long, Long> startingPointMap = buildStartingPoints(buildPowerStartMap());

        int t = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < t; i++) {
            long n = Long.parseLong(reader.readLine().trim());
            writer.println("Case #" + (i + 1) + ": " + getResult(n, startingPointMap));
        }
    }

    private static String getResult(long goal, TreeMap<Long, Long> startingPointMap) {
        if (goal <= 10000000000000L) {
            Long res = startingPointMap.get(goal);
            if (res != null) {
                return res.toString();
            } else {
                Map.Entry<Long, Long> prevEntry = startingPointMap.lowerEntry(goal);
                return Long.toString(prevEntry.getValue() + (goal - prevEntry.getKey()));
            }
        } else {
            Map.Entry<Long, Long> prevEntry = startingPointMap.lowerEntry(goal);
            long cur = prevEntry.getKey();
            long res = prevEntry.getValue();
            while (true) {
                long reverse = reverse(cur);
                if (reverse > cur && reverse <= goal) {
                    res++;
                    cur = reverse;
                } else {
                    cur++;
                    res++;
                }
                if (cur == goal) {
                    return Long.toString(res);
                }
            }
        }
    }

    private static TreeMap<Long, Long> buildStartingPoints(Map<Integer, Long> powerStartMap) {
        TreeMap<Long, Long> startingMap = new TreeMap<Long, Long>();
        startingMap.put(1L, 1L);
        for (int pow = 1; pow < 13; pow++) {
            Long powerStart = powerStartMap.get(pow);
            int size = (pow + 1) / 2;
            Long toAddLast = powerStartMap.get(size) - 1;
            for (long toAdd = 1; toAdd <= toAddLast; toAdd++) {
                long current = powerStart + toAdd;
                long reverse = reverse(current);
                if (reverse > current) {
                    Map.Entry<Long, Long> previousEntry = startingMap.lowerEntry(current);
                    Long previousNumber = previousEntry.getKey();
                    Long previousScore = previousEntry.getValue();

                    Long needAdd = current - previousNumber;
                    startingMap.put(reverse, previousScore + needAdd + 1L);
                }
            }
        }
        return startingMap;
    }

    private static Long reverse(Long number) {
        while (number % 10 == 0) {
            number = number / 10;
        }
        long res = 0;
        while (number > 0) {
            res = res * 10 + number % 10;
            number = number / 10;
        }
        return res;
    }

    private static Map<Integer, Long> buildPowerStartMap() {
        Map<Integer, Long> powerStartMap = new HashMap<Integer, Long>(20);
        powerStartMap.put(0, 1L);
        powerStartMap.put(1, 10L);
        powerStartMap.put(2, 100L);
        powerStartMap.put(3, 1000L);
        powerStartMap.put(4, 10000L);
        powerStartMap.put(5, 100000L);
        powerStartMap.put(6, 1000000L);
        powerStartMap.put(7, 10000000L);
        powerStartMap.put(8, 100000000L);
        powerStartMap.put(9, 1000000000L);
        powerStartMap.put(10, 10000000000L);
        powerStartMap.put(11, 100000000000L);
        powerStartMap.put(12, 1000000000000L);
        powerStartMap.put(13, 10000000000000L);
        powerStartMap.put(14, 100000000000000L);
        return powerStartMap;
    }

}
