/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejamround1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 *
 * @author Dean
 */
public class CodeJamRound1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(reader.readLine().trim());
        for (int i = 1; i <= testCases; i++) {
            String line = reader.readLine().trim();
            StringTokenizer st = new StringTokenizer(line);
            int contestants = Integer.parseInt(st.nextToken());
            double scores[] = new double[contestants];
            int count = 0;
            while (st.hasMoreTokens()) {
                scores[count] = Integer.parseInt(st.nextToken());
                count++;
            }

            System.out.println("Case #" + i + ": " + calculateAnswer(scores));
        }

    }

    public static String calculateAnswer(double scores[]) {
        double sum = 0;
        for (int i = 0; i < scores.length; i++) {
            sum += scores[i];
        }


        String ans = "";
        double total = 0;
        double answers[] = new double[scores.length];
        boolean done = false;
        while (!done) {
            done = true;
            double c = calcC(scores, sum);
            for (int i = 0; i < scores.length; i++) {
                if (scores[i] != -1) {
                    double temp = (100 * (c - scores[i]) / sum);
                    if (temp < 0) {
                        temp = 0.0;
                        scores[i] = -1;
                        answers[i] = temp;
                        done = false;
                        break;
                    }
                    else {
                        answers[i] = temp;
                    }
                }
            }
        }
        for (int i = 0; i < answers.length; i++) {
            ans = ans + answers[i] + " ";
        }
        ans = ans.trim();
        return ans;
    }

    public static double calcC(double scores[], double total) {
        double sum = 0;
        int count = 0;
        for (int i = 0; i < scores.length; i++) {
            if (scores[i] == -1) {
                continue;
            }
            sum += scores[i];
            count++;
        }
        return (sum + total) / count;
    }
}
