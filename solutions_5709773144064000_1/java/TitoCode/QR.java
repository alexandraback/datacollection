/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package yasmin;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.LinkedList;

/**
 *
 * @author Tito
 */
public class QR {
    
    private static String inputFileName = "x.in";
    private static String outputFileName = "x.out";
    
    
    private static void writeOutputToFile(String str) {
        Path file = Paths.get(outputFileName);
        try {
            Files.write(file, str.getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public static void main(String args[]) throws IOException{
        //input
        BufferedReader br = new BufferedReader(new FileReader(inputFileName));
        //to store output
        StringBuilder out = new StringBuilder();

        int testNo = Integer.parseInt(br.readLine());
        for(int i=1; i <= testNo; i++){
            
            //solution of this test case
            String sol = "";

            String[] ss = br.readLine().split(" ");
            Double[] dd = new Double[3];
            
            double cps = 2;
            dd[0] = Double.parseDouble(ss[0]);
            dd[1] = Double.parseDouble(ss[1]);
            dd[2] = Double.parseDouble(ss[2]);
            
            double minTime = dd[2]/cps;
            double curr = 0;
            double numOfc = 0;
            double tempTime;
            // solve the problem
            while(true){
                curr += dd[0]/cps;
                cps += dd[1];
                tempTime = curr + dd[2]/cps;
                if(tempTime < minTime){
                    minTime = tempTime;
                } else {
                    break;
                }
            }
            
            sol = sol+minTime;
            
            System.out.println(sol);
            out.append("Case #").append(i).append(": ").append(sol);
            out.append("\n");
        }
        writeOutputToFile(out.toString());
    }
    
}
