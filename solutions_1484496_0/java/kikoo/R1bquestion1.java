/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package r1bquestion1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.Scanner;

/**
 *
 * @author karim
 */
public class R1bquestion1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        BufferedWriter out = new BufferedWriter(new FileWriter("output.out"));
        BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
        int numOfcases = Integer.parseInt(in.readLine());
        Hashtable<Integer, ArrayList<Integer>> sets;
        int temp = 0;
        int numOfNumbers = 0;
        ArrayList<Integer> basicNumbers;
        outerloop:
        for (int caseNum = 1; caseNum <= numOfcases; caseNum++) {
            String input = in.readLine();
            Scanner s = new Scanner(input);
            numOfNumbers = s.nextInt();
            basicNumbers = new ArrayList<Integer>(numOfNumbers);
            sets = new Hashtable<Integer, ArrayList<Integer>>();
            while (s.hasNextInt()) {
                temp = s.nextInt();
                basicNumbers.add(temp);
                ArrayList<Integer> tempL = new ArrayList<Integer>();
                tempL.add(temp);
                sets.put(temp, tempL);
            }
            for (int i = 2; i <= basicNumbers.size(); i++) {
                CombinationGenerator gen = new CombinationGenerator(basicNumbers.size(), i);

                while (gen.hasMore()) {
                    int sum = 0;
                    int[] indices = gen.getNext();
                    ArrayList<Integer> comb = new ArrayList<Integer>();
                    for (int f = 0; f < indices.length; f++) {
                        comb.add(basicNumbers.get(indices[f]));
                        sum += basicNumbers.get(indices[f]);
                    }

                    if (sets.get(sum) != null) {
                        out.write("Case #" + caseNum + ":");
                        out.newLine();
                        for (int jj : comb) {
                            out.write(jj + " ");
                        }
                        out.newLine();
                        for (int jj : sets.get(sum)) {
                            out.write(jj + " ");
                        }
                        out.newLine();
                        continue outerloop;


                    } else {
                        sets.put(sum, comb);
                    }

                }
            }

        }
        out.flush();
        out.close();
        in.close();
    }
}
