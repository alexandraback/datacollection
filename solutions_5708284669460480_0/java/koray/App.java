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
                long res = 0;
                int R = new Integer(sc.nextInt());
                int C = new Integer(sc.nextInt());
                int W = new Integer(sc.nextInt());
                boolean divides = C%W == 0;
                int misses = (R-1) * (C/W);
                int lastrow = (C/W) - 1 +  (divides?W:W+1);
                 res = misses + lastrow;
    
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
    
 
    
    public static void questionB()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                double res = 0;
                int K = new Integer(sc.nextInt());
                int L = new Integer(sc.nextInt());
                int S = new Integer(sc.nextInt()); 
                String keyboard = sc.next();
                String target = sc.next();
                String best = "";
                double optimal = 0;
                
                for(int j = 0 ; j < S ; j++)
                {
                     
                    for(int k = target.length()-1 ; k > -1 ; k--)
                    {
                        String tosearch = target.substring(0,k);
                        if(best.endsWith(tosearch))
                        {
                            if(keyboard.indexOf(target.charAt(k)) > -1)
                                best+= target.charAt(k);
                            else
                                best+="!";
                            break;
                        }
                    }
                    if(best.endsWith(target))
                        optimal+=1.0;
                }
                
                int place = S-L +1;
                double prob = 1.0;
                for(int j = 0 ; j < target.length() ; j++ )
                {
                    double counter = 0;
                    for( int k=0; k<keyboard.length(); k++ ) {
                        if( keyboard.charAt(k) == target.charAt(j) ) {
                            counter+=1.0;
                        }
                    }
                    prob*=counter / ((double) K );
                }
                res = optimal - prob * place;
    
                System.out.println(keyboard);
                System.out.println(optimal + "  " + best);
                System.out.println(target);
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
