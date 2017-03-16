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
public class QualD {

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
        int K,C,S;
//Input Starts from here
        T=reader.nextInt();
        for(int i=1;i<=T;i++)
        {
            K=reader.nextInt();
            C=reader.nextInt();
            S=reader.nextInt();
    
//Calculations
           // long seq=(long)Math.pow(K,C);        
//Output
            System.out.print("Case #"+i+": ");
            if(K==S)
                for(long j=1;j<=S;j++)
                {
                    System.out.print(j+" ");
                }
            else
                System.out.print("Invalid small Input");
            System.out.println();
        }
    }
    
}
