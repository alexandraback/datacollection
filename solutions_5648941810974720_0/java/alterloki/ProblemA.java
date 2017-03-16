package y2016.contest.r1b;

import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @author ashevenkov 30.04.16 18:49.
 */
public class ProblemA {

    public static final String TITLE = "A-small-attempt3";
    private static BufferedReader in = prodIn();
    private static BufferedWriter out = prodOut();

    private static BufferedWriter prodOut() {
        try {
            return new BufferedWriter(new FileWriter("codejam/output/" + TITLE + ".out"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private static BufferedReader prodIn() {
        try {
            return new BufferedReader(new FileReader("codejam/input/" + TITLE + ".in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }


    private static BufferedWriter testOut() {
        return new BufferedWriter(new OutputStreamWriter(System.out));
    }

    private static BufferedReader testIn() {
        return new BufferedReader(new InputStreamReader(System.in));
    }

    public static void main(String[] args) throws Exception {
        new ProblemA().solve(in, out);
        out.flush();
        out.close();
    }

    //implement
    private void solve(BufferedReader in, BufferedWriter out) throws Exception {
        Scanner scanner = new Scanner(in);
        int t = scanner.nextInt();
        for(int i = 0; i < t; i++) {
            String s = scanner.next();
            out.write("Case #" + (i + 1) + ": " + solveCase(s));
            out.newLine();
        }
    }

    private String solveCase(String s) {
        Map<Character, Integer> charCount = countChars(s);
        int[] numbersCount = new int[10];
        numbersCount[2] = countAndMinus(charCount, 'W', "TWO");
        numbersCount[8] = countAndMinus(charCount, 'G', "EIGHT");
        numbersCount[3] = countAndMinus(charCount, 'T', "THREE");
        numbersCount[0] = countAndMinus(charCount, 'Z', "ZERO");
        numbersCount[4] = countAndMinus(charCount, 'R', "FOUR");
        numbersCount[5] = countAndMinus(charCount, 'F', "FIVE");
        numbersCount[6] = countAndMinus(charCount, 'X', "SIX");
        numbersCount[7] = countAndMinus(charCount, 'S', "SEVEN");
        numbersCount[1] = countAndMinus(charCount, 'O', "ONE");
        numbersCount[9] = countAndMinus(charCount, 'I', "NINE");
        int allNumCount = 0;
        for (int i : numbersCount) {
            allNumCount += i;
        }
        int[] result = new int[allNumCount];
        int counter = 0;
        for (int i = 0; i < numbersCount.length; i++) {
            int nCount = numbersCount[i];
            for(int j = 0; j < nCount; j++) {
                result[counter++] = i;
            }
        }
        Arrays.sort(result);
        return toStringResult(result);
    }

    private String toStringResult(int[] result) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < result.length; i++) {
            sb.append(result[i]);
        }
        return sb.toString();
    }

    private int countAndMinus(Map<Character, Integer> charCount, char c, String numberString) {
        Integer numberCount = charCount.get(c);
        if(numberCount == null) {
            numberCount = 0;
        }
        if(numberCount > 0) {
            for (char c1 : numberString.toCharArray()) {
                Integer currentCount = charCount.get(c1);
                currentCount -= numberCount;
                charCount.put(c1, currentCount);
            }
        }
        return numberCount;
    }

    private Map<Character, Integer> countChars(String s) {
        Map<Character, Integer> result = new HashMap<>();
        for (char c : s.toCharArray()) {
            Integer count = result.get(c);
            if(count == null) {
                count = 0;
            }
            count++;
            result.put(c, count);
        }
        return result;
    }
}
