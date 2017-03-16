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
public class RankAndFile  {
    public static void main(String args[])
    {
        try{
   //  Scanner s = new Scanner(System.in);
  Scanner s = new Scanner(new File("C:/users/abhishek/desktop/B-small-attempt0 (1).in"));
      FileOutputStream fout = new FileOutputStream("C:/users/abhishek/desktop/solution.out");
       PrintWriter pw = new PrintWriter(fout);
       int t = s.nextInt();
        for(int i = 0; i < t; i++)
        {
            int n = s.nextInt();
            int arr[][] = new int[2*n-1][n];
            int max = 0;
            for(int j= 0;j<2*n-1;j++)
            {
                for(int k = 0;k<n;k++)
                {
                    arr[j][k] = s.nextInt();
                    if(arr[j][k]>max)
                        max = arr[j][k];
                }
            }
            boolean p[] = new boolean[max+1];
            boolean c[] = new boolean[max+1];
            for(int j=0;j<max;j++)
                c[j] = false;
            for(int j= 0;j<2*n-1;j++)
            {
                for(int k = 0;k<n;k++)
                {
                    if(!c[arr[j][k]])
                    { c[arr[j][k]] = true;
                      p[arr[j][k]] = true;
                    }
                    else p[arr[j][k]] = !p[arr[j][k]];
                }
             }
            for(int j= 0;j<max;j++)
            {
              //  System.out.println(c[j]+" "+p[j]+" "+max);
             }
            int ans[] = new int[n];
            int k = 0;
            for(int j = 0;j<=max;j++)
            {
                if(c[j])
                {
                    if(p[j])
                    {  
                        ans[k] = j;
                        k++;
                        }
                }
            }
         /*  System.out.print("Case #"+(i+1)+": ");
            for(int j = 0;j<n;j++)
             System.out.print(ans[j]+" ");
            System.out.println();
           */
           pw.print("Case #"+(i+1)+": ");
            for(int j = 0;j<n;j++)
            pw.print(ans[j]+" ");
            pw.println();
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

