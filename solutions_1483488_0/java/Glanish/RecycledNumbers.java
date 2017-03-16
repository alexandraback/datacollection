/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejamqualifier;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

/**
 *
 * @author Dean
 */
public class RecycledNumbers {

    public static void main(String args[]) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < testCases; i++) {
            String split[] = reader.readLine().split("[\\s]+");
            int A = Integer.parseInt(split[0]);
            int B = Integer.parseInt(split[1]);
            System.out.println("Case #" + (i + 1) + ": " + countPermutations(A, B));
        }
    }

    public static int countPermutations(int A, int B) {
        int count = 0;

        int digits = (B + "").length();
        for (int m = A + 1; m <= B; m++) {
            HashMap<Integer, Boolean> checked = new HashMap<Integer, Boolean>(10);
            for (int i = 1; i < digits; i++) {
                int mul = (int) (Math.pow(10, i));
                int move = m % mul;
                int n = m / mul;
                n = n + move * (int) (Math.pow(10, (digits - i)));
                if ((n < m) && ((n + "").length() == digits)&& (A <= n)) {
                    //count++;
                    if (checked.containsKey(n)) {
                        continue;
                    } else {
                        count++;
                        checked.put(n, true);
                    }
                }
            }
        }
        return count;
    }
}
