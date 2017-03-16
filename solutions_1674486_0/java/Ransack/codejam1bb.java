/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

/**
 *
 * @author Eren
 */

import java.util.ArrayList;
import java.util.Scanner;
import java.io.*;
import java.util.StringTokenizer;

public class codejam1bb {
    public static void main(String[] args) throws IOException
    {
        	BufferedReader in = new BufferedReader(new FileReader("d:\\asd.txt"));
		FileWriter fw = new FileWriter("d:\\dfg.txt");
                int N = new Integer(in.readLine());
                int classNum;
                ArrayList<int[]> classArray;
                int[] intarray2;
                StringTokenizer tokenizer;
                int[] intarray = null;
                int temp;
                int[] intarray3;

                String result = "No";
                for (int cases = 1; cases <= N; cases++) {
                    result = "No";
                    classNum = Integer.parseInt(in.readLine());
                   // System.out.println("Number of classes: " + classNum);
                    //intarray = new int[classNum];
                    classArray = new ArrayList<int[]>();
                    for ( int i = 0; i < classNum; i++)
                    {
                        tokenizer = new StringTokenizer(in.readLine());
                        temp = Integer.parseInt(tokenizer.nextToken());
                        intarray = new int[temp];
                        for ( int k = 0; k < temp; k++)
                        {
                            intarray[k] = Integer.parseInt(tokenizer.nextToken());
                        }
                        classArray.add(intarray);
                    }
                    
                    for ( int i = 0; i < classNum; i++)
                    {
                       intarray2 = new int[classNum];
                       intarray3 = classArray.get(i);
                       if (intarray3.length >=2)
                       {
                           mymethod(intarray2,intarray3,i,classArray);
                       }
                       
                       for ( int l = 0; l < intarray2.length; l++)
                        {
                       // System.out.println( "RESULT: " + intarray2[l]);
                            if( intarray2[l] >= 2)
                            {
                              //  System.out.println("class : "+ (i+1)+ "asd: " + (l+1) + "dfg: " + intarray2[l]);
                                result = "Yes";
                                  break;
                             }
                        }
                       
                    }
                    
            //classArray.add(Integer.parseInt(tokenizer.nextToken()));
                    
                    
                    
                fw.write("Case #" + cases + ": "+result+"\n");
                System.out.print("Case #" + cases + ": "+result+"\n");
                }
                fw.flush();
                fw.close();
    }
    
    public static void mymethod(int[] intarray2, int[] intarray3, int i,ArrayList<int[]> classArray)
    {
        int[] intarray4;
        if ( intarray3.length != 0)
        {
            int sizee = intarray3.length;
            for ( int j = 0; j < sizee; j++)
                {
//                    System.out.println("j : " + j+ " intarray2 size: " + intarray2.length+ " intarray3[j]-1: " + (intarray3[j]-1));
                   // System.out.println(intarray3[j]-1);
                    intarray2[ intarray3[j]-1]++;
                    intarray4 = classArray.get(intarray3[j]-1);
                    mymethod(intarray2, intarray4, j,classArray);
                }
        }
    }
    
   /* public static String methodd(String ip)
    {
        StringTokenizer sc = new StringTokenizer(ip);
        return null;
    }*/
    
}
