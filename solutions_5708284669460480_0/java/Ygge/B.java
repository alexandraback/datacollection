import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class B {

    private static final String FILE_NAME = "B-small-attempt0";

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            String[] split = in.readLine().split(" ");
            int k = Integer.parseInt(split[0]);
            int s = Integer.parseInt(split[2]);
            String keys = in.readLine();
            String target = in.readLine();

            Map<Character, Integer> keyCount = new HashMap<>();
            for (int i = 0; i < keys.length(); ++i) {
                char c1 = keys.charAt(i);
                int count = keyCount.containsKey(c1) ? keyCount.get(c1) : 0;
                keyCount.put(c1, count+1);
            }

            Result result = new Result();
            calc(result, keyCount, k, s, target, "", 1.0);

            String ans = String.format("Case #%d: %f\n", c, result.max-result.expected);
            out.write(ans);
            System.out.print(ans);
        }
        out.close();
    }

    private static void calc(Result result, Map<Character, Integer> keyCount, int k, int s, String target,
                             String currentWord, double currentProbability) {
        if (currentWord.length() == s) {
            int targetWords = targetWords(currentWord, target);
            result.expected += targetWords * currentProbability;
            if (result.max < targetWords) {
                result.max = targetWords;
            }
            return;
        }
        for (Map.Entry<Character, Integer> entry : keyCount.entrySet()) {
            calc(result, keyCount, k, s, target, currentWord+entry.getKey(), currentProbability*entry.getValue()/k);
        }
    }

    private static int targetWords(String currentWord, String target) {
        int count = 0;
        for (int i = 0; i < currentWord.length()-target.length()+1; ++i) {
            if (target.equals(currentWord.substring(i, i+target.length()))) {
                ++count;
            }
        }
        return count;
    }

    private static class Result {
        int max = 0;
        double expected = 0;
    }
}
