/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package deceitfulwar;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 *
 * @author martin
 */
public class DeceitfulWar {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        String fileName;
        if (args.length < 1) {
            fileName = "/mnt/SSD180/GCJ/2014_Qualif/D/Sample.txt";
        } else {
            fileName = args[0];
        }
        TestCase[] tcs = readTestCases(new File(fileName));
        for (int i = 0; i < tcs.length; i++) {
            int y = getDeceitfulWar(tcs[i]);
            int z = getWar(tcs[i]);
            System.out.println("Case #"+(i+1)+": "+y+" "+z);
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
            int nn = Integer.parseInt(line);
            tc.N = nn;
            line = br.readLine();
            tc.Naomi = readDoubles(nn, line);
            line = br.readLine();
            tc.Ken = readDoubles(nn, line);
            testCases[i] = tc;
        }
        return testCases;
    }

    private static double[] readDoubles(int n, String line) {
        double[] d = new double[n];
        int pos = 0;
        int i = 0;
        do {
            int pos2 = line.indexOf(' ', pos);
            if (pos2 < 0) pos2 = line.length();
            d[i] = Double.parseDouble(line.substring(pos, pos2));
            i++;
            pos = pos2 + 1;
        } while(pos < line.length());
        Arrays.sort(d);
        return d;
    }

    private static int getDeceitfulWar(TestCase testCase) {
        int N = testCase.N;
        double[] Naomi = testCase.Naomi;
        double[] Ken = testCase.Ken;
        List<Double> NaomiList = new ArrayList<>();
        for (double d : Naomi) {
            NaomiList.add(d);
        }
        int score = 0;
        for (int k = 0; k < N; k++) {
            double kenMin = Ken[k];
            // Do we have a larger than his min?
            boolean NaomiHas = false;
            for (int i = 0; i < NaomiList.size(); i++) {
                if (kenMin < NaomiList.get(i)) {
                    score++;
                    NaomiList.remove(i);
                    NaomiHas = true;
                    break;
                }
            }
            if (!NaomiHas) {
                NaomiList.remove(0);
            }
        }
        return score;
    }
    
    /*
    private static int getDeceitfulWar(TestCase testCase) {
        int N = testCase.N;
        double[] Naomi = testCase.Naomi;
        double[] Ken = testCase.Ken;
        List<Double> KenList = new ArrayList<>();
        for (double d : Ken) {
            KenList.add(d);
        }
        List<Double> NaomiList = new ArrayList<>();
        for (double d : Naomi) {
            NaomiList.add(d);
        }
        int score = 0;
        for (int k = 0; k < KenList.size(); k++) {
            double kenMin = KenList.get(k);
            // Do we have a larger than his min?
            for (int i = 0; i < NaomiList; i++) {
                
            }
        }
        /*
        for (int i = 0; i < N; i++) {
            double nao = Naomi[i];
            double maxKen = KenList.get(KenList.size() - 1);
            if (nao < maxKen) {
                // we'll loose..., but Ken will lose it's max
                KenList.remove(KenList.size() - 1);
            } else {
                // we'll win
                score++;
                KenList.remove(0);
            }
        }*//*
        return score;
    }*/

    private static int getWar(TestCase testCase) {
        int N = testCase.N;
        double[] Naomi = testCase.Naomi;
        double[] Ken = testCase.Ken;
        List<Double> KenList = new ArrayList<>();
        for (double d : Ken) {
            KenList.add(d);
        }
        int score = 0;
        for (int i = 0; i < N; i++) {
            double nao = Naomi[i];
            boolean kenHas = false;
            for (int k = 0; k < KenList.size(); k++) {
                if (KenList.get(k) > nao) {
                    KenList.remove(k);
                    kenHas = true;
                    break;
                }
            }
            if (!kenHas) {
                score++;
                KenList.remove(0);
            }
        }
        return score;
    }
    
    private static class TestCase {
        int N;
        double Naomi[];
        double Ken[];
    }
    
}
