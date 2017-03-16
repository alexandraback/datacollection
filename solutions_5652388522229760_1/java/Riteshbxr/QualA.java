/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author RITESH
 */
public class QualA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException{
      final String curdir=System.getProperty("user.dir")+"/src/gcj";
      Scanner reader=new Scanner(System.in);
     //System.out.print(curdir);
      switch(2)//Setting the input and output resources
      {
          case 2:
              System.setOut(new PrintStream(new File(curdir+"/output.txt")));
          case 3:
               reader = new Scanner(new File(curdir+"/input.txt"));
      }
        int T=0;
        long N;
//Input Starts from here
        T=reader.nextInt();
        for(int i=1;i<=T;i++)
        {
            N=reader.nextInt();
//Calculations
            long Next=N;
            boolean digits[]=new boolean[10];
            long j;
            for( j=1;j<=1000 && !checkDigits(digits);j++)
            {
                Next=N*j;
                updatedigits(digits, Next);
            }
            System.out.print("Case #"+i+": ");
            if(j>1000)
                System.out.println("INSOMNIA");
            else
                System.out.println(Next);
        }
    }
    private static boolean checkDigits(boolean digits[])
    {
        for(int i=0;i<10;i++)
        {
            if(digits[i]!=true)
                return false;
        }
        return true;
    }
    
    private static void updatedigits(boolean digits[], long N)
    {
        int breakup[]=new int[8];
        int length=0;
        for(int j=0;j<8;j++)
        {
            breakup[j]=(int)N%10;
            N=N/10;
            if(N==0)
            {
                length=j;
                break;
            }
        }
        for(int j=0;j<=length;j++)
            digits[breakup[j]]=true;
        //return (checkDigits(digits));
    }
}
