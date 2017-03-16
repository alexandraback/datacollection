package midnighter.googlejam.y2012;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Round1C_A
{
	static final String inFileName = "inputs/A-large.in";
	static final String outFileName = "outputs/A-large.out";
   
    public String oneCase()
    {
    	int N = in.nextInt();
    	List<Integer> childs[] = new ArrayList[N];
    	int[][] via = new int[N][N];
    	int[][] len = new int[N][N];
    	int[] origChilds = new int[N];
    	int tmp;
    	for (int i = 0; i < N; i++)
    	{
    		childs[i] = new ArrayList<Integer>();
    		Arrays.fill(via[i], -1);
    		int M = origChilds[i] = in.nextInt();
    		for (int j = 0; j < M; j++)
    		{
    			childs[i].add(tmp = (in.nextInt()-1));
    			via[i][tmp] = i;
    			//len[i][tmp] = 1;
    		}
    	}
    	
    	boolean smthHappened = true;
    	while (smthHappened)
    	{
    		smthHappened = false;
    		for (int i = 0; i < N; i++)
    		{
    			for (int j = 0; j < childs[i].size(); j++)
    			{
    				int ch1 = childs[i].get(j);
    				for (int l = 0; l < origChilds[ch1]; l++)
    				{
    					int ch2 = childs[ch1].get(l);
    					if (via[i][ch2] == -1)
    					{
    						via[i][ch2] = ch1;
    						childs[i].add(ch2);
    						//len[i][ch2] = len[i][ch1] + 1;
    						smthHappened = true;
    					}
    					else if (via[i][ch2] != ch1)
    					{
    						//System.out.println(len[i][ch1] + 1);
    						//System.out.println(len[i][ch2]);
    						System.out.println("" + ch2 + " to " + i + " via " + ch1 + " and " + via[i][ch2]);
    						return "Yes";
    					}
    				}
    			}
    		}
    	}
    	
    	return "No";
    }
   
    public void run() throws Exception
    {
        in = new Scanner(new FileReader(inFileName));
        out = new PrintWriter(new FileWriter(outFileName));
       
        int nCases = in.nextInt();
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
    
    Scanner in;
    PrintWriter out;
}
