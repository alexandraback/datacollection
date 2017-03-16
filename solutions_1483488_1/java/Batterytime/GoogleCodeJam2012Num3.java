/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam2012;

import java.io.*;
import java.util.HashSet;

/**
 *
 * @author Stephen
 */
public class GoogleCodeJam2012Num3 {

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
                String[] splitted = caseLine.split(" ");
                int A = Integer.parseInt(splitted[0]);
                int B = Integer.parseInt(splitted[1]);
                System.out.println(A+" <= n < m <= "+B);
                int numLength = String.valueOf(A).length();
                System.out.println("Length of number: "+numLength);
                int powerThing = 1;
                for(int a = 1; a < numLength; a++)
                    powerThing*=10;
                System.out.println("Power Multiplier: "+powerThing);
                int numPairs = 0;
                for(int n = A; n < B; n++)
                {
                    int m = n;
                    HashSet<Integer> ht = new HashSet<Integer>();
                    for(int k = 0; k < numLength; k++)
                    {
                        int rem = m%10;
                        m = m/10+rem*powerThing;
                        if(m <= B && m > n && !ht.contains(m))
                        {
                            ht.add(m);
                            numPairs++;
                        }
                    }
                }
                System.out.println("Pairs: "+numPairs);
                out.write("Case #"+i+": "+numPairs+"\r\n");
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
