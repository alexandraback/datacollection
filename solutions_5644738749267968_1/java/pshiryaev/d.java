/*
 * D. Deceitful War
 * Qualification Round 2014
 */
package jam.y2014.q;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 *
 * @author ps
 */
public class d {

    static Scanner in;
    static PrintStream out;
    static final String filepath = System.getProperty("user.dir") + "//src//jam//y2014//q//D-large.in";
    //static final String filepath = System.getProperty("user.dir") + "//src//jam//y2014//q//D-small-attempt0.in";
    //static final String filepath = System.getProperty("user.dir") + "//src//jam//y2014//q//D-sample.in";

    public static void main(String[] args) throws FileNotFoundException {

        System.out.println(filepath);
        in = new Scanner(new File(filepath));
        out = new PrintStream(new File(filepath + ".out"));

        int T = Integer.parseInt(in.nextLine()); // The first line of the input gives the number of test cases, T. T test cases follow. 
        for (int t = 1; t <= T; t++) {

            int N = in.nextInt(); // number of blocks

            ArrayList naomi = new ArrayList(N);
            ArrayList ken = new ArrayList(N);
            for (int i = 1; i <= N; i++) {
                naomi.add(in.nextFloat());
            }
            for (int i = 1; i <= N; i++) {
                ken.add(in.nextFloat());
            }

            int Z = playWar(naomi, ken, N);
            int Y = playDeceitfulWar(naomi, ken, N);

            System.out.println("Case #" + t + ": " + Y + " " + Z);
            out.println("Case #" + t + ": " + Y + " " + Z);

        }
        in.close();
        out.close();
    }

    static int playWar(ArrayList input_naomi, ArrayList input_ken, int N) {

        ArrayList naomi = new ArrayList(input_naomi.size());
        naomi.addAll(input_naomi);

        ArrayList ken = new ArrayList(input_ken.size());
        ken.addAll(input_ken);
        Collections.sort(ken);

        int naomiPoints = 0;
        while (naomi.size() > 0) {
            float naomiChosen = (float) naomi.get(0); // get 1st element
            int kenJ = -1; // ken's choice
            for (int j = 0; j < ken.size(); j++) {
                float kenChosen = (float) ken.get(j);
                if (kenChosen > naomiChosen) // ken won
                {
                    kenJ = j;
                    break;
                }
            }

            if (kenJ == -1) // naomi wins
            {
                naomiPoints++;
                kenJ = 0; // destroy lightest block
            }

            // destroy blocks
            naomi.remove(0);
            ken.remove(kenJ);

        }

        return naomiPoints;

    }

    static int playDeceitfulWar(ArrayList naomi, ArrayList ken, int N) {

        int naomiPoints = 0;

        Collections.sort(naomi, Collections.reverseOrder());
        Collections.sort(ken, Collections.reverseOrder());

        // need to maximize a number of Naomi's blocks that are just above Ken's weights
        // all of them will play
        while (naomi.size() > 0) {
            {
                float naomiChosen = (float) naomi.get(0);

                int kenJ = 0; // delete heaviest ken's element by default
                for (int j = 0; j < ken.size(); j++) {
                    float kenChosen = (float) ken.get(j);
                    if (kenChosen < naomiChosen) // naomi's block will play
                    {
                        naomiPoints++;

                        kenJ = j;
                        break;
                    }

                }

                // destroy blocks
                naomi.remove(0);
                ken.remove(kenJ);

            }
        }
        return naomiPoints;
    }

}
