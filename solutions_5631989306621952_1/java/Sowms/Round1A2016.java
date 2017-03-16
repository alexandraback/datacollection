/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication7;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

/**
 *
 * @author admin
 */
public class Round1A2016 {

    /**
     * @param args the command line arguments
     */
        
    public static void main(String[] args) {
        BufferedReader br1 = null;
        BufferedWriter br2 = null;
        try {
 		br1 = new BufferedReader(new FileReader("A-large.in"));
                br2 = new BufferedWriter(new FileWriter("A-small.out"));
                int noLines = Integer.parseInt(br1.readLine());
                for (int i = 0; i < noLines; i++) {
                    String line = br1.readLine();
                    String ans = line.charAt(0)+"";
                    for (int j=1; j<line.length(); j++) {
                        if (line.charAt(j) >=  ans.charAt(0)) 
                            ans = line.charAt(j) + ans;
                        else
                            ans = ans + line.charAt(j);
                    }
                    br2.write("Case #"+(i+1)+": "+ans+"\n");
                }
            br1.close();
            br2.close();
        } catch (Exception e) {
            e.printStackTrace();
        }	
    }

}
