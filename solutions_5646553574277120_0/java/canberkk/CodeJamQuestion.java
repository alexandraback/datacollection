/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package codejamquestion;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * @author Canberk
 */

public class CodeJamQuestion {

    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("C-small-attempt0.in"));
            PrintWriter out = new PrintWriter("C-small-attempt0.out");

            int cases = Integer.parseInt(in.nextLine());
            
            for (int caseNo = 1; caseNo <= cases; caseNo++) {
                String answer = "Case #" + caseNo + ": ";
                
                
                int c = in.nextInt();
                int d = in.nextInt();
                int v = in.nextInt();
                
                ArrayList<Integer> dominations = new ArrayList<Integer>();
                for(int i = 0; i<d; i++){
                    dominations.add(in.nextInt());
                }
                int extra = 0;
                
                for(int i = 1; i <= v;i++){
                    int target = i;
                    int j = 0;
                    for(; j < dominations.size() && dominations.get(j) <= i ;j++){
                        target -= dominations.get(j)*c;
                    }
                    if ( target > 0){
                        extra ++;
                        dominations.add(j, i);
                    }
                }
                
                System.out.println(dominations);
                out.println(answer + extra);
            }
            in.close();
            out.close();
        } catch (FileNotFoundException ex) {
            System.out.println("ERROR");
        }

    }
    
}
