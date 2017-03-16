/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2012;

import java.io.*;
import java.util.HashSet;

/**
 *
 * @author Stephen
 */
public class GoogleCodeJam2012R1N1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try 
        {
            FileInputStream fs = new FileInputStream("input.txt");
            DataInputStream in = new DataInputStream(fs);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            FileWriter fws = new FileWriter("output.txt");
            BufferedWriter out = new BufferedWriter(fws);
            String numLine = br.readLine();
            System.out.println(numLine);
            int numCases = Integer.parseInt(numLine);
            String caseLine;
            for(int i = 1; i <= numCases; i++)
            {
                caseLine = br.readLine();
                System.out.println("Case #"+i);
                String[] splitted = caseLine.split(" ");
                int A = Integer.parseInt(splitted[0]);
                int B = Integer.parseInt(splitted[1]);
                caseLine = br.readLine();
                splitted = caseLine.split(" ");
                double[] probArray = new double[A];
                double allRightProb = 1;
                for(int j = 0; j < A; j++) {
                    probArray[j] = Double.parseDouble(splitted[j]);
                    allRightProb *= probArray[j];
                }
                double enterRightAway = B+2;
                System.out.println("Enter right away prob: "+enterRightAway);
                int requiredToFinish = B-A+1;
                double keepTyping = requiredToFinish*allRightProb + (requiredToFinish+B+1)*(1-allRightProb);
                System.out.println("KeepTyping prob: "+keepTyping);
                
                double best = Math.min(enterRightAway, keepTyping);
                
                for(int j = 1; j < A; j++) {
                    allRightProb = 1;
                    for(int k = 0; k < (A-j); k++) {
                        allRightProb*= probArray[k];
                    }
                    requiredToFinish = (B-A+1+2*j);
                    double backspaced = requiredToFinish*allRightProb + (requiredToFinish+B+1)*(1-allRightProb);
                    System.out.println("Backspacing "+j+" spaces prob: "+backspaced);
                    best = Math.min(best, backspaced);
                }
                System.out.println("Best: "+best);
                
                out.write("Case #"+i+": "+best+"\r\n");
            }
            in.close();
            out.close();
            
            displayOutput();
        } 
        catch (Exception e) 
        {
            System.err.println("Oops! Error occured: " + e.getMessage());
        }
    }
    
    public static void displayOutput()
    {
        System.out.println("START OUTPUT\n-------------------");
        try
        {
            FileInputStream fs = new FileInputStream("output.txt");
            DataInputStream in = new DataInputStream(fs);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String readLine;
            while ((readLine = br.readLine()) != null)   {
                System.out.println(readLine);
            }
        }
        catch (Exception e) 
        {
            System.err.println("Oops! Error occured: " + e.getMessage());
        }
        System.out.println("---------------------\nEND OUTPUT");
    }
}
