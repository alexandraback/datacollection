/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;


/**
 *
 * @author user
 */
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner a=null;
        try {
            a = new Scanner(new File("A.in"));
        } catch (FileNotFoundException ex) {
            
        }
        int T=a.nextInt();
        long r, t;
        int i=0;
        while(i<T){
            r=a.nextLong();
            t=a.nextLong();
            i++;
            System.out.println("Case #"+i+": "+f(r,t));
        }

        
    }
    public static BigInteger f(long r, long t)
    {
        BigInteger r1= new BigInteger(2*r-1+"");
        BigInteger t1= new BigInteger(8*t+"");
        r1=r1.multiply(r1);
        r1=r1.add(t1);
        BigInteger i=new BigInteger("1");
        BigInteger two=new BigInteger("2");
        BigInteger one=new BigInteger("1");
        while(i.multiply(i).compareTo(r1)!=1)
        {
            i=i.multiply(two);
        }
        BigInteger j=i.divide(two);
        while(j.add(one).compareTo(i)!=0)
        {
       //     System.out.println(j+"    "+i+"    "+r1);
            BigInteger l=i.add(j).divide(two);
            BigInteger m=l.multiply(l);
            if(m.compareTo(r1)==1)
            {
                i=l;
            }
            else
            {
                j=l;
            }
        }
        return j.subtract(new BigInteger(2*r-1+"")).divide(new BigInteger("4"));
        //return (long)Math.floor((Math.sqrt(8*t+(2*r-1)*(2*r-1)+0.00000)-(2*r-1))/4.000);
    }
}
