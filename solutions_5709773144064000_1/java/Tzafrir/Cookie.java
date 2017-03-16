package googleContest.Jam2015;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Cookie {
    public static void main(String[] args) throws FileNotFoundException {
        System.setOut(new PrintStream(args[0]+".out"));
        new Cookie().solve(args);
    }

    private DecimalFormat df;
    private double calcTotalTime(int farmsCount, double cost, double productionInc, double goal) {
        double time = 0;
        double rate = 2;
        for (int i=0;i<farmsCount;i++) {
            time+=cost/rate;
            rate += productionInc;
        }
        time+=goal/rate;
        return time;
    }

    /**
     *
     * choose whether to buy a farm or not
     * return amount of farms to buy
     * @param prodRate
     * @param cost
     * @param productionInc
     * @param goal
     * @return
     */
    private int howManyFarmsToBuy(double prodRate, double cost, double productionInc, double goal) {
        double timeWithFarm = goal/(prodRate+productionInc);
        double timeWithoutFarm = (goal-cost)/(prodRate);
        int count = 0;
        while (timeWithFarm<timeWithoutFarm) {
            count++;
            prodRate+=productionInc;
            timeWithFarm = goal/(prodRate+productionInc);
            timeWithoutFarm = (goal-cost)/(prodRate);
        }
        return count;
    }

    /**
     * solve the given riddle
     * first read the amount of riddles in the data, then solve each of it
     * @param scanner to read the input data from
     */
    public void solve(Scanner scanner) {
        int numCases = scanner.nextInt();
        df = new DecimalFormat("#.0000000");
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

    /**
     * solve a given case of the underlying riddle
     * @param scanner to get the input data from
     */
    public void solveCase(Scanner scanner) {
        double cost = scanner.nextDouble();
        double productionInc = scanner.nextDouble();
        double goal = scanner.nextDouble();
        double prodRate = 2;
        int farmsCount = howManyFarmsToBuy(prodRate,cost,productionInc,goal);
        double totalTime= calcTotalTime(farmsCount,cost,productionInc,goal);

        System.out.println(df.format(totalTime));
    }
}
