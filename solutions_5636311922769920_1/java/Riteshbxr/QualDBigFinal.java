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
public class QualDBigFinal {

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
 //calc
            
            System.out.print("case #"+i+": ");
            if(S<Math.ceil((double)K/2)) 
            {
                System.out.print("IMPOSSIBLE");
                
            }
            else if(C==1 && S<K) {System.out.print("IMPOSSIBLE");
                }
            else if(K==1 && S>=1){ System.out.print("1");}
            else if(K==2 && S>=1) {System.out.print("2"); }
           // else if(K==3 && S>=2) System.out.print("2 "+ ((long)Math.pow(K,C)-1));
            else
                PrintSpecial(K, C);
            System.out.println();
        }
    }
 

    private static void PrintSpecial(int K, int C)
    {
        long B=(long)Math.pow(K, C-1);
        long s1[],s2[];
        int k=0;
        int half=(int) Math.floor((Math.ceil((double)K/2))/2);
        //int half=total%2==1?total/2+1:total/2;
        s1=new long[half+1];s2=new long[half];
        for(int i=0,j=2;k<half+1;i+=2,j+=2)
            s1[k++]= (B*i+j);
        //System.out.print("<>");
        k=0;
        for(int i=K,j=1;k<half;i-=2,j+=2)
            s2[k++]=(B*i-j);
        long s3[]=new long[half];
        k=0;
        for(int i=(s2.length)-1;i>=0;i--)
            s3[k++]=s2[i];

            if((half+half+1)==(int)(Math.ceil((float)(K/2))))
            {  
                Print(s1,half+1);
            }
            else
            {
                Print(s1,half);
            }
            Print(s3,half);
    }
    private static void Print(long a[],int N)
    {
        for(int i=0;i<N;i++)
        {
           System.out.print(a[i]+" ");
        }
    }
}
