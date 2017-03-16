package Runde1B;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashSet;

public class C {
	public static void main(String[] args) throws Exception {
		
		BufferedReader f = new BufferedReader(new FileReader("input.txt"));
		PrintStream out = new PrintStream(new File("output.txt"));
		
		// number of test cases
		int t = Integer.parseInt(f.readLine());
		
		// handle every testcase
		for (int i = 1; i <= t; i++) {
			int[] s = new int[20];
			String[] st = f.readLine().split(" ");
			for (int j = 1; j <= 20; j++) {
				s[j-1] = Integer.parseInt(st[j]);
			}
			out.println("Case #" + i + ": ");
			out.print(solve(s) );
		}
	}

	private static String solve(int[] s) {
		HashSet h = new HashSet();
		String ret = "";
		int n=20;
		int sum =getSum(s);
		if (sum ==-1)
			return "Impossible";
		else
			return searchsum(s,sum);
		
		
	}

	private static String searchsum(int[] s, int sum) {
		 // iterate over all the subsets
		int i;
		int counter =0;
		String ret = "";
		for (i=0; i < (1<<20) && counter <2; i++)
		{
			int sum2 =0;
		    // generate the i-th sum
		    for (int k=0; k < 20; k++)
		    {
		        if ((i&(1<<k)) > 0)
		            sum2 += s[k];
		    }
		            
		    if(sum2 == sum){
		    	 for (int l=0; l < 20; l++)
				    {
				        if ((i&(1<<l)) > 0)
				            ret = ret + s[l] + " " ;
				    }
		    	 ret = ret +"\n";
		    	 counter++;
		    }
		}
		return ret;
	}

	private static int getSum(int[] s) {
		HashSet h = new HashSet();
		for (int i=0; i < (1<<20); i++)
		{
			int sum =0;
		    // generate the i-th sum
		    for (int k=0; k < 20; k++)
		    {
		        if ((i&(1<<k)) > 0)
		            sum += s[k];
		    }
		            
		    if(h.contains(sum)){
		    	return sum;
		    }
		    else
		    	h.add(sum);
		}
		return -1;
	}
}
