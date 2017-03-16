import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.*;

public class CodeJamC {

    private static final String INPUT = "/opt/dev/TopCoder/src/C-small-attempt2.in";
    private static final String OUTPUT = "/opt/dev/TopCoder/src/out.txt";

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter writer = new PrintWriter(OUTPUT, "UTF-8");
        solve(br, writer);
        br.close();
        writer.close();
    }

    private static void solve(BufferedReader reader, PrintWriter writer) throws Exception {
        int t = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < t; i++) {
            String[] cdv = reader.readLine().trim().split(" ");
            int d = Integer.parseInt(cdv[1]);
            int v = Integer.parseInt(cdv[2]);
            String[] coins = reader.readLine().trim().split(" ");
            int[] coinArray = new int[coins.length];
            int j = 0;
            for (String coinStr : coins) {
                coinArray[j] = Integer.parseInt(coinStr);
                j++;
            }
            writer.println("Case #" + (i + 1) + ": " + resolve(v, coinArray));
        }
    }

    public static String resolve(int v, int[] coinArray) {
        Set<Integer> values = new HashSet<Integer>(1000);
        fill(0, 0, coinArray, values);
        int size = values.size();
        int[] coinValueArray = new int[size];
        int ii = 0;
        for (Integer coinValue : values) {
            coinValueArray[ii] = coinValue;
            ii++;
        }
        Arrays.sort(coinValueArray);

        List<List<Integer>> required = new ArrayList<List<Integer>>(100);
        List<Integer> urgentRequired = new ArrayList<Integer>(100);
        int minCoin = coinValueArray[0];

        for (int i = 1; i < minCoin; i++) {
            urgentRequired.add(i);
        }

        for (int i = minCoin; i <= v; i++) {
            if (!values.contains(i)) {
                List<Integer> requiredThisTime = new ArrayList<Integer>();
                for (int j = 0; j < size && coinValueArray[j] < i; j++) {
                    int candidateRequired = i - coinValueArray[j];
                    if (!contains(coinArray, candidateRequired)) {
                        requiredThisTime.add(candidateRequired);
                    }
                }
                required.add(requiredThisTime);
            }
        }


        int result = 0;
        while (true) {
            if (required.isEmpty() && urgentRequired.isEmpty()) {
                return Integer.toString(result);
            }
            deleteMostPopular(required, urgentRequired);
            result++;
        }


    }

    private static void deleteMostPopular(List<List<Integer>> required, List<Integer> urgentRequired) {
        if (urgentRequired.isEmpty()) {
            Map<Integer, Integer> occurence = new HashMap<Integer, Integer>(30);
            for (int i = 0; i <= 100; i++) {
                occurence.put(i, 0);
            }

            for (List<Integer> requiredList : required) {
                for (Integer coin : requiredList) {
                    occurence.put(coin, occurence.get(coin) + 1);
                }
            }

            Integer maxOccurence = null;
            Integer maxCoin = null;

            for (Map.Entry<Integer, Integer> occurEntry : occurence.entrySet()) {
                int coin = occurEntry.getKey();
                int occur = occurEntry.getValue();
                if (maxOccurence == null || occur > maxOccurence) {
                    maxCoin = coin;
                    maxOccurence = occur;
                }
            }

            Iterator<List<Integer>> iterator = required.iterator();
            while (iterator.hasNext()) {
                List<Integer> reqCoins = iterator.next();
                boolean delete = false;
                for (Integer coin : reqCoins) {
                    if (coin.equals(maxCoin)) {
                        delete = true;
                        break;
                    }
                }
                if (delete) {
                    iterator.remove();
                }
            }
        } else {
            int coin = urgentRequired.remove(urgentRequired.size() - 1);

            Iterator<List<Integer>> iterator = required.iterator();
            while (iterator.hasNext()) {
                List<Integer> reqCoins = iterator.next();
                boolean delete = false;
                for (Integer ccoin : reqCoins) {
                    if (ccoin.equals(coin)) {
                        delete = true;
                        break;
                    }
                }
                if (delete) {
                    iterator.remove();
                }
            }
        }

    }

    private static boolean contains(int[] array, int value) {
        for (int arrItem : array) {
            if (arrItem == value) {
                return true;
            }
        }
        return false;
    }

    private static void fill(int curVal, int nextCoinIndex, int[] coinArray, Set<Integer> valueSet) {
        if (nextCoinIndex == coinArray.length) {
            valueSet.add(curVal);
            return;
        }
        fill(curVal, nextCoinIndex + 1, coinArray, valueSet);
        fill(curVal + coinArray[nextCoinIndex], nextCoinIndex + 1, coinArray, valueSet);
    }

}
