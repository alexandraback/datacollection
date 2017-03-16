/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package question3;

import com.sun.org.apache.xpath.internal.FoundIndex;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 *
 * @author karim
 */
public class Question3 {

    static Map<Pair, Integer> found = new HashMap<Pair, Integer>();

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        BufferedWriter out = new BufferedWriter(new FileWriter("output.out"));
        BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
        int numOfcases = Integer.parseInt(in.readLine());
        for (int caseNum = 1; caseNum <= numOfcases; caseNum++) {
            found = new HashMap<Pair, Integer>();
            String input = in.readLine();
            Scanner s = new Scanner(input);
            int a = s.nextInt();
            int b = s.nextInt();
            long output = 0;
            if (b >= 10) {
                for (int currentNum = b; currentNum >= a; currentNum--) {
                    int temp = currentNum;
                    int divisor = 10;
                    while (temp / divisor != 0) {
                        int div = temp / divisor;
                        int reminder = temp % divisor;
                        divisor *= 10;
                        int newNumber = Integer.parseInt("" + reminder + div);
                        if (newNumber >= a && newNumber <= b && newNumber != currentNum) {
                            Pair p = new Pair(newNumber, currentNum);
                            if (!found.containsKey(p)) {
                                System.out.println(currentNum + "  " + newNumber);
                                found.put(p, 1);
                                output++;
                            }
                        }

                    }

                }
            }
            out.write("Case #" + caseNum + ": " + output);
            out.newLine();
        }
        out.flush();
        out.close();
        in.close();
    }
}
