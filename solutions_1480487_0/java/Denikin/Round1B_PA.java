/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package round1b_pa;

import java.util.Arrays;
import java.util.Scanner;
import sun.io.ConversionBufferFullException;

/**
 *
 * @author marcin
 */
public class Round1B_PA {

    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = Integer.parseInt(in.nextLine());
        for (int testCase = 1; testCase <= T; ++testCase) {
            int N = in.nextInt();
            int[] scores = new int[N];
            int scoreSum = 0;
            for (int i = 0; i < N; ++i) {
                int nextScore = in.nextInt();
                scoreSum += nextScore;
                scores[i] = nextScore;
            }
            
            int[] sortedScores = scores.clone();
            Arrays.sort(sortedScores);
            
            int intLevel = 0;
            int lacks = 0;
            int aboves = 0;
            for (int i = sortedScores.length - 1; i >= 0; --i) {
                intLevel = sortedScores[i];
                lacks = 0;
                for (int j = 0; j < scores.length; ++j) {
                    lacks += Math.max(0, intLevel - scores[j]);
                }
                if (lacks <= scoreSum) {
                    break;
                }
                ++aboves;
            }
            int surplus = scoreSum - lacks;
            int participants = N - aboves;
            double level = ((double) intLevel) + (((double) surplus) / ((double) participants));
            
            //System.out.println(level);
            
            String resultString = "Case #" + testCase + ":";
            for (int i = 0; i < N; ++i) {
                double result;
                double score = (double) scores[i];
                if (score >= level)
                    result = (double) 0.0;
                else {
                    result = (level - score) / ((double) scoreSum);
                    result *= 100;
                }
                resultString += " " + result;
            }
            System.out.println(resultString);
            
            
            /*int maxLevel = 200;
            int minLevel = 0;
            
            int level = 100;
            int nextLevel;
            while (true) {
                int lacks = 0;
                for (int i = 0; i < N; ++i) {
                    lacks += Math.max(0, level - scores[i]);
                }
                if (lacks > scoreSum) {
                    maxLevel = level - 1;
                } else {
                    minLevel = level;
                }
                nextLevel = (maxLevel - minLevel + 1) / 2 + minLevel;
                //System.out.println("Level: " + level + "; Lacks: " + lacks + "; NextLevel: " + nextLevel + "; MaxL:" + maxLevel + "; MinL: " + minLevel);
                if (nextLevel == level) {
                    break;
                } else {
                    level = nextLevel;
                }
            }
            
            //System.out.println("Level: " + level);
            
            String resultString = "Case #" + testCase + ":";
            for (int i = 0; i < N; ++i) {
                double result;
                int score = scores[i];
                if (score >= level)
                    result = (double) 0.0;
                else {
                    result = ((double) (level - score)) / ((double) scoreSum);
                    result *= 100;
                }
                resultString += " " + result;
            }
            System.out.println(resultString);*/
        }
    }
}
