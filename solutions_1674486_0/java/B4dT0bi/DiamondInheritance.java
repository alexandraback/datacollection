/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package diamondinheritance;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

/**
 *
 * @author B4dT0bi
 */
public class DiamondInheritance
{

    public static String [] input;
    public static String wholeOutput="";
    public static void readInput(String inputFile)
    {
        BufferedReader br = null;
        try
        {
            br = new BufferedReader(new FileReader(inputFile));
            String serializedSettings = "";
            String line = null;
            while ((line = br.readLine()) != null)
                serializedSettings += line + "\n";
            input=serializedSettings.split("\n");
            br.close();
        } catch (Exception ex)
        {
            ex.printStackTrace();
        } finally
        {
            try
            {
                br.close();
            } catch (IOException ex)
            {
                ex.printStackTrace();
            }
        }
    }
    public static void writeOutput(String inputFile)
    {
        try
        {
            BufferedWriter out = new BufferedWriter(new FileWriter(inputFile+".out"));
            out.write(wholeOutput);
            out.close();
        } catch (IOException e)
        {
            e.printStackTrace();
        }

    }
    public static void main(String[] args)
    {
        if(args.length!=0)
            readInput(args[0]);
        else
        {
            input=new String[15];
            input[0]="3";
            input[1]="3";
            input[2]="1 2";
            input[3]="1 3";
            input[4]="0";
            input[5]="5";   
            input[6]="2 2 3";
            input[7]="1 4";
            input[8]="1 5";
            input[9]="1 5";
            input[10]="0";
            input[11]="3";
            input[12]="2 2 3";
            input[13]="1 3";
            input[14]="0";
        }
        wholeOutput="";
        int tc=0;
        for(int i=1;i<input.length;i++)
        {
            tc++;
            String tmp="";
            int anzC=Integer.parseInt(input[i]);
            i++;
            int inh[][]=new int[anzC][];
            for(int n=0;n<anzC;n++)
            {
                String t[]=input[i].split(" ");
                i++;
                int anzI=Integer.parseInt(t[0]);
                inh[n]=new int[anzI];
                for(int m=0;m<anzI;m++)
                {
                    inh[n][m]=Integer.parseInt(t[m+1]);
                }
            }
            i--;
            int ways=0;
            for(int n=0;n<anzC;n++)
            {
                for(int m=0;m<anzC;m++)
                {
                    if(n!=m)
                    {
                        ways=anzWays(n, m, inh);
                        if(ways>=2)
                        {
                            break;
                        }
                    }
                }
                if(ways>=2)break;
            }
            String tco="Case #"+tc+": "+ (ways>=2?"Yes":"No")+"\n";
            System.out.println(tco);
            wholeOutput+=tco;
        }
        if(args.length!=0)
            writeOutput(args[0]);
        else
            System.out.println(wholeOutput);
        
    }
    private static int anzWays(int from, int to,int [][] inh)
    {
        if(from>=inh.length)return 0;
        if(inh[from].length==0)return 0;
        int res=0;
        for(int i=0;i<inh[from].length;i++)
        {
            if(inh[from][i]-1==to)
            {
                res++;
            }
            else
            {
                    int tt=anzWays(inh[from][i]-1, to, inh);
                    if(tt>0)res++;
            }
        }
        return res;
    }
}
