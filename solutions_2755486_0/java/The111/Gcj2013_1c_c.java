package Gcj2013_1c;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Gcj2013_1c_c {
    final static String WORK_DIR = "C:\\eclipse\\workspace\\GoogleCodeJam\\IO\\2013_1c\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        
        int numSuccesses = 0;
        
        int[] d = new int[N];
        int[] d2 = new int[N];
        int[] n = new int[N];
        int[] w = new int[N];
        int[] e = new int[N];
        int[] s = new int[N];
        int[] delta_d = new int[N];
        int[] delta_p = new int[N];
        int[] delta_s = new int[N];
        
        for (int i = 0; i < N; i++) {
            d[i] = sc.nextInt();
            n[i] = sc.nextInt();
            w[i] = sc.nextInt();
            e[i] = sc.nextInt();
            s[i] = sc.nextInt();
            delta_d[i] = sc.nextInt();
            delta_p[i] = sc.nextInt();
            delta_s[i] = sc.nextInt();
            d2[i] = d[i] + (n[i] - 1) * delta_d[i];
        }
        
        int wallStart = w[0];
        int wallEnd = e[0];
        int dayStart = d[0];
        int dayEnd = d[0] + (n[0] - 1) * delta_d[0];
        for (int i = 0; i < N; i++) {
            wallStart = Math.min(wallStart, w[i]);
            wallStart = Math.min(wallStart, w[i] + (n[i] - 1) * delta_p[i]);
            wallEnd = Math.max(wallEnd, e[i]);
            wallEnd = Math.max(wallEnd, e[i] + (n[i] - 1) * delta_p[i]);
            dayStart = Math.min(dayStart, d[i]);
            dayEnd = Math.max(dayEnd, d[i] + (n[i] - 1) * delta_d[i]);
        }
        
        int[] wall = new int[wallEnd - wallStart];
        int[] strength = new int[wall.length];
        for (int i = 0; i < strength.length; i++) {
            strength[i] = 0;
        }
        
        for (int i = dayStart; i <= dayEnd; i++) { // for each day
            for (int j = 0; j < N; j++) { // for each tribe
                if (i >= d[j] && i <= d2[j] && (i - d[j]) % delta_d[j] == 0) { // if tribe j attacks on day i...
                    int numDayDeltas = (i - d[j]) / delta_d[j];
                    
                    int attackWest = w[j] + numDayDeltas * delta_p[j];
                    int attackEast = e[j] + numDayDeltas * delta_p[j];
                    int attackStrength = s[j] + numDayDeltas * delta_s[j];
                    
                    //System.out.println("on day " + i + " tribe " + j + " attacks from " + attackWest + " to "
                    //+ attackEast + " with strength " + attackStrength);
                    
                    boolean attackSucceeded = false;
                    for (int k = attackWest; k < attackEast; k++) {
                        
                        /*if (wall.length == 151 && k - wallStart == 150) {
                            System.out.print("");
                        }
                        
                        System.out.println(wall.length + " " + (k - wallStart));*/
                        if (wall[k - wallStart] < attackStrength) {
                            attackSucceeded = true;
                        }
                    }
                    if (attackSucceeded) {
                        numSuccesses++;
                        //System.out.println("success");
                    }
                }
            }
            
            for (int j = 0; j < N; j++) { // for each tribe
                if (i >= d[j] && i <= d2[j] && (i - d[j]) % delta_d[j] == 0) { // if tribe j attacks on day i...
                    int numDayDeltas = (i - d[j]) / delta_d[j];
                    
                    int attackWest = w[j] + numDayDeltas * delta_p[j];
                    int attackEast = e[j] + numDayDeltas * delta_p[j];
                    int attackStrength = s[j] + numDayDeltas * delta_s[j];
                    
                    //System.out.println("on day " + i + " tribe " + j + " attacks from " + attackWest + " to "
                    //+ attackEast + " with strength " + attackStrength);
                    
                    for (int k = attackWest; k < attackEast; k++) {
                        if (wall[k - wallStart] < attackStrength) {
                            wall[k - wallStart] = attackStrength;
                        }
                    }
                }
            }
        }
        
        //System.out.println(wall.length);
        //System.out.println(dayStart + " " + dayEnd);

        pw.println(numSuccesses);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "C-small-attempt1.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "C-small-attempt1.out"));
        int T = sc.nextInt();
        for (int t=0; t<T; t++) {
            System.out.println("Processing test case " + (t + 1) + " of " + T);
            pw.print("Case #" + (t+1) + ": ");
            new Gcj2013_1c_c().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
