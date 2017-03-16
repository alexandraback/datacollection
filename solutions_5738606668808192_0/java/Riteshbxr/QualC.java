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
public class QualC {

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
        int N,J;
//Input Starts from here
        T=reader.nextInt();
        for(int i=1;i<=T;i++)
        {
            System.out.print("Case #"+i+":");
            N=reader.nextInt();
            J=reader.nextInt();
            int jamcoin[]=new int[N];
//Calculations
            boolean flag=false;
            long divisors[]=new long[9];
            long min2=0,max2=0;
            int count=0;
            min2=1+POWER(2,(N-1));
            for(int j=0;j<N;j++)
                max2+=POWER(2,j);
            count=0;
            /*set2sbinary(jamcoin[count], min2);
            System.out.print(min2 +":"+getString(jamcoin[count])+"\n");
            set2sbinary(jamcoin[count], max2);
            System.out.print(max2 +" "+getString(jamcoin[count])+"\n");
              */      
            for(long value2=min2;value2<=max2 && count<J;value2+=2)
            {
                set2sbinary(jamcoin, value2);
                //System.out.print(value2 +" "+getString(jamcoin[count])+"\n");
                flag=true;
                for(int j=2;j<=10 && flag==true;j++)
                {
                    long value=0;
                    for(int k=0;k<N;k++)
                        value=value+POWER((jamcoin[k]*j),k);
                    divisors[j-2]=getdivisor(value);
                    if(divisors[j-2]==1)
                           flag=false;
                }
                if(flag==true)
                {
                    count++;
                    System.out.println();
                    System.out.print(getString(jamcoin)+" ");
                    for(int k=2;k<=10;k++)
                        System.out.print(divisors[k-2]+" ");
                }
            }
//Output
           /* System.out.print("Case #"+i+":");
            for(int j=0;j<J;j++)
            {
                System.out.println();
                System.out.print(getString(jamcoin[j])+" ");
                for(int k=2;k<=10;k++)
                    System.out.print(divisors[j][k-2]+" ");
            }
            */
        }
    }
    private static long getdivisor(long x)
    {
        for(long i=2;POWER(i,2)<=x;i++)
            if(x%i==0)
                return i;
        return 1;
    }
    
    private static String getString(int intarray[])
    {
        String S="";
        for(int i=intarray.length-1;i>=0;i--)
            S=S+intarray[i];
        return S;
    }
    
    private static void set2sbinary(int jamcoin[],long value)
    {
        long breakit=value;
        for(int j=0;j<jamcoin.length;j++)           
        {
            jamcoin[j]=(int)breakit%2;
            breakit=breakit/2;
        }   
    }
    private static long POWER(long x,long N)
    {
        return (long) Math.pow(x,N);
    }
    private static long POWER(int x,int N)
    {
        return POWER((long)x,N);
    }
     private static long POWER(long x,int N)
    {
        return POWER((long)x,(long)N);
    }
}
