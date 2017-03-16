/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package codejamquestion;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Canberk
 */

public class CodeJamQuestion {

    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("A-small-attempt0.in"));
            PrintWriter out = new PrintWriter("A-small-attempt0.out");

            int cases = Integer.parseInt(in.nextLine());
            
            for (int caseNo = 1; caseNo <= cases; caseNo++) {
                String answer = "Case #" + caseNo + ": ";
                
                int r = in.nextInt();
                int c = in.nextInt();
                int w = in.nextInt();
                
                int shots = 0;
                shots += (c/w)*r;
                shots += w;
                if(c%w == 0) shots--;
                
                answer += shots;
                
                
                out.println(answer);
            }
            in.close();
            out.close();
        } catch (FileNotFoundException ex) {
            System.out.println("ERROR");
        }

    }
    
}
