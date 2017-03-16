/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package question2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author karim
 */
public class Question2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {

        BufferedWriter out = new BufferedWriter(new FileWriter("output.out"));
        BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
        int numOfcases = Integer.parseInt(in.readLine());
        for (int caseNum = 1; caseNum <= numOfcases; caseNum++) {
            String input = in.readLine();
            Scanner s = new Scanner(input);
            int googlers = s.nextInt();
            int surp = s.nextInt();
            int p = s.nextInt();
            int minCountedTriplet = 3*p -2;
            int minCountedTripletWithSur = 3*p -4;
            int output =0;
            while(s.hasNextInt()){
                int temp = s.nextInt();
                if(temp >= minCountedTriplet)
                    output++;
                else{
                    if(surp>0 && temp >= minCountedTripletWithSur && minCountedTripletWithSur>=0){
                        output++;
                        surp--;
                    }
                }
                
            }
            out.write("Case #" + caseNum + ": " + output);
            out.newLine();
        }
        out.flush();
        out.close();
        in.close();
        
        // TODO code application logic here
    }
}
