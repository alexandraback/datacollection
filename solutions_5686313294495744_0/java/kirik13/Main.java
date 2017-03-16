
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Stream;


// 10^6 ~ 2 sec
public class Main {

    private static final String IN_FILENAME = "/Users/kyesipau/dev/personal/src/C-small-attempt-jam.in";
    private static final String OUT_FILENAME = "/Users/kyesipau/dev/personal/src/out.txt";

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(IN_FILENAME));
        PrintWriter writer = new PrintWriter(OUT_FILENAME, "UTF-8");
        int t = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < t; i++) {
            int caseNum = i + 1;
            writer.println("Case #" + caseNum + ": " + solve(reader));
        }

        reader.close();
        writer.close();
    }

    private static long solve(BufferedReader reader) throws Exception {
        int n = Integer.parseInt(reader.readLine().trim());
        Map<String, Integer> firstOcc =  new HashMap<>(1000);
        Set<String> firstOriginals = new HashSet<>(1000);
        Map<String, Integer> secondOcc =  new HashMap<>(1000);
        Set<String> secondOriginals = new HashSet<>(1000);
        List<String[]> topicList = new ArrayList<>(n);

        for (int i = 0; i < n; i++) {
            String[] topic = reader.readLine().trim().split(" ");
            addToMap(firstOcc, topic[0]);
            addToMap(secondOcc, topic[1]);
            topicList.add(topic);
        }

        ResultKeeper resultKeeper = new ResultKeeper();
        resultKeeper.setResult(0);

        doIteration(firstOcc, firstOriginals, secondOcc, secondOriginals, topicList, resultKeeper, 0, 0);

        return resultKeeper.getResult();
    }


    private static void doIteration(Map<String, Integer> firstOcc, Set<String> firstOriginals,
        Map<String, Integer> secondOcc, Set<String> secondOriginals, List<String[]> topicList, ResultKeeper resultKeeper, int topicIdx, long current) {
        if (topicIdx == topicList.size()) {
            if (current > resultKeeper.getResult()) {
                resultKeeper.setResult(current);
            }
            return;
        }

        String first = topicList.get(topicIdx)[0];
        String second = topicList.get(topicIdx)[1];

        boolean firstOriginal = firstOriginals.contains(first);
        boolean secondOriginal = secondOriginals.contains(second);
        Integer firstOccurrence = firstOcc.get(first);
        Integer secondOccurrence = secondOcc.get(second);

        // Minus one occurrence in the end
        firstOcc.put(first, firstOccurrence - 1);
        secondOcc.put(second, secondOccurrence - 1);

        if ((!firstOriginal && firstOccurrence == 1) || (!secondOriginal && secondOccurrence == 1)) {
            firstOriginals.add(first);
            secondOriginals.add(second);
            doIteration(firstOcc, firstOriginals, secondOcc, secondOriginals, topicList, resultKeeper, topicIdx + 1, current);

            // Recover from it
            if (firstOriginal) {
                firstOriginals.add(first);
            } else {
                firstOriginals.remove(first);
            }
            if (secondOriginal) {
                secondOriginals.add(second);
            } else {
                secondOriginals.remove(second);
            }
        } else {
            // 1st way is count as originals
            firstOriginals.add(first);
            secondOriginals.add(second);
            doIteration(firstOcc, firstOriginals, secondOcc, secondOriginals, topicList, resultKeeper, topicIdx + 1, current);

            // Recover from it
            if (firstOriginal) {
                firstOriginals.add(first);
            } else {
                firstOriginals.remove(first);
            }
            if (secondOriginal) {
                secondOriginals.add(second);
            } else {
                secondOriginals.remove(second);
            }

            doIteration(firstOcc, firstOriginals, secondOcc, secondOriginals, topicList, resultKeeper, topicIdx + 1, current + 1);
        }

        // Recover
        firstOcc.put(first, firstOccurrence);
        secondOcc.put(second, secondOccurrence);
    }

    private static void addToMap(Map<String, Integer> map, String s) {
        Integer number = map.get(s);
        if (number == null) {
            map.put(s, 1);
        } else {
            map.put(s, number + 1);
        }
    }

    public static class ResultKeeper {

        private long result;

        public long getResult() {
            return result;
        }

        public void setResult(long result) {
            this.result = result;
        }
    }
}
