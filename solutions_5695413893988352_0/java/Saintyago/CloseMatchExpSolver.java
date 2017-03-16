/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author santiago
 */
public class CloseMatchExpSolver {

    private static final String PATH_IN = "C:\\Users\\santiago\\Desktop\\codeJam\\small.in";
    private static final String PATH_OUT = "C:\\Users\\santiago\\Desktop\\codeJam\\small.out";

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new java.io.FileReader(PATH_IN));
            BufferedWriter bw = new BufferedWriter(new FileWriter(PATH_OUT));
            int numberOfTests = Integer.parseInt(br.readLine());
            for (int test = 1; test <= numberOfTests; test++) {
                String[] scores = br.readLine().split(" ");
                String[] result = solve(scores[0], scores[1]);
                bw.write("case #" + test + ": " + result[0] + " " + result[1]);
                bw.newLine();
            }
            br.close();
            bw.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(CloseMatchExpSolver.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(CloseMatchExpSolver.class.getName()).log(Level.SEVERE, null, ex);
        } catch (Exception ex) {
            Logger.getLogger(CloseMatchExpSolver.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static String[] solve(String coders, String jammers) {
        return solve(new String[]{coders, jammers}, new String[]{"", ""});
    }

    private static String[] solve(String[] originals, String[] currents) {
        if (currents[0].length() < originals[0].length()) {
            if (originals[0].charAt(currents[0].length()) == '?') {
                String[] sol = solve(originals, new String[]{currents[0] + "0", currents[1]});
                String diff = diff(sol);
                for (int i = 1; i < 10; i++) {
                    String[] solNow = solve(originals, new String[]{currents[0] + i, currents[1]});
                    String diffNow = diff(solNow);
                    if (diff.compareTo(diffNow) > 0) {
                        sol = solNow;
                        diff = diffNow;
                    }
                }
                return sol;
            } else {
                return solve(originals, new String[]{currents[0] + originals[0].charAt(currents[0].length()), currents[1]});
            }
        } else if (currents[1].length() < originals[1].length()) {
            if (originals[1].charAt(currents[1].length()) == '?') {
                String[] sol = solve(originals, new String[]{currents[0], currents[1] + "0"});
                String diff = diff(sol);
                for (int i = 1; i < 10; i++) {
                    String[] solNow = solve(originals, new String[]{currents[0], currents[1] + i});
                    String diffNow = diff(solNow);
                    if (diff.compareTo(diffNow) > 0) {
                        sol = solNow;
                        diff = diffNow;
                    }
                }
                return sol;
            } else {
                return solve(originals, new String[]{currents[0], currents[1] + originals[1].charAt(currents[1].length())});
            }
        } else {
            return currents;
        }
    }

    private static String diff(String[] vector) {
        return diff(greater(vector[0], vector[1]), lower(vector[0], vector[1]));
    }

    private static String greater(String one, String two) {
        for (int i = 0; i < one.length(); i++) {
            if (one.charAt(i) > two.charAt(i)) {
                return one;
            } else if (two.charAt(i) > one.charAt(i)) {
                return two;
            }
        }
        return one;
    }

    private static String lower(String one, String two) {
        String greater = greater(one, two);
        if (greater.equals(one)) {
            return two;
        } else {
            return one;
        }
    }

    private static String diff(String greater, String lower) {
        String result = "";
        int rest = 0;
        for (int i = greater.length() - 1; i >= 0; i--) {
            int g = greater.charAt(i);
            int l = lower.charAt(i);
            int diff = g - (rest + l);
            if (diff < 0) {
                rest = 1;
                result = (diff + 10) + result;
            } else {
                rest = 0;
                result = diff + result;
            }
        }
        return result;

    }

}
