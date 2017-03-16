/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package standing;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author kiss
 */
public class Standing {
    static final String WORKDIR = "C:\\proj\\codejam\\2015\\qual_a\\";
    
    static int[] makeIntArr(int n, String s) {
        int[] result = new int[n];
        for (int i=0; i < n; i++) {
            result[i] = Character.getNumericValue(s.charAt(i));
        }
        return result;
    }
    static int solve(Scanner cin) {
       int smax = cin.nextInt();
       if (smax == 0) { cin.next(); return 0; }
       int[] people = makeIntArr(smax+1, cin.next());
       int total = people[0];
       int diff = 0;
       for (int i=1; i <= smax; i++) {
           if (i > total) {
               diff += i-total;
               total = i;
           }
           total += people[i];
       }
       return diff;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            Scanner cin = new Scanner(new BufferedReader(new FileReader(WORKDIR+args[0])));
            PrintWriter cout = new PrintWriter(  new FileWriter(WORKDIR+args[0]+".out"));
            int numTests = cin.nextInt();
            for (int i=1; i <=numTests; ++i) {
                cout.println("Case #" + i + ": " + solve(cin));
            }
            cin.close();
            cout.close();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
   
}
