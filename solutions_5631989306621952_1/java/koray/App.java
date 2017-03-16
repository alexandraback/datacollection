package com.koray.codejam;

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
                String res = "";
                String input  = sc.next();
                for (int j = 0 ; j < input.length() ; j ++ )
                {
                    if((res+input.charAt(j)).compareTo(input.charAt(j) + res) > 0)
                        res += input.charAt(j);
                    else
                        res = input.charAt(j) + res;
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

    
    public static void questionB()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                int res = 0;

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


}
