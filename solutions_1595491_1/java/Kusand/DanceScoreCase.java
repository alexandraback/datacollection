package dancinggooglers;

import java.util.ArrayList;

public class DanceScoreCase {

    private int dancers;
    private int surpriseScores;
    private int scoreThreshold;
    private ArrayList<Integer> scores;

    public DanceScoreCase(String scoreLine) {

        String[] integers = scoreLine.split(" ");
        if(integers.length < 4) {
            throw new IllegalArgumentException("Not enough strings");
        }

        dancers = new Integer(integers[0]);
        surpriseScores = new Integer(integers[1]);
        scoreThreshold = new Integer(integers[2]);
        scores = new ArrayList<Integer>();
        for(int i = 3; i < integers.length; i++) {
            scores.add(Integer.valueOf(integers[i]));
        }

    }

    public Integer maxDancersThatCouldPass() {
        int passesUnsurprising = 0;
        int passesSurprising = 0;
        ArrayList<Integer> couldNotPassUnsuprising = new ArrayList<Integer>();

        for(Integer score : scores) {
            if(canPassThresholdUnsurprising(score, scoreThreshold)) {
                passesUnsurprising++;
            } else if(canPassThresholdSurprising(score, scoreThreshold)) {
                passesSurprising++;
            }
        }

        return passesUnsurprising + Math.min(passesSurprising, surpriseScores);
    }


    public static boolean canPassThresholdUnsurprising(int score, int threshold) {
        int minScore = Math.max(0, threshold-1);
        return (score >= threshold + 2*minScore);
    }

    public static boolean canPassThresholdSurprising(int score, int threshold) {
        int minScore = Math.max(0, threshold-2);
        return (score >= threshold + 2*minScore);
    }

    public int getDancers() {
        return dancers;
    }

    public int getSurpriseScores() {
        return surpriseScores;
    }

    public int getScoreThreshold() {
        return scoreThreshold;
    }

    public ArrayList<Integer> getScores() {
        return scores;
    }
}
