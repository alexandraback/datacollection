package googleContest.Jam2015;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class War {

    public static void main(String[] args) throws FileNotFoundException {
        System.setOut(new PrintStream(args[0]+".out"));
        new War().solve(args);
    }

    private double[] naomiData;
    private double[] kenData;
    private boolean[] naomiUsedData;
    private boolean[] kenUsedData;
    private int n;
    //    private double DELTA = 0.0000000000;
    private final double DELTA_CONST = 0.0000000001;

    /**
     * pick the best card out of ken's data to match the given number
     * pick the first higher, or the lowest
     * @param naomiCard
     * @return
     */
    private double bestWarCard(double[] data, boolean[] usedData, double opponentCard) {
        int ind = n-1;
        //look for the smallest number that is bigger
        while (ind>0 && data[ind-1]>opponentCard)
            ind--;
        while (usedData[ind] && ind<n-1)
            ind++;
        //if couldnt find any, look for the smallest number
        if (data[ind]<opponentCard || usedData[ind]) {
            //return lowest numer
            ind = 0;
            while (usedData[ind])
                ind++;
        }
        //mark the index as used and return it
        usedData[ind]=true;
        return data[ind];
    }

    private void decietfulWar() {
        int count = 0;
        for (int index=n-1; index>=0;index--) {
            double naomiCard = naomiTellCard();
            double kenCard = bestWarCard(kenData,kenUsedData,naomiCard);
            naomiCard = bestWarCard(naomiData,naomiUsedData,kenCard);
            if (naomiCard>kenCard)
                count++;
        }
        System.out.print(count+ " ");
    }

    private double naomiTellCard() {
        for (int i=n-1;i>=0;i--)
            if (!naomiUsedData[i])
                return naomiData[i]-DELTA_CONST;
        throw new IllegalArgumentException("data is all used!");
    }

    private void resetUsed() {
        for (int i=0;i<n;i++) {
            kenUsedData[i]=false;
            naomiUsedData[i]=false;
        }

    }

    /**
     * solve the given riddle
     * first read the amount of riddles in the data, then solve each of it
     * @param scanner to read the input data from
     */
    public void solve(Scanner scanner) {
        int numCases = scanner.nextInt();
        for (int i = 1; i <= numCases; i++) {
            System.out.print("Case #" + i + ": ");
            solveCase(scanner);
        }
    }

    /**
     * solve the given riddle
     * if the args array is not empty, get the input data file from the first value
     * otherwise read the input data from the stdin
     * @param args
     */
    public void solve(String[] args) throws FileNotFoundException {
        InputStream is;
        if (args.length > 0)
            is = new BufferedInputStream(new FileInputStream(args[0]));
        else
            is = System.in;
        Scanner scanner = new Scanner(is);
        solve(scanner);
    }

    private void solveCase(Scanner scanner) {
        long tick = System.currentTimeMillis();
        n = scanner.nextInt();
        naomiData = new double[n];
        naomiUsedData = new boolean[n];
        for (int i=0;i<n;i++)
            naomiData[i] = scanner.nextDouble();
        kenData = new double[n];
        kenUsedData = new boolean[n];
        for (int i=0;i<n;i++)
            kenData[i] = scanner.nextDouble();
        Arrays.sort(kenData);
        Arrays.sort(naomiData);
        resetUsed();
        decietfulWar();
        resetUsed();
        warScore();
        long tock = System.currentTimeMillis();
        //        System.out.println(tock-tick);
    }

    private void warScore() {
        int count = 0;
        for (int index=n-1; index>=0;index--) {
            double naomiCard = naomiData[index];
            double kenCad = bestWarCard(kenData,kenUsedData,naomiCard);
            if (naomiCard>kenCad)
                count++;
        }
        System.out.println(count);
    }

}
