package org.midnighter.googlejam.y2013;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Round1C_A
{
	static final String assignment = "A-small-attempt2";
	static final String inFileName = "files/" + assignment + ".in";
	static final String outFileName = "files/"+assignment+".out";
	
    Scanner in;
    PrintWriter out;
    
    Character vowels[] = new Character[]{'a', 'e', 'i', 'o', 'u'};
    List<Character> vowL = Arrays.asList(vowels);
   
    public long oneCase()
    {
    	String[] str = in.nextLine().split(" ");
    	String name = str[0];
    	Integer N = Integer.valueOf(str[1]);
    	long res = 0;
    	
    	int cons = 0;
    	int startFrom = 0;
    	for (int i = 0; i < name.length(); i++)
    		if (!vowL.contains(name.charAt(i)))
    			cons++;
    		else
    		{
    			if (cons >= N)
    			{
    				int delta = (cons - N + 1) * (cons - N + 2) / 2 + (cons - N + 1) * (name.length() - cons - startFrom) + (i - cons  - startFrom) * (name.length() - i);
    				System.out.println((cons - N + 1) * (cons - N + 2) / 2);
    				System.out.println((cons - N + 1) * (name.length() - cons - startFrom));
    				System.out.println((i - cons  - startFrom) * (name.length() - i));
    				res += delta;
    				System.out.println("+" + (delta));
    				startFrom = i - N + 1;
    			}
   				cons = 0;
   			}
    	
    	if (cons >= N)
    	{
    		int delta  =(cons - N + 1) * (cons - N + 2) / 2 + (cons - N + 1) * (name.length() - cons - startFrom); 
    		res += delta;
    		System.out.println("L+" + (delta));
    	}
    		
    	System.out.println();
    	return res;
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
        new Round1C_A().run();
    }
}
