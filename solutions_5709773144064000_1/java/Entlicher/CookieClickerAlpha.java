/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cookieclickeralpha;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author martin
 */
public class CookieClickerAlpha {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        String fileName;
        if (args.length < 1) {
            fileName = "/mnt/SSD180/GCJ/2014_Qualif/B/Sample.txt";
        } else {
            fileName = args[0];
        }
        TestCase[] tcs = readTestCases(new File(fileName));
        for (int i = 0; i < tcs.length; i++) {
            double y = getMinimumSeconds(tcs[i]);
            System.out.println("Case #"+(i+1)+": "+y);
        }
    }

    private static TestCase[] readTestCases(File f) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(f));
        String line = br.readLine(); // Number of test cases
        int n = Integer.parseInt(line);
        //System.err.println("Have "+n+" test cases.");
        TestCase[] testCases = new TestCase[n];
        for (int i = 0; i < n; i++) {
            TestCase tc = new TestCase();
            line = br.readLine();
            int pos = 0;
            int pos2 = line.indexOf(' ', pos);
            tc.C = Double.parseDouble(line.substring(pos, pos2));
            pos = pos2 + 1;
            pos2 = line.indexOf(' ', pos);
            tc.F = Double.parseDouble(line.substring(pos, pos2));
            pos = pos2 + 1;
            tc.X = Double.parseDouble(line.substring(pos));
            testCases[i] = tc;
        }
        return testCases;
    }

    private static double getMinimumSeconds(TestCase testCase) {
        double C = testCase.C;
        double F = testCase.F;
        double X = testCase.X;
        double s = X/2; // Maximum number of seconds when we do not buy anything
        int n = 0;
        double sum = 0;
        double s2 = s;
        do {
            sum += C/(2 + n*F);
            s2 = sum + X/(2 + (n+1)*F);
            if (s2 < s) {
                s = s2;
            } else {
                break;
            }
            n++;
        } while (true);
        return s;
    }
    
    private static class TestCase {
        double C, F, X;
    }
}
