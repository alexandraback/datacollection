package com.googlerese.file;

public class GooglersBean {

    private int numGooglers;

    private int surprising;

    private int result;

    private int[] scores = new int[100];

    public int getNumGooglers() {
        return numGooglers;
    }

    public int getSurprising() {
        return surprising;
    }

    public int getResult() {
        return result;
    }

    public int[] getScores() {
        return scores;
    }

    public void setNumGooglers( int numGooglers ) {
        this.numGooglers = numGooglers;
    }

    public void setSurprising( int surprising ) {
        this.surprising = surprising;
    }

    public void setResult( int result ) {
        this.result = result;
    }

    public void setScores( int[] scores ) {
        this.scores = scores;
    }

    public void addScore( int index, int score ) {
        scores[index] = score;
    }

}
