/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

public class Main {
    
    public static final String changeLine = System.getProperty("line.separator");
    
    public static void main(String[] args) throws FileNotFoundException, IOException{
        Main main = new Main();
    }
    
    public Main() throws FileNotFoundException, IOException{
        BufferedReader br = new BufferedReader(new FileReader("D:/A-small-attempt0.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
        int cases = Integer.parseInt(br.readLine());
        for (int caseNum = 0; caseNum < cases; caseNum++) {
            String [] split = br.readLine().split(" ");
            int r = Integer.parseInt(split[0]);
            int t = Integer.parseInt(split[1]);
            int count = 0;
            t-=(r+1)*(r+1)-r*r;
            while(t>=0){
                count++;
                r+=2;
                t-=(r+1)*(r+1)-r*r;
            }
            // output
            System.out.println("Case #"+(caseNum+1)+":");
            bw.write("Case #"+(caseNum+1)+":");
            bw.write(Integer.toString(count));
            bw.write(changeLine);
        }
        br.close();
        bw.close();
    }
    
    public class Timer{
        long start;
        void start(){
            start = System.nanoTime();
        }
        double end(){
            return ((double)(System.nanoTime()-start))/1000000000;
        }
    }
}