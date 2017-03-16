/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejamqualifier;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Dean
 */
public class DancingWithGooglers {
    public static void main(String args[]) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(reader.readLine());
        for (int i = 0; i < cases; i ++) {
            String line = reader.readLine().trim();
            String split[] = line.split("[\\s]+");
            int people = Integer.parseInt(split[0]);
            int suprising = Integer.parseInt(split[1]);
            int maxScore = Integer.parseInt(split[2]);
            int count = 0;
            for (int j = 3; j < split.length; j++) {
                double score = Double.parseDouble(split[j]);
                score = (score - maxScore)/2;
                if (score < 0) {
                    continue;
                }
                score = score - maxScore;
                if (score >= -1) {
                    count++;
                }
                else if (score >= -2) {
                    if (suprising > 0) {
                        suprising --;
                        count++;
                    }
                }
            }
            System.out.println("Case #" + (i+1) + ": " + count);
        }
    }
}
