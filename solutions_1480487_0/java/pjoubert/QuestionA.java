/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package year_2012.round1B;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

/**
 *
 * @author paul
 * @date 05 May 2012
 */
public class QuestionA {


    public static void main(String[] args) throws FileNotFoundException, IOException {

        String question = "A";

//        String name = "large";
        String name = "small-attempt1";
//        String name = "test";

        String filename = String.format("%s-%s", question, name);

        BufferedReader input = new BufferedReader(
                new FileReader(String.format("/home/paul/Documents/code-jam/2012/round1b/%s.in",
                filename)));

        String firstLine = input.readLine();

        PrintWriter pw = new PrintWriter(new File(
                String.format("/home/paul/Documents/code-jam/2012/round1b/%s.out", filename)));


        int T = Integer.parseInt(firstLine);

        // Loop through test cases.
        for (int t = 0; t < T; t++) {

            // Read data.
            String[] tokens = input.readLine().split(" ");
            int n = Integer.parseInt(tokens[0]);
            int[] ss = new int[tokens.length - 1];
            double s = 0.0;
            for (int i = 1; i < tokens.length; i++) {
                ss[i-1] = Integer.parseInt(tokens[i]);
                s += ss[i-1];
            }
            int[] sscopy = new int[ss.length];
            for (int i = 0; i < sscopy.length; i++) {
                sscopy[i] = ss[i];
            }
            Arrays.sort(ss);

            double v = s;
            double threshold = ss[0];
            boolean done = false;
            for (int j = 1; j < ss.length; j++) {
                if (ss[j] > threshold) {
                    double need = j * (ss[j] - threshold);
                    if (v >= need) {
                        v -= need;
                        threshold = ss[j];
                    } else {
                        threshold += v / j;
                        done = true;
                    }
                    if (done) {
                        break;
                    }
                }
            }
            if (!done) {
                threshold = 2.0*s / n;
            }

            //            System.out.println(Arrays.toString(ss));



            double[] results = new double[tokens.length - 1];
            for (int i = 0; i < ss.length; i++) {
                results[i] = Math.max((threshold - sscopy[i]) / s, 0.0) * 100.0;
            }
            
//            int B = Integer.parseInt(tokens[1]);
//
//            tokens = input.readLine().split(" ");
//
//
//            double result = 0.0;

            pw.format("Case #%d: ", t + 1);
            for (int i = 0; i < results.length; i++) {
                pw.format("%1.6f ", results[i]);
            }
            pw.format("\n");

//            pw.format("Case #%d: %1.6f\n", t + 1, result);
        }

        pw.close();

    }


}
