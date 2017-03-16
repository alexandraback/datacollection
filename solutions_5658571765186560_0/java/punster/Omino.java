/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package omino;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author kiss
 */
public class Omino {

    static final String WORKDIR = "C:\\proj\\codejam\\2015\\qual_d\\";
    

    static String solve(Scanner cin) {
       int x = cin.nextInt();
       int rows = cin.nextInt();
       int cols = cin.nextInt();
       if (x == 1) { return "GABRIEL"; }
       if (x >= 7) { return "RICHARD"; } // can make a hole in x-omino
       if (((rows*cols)%x)!=0) {
           return "RICHARD";
       }
       if (x == 2) { return "GABRIEL"; } // only way to stop 2 is odd area
       int min_dim = (rows < cols) ? rows : cols;
       int max_dim = (cols == min_dim) ? rows : cols;
       if (x > max_dim) { return "RICHARD"; }
       if (min_dim < (x/2+x%2)) { return "RICHARD"; }
       if (x == 3) { return "GABRIEL"; }
       if ((rows*cols)<= (x*2)) { return "RICHARD"; }
       
       return "GABRIEL";
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
