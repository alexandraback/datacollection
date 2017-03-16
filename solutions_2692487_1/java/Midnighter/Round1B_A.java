package org.midnighter.googlejam.y2013;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class Round1B_A
{
	static final String assignment = "A-large";
	static final String inFileName = "files/" + assignment + ".in";
	static final String outFileName = "files/"+assignment+".out";
	
    Scanner in;
    PrintWriter out;
   
    public long oneCase()
    {
    	long A = in.nextLong();
    	long N = in.nextLong();
    	in.nextLine();
    	List<Long> vals = new ArrayList<Long>();
    	
    	for (int i = 0; i < N; i++)
    	{
    		long val = in.nextInt();
    		if (val < A)
    			A += val;
    		else
    			vals.add(val);
    	}
    	
    	Collections.sort(vals);
    	
    	long res = vals.size();
    	long added = 0;
    	
    	if (A == 1)
    		return vals.size();
    	
    	while (!vals.isEmpty())
    	{
    		Iterator<Long> it = vals.iterator();
	    	while (it.hasNext())
	    	{
	    		long val = it.next();
	    		if (A > val)
	    			A += val;
	    		else
    			{
	    			while (A <= val)
	    			{
	    				A += (A - 1);
	    				added++;
	    			}
	    			A += val;
    			}
	    		it.remove();
	    		if (added > res)
	    			return res;
	    		if (vals.size() + added < res)
	    			res = vals.size() + added;
	    	}
    	}
    	
    	return Math.min(added, res);
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
        new Round1B_A().run();
    }
}
