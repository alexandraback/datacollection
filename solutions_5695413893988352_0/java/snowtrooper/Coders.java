package jam2016.round1b;

import java.io.*;
import java.util.regex.Pattern;

/**
 *
 */
public class Coders {
    private static final String TEST_FILE_NAME = "/Users/apovh/projects/GooglePractice/src/jam2016/round1b/B-small";

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(TEST_FILE_NAME + ".in.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter(TEST_FILE_NAME + ".out"));

        Integer casesNum = Integer.valueOf(reader.readLine());
        System.out.println("index = " + casesNum);
        long startTime = System.currentTimeMillis();


        for (int i = 1; i <= casesNum; i++) {
            String[] scores = reader.readLine().split(" ");

            String codersScore = scores[0];
            String jammersScore = scores[1];
            int length = codersScore.length();
            Pattern codersPattern = Pattern.compile(codersScore.replaceAll("\\?", "\\\\d"));
            Pattern jammersPattern = Pattern.compile(jammersScore.replaceAll("\\?", "\\\\d"));

            int max = (int) Math.pow(10, length);
            int codersScoreResult = -1;
            int jammersScoreResult = -1;
            int minimumDifference = -1;
            boolean done = false;

            for (int c = 0; c < max; c++) {
                String cStr = Integer.toString(c);
                cStr = cStr.length() == length ? cStr : getZeroes(length - cStr.length()) + cStr;
                if (codersPattern.matcher(cStr).matches()) {
                    for (int j = 0; j < max; j++) {
                        String jStr = Integer.toString(j);
                        jStr = jStr.length() == length ? jStr : getZeroes(length - jStr.length()) + jStr;
                        if (jammersPattern.matcher(jStr).matches()) {
                            int scoreDiff1 = c - j;
                            int scoreDiff2 = j - c;
                            int scoreDiff = -1;

                            if (scoreDiff1 >= 0) {
                                if (scoreDiff2 >= 0) {
                                    if (scoreDiff1 >= scoreDiff2) {
                                        scoreDiff = scoreDiff2;
                                    }
                                    else {
                                        scoreDiff = scoreDiff1;
                                    }
                                }
                                else {
                                    scoreDiff = scoreDiff1;
                                }
                            }
                            else if (scoreDiff2 >= 0) {
                                scoreDiff = scoreDiff2;
                            }

                            if (minimumDifference == -1) {
                                minimumDifference = scoreDiff;
                                codersScoreResult = c;
                                jammersScoreResult = j;
                            }
                            else if (scoreDiff < minimumDifference) {
                                minimumDifference = scoreDiff;
                                codersScoreResult = c;
                                jammersScoreResult = j;
                            }
                            else if (scoreDiff == minimumDifference) {
                                if (c < codersScoreResult) {
                                    codersScoreResult = c;
                                    jammersScoreResult = j;
                                }
                                else if (c == codersScoreResult && j < jammersScoreResult) {
                                    jammersScoreResult = j;
                                }
                            }
                        }
                    }
                }
            }

            String codersZeroes = getZeroes(length - Integer.toString(codersScoreResult).length());
            String jammersZeroes = getZeroes(length - Integer.toString(jammersScoreResult).length());
            String result = codersZeroes + codersScoreResult + " " + jammersZeroes + jammersScoreResult;

            String caseResult = "Case #" + i + ": " + result;
            System.out.println(caseResult);
            writer.write(caseResult);
            writer.newLine();

        }
        System.out.println("Total time: " + (System.currentTimeMillis() - startTime));

        reader.close();
        writer.close();
    }

    private static String getZeroes(int length) {
        if (length == 0) {
            return "";
        }
        StringBuilder zeroes = new StringBuilder();
        for (int i = 0; i < length; i++) {
            zeroes.append(0);
        }
        return zeroes.toString();
    }

}
