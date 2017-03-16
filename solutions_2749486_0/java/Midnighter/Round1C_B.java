package org.midnighter.googlejam.y2013;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Round1C_B
{
	static final String assignment = "B-small-attempt2";
	static final String inFileName = "files/" + assignment + ".in";
	static final String outFileName = "files/"+assignment+".out";
	
    Scanner in;
    PrintWriter out;
   
    public String oneCase()
    {
    	int X = in.nextInt();
    	int Y = in.nextInt();
    	
    	String str = "";
    	for (int i = 0; i < Math.abs(X) - 1; i++)
    		str += "EW";
    	
    	if (X < 0)
    		str += "EW";
    	else if (X > 0)
    		str += "E";
    	
    	if (Y != 0)
    		for (int i = 0; i < Math.abs(Y); i++)
    			if (Y < 0)
    				str += "NS";
    			else
    				str += "SN";
    	
    	if (str.length() >= 500)
    		throw new RuntimeException("aaa");
    		
    	System.out.println(str);
    	return str;
    }
   
    public void run() throws Exception
    {
        in = new Scanner(new FileReader(inFileName));
        out = new PrintWriter(new FileWriter(outFileName));
        
        int nCases = in.nextInt();
        in.nextLine();
        for (int c = 1; c <= nCases; c++)
            out.println("Case #" + c + ": " + oneCase());
       
        out.flush();
        out.close();
        in.close();
    }
    
   
    public static void main(String[] args) throws Exception
    {
    	System.out.println((-1) % 2);
        new Round1C_B().run();
    }
}
