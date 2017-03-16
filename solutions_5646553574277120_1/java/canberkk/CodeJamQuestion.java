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
            Scanner in = new Scanner(new File("C-large.in"));
            PrintWriter out = new PrintWriter("C-large.out");

            long cases = Long.parseLong(in.nextLine());
            
            for (long caseNo = 1; caseNo <= cases; caseNo++) {
                String answer = "Case #" + caseNo + ": ";
                System.out.println(caseNo);
                
                long c = in.nextLong();
                long d = in.nextLong();
                long v = in.nextLong();
                
                ArrayList<Long> dominations = new ArrayList<Long>();
                for(long i = 0; i<d; i++){
                    dominations.add(in.nextLong());
                }
                long extra = 0;
                long currentCount = 0;
                int currentIndex = 0;
                
                for(long i = 1; i <= v;i++){
                    for(; currentIndex < dominations.size() && dominations.get(currentIndex) <= i ;currentIndex++){
                        currentCount += dominations.get(currentIndex)*c;
                    }
                    if ( i > currentCount){
                        extra ++;
                        currentCount += i*c;
                    }
                }
                
                out.println(answer + extra);
            }
            in.close();
            out.close();
        } catch (FileNotFoundException ex) {
            System.out.println("ERROR");
        }

    }
    
}
