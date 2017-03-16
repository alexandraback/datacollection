package midnighter.googlejam.y2012;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class QualificationC
{
	static final String inFileName = "inputs/C-small-attempt0.in";
	static final String outFileName = "outputs/C-small.out";
	

    Scanner in;
    PrintWriter out;
   
    public int oneCase()
    {
    	int A = in.nextInt();
    	int B = in.nextInt();
    	int res = 0;
    	for (int i = A; i <= B; i++)
    	{
    		int d = 1, c = i;
    		while ((c /= 10) > 0)
    			d++;
    		int v = i;
    		for (int k = 0; k < d - 1; k++)
    		{
    			int nw = v % 10;
    			for (int j = 0; j < d - 1; j++)
    				nw *= 10;
    			v = v / 10 + nw;
    			if (v == i)
    				break;
    			if (nw != 0 && v <= B && v > i)
    				res++;
    		}
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
        new QualificationC().run();
    }
}
