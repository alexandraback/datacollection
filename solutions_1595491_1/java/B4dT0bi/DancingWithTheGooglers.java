/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dancing.with.the.googlers;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author B4dT0bi
 */
public class DancingWithTheGooglers
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
            Logger.getLogger(DancingWithTheGooglers.class.getName()).log(Level.SEVERE, null, ex);
        } finally
        {
            try
            {
                br.close();
            } catch (IOException ex)
            {
                Logger.getLogger(DancingWithTheGooglers.class.getName()).log(Level.SEVERE, null, ex);
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
        readInput(args[0]);
        
        wholeOutput="";
        for(int i=1;i<input.length;i++)
        {
            String[] in=input[i].split(" ");
            int nrGooglers=Integer.parseInt(in[0]);
            int surResult=Integer.parseInt(in[1]);
            int bestResult=Integer.parseInt(in[2]);
            int [] googlerPoints=new int[in.length-3];
            for(int n=3;n<in.length;n++)
            {
                googlerPoints[n-3]=Integer.parseInt(in[n]);
            }
            int anzBest=0;
            for(int n=0;n<googlerPoints.length;n++)
            {
                if(win(googlerPoints[n], bestResult, false))
                {
                    anzBest++;
                }
                else
                {
                    if(surResult>0)
                    {
                        if(win(googlerPoints[n], bestResult, true))
                        {
                            anzBest++;
                            surResult--;
                        }
                    }
                }
            }
            wholeOutput+="Case #"+i+": "+anzBest+"\n";
        }
        writeOutput(args[0]);
        
    }
    static HashMap<Integer,ArrayList>results=new HashMap<Integer, ArrayList>();
    public static boolean win(int result,int best,boolean surprise)
    {
        if(!results.containsKey(result))
        {
            results.put(result, getResults(result));
        }
        ArrayList<ArrayList>tmp=results.get(result);
        for(int i=0;i<tmp.size();i++)
        {
            ArrayList<Integer>tmp2=tmp.get(i);
            int max=tmp2.get(0);
            int sur=tmp2.get(1);
            if(sur==0)
            {
                if(max>=best)return true;
            }
        }
        if(surprise)
        for(int i=0;i<tmp.size();i++)
        {
            ArrayList<Integer>tmp2=tmp.get(i);
            int max=tmp2.get(0);
            int sur=tmp2.get(1);
            if(sur==1)
            {
                if(max>=best)return true;
            }
        }
        return false;
    }
    private static ArrayList getResults(int res)
    {
        ArrayList<ArrayList>tmp=new ArrayList<ArrayList>();
        HashSet<String>mySet=new HashSet<String>();
        for(int a=0;a<11;a++)
        {
            for(int b=0;b<11;b++)
            {
                for(int c=0;c<11;c++)
                {
                    if(a+b+c==res)
                    {
                        int min=a;
                        if(b<min)min=b;
                        if(c<min)min=c;
                        int max=a;
                        if(b>max)max=b;
                        if(c>max)max=c;
                        if(max-min<=2)
                        {
                            ArrayList<Integer>tmp2=new ArrayList<Integer>();
                            tmp2.add(max);
                            if(max-min==2)
                            {
                                tmp2.add(1);
                            }
                            else
                            {
                                tmp2.add(0);
                            }
                            if(!mySet.contains(""+max+";"+tmp2.get(1)))
                            {
                                mySet.add(""+max+";"+tmp2.get(1));
                                tmp.add(tmp2);
                            }
                        }
                    }
                }
            }
        }
        return tmp;
    }
}

