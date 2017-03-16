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
public class GettingTheDigitsSolver {

    private static final String PATH_IN = "C:\\Users\\santiago\\Desktop\\codeJam\\large.in";
    private static final String PATH_OUT = "C:\\Users\\santiago\\Desktop\\codeJam\\large.out";

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new java.io.FileReader(PATH_IN));
            BufferedWriter bw = new BufferedWriter(new FileWriter(PATH_OUT));
            int numberOfTests = Integer.parseInt(br.readLine());
            for (int test = 1; test <= numberOfTests; test++) {
                bw.write("case #" + test + ": " + solve(br.readLine()));
                bw.newLine();
            }
            br.close();
            bw.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(GettingTheDigitsSolver.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(GettingTheDigitsSolver.class.getName()).log(Level.SEVERE, null, ex);
        } catch (Exception ex) {
            Logger.getLogger(GettingTheDigitsSolver.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static String solve(String given) {
        String s = given;
        int[] toAnalize = new int[10];
        toAnalize[0] = getDigitQuantity(s, 'Z');
        s = removeNumber(s, toAnalize[0], "ZERO");
        toAnalize[2] = getDigitQuantity(s, 'W');
        s = removeNumber(s, toAnalize[2], "TWO");
        toAnalize[4] = getDigitQuantity(s, 'U');
        s = removeNumber(s, toAnalize[4], "FOUR");
        toAnalize[5] = getDigitQuantity(s, 'F');
        s = removeNumber(s, toAnalize[5], "FIVE");
        toAnalize[6] = getDigitQuantity(s, 'X');
        s = removeNumber(s, toAnalize[6], "SIX");
        toAnalize[7] = getDigitQuantity(s, 'S');
        s = removeNumber(s, toAnalize[7], "SEVEN");
        toAnalize[8] = getDigitQuantity(s, 'G');
        s = removeNumber(s, toAnalize[8], "EIGHT");
        toAnalize[3] = getDigitQuantity(s, 'T');
        s = removeNumber(s, toAnalize[3], "THREE");
        toAnalize[1] = getDigitQuantity(s, 'O');
        s = removeNumber(s, toAnalize[1], "ONES");
        toAnalize[9] = getDigitQuantity(s, 'I');
        String phone = "";
        for (int i = 0; i < toAnalize.length; i++) {
            for (int j = 0; j < toAnalize[i]; j++) {
                phone = phone + i;
            }
        }
        return phone;
    }

    private static int getDigitQuantity(String s, char diffDigit) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == diffDigit) {
                result++;
            }
        }
        return result;
    }

    private static String removeNumber(String s, int times, String number) {
        String result = s;
        if (times > 0) {
            for (int i = 0; i < number.length(); i++) {
                result = removeChar(result, number.charAt(i), times);
            }
        }
        return result;
    }

    private static String removeChar(String s, char c, int numberOfTimes) {
        String result = "";
        int numberOfRemovals = 0;
        for (int i = 0; i < s.length(); i++) {
            if (numberOfRemovals < numberOfTimes) {
                if (s.charAt(i) == c) {
                    numberOfRemovals++;
                } else {
                    result = result + s.charAt(i);
                }
            } else {
                result = result + s.charAt(i);
            }
        }
        return result;
    }

}
