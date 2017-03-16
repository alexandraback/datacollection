/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlerese;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author B4dT0bi
 */
public class Googlerese
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
            Logger.getLogger(Googlerese.class.getName()).log(Level.SEVERE, null, ex);
        } finally
        {
            try
            {
                br.close();
            } catch (IOException ex)
            {
                Logger.getLogger(Googlerese.class.getName()).log(Level.SEVERE, null, ex);
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
            String tmp=input[i].replaceAll("a", "Y");
            tmp=tmp.replaceAll("b","H");
            tmp=tmp.replaceAll("c","E");
            tmp=tmp.replaceAll("d","S");
            tmp=tmp.replaceAll("e","O");
            tmp=tmp.replaceAll("f","C");
            tmp=tmp.replaceAll("g","V");
            tmp=tmp.replaceAll("h","X");
            tmp=tmp.replaceAll("i","D");
            tmp=tmp.replaceAll("j","U");
            tmp=tmp.replaceAll("k","I");
            tmp=tmp.replaceAll("l","G");
            tmp=tmp.replaceAll("m","L");
            tmp=tmp.replaceAll("n","B");
            tmp=tmp.replaceAll("o","K");
            tmp=tmp.replaceAll("p","R");
            tmp=tmp.replaceAll("q","Z");
            tmp=tmp.replaceAll("r","T");
            tmp=tmp.replaceAll("s","N");
            tmp=tmp.replaceAll("t","W");
            tmp=tmp.replaceAll("u","J");
            tmp=tmp.replaceAll("v","P");
            tmp=tmp.replaceAll("w","F");
            tmp=tmp.replaceAll("x","M");
            tmp=tmp.replaceAll("y","A");
            tmp=tmp.replaceAll("z","Q");
            wholeOutput+="Case #"+i+": "+tmp.toLowerCase()+"\n";
        }
        writeOutput(args[0]);
        
    }
}
