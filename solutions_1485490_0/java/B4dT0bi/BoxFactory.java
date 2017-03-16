/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package boxfactory;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

/**
 *
 * @author B4dT0bi
 */
public class BoxFactory
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
            input=new String[13];
            input[0]="4";
            input[1]="3 3";
            input[2]="10 1 20 2 25 3";
            input[3]="10 2 30 3 20 1";
            input[4]="3 5";
            input[5]="10 1 6 2 10 1";
            input[6]="5 1 3 2 10 1 3 2 5 1";
            input[7]="3 5";
            input[8]="10 1 6 2 10 1";
            input[9]="5 1 6 2 10 1 6 2 5 1";
            input[10]="1 1";
            input[11]="5000000 10";
            input[12]="5000000 100";
        }
        wholeOutput="";
        int tc=0;
        for(int i=1;i<input.length;i++)
        {
            tc++;
            String tmp="";
            i++;
            String l1=input[i];
            i++;
            String l2=input[i];
            wholeOutput+="Case #"+tc+": "+getMax(l1, l2, new HashMap<String, Long>()) +"\n";
        }
        if(args.length!=0)
            writeOutput(args[0]);
        else
            System.out.println(wholeOutput);
        
    }
    private static long getMax(String line1, String line2, HashMap<String,Long> tmpVal)
    {
        long tmpRes=0;
        if(line1.isEmpty())return 0;
        if(line2.isEmpty())return 0;
        String typeA=getType(line1);
        String typeB=getType(line2);
        String tmpL1=line1;
        String tmpL2=line2;
        if(typeA.equals(typeB))
        {
            String tmp[] = removeElements(line1, line2);
            tmpL1=tmp[0];
            tmpL2=tmp[1];
            tmpRes=Long.parseLong(tmp[2]);
            return tmpRes+getMax(tmpL1, tmpL2, tmpVal);
        }
        if(tmpL1.isEmpty())return tmpRes;
        if(tmpL2.isEmpty())return tmpRes;
        String tryL1=remove(tmpL1);
        String tryL2=remove(tmpL2);
        long tA=0;
        long tB=0;
        if(tmpVal.containsKey(tryL1+";"+tmpL2))
        {
            tA=tmpVal.get(tryL1+";"+tmpL2);
        }
        else
        {
            tA=getMax(tryL1, tmpL2, tmpVal);
            tmpVal.put(tryL1+";"+tmpL2, tA);
        }
        if(tmpVal.containsKey(tmpL1+";"+tryL2))
        {
            tB=tmpVal.get(tmpL1+";"+tryL2);
        }
        else
        {
            tB=getMax(tmpL1, tryL2, tmpVal);
            tmpVal.put(tmpL1+";"+tryL2, tB);
        }
        if(tA>tB)
            return tA;
        else
            return tB;
    }
    private static String remove(String line)
    {
        String t[]=line.split(" ");
        if(t.length>0)
        {
            t[0]="0";
        }
        String res="";
        for(int i=0;i<t.length;i++)
        {
            if(i%2==0)
            {
                if(t[i].equals("0"))
                {
                    i++;
                }
                else
                {
                    res+=t[i]+" "+t[i+1]+" ";
                }
            }
        }
        return res.trim();
    }
    private static String [] removeElements(String line1, String line2)
    {
        String t1[]=line1.split(" ");
        String t2[]=line2.split(" ");
        String res[]=new String[3];
        long A=Long.parseLong(t1[0]);
        long B=Long.parseLong(t2[0]);
        if(A==B)
        {
            t1[0]="0";
            t2[0]="0";
            res[2]=""+A;
        }
        else
        {
            if(A>B)
            {
                t1[0]=""+(A-B);
                t2[0]="0";
                res[2]=""+B;
            }
            else
            {
                t1[0]="0";
                t2[0]=""+(B-A);
                res[2]=""+A;
            }
        }
        res[0]="";
        res[1]="";
        for(int i=0;i<t1.length;i++)
        {
            if(i%2==0)
            {
                if(t1[i].equals("0"))
                {
                    i++;
                }
                else
                {
                    res[0]+=t1[i]+" "+t1[i+1]+" ";
                }
            }
        }
        res[0]=res[0].trim();
        for(int i=0;i<t2.length;i++)
        {
            if(i%2==0)
            {
                if(t2[i].equals("0"))
                {
                    i++;
                }
                else
                {
                    res[1]+=t2[i]+" "+t2[i+1]+" ";
                }
            }
        }
        res[1]=res[1].trim();
        return res;
    }
    private static String getType(String line)
    {
        String t[]=line.split(" ");
        if(t.length>0)return t[1];
        return null;
    }
}
