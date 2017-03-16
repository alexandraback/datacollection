
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Date;
import java.util.HashMap;
import java.util.HashSet;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author B4dT0bi
 */
public class RecycledNumbers
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
        readInput(args[0]);
        wholeOutput="";
        for(int i=1;i<input.length;i++)
        {
            String [] tmp=input[i].split(" ");
            int A=Integer.parseInt(tmp[0]);
            int B=Integer.parseInt(tmp[1]);
            int anz=0;
            for(int x=A;x<B-1;x++)
            {
                anz+=existingPairs(x, B);
            }
            wholeOutput+="Case #"+i+": "+anz+"\n";
        }
        writeOutput(args[0]);
        
    }
    private static int existingPairs(int x, int B)
    {
        String sX=""+x;
        int anz=0;
        HashSet<String>already=new HashSet<String>();
        for(int i=1;i<sX.length();i++)
        {
            String tmp=sX.substring(sX.length()-i)+""+sX.substring(0,sX.length()-i);
            if(tmp.charAt(0)=='0')continue;
            int nr=Integer.parseInt(tmp);
            if(nr<=B && nr>x)
            {
                if(!already.contains(tmp))
                {
                    already.add(tmp);
                    anz++;
                }
            }
        }
        return anz;
    }    
}
