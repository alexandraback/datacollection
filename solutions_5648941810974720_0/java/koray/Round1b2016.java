package com.koray.codejam;

import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Round1b2016
{
    
    
    public static void questionA()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                String ret = "";
                String input  = sc.next();
                int[] arr = new int[150];
                for ( int j = 0 ; j < input.length() ; j ++)
                    arr[input.charAt(j)] ++;

                List<Integer> res  = new ArrayList<Integer>();
                for(int j = 0 ; j < arr['Z'] ; j ++)
                    res.add(0);
                for(int j = 0 ; j < arr['W'] ; j ++)
                    res.add(2);
                for(int j = 0 ; j < arr['U'] ; j ++)
                    res.add(4);
                for(int j = 0 ; j < arr['G'] ; j ++)
                    res.add(8);
                for(int j = 0 ; j < arr['X'] ; j ++)
                    res.add(6);
                for(int j = 0 ; j < arr['T'] - arr['G'] - arr['W']; j ++)
                    res.add(3);
                for(int j = 0 ; j < arr['O'] -arr['U'] -arr['W'] -arr['Z'] ; j ++)
                    res.add(1);
                for(int j = 0 ; j < arr['F'] - arr['U'] ; j ++)
                    res.add(5);
                for(int j = 0 ; j < arr['S'] - arr['X'] ; j ++)
                    res.add(7);
                for(int j = 0 ; j < arr['I'] - arr['G'] - arr['X'] -arr['F'] + arr['U'] ; j ++)
                    res.add(9);
                Collections.sort(res);
                for(Integer k: res)
                    ret += k;
                System.out.println("Case #" + i + ": " + ret);
                out.write("Case #" + i + ": " + ret + "\n");
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
                String ret = "";
                String input  = sc.next();



                System.out.println("Case #" + i + ": " + ret);
                out.write("Case #" + i + ": " + ret + "\n");
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
                String ret = "";
                String input  = sc.next();



                System.out.println("Case #" + i + ": " + ret);
                out.write("Case #" + i + ": " + ret + "\n");
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
