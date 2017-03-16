package com.koray.codejam;

import com.google.common.collect.TreeMultiset;

import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Hello world!
 * 
 */
public class App 
{
    
    
    static Map<BigInteger, BigInteger> map=  new HashMap<BigInteger, BigInteger>();
    public static void questionA()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                long res = 1;
                long N = new Long(sc.nextLong());
                BigInteger x = new BigInteger(N+"");
//                sc.nextLine();
                
                while (!x.equals(BigInteger.ONE))
                {
                    String ss = x.toString();
                    int len = ss.length();
                    boolean poweroften = isPowerOfTen(ss);
                    if(len == 1)
                    {
                         
                        res+= x.longValue()-1;
                        x = BigInteger.ONE;
                    }
                    else if(poweroften) {
                        res += 1;
                        x = x.subtract(BigInteger.ONE);
                    }
                    else {
                         
                        int big = len %2 ==0 ? len/2 : len/2+1;
                        int small =  len/2  ;
                        String ssbig = ss.substring(small);
                        String sssmall = new StringBuilder(ss.substring(0,small)).reverse().toString();
                        BigInteger nbig = new BigInteger(ssbig);
                        BigInteger nsmall = new BigInteger(sssmall);
                        if(isPowerOfTen(nsmall.toString()))
                        {
                            res += nbig.longValue();
                            x = getBigIntegerOfLen(len);
                        }
                        else if(nbig.equals(BigInteger.ZERO))
                        {
                            res += 1;
                            x = x.subtract(BigInteger.ONE);
                            
                        }
                        else {
                            res += nbig.longValue();
                            res += nsmall.longValue();
                            x = getBigIntegerOfLen(len);
                        }
                        
                    }
    
    
                }
    
                System.out.println("Case #" + i + ": " + res);
                out.write("Case #" + i + ": " + res + "\n");
                try {
                    sc.nextLine();
                } catch (Exception e) {
                }

            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
    
    private static BigInteger getBigIntegerOfLen(int len) {
        String ret = "1";
        for(int i = 1 ; i < len ; i++)
            ret+="0";
        return new BigInteger(ret);
        
    }
    
    private static boolean isPowerOfTen(String ss) {
        boolean poweroften =true;
        poweroften &= ss.startsWith("1");
        for(int j = 1 ; j < ss.length() ; j++)
            poweroften &= ss.charAt(j) == '0';
         return poweroften;
    }
    
    
    public static void questionB()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                int res = 0;
                int length = new Integer(sc.nextInt());
               

                System.out.println("Case #" + i + ": " + res);
                out.write("Case #" + i + ": " + res + "\n");
                try {
                    sc.nextLine();
                } catch (Exception e) {
                }

            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }


 

 

    public static void questionC()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                String res = "NO";
                int length = new Integer(sc.nextInt());
                long repetition = new Long(sc.nextLong())%2048;
                sc.nextLine();
                 

                System.out.println("Case #" + i + ": " + res);
                out.write("Case #" + i + ": " + res + "\n");
                try {
                    sc.nextLine();
                } catch (Exception e) {
                }

            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }


 
    public static void questionD()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                String  res = "";
                int X = new Integer(sc.nextInt());
                 

            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }


}
