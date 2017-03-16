/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author astorres
 */
public class A {

    public static final String rutaDatos = "C:\\Users\\astorres\\Desktop\\CodeJam\\";
    
    public static int TB[];
    
    public static int rev(int n){
        int r = 0;
        String s = Integer.toString(n);
        String rv = "";
        for(int i=0;i<s.length();i++)
            rv = s.charAt(i) + rv;
        return Integer.parseInt(rv);
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        String problem = "A";
        //String input=problem+"-sample.in";
        String input=problem+"-small-attempt0.in";
        //String input=problem+"-large.in";
        Scanner in = new Scanner(new File(rutaDatos+input));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(rutaDatos+"out\\"+input+".out.txt")));    
        
        int T = in.nextInt();
        for(int i=0;i<T;i++) {
            
            /*********************************/
            
            int N = in.nextInt();
            TB = new int[N+1];
            TB[N] = 1;
            for(int j=N-1;j>=0;j--) {
                TB[j] = 1+TB[j+1];
                int rv = rev(j);
                if((rv>j)&&rv<=N)
                    TB[j] = Math.min(TB[j],1+TB[rv]);
            }
            int r = TB[1];

            /*********************************/
            
            System.out.println("Case #"+(i+1)+": "+r);
            out.println("Case #"+(i+1)+": "+r);
        }
        out.close();
    }
    
}
