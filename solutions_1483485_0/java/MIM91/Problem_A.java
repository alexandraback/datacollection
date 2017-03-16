/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam12;

import java.io.*;
import java.util.StringTokenizer;

/**
 *
 * @author Mohamed Ibrahim (MIM)
 */
public class Problem_A {
    public static void main(String[] args) throws IOException {
        
        BufferedReader r = new BufferedReader(new FileReader("A-small-attempt0.in"));
        PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt0.out")));
        
        int nCases = Integer.parseInt(r.readLine());
        
        for (Integer k = 1; k <= nCases; k++) {
            w.print("Case #" + k + ": ");
            String line=r.readLine();
            String out= "";
            for (int i = 0; i <line.length(); i++) {
                if(line.charAt(i)=='a')out+="y";
                else if(line.charAt(i)=='b')out+="h";
                else if(line.charAt(i)=='c')out+="e";
                else if(line.charAt(i)=='d')out+="s";
                else if(line.charAt(i)=='e')out+="o";
                else if(line.charAt(i)=='f')out+="c";
                else if(line.charAt(i)=='g')out+="v";
                else if(line.charAt(i)=='h')out+="x";
                else if(line.charAt(i)=='i')out+="d";
                else if(line.charAt(i)=='j')out+="u";
                else if(line.charAt(i)=='k')out+="i";
                else if(line.charAt(i)=='l')out+="g";
                else if(line.charAt(i)=='m')out+="l";
                else if(line.charAt(i)=='n')out+="b";
                else if(line.charAt(i)=='o')out+="k";
                else if(line.charAt(i)=='p')out+="r";
                else if(line.charAt(i)=='q')out+="z";
                else if(line.charAt(i)=='r')out+="t";
                else if(line.charAt(i)=='s')out+="n";
                else if(line.charAt(i)=='t')out+="w";
                else if(line.charAt(i)=='u')out+="j";
                else if(line.charAt(i)=='v')out+="p";
                else if(line.charAt(i)=='w')out+="f";
                else if(line.charAt(i)=='x')out+="m";
                else if(line.charAt(i)=='y')out+="a";
                else if(line.charAt(i)=='z')out+="q";
                else if(line.charAt(i)==' ')out+=" ";
            }
            w.println(out);
        }
        w.close();
        
        
    }
}
