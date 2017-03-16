package at.jaki.round0.B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class B {

    private static final String INPUT = "B-small-attempt0.in";
    //private static final String INPUT = "B-test.in";
    private static final String OUTPUT = "B-small-attempt0.out";
    //private static final String OUTPUT = "B-test.out";

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(OUTPUT);
        int totalTests = Integer.parseInt(br.readLine());
        for (int testNo = 1; testNo <= totalTests; testNo++) {
            String[] input = br.readLine().split(" ");
            double c = Double.parseDouble(input[0]);
            double f = Double.parseDouble(input[1]);
            double x = Double.parseDouble(input[2]);

            double bestFinishTime = Double.MAX_VALUE;
            double time = 0;
            double currGain = 2.0;
            while (true) {
                double y = x / currGain + time;
                if (y < bestFinishTime) {
                    bestFinishTime = y;
                } else {
                    break;
                }
                time += c / currGain;
                currGain += f;
            }

            System.out.println(bestFinishTime);
            pw.print("Case #" + testNo + ": ");
            pw.println(bestFinishTime);
        }

        pw.flush();
        pw.close();

    }
}
