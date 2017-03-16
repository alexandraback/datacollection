
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ehsan
 */
public class Cookie {
    public static class TestCase {
        double F, C, X, opt_time;
        int M;
    }
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner in = new Scanner(new File("/home/ehsan/Downloads/blarge.in"));
        int n_tests = in.nextInt();
        TestCase[] tests = new TestCase[n_tests];
        for (int i = 0; i < n_tests; i++) {
            tests[i] = new TestCase();
            tests[i].C = in.nextDouble();
            tests[i].F = in.nextDouble();
            tests[i].X = in.nextDouble();
        }
        for (int i = 0; i < n_tests; i++) {
            solve(tests[i]);            
        }
        BufferedWriter bw = new BufferedWriter(new FileWriter("/home/ehsan/results.txt"));
        for (int i = 0; i < n_tests; i++) {
            System.out.println("Case #" + (i + 1) + ": " + tests[i].opt_time);
            bw.write("Case #" + (i + 1) + ": " + tests[i].opt_time + "\n");
        }
        bw.close();
    }
    
    private static void solve(TestCase t) {
        double prev_time = Double.POSITIVE_INFINITY;
        for (int i = 0; ;i++) {
          // buying i farms
          double rate = 2;
          double time = 0;
          
          int nfarms = 0;
          while (nfarms < i) {
              double time_for_farm = (double) t.C / rate;
              time += time_for_farm;
              nfarms++;
              rate += t.F;
          }
          double time_to_end = t.X / rate;
          time += time_to_end;
          if (time > prev_time) {
              t.M = nfarms - 1;
              t.opt_time = prev_time;
              break;
          }
          prev_time = time;
        }
    }
}
