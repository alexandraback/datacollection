package cookies;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 * Created with IntelliJ IDEA.
 * User: thasner
 * Date: 4/11/14
 * Time: 7:35 PM
 * To change this template use File | Settings | File Templates.
 */
public class Cookie {

    private static final String SPACE = " ";

    private static int nRead = 0;

    private static double findMinTime(double farmCost, double farmOutput, double goal) {
        int startingOutput = 2;
        // Easy case.  We will reach 'goal' before even having the option to buy a farm
        if (goal < farmCost) {
            return (goal / startingOutput);
        }

        double time = 0;
        double currentOutput = startingOutput;

        while (true) {
            // We have the option to buy a farm, or wait it out.
            double oneFarmTime, noFarmTime;
            // Let's see if we would be better buying one farm or none

            // One Farm
            //
            double timeToBuyFarm = farmCost / currentOutput;
            double newOutput = currentOutput + farmOutput;
            oneFarmTime = (goal / newOutput) + timeToBuyFarm;

            // No Farm
            //
            noFarmTime = goal / currentOutput;

            if (noFarmTime < oneFarmTime) {
                return time + noFarmTime;
            }
            time += timeToBuyFarm;
            currentOutput = newOutput;
        }
    }

//    // You should always enter this method with 0 cookies
//    private static double findMinTime(double time, double currentOutput, double farmCost, double farmOutput, double goal) {
//
//        // We have the option to buy a farm, or wait it out.
//        double oneFarmTime, noFarmTime;
//        // Let's see if we would be better buying one farm or none
//
//        // One Farm
//        //
//        double timeToBuyFarm = farmCost / currentOutput;
//        double newOutput = currentOutput + farmOutput;
//        oneFarmTime = (goal / newOutput) + timeToBuyFarm;
//
//        // No Farm
//        //
//        noFarmTime = goal / farmOutput;
//
//        if (noFarmTime < oneFarmTime) {
//            return time + noFarmTime;
//        }
//        return findMinTime(time + oneFarmTime, newOutput, farmCost, farmOutput, goal);
//    }

    public static void main(String[] args) throws Exception {
        FileReader input = new FileReader("src/cookies/B-small-attempt2.in");
//        FileReader input = new FileReader("src/cookies/example.in");
//        FileReader input = new FileReader("src/cookies/A-large-practice.in");
        BufferedReader b = new BufferedReader(input);

        FileWriter output = new FileWriter("src/cookies/B-small-attempt2.out");
//        FileWriter output = new FileWriter("src/cookies/example.out");
//        FileWriter output = new FileWriter("src/cookies/A-large-practice.out");
        BufferedWriter w = new BufferedWriter(output);

        String nLines = b.readLine();
        int n = Integer.parseInt(nLines);

        String line = null;
        String tmp = null;
        double x, y, z, t;
        while ((line = b.readLine()) != null) {
            String[] nums = line.split(SPACE);
            tmp = nums[0];
            x = Double.parseDouble(tmp);
            tmp = nums[1];
            y = Double.parseDouble(tmp);
            tmp = nums[2];
            z = Double.parseDouble(tmp);

            t = Cookie.findMinTime(x, y, z);
            Cookie.nRead++;

            w.write("Case #" + nRead + ": " + t);
            w.newLine();
        }

        // Safety check
        if (nRead != n) {
            throw new Exception("   ");
        }

        w.flush();
        w.close();
    }
}
