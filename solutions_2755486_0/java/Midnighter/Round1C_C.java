package org.midnighter.googlejam.y2013;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Round1C_C
{
	static final String assignment = "C-small-attempt3";
	static final String inFileName = "files/" + assignment + ".in";
	static final String outFileName = "files/"+assignment+".out";
	
    Scanner in;
    PrintWriter out;
   
    public long oneCase()
    {
    	int N = in.nextInt();
    	in.nextLine();
    	int d[] = new int[N];
    	int n[] = new int[N];
    	int w[] = new int[N];
    	int e[] = new int[N];
    	int s[] = new int[N];
    	int dD[] = new int[N];
    	int dP[] = new int[N];
    	int dS[] = new int[N];
    	
    	for (int i = 0; i < N; i++)
    	{
    		d[i] = in.nextInt();
    		n[i] = in.nextInt();
    		w[i] = in.nextInt();
    		e[i] = in.nextInt();
    		s[i] = in.nextInt();
    		dD[i] = in.nextInt();
    		dP[i] = in.nextInt();
    		dS[i] = in.nextInt();
    	}
    	
    	long[] h = new long[100000];
    	int res = 0; 
    	
    	for (int today = 0; today <= 676080; today++)
    	{
    		for (int i = 0; i < N; i++)
    			if (today >= d[i] && (today - d[i]) % dD[i] == 0)
    			{
    				int nA = (today - d[i]) / dD[i];
    				if (nA >= n[i])
    					continue;
    				int cS = dS[i] * nA + s[i];
    				for (int t = w[i] + dP[i] * nA; t <= e[i] + dP[i] * nA; t++)
    					if (h[2 * t + 50000] < cS || (t < e[i] + dP[i] * nA && h[2 * t + 1 + 50000] < cS))
    					{
    						System.out.println("Tribe " + i + " in day " + today + " position " + t + " height " + h[2 * t + 50000] + ", " + h[2 * t + 1 + 50000] + " less than " + cS);
    						res++;
    						break;
    					}
    			}
    		
    		for (int i = 0; i < N; i++)
    			if (today >= d[i] && (today - d[i]) % dD[i] == 0)
    			{
    				int nA = (today - d[i]) / dD[i];
    				if (nA >= n[i])
    					continue;
    				int cS = dS[i] * nA + s[i];
    				for (int t = w[i] + dP[i] * nA; t <= e[i] + dP[i] * nA; t++)
    					//if (h[2 * t + 50000] < cS)
    					{
    						h[2 * t + 50000] = cS;
    						if (t < e[i] + dP[i] * nA)
    							h[2 * t + 1 + 50000] = cS;
    					}
    			}
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
        new Round1C_C().run();
    }
}
