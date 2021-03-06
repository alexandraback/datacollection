/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2012;

import java.io.*;

/**
 *
 * @author Stephen
 */
public class GoogleCodeJam2012 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try 
        {
            FileInputStream fs = new FileInputStream("input.txt");
            DataInputStream in = new DataInputStream(fs);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            FileWriter fws = new FileWriter("output.txt");
            BufferedWriter out = new BufferedWriter(fws);
            String numLine = br.readLine();
            System.out.println(numLine);
            int numCases = Integer.parseInt(numLine);
            String caseLine;
            for(int i = 1; i <= numCases; i++)
            {
                caseLine = br.readLine();
                System.out.println("Case #"+i);
                System.out.println("In: "+caseLine);
                System.out.println("Out: "+gDecode(caseLine));
                out.write("Case #"+i+": "+gDecode(caseLine)+"\r\n");
            }
            in.close();
            out.close();
            
            displayOutput();
        } 
        catch (Exception e) 
        {
            System.err.println("Oops! Error occured: " + e.getMessage());
        }
    }
    
    public static String gDecode(String input)
    {
        String decoded = "";
        for(int i = 0; i < input.length(); i++)
        {
            if(input.charAt(i) == ' ')
                decoded += ' ';
            else
                decoded += decodeChar(input.charAt(i)-'a');
        }
        return decoded;
    }
    
    public static String googleKey = "yhesocvxduiglbkrztnwjpfmaq";
    
    public static char decodeChar(int encoded)
    {
        return googleKey.charAt(encoded);
    }
    
    public static void displayOutput()
    {
        System.out.println("START OUTPUT\n-------------------");
        try
        {
            FileInputStream fs = new FileInputStream("output.txt");
            DataInputStream in = new DataInputStream(fs);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            String readLine;
            while ((readLine = br.readLine()) != null)   {
                System.out.println(readLine);
            }
        }
        catch (Exception e) 
        {
            System.err.println("Oops! Error occured: " + e.getMessage());
        }
        System.out.println("---------------------\nEND OUTPUT");
    }
}
