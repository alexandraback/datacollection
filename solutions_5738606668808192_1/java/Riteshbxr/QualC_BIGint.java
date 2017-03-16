/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author RITESH
 */
public class QualC_BIGint {

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
            BigInteger divisors[]=new BigInteger[9];
            BigInteger min2=BigInteger.ONE;
            BigInteger max2=BigInteger.ZERO;
            int count=0;
            min2=min2.add(POWERBIG(2,(N-1)));
            
            for(int j=0;j<N;j++)
                max2=max2.add(POWERBIG(2,j));
            count=0;
            //set2sbinary(jamcoin, min2);
            //System.out.print(min2 +":"+getString(jamcoin)+"\n\n");
            //set2sbinary(jamcoin, max2);
            //System.out.print(max2 +" "+getString(jamcoin)+"\n");   
            for(BigInteger value2=min2;
                    value2.compareTo(max2)<=0 && count<J;
                    value2=value2.add(BigInteger.valueOf(2)))
            {
                set2sbinary(jamcoin, value2);
                //System.out.print(value2 +" "+getString(jamcoin)+"<<\n");
                flag=true;
                for(int j=2;j<=10 && flag==true;j++)
                {
                    BigInteger value=BigInteger.ZERO;
                    for(int k=0;k<N;k++)
                        value=value.add(POWERBIG((jamcoin[k]*j),k));
                    divisors[j-2]=getdivisor(value);
                    if(divisors[j-2].equals(BigInteger.ONE))
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
    private static BigInteger getdivisor(BigInteger x)
    {
        for(BigInteger i=BigInteger.valueOf(2);i.compareTo(BigInteger.valueOf(1000))<=0;i=i.add(BigInteger.ONE))
            if(x.mod(i).equals(BigInteger.ZERO))
                return i;
        return BigInteger.ONE;
    }
    
    private static String getString(int intarray[])
    {
        String S="";
        for(int i=intarray.length-1;i>=0;i--)
            S=S+intarray[i];
        return S;
    }
    
    private static void set2sbinary(int jamcoin[],BigInteger value)
    {
        BigInteger breakit=value;
        for(int j=0;j<jamcoin.length;j++)           
        {
            jamcoin[j]=breakit.mod(BigInteger.valueOf(2)).intValue();
            breakit=breakit.divide(BigInteger.valueOf(2));
        }   
    }
    private static BigInteger POWERBIG(BigInteger x,long N)
    {
        BigInteger RetValue=x;
        RetValue=RetValue.pow((int)N);
        return RetValue;
    }
    private static BigInteger POWERBIG(long x,long N)
    {
        return POWERBIG(BigInteger.valueOf(x),N);
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
