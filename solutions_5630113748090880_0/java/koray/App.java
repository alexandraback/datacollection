package com.koray.codejam;

import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Hello world!
 * 
 */
public class App 
{
    
    
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
                int N = sc.nextInt();
                int []  all = new int [2900];
                int [] ret = new int [N];
                for(int j = 0 ; j < 2*N-1 ; j++)
                {
                    for (int k = 0 ; k < N ; k ++)
                    {
                        all[sc.nextInt()]++;
                    }
                }
                int index = 0 ;
                for (int j = 0 ; j < 2600 ; j ++)
                {
                    if(all[j] % 2 ==1)
                    {
                        ret[index] = j;
                        index ++;
                    }
                }


                Arrays.sort(ret);





                String res = "";
                for(int j = 0 ; j < N ; j ++)
                    res+=" " + ret[j];
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

//
//    public static int getSmallest(int[][] in , int smallindex,boolean [] excluded ){
//        int ret =2501;
//        for(int i = 0; i < in.length &&!excluded[i]; i++)
//        {
//            if (ret > in[i][smallindex])
//                ret = in[i][smallindex];
//
//        }
//        return ret;
//    }
//
//    public static int countSmallIndex(int[][] in , int smallindex , int value ,boolean [] excluded ){
//        int ret =0;
//        for(int i = 0; i < in.length &&!excluded[i]; i++)
//        {
//            if (value == in[i][smallindex])
//                ret ++;
//
//        }
//        return ret;
//    }
//
//
//
//    public static int getBiggest(int[][] in , int bigindex,boolean [] excluded  ){
//        int ret =2501;
//        for(int i = 0; i < in.length&&!excluded[i] ; i++)
//        {
//            if (ret > in[i][bigindex])
//                ret = in[i][bigindex];
//
//        }
//        return ret;
//    }
//
//    public static int countBigIndex(int[][] in , int bigindex , int value ,boolean [] excluded ){
//        int ret =0;
//        for(int i = 0; i < in.length&&!excluded[i] ; i++)
//        {
//            if (value == in[i][bigindex])
//                ret ++;
//
//        }
//        return ret;
//    }
//
//
//

 

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
