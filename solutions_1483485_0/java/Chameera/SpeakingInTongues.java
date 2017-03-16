/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.*;

/**
 *
 * @author wijebandara
 */
public class SpeakingInTongues
{
    public static void main(String[] args) throws FileNotFoundException, IOException {

        //java.io.BufferedReader in = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        java.io.BufferedReader in=new java.io.BufferedReader(new java.io.FileReader("/home/wijebandara/Desktop/A-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("/home/wijebandara/Desktop/A-small-attempt0.out")));
    
        int n=Integer.parseInt(in.readLine());
        String s;
        for(int i=0;i<n;i++)
        {
            s=in.readLine();
            System.out.print("Case #"+(i+1)+": ");
            out.print("Case #"+(i+1)+": ");
            for(int j=0;j<s.length();j++)
            {
                System.out.print(convert(s.charAt(j)));
                out.print(convert(s.charAt(j)));
            }
            System.out.println("");
            out.println("");
        }
        out.close();
        System.exit(0);
    
    }
    static char convert(char c)
    {
        switch(c)
        {
            case 'y':
                return 'a';
            case 'n':
                return 'b';
            case 'f':
                return 'c';
            case 'i':
                return 'd';
            case 'c':
                return 'e';
            case 'w':
                return 'f';
            case 'l':
                return 'g';
            case 'b':
                return 'h';
            case 'k':
                return 'i';
            case 'u':
                return 'j';
            case 'o':
                return 'k';
            case 'm':
                return 'l';
            case 'x':
                return 'm';
            case 's':
                return 'n';
            case 'e':
                return 'o';
            case 'v':
                return 'p';
            case 'q':
                return 'z';
            case 'p':
                return 'r';
            case 'd':
                return 's';
            case 'r':
                return 't';
            case 'j':
                return 'u';
            case 'g':
                return 'v';
            case 't':
                return 'w';
            case 'h':
                return 'x';
            case 'a':
                return 'y';
            case 'z':
                return 'q';
            case ' ':
               return ' ';
        }
        return ' ';
        
    }
}
