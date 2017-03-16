package war;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

/**
 * Created with IntelliJ IDEA.
 * User: thasner
 * Date: 4/11/14
 * Time: 9:02 PM
 * To change this template use File | Settings | File Templates.
 */
public class War {

    private static final String SPACE = " ";

    private static int nRead = 0;

    public static void main(String[] args) throws Exception {
        FileReader input = new FileReader("src/war/D-small-attempt0.in");
//        FileReader input = new FileReader("src/war/example.in");
        BufferedReader b = new BufferedReader(input);

        FileWriter output = new FileWriter("src/war/D-small-attempt0.out");
//        FileWriter output = new FileWriter("src/war/example.out");
        BufferedWriter w = new BufferedWriter(output);

        String nLines = b.readLine();
        int n = Integer.parseInt(nLines);

        String size = null;
        String l1 = null, l2 = null;
        while ((size = b.readLine()) != null && (l1 = b.readLine()) != null && (l2 = b.readLine()) != null) {
            String[] nS = l1.split(SPACE);
            String[] kS = l2.split(SPACE);


            //////////////
            // Solve once for cheating
            ArrayList<Double> nD = getSorted(nS);
            ArrayList<Double> kD = getSorted(kS);

            int nW = 0;
            while (nD.size() > 0) {
                double nNum = nD.remove(0);

                double kLast = kD.get(kD.size() - 1);
                if (nNum > kLast) {
                    // We win the rest
//                    kD.remove(kD.size() - 1);
                    nW += kD.size();
                    break;
                }

                double kFirst = kD.get(0);
                if (nNum > kFirst) {
                    // We can at least trick ken to play his smallest block
                    kD.remove(0);
                    nW++;
                    continue;
                }

                // Take a loss against ken's largest
                kD.remove(kD.size() - 1);
            }

            /////////////////
            // Solve standard
            nD = getSorted(nS);
            kD = getSorted(kS);
            int standardWins = 0;
            while (nD.size() > 0) {
                double nNum = nD.remove(0);

                boolean lostOne = false;
                for (int i = 0; i < kD.size(); i++) {
                    double leastBeat = kD.get(i);
                    if (leastBeat > nNum) {
                        kD.remove(i);
                        lostOne = true;
                        break;
                    }
                }
                if (lostOne) {
                    continue;
                }
                // Otherwise, ken doesn't have any pieces that can beat our smallest number!
                // He can't beat any of our numbers!
                standardWins = kD.size(); // Be careful!!! nD.size is one smaller cuz we grabbed a double out for 'nNum'
            }

            War.nRead++;

            w.write("Case #" + nRead + ": " + nW + " " + standardWins);
            w.newLine();
        }

        // Safety check
        if (size != null) {
            throw new Exception();
        }
        if (nRead != n) {
            throw new Exception("   ");
        }

        w.flush();
        w.close();
    }

    private static ArrayList<Double> getSorted(String[] input) {
        ArrayList<Double> ret = new ArrayList<Double>(input.length);
        for (String s : input) {
            double x = Double.parseDouble(s);
            ret.add(x);
        }
        Collections.sort(ret);
        return ret;
    }
}
