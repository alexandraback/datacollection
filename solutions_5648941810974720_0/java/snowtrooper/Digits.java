package jam2016.round1b;

import java.io.*;
import java.util.*;

/**
 *
 */
public class Digits {
    private static final String TEST_FILE_NAME = "/Users/apovh/projects/GooglePractice/src/jam2016/round1b/A-small";

//    {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
//    "Z", "O?", "W", "T?", "U", "F?", "X", "S?", "G", "N??"

    public static void main(String[] args) throws IOException {
        // data maps setup

        Map<Character, Object[]> primaryDigitsMap = new HashMap<Character, Object[]>();
        primaryDigitsMap.put('Z', new Object[]{"ZERO", 0});
        primaryDigitsMap.put('W', new Object[]{"TWO", 2});
        primaryDigitsMap.put('U', new Object[]{"FOUR", 4});
        primaryDigitsMap.put('X', new Object[]{"SIX", 6});
        primaryDigitsMap.put('G', new Object[]{"EIGHT", 8});


        Map<Character, Object[]> secondaryDigitsMap = new HashMap<Character, Object[]>();
        secondaryDigitsMap.put('O', new Object[]{"ONE", 1});
        secondaryDigitsMap.put('T', new Object[]{"THREE", 3});
        secondaryDigitsMap.put('F', new Object[]{"FIVE", 5});
        secondaryDigitsMap.put('S', new Object[]{"SEVEN", 7});
//        primaryDigitsMap.put('N', new Object[]{"NINE", 9});


        BufferedReader reader = new BufferedReader(new FileReader(TEST_FILE_NAME + ".in.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter(TEST_FILE_NAME + ".out"));

        Integer casesNum = Integer.valueOf(reader.readLine());
        System.out.println("index = " + casesNum);
        long startTime = System.currentTimeMillis();


        for (int i = 1; i <= casesNum; i++) {
            String codedPhone = reader.readLine();
            Map<Character, Integer> lettersToSkip = new HashMap<Character, Integer>();
            List<Integer> result = new ArrayList<Integer>();
            int parsedLength = 0;

            // first iteration
            for (char c : codedPhone.toCharArray()) {
                Object[] digitData = primaryDigitsMap.get(c);
                if (digitData != null) {
                    result.add((Integer) digitData[1]);
                    String digitStr = ((String) digitData[0]);
                    parsedLength += digitStr.length();
                    for (char c_ : digitStr.toCharArray()) {
                        Integer times = lettersToSkip.get(c_);
                        times = times == null ? 1 : times + 1;
                        lettersToSkip.put(c_, times);
                    }
                }
            }

            // second iteration
            for (char c : codedPhone.toCharArray()) {
                Object[] digitData = secondaryDigitsMap.get(c);
                Integer times = lettersToSkip.get(c);

                if (digitData != null) {
                    if (times == null || times == 0) {
                        result.add((Integer) digitData[1]);
                        String digitStr = ((String) digitData[0]);
                        parsedLength += digitStr.length();
                    }
                    else {
                        lettersToSkip.put(c, times - 1);
                    }
                }
            }

            // any nines?
            int ninesLength = codedPhone.length() - parsedLength;
            if (ninesLength > 0) {
                for (int j = 0; j < ninesLength / "NINE".length(); j++) {
                    result.add(9);
                }
            }

            StringBuilder decodedPhone = new StringBuilder();
            Collections.sort(result);
            for (Integer digit : result) {
                decodedPhone.append(digit);
            }

            String caseResult = "Case #" + i + ": " + decodedPhone.toString();
            System.out.println(caseResult);
            writer.write(caseResult);
            writer.newLine();

        }
        System.out.println("Total time: " + (System.currentTimeMillis() - startTime));

        reader.close();
        writer.close();
    }
}
