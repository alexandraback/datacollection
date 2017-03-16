import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Vector;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TypewriterMonkey2 {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(new File("input.in"));
                BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output.out")))) {
            int n = sc.nextInt();
            for (int i = 0; i < n; i++) {
                String answer = "Case #" + (i + 1) + ": "
                        + String.format("%.7f", solve(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.next(), sc.next()));
                System.out.println(answer);
                bw.write(answer);
                bw.newLine();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static double solve(int k, int l, int s, String monkey, String target) {
        Vector<String> allWords = new Vector<>();
        getAllWord(k, s, monkey, "", allWords);
        double initBanana = getInitBanana(s, target);
        double useBanana = 0;
        for (String str : allWords) {
            Matcher matcher = Pattern.compile(target).matcher(str);
            int banana = 0;
            while (matcher.find()) {
                banana++;
            }
            useBanana += (double) banana / allWords.size();
        }
        return initBanana - useBanana;
    }

    private static void getAllWord(int k, int s, String monkey, String current, Vector<String> allWords) {
        if (current.length() == s) {
            allWords.add(current);
            return;
        }
        for (char c : monkey.toCharArray()) {
            getAllWord(k, s, monkey, current + c, allWords);
        }

    }

    private static double getDoubleShotPercent(Map<Character, Integer> monkeyCharMap, String target, int monkeySum) {
        double percent = 1;
        boolean isFirst = true;
        for (char c : target.toCharArray()) {
            if (isFirst) {
                percent *= 1 - ((double) monkeyCharMap.get(c) / monkeySum);
                isFirst = false;
            }
            percent *= ((double) monkeyCharMap.get(c) / monkeySum);
        }
        return percent;
    }

    private static double duplicatePercent(Map<Character, Integer> monkeyCharMap, String target, int k) {
        double percent = 0;
        for (int i = 0; i < target.length() - 1; i++) {
            if (target.endsWith(target.substring(0, i + 1))) {
                percent = getPercent(monkeyCharMap, target.substring(i + 1), k);
            } else {
                return percent;
            }
        }
        return percent;
    }

    private static Map<Character, Integer> getMonkeyMap(String monkey) {
        Map<Character, Integer> monkeyCharMap = new HashMap<>();
        for (char c : monkey.toCharArray()) {
            if (monkeyCharMap.containsKey(c)) {
                monkeyCharMap.put(c, monkeyCharMap.get(c) + 1);
            } else {
                monkeyCharMap.put(c, 1);
            }
        }
        return monkeyCharMap;
    }

    private static double getPercent(Map<Character, Integer> monkeyCharMap, String target, int monkeySum) {
        double percent = 1;
        for (char c : target.toCharArray()) {
            percent *= ((double) monkeyCharMap.get(c) / monkeySum);
        }
        return percent;
    }

    private static double getInitBanana(int s, String target) {
        double banana = 0;
        StringBuffer ideal = new StringBuffer();
        while (ideal.length() <= s) {
            ideal.append(target);
        }
        String idealStr = ideal.toString().substring(0, s);
        Matcher matcher = Pattern.compile(target).matcher(idealStr);

        while (matcher.find()) {
            banana++;
        }
        return banana;
    }
}
