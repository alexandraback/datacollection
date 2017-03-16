package org.midnighter.googlejam.y2013;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.ObjectInputStream.GetField;
import java.util.Scanner;

public class Round1B_B
{
	static final String assignment = "B-small-attempt2";
	static final String inFileName = "files/" + assignment + ".in";
	static final String outFileName = "files/"+assignment+".out";
	
    Scanner in;
    PrintWriter out;
   
    public double oneCase()
    {
    	int N = in.nextInt();
    	int X = in.nextInt();
    	int Y = in.nextInt();
    	
    	double f = getFormation(N);
    	
    	if ((X + Y) / 2 <= f)
    		return 1.0;
    	
    	if ((X + Y) / 2 > f + 0.6)
    		return 0.0;
    	long fF = Math.round(Math.floor(f)) + 1;
    	System.out.println("" + N + " " + X + " " + Y);
    	System.out.println("Filling formation " + fF);
    	System.out.println("Diff " + getDiff(N));
    	System.out.println(getProb(getDiff(N), Y, fF));
    	System.out.println();
    	
    	return getProb(getDiff(N), Y, fF);
    }
    
    private static double getFormation(int N)
    {
    	double a = (-3 + Math.sqrt(1 + 8 * N)) / 4;
    	long F = Math.round(a) - 1;
    	
    	while (2*F*F + 3*F + 1 - N < 0)
    		F++;
    	
    	if (2*F*F + 3*F + 1 - N == 0)
    		return F;
    	else
    		return F - 0.5;
    }
    
    private static double getProb(long d, long h, long f)
    {
    	if (h >= d)
    		return 0.0;
    	
    	if (d >= 2 * f + 1 + h)
    		return 1.0;
    	
    	
    	int cnt = 0;
    	for (int i = 0; i < 100000; i++)
    	{
    		int[] a = new int[]{0, 0};
    		for (int k = 0; k < d; k++)
    		{
    			int j = (int) (Math.round(Math.random() * 1000) % 2);
				if (a[j] == 2 * f)
					a[1-j]++;
				else 
					a[j]++;
    		}
    		if (a[0] >= (h + 1))
    			cnt++;
    	}
    		
    	double res = 1.0 * cnt / 100000;
    	return 1.0 * Math.round(res * 256) / (256);
    }
    
    private static long getDiff(int N)
    {
    	double F = getFormation(N);
    	long iF = Math.round(Math.floor(F));
    	return N - (2*iF*iF + 3*iF + 1);
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
    	//System.out.println(getProb(3, 1, 1));
        new Round1B_B().run();
    }
}
