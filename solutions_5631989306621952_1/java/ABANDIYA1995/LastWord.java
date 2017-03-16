/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CodeJam;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Abhishek
 */
public class LastWord {
    public static void main(String args[])
    {
        try{
    //  Scanner s = new Scanner(System.in);
  Scanner s = new Scanner(new File("C:/users/abhishek/desktop/A-large (1).in"));
      FileOutputStream fout = new FileOutputStream("C:/users/abhishek/desktop/solution.out");
       PrintWriter pw = new PrintWriter(fout);
       int t = s.nextInt();
        for(int i = 0; i < t; i++)
        {
            String str = s.next();
            char c = str.charAt(0);
            String ans = c+"";
            for(int j= 1;j<str.length();j++)
            {
             if(str.charAt(j)<ans.charAt(0))
             {
                 ans += str.charAt(j);
             }
             else ans = str.charAt(j)+ans;
               // System.out.println(ans);
            }
            pw.println("Case #"+(i+1)+": "+ans);
         //   System.out.println("Case #"+(i+1)+": "+ans);
        }
        pw.flush();
        pw.close();
        fout.close();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
}
