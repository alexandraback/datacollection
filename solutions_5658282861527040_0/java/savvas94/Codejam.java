/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import javax.naming.BinaryRefAddr;

/**
 *
 * @author Savvas
 */
public class Codejam {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException, IOException {
        // TODO code application logic here
        
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt")));
        BufferedReader input = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"), "cp1253"));
        
        Scanner in = new Scanner(input);
        int numOfCases = in.nextInt();
        
        
        int a,b,k, winning;

        for (int ppp = 0; ppp < numOfCases; ppp++) {
            winning = 0;
            a = in.nextInt();
            b = in.nextInt();
            k = in.nextInt();
            
            StringBuilder[] aBin = new StringBuilder[a];
            StringBuilder[] bBin = new StringBuilder[b];
            
            
            
            for (int i = 0; i < a; i++) {
                aBin[i] = new StringBuilder(Integer.toBinaryString(i));
                while(aBin[i].length()<15){
                    aBin[i].insert(0, "0");
                }
                
            }
            
            for (int i = 0; i < b; i++) {
                bBin[i] = new StringBuilder(Integer.toBinaryString(i));
                while(bBin[i].length()<15){
                    bBin[i].insert(0, "0");
                }
                
            }
            
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    StringBuilder and = new StringBuilder();
                    for (int l = 0; l < 15; l++) {
                        if(aBin[i].charAt(l)=='1' && bBin[j].charAt(l)=='1'){
                            and.append("1");
                        }
                        else{
                            and.append("0");
                        }
                    }
                    //int aaa = Integer.parseInt(and.toString(), 2);
                    //System.out.println(aaa);
                    if(Integer.parseInt(and.toString(), 2)<k){
                        winning++;
                    }
                }
                
            }
            System.out.println("");
            System.out.println("");
            System.out.println("");
            System.out.println("");
            
            output.append("Case #"+(ppp+1)+": "+winning);
            output.newLine();
        }
        output.close();
        
    }
}
