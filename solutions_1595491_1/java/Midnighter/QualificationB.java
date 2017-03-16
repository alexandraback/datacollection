package midnighter.googlejam.y2012;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class QualificationB
{
	static final String inFileName = "inputs/B-large.in";
	static final String outFileName = "outputs/B-large.out";
	

    Scanner in;
    PrintWriter out;
   
    public int oneCase()
    {
    	int N = in.nextInt();
    	int S = in.nextInt();
    	int P = in.nextInt();
    	int[] scores = new int[N];
    	int res = 0;
    	
    	for (int i = 0; i < N; i++)
    	{
    		int s = scores[i] = in.nextInt();
    		int max1 = (s % 3 == 0) ? s / 3 : s / 3 + 1;
    		int max2 = (s % 3 == 2) ? s / 3 + 2 : s / 3 + 1;
    		
    		if (s == 0)
    			max1 = max2 = 0;
    		if (s == 1)
    			max1 = max2 = 1;
    		
    		if (max1 >= P || (max2 >= P && --S >= 0))
    			res++;
    	}
    		
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
        new QualificationB().run();
    }
}
